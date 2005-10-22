/* 
 * Copyright (c) 2004, Laminar Research.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
 * THE SOFTWARE.
 *
 */
#ifndef MAPALGS_H
#define MAPALGS_H

#include "XESConstants.h"
#define kOverscale 1.0

#include "MapDefs.h"
#include "ProgressUtils.h"

struct	PolyRasterizer;
struct	DEMGeo;

/************************************************************************************************
 * FACE SETS AND EDGE SETS
 ************************************************************************************************
 * 
 * It is often useful to treat a group of faces or a group of edges as a unit...two examples:
 *
 * - A body of water might be made up of multiple faces becaue bridges split the body of water.
 *   So we use a face set to represent the entire body of water.
 *
 * - When merging or copying from one map to another, a single face or single edge in one map
 *   may be represented by many edges or faces in the new one!
 *
 * Generally when we have an edge set we mean a set of halfedges that form one or more rings.
 * (But the edge set is not ordered!)  When we have a face set, the area of the faces is not
 * necessarily continuous and may contain holes, islands, or whatever!
 *
 */

/*
 * FindEdgesForFace
 *
 * Given a face, return all halfedges that have the face on its left.
 * THIS DOES NOT CLEAR THE SET, FOR YOUR CONVENIENCE!!
 *
 */
void	FindEdgesForFace(GISFace * face, set<GISHalfedge *>& outEdges);

/*
 * FindFacesForEdgeSet
 *
 * Given a bounded edge set, return all faces within that edge set.
 * THIS DOES CLEAR THE FACE SET!
 *
 */
void	FindFacesForEdgeSet(const set<GISHalfedge *>& inEdges, set<GISFace *>& outFaces);

/*
 * FindEdgesForFaceSet
 *
 * Given a set of faces, finds the halfedges that bound the set of faces.
 *
 */
void	FindEdgesForFaceSet(const set<GISFace *>& inFaces, set<GISHalfedge *>& outEdges);

/*
 * FindAdjacentFaces
 *
 * Given a face, returns all faces that are touching this face.
 *
 */
void	FindAdjacentFaces(GISFace * inFace, set<GISFace *>& outFaces); 

/*
 * FindAdjacentWetFaces
 *
 * Given a face, returns all faces that are touching this face.
 *
 */
void	FindAdjacentWetFaces(GISFace * inFace, set<GISFace *>& outFaces); 

/*
 * FindConnectedWetFaces
 *
 * Given a water face, return all connected waterways.  This gives you a truly enclosed water
 * body, taking into account things like bridges.
 *
 */
void	FindConnectedWetFaces(GISFace * inFace, set<GISFace *>& outFaces); 

/*
 * CCBToPolygon
 *
 * Given a CCB (ring) in a map, this converts it to a simple polygon.  You can pass a weight function in which case a second array 
 * of per-side weights (0th weight is the CCB edge passed in) are also built up.
 *
 */
void		CCBToPolygon(const GISHalfedge * ccb, Polygon2& outPolygon, vector<double> * road_types, double (* weight_func)(const GISHalfedge * edge));

/*
 * FaceToComplexPolygon
 *
 * Given a face, this builds a "complex" polygon (multiple rings, first is outside CCW, rest are inside CW) from each ring (the outer CCB and holes) of the polygon.
 * Like above a weighting function is used.
 *
 */
void		FaceToComplexPolygon(const GISFace * face, vector<Polygon2>& outPolygon, vector<vector<double> > * road_types, double (* weight_func)(const GISHalfedge * edge));

/*
 * ComplexPolygonToPmwx
 *
 * Given a complex polygon (outer bounds and holes) this builds a PMWX with the same topolgoy.  InTerrain and outTerrain are terrain types assigned to space
 * in the PMWX inside and outside the complex polygon.
 *
 */
GISFace *	ComplexPolygonToPmwx(const vector<Polygon2>& inPolygons, Pmwx& outPmwx, int inTerrain, int outTerain);

/************************************************************************************************
 * MAP EDITING
 ************************************************************************************************
 *
 * Our fundamental map editing operations are:
 * 
 * Swap - given two rings of equal geometry in two maps, swap what's inside and on them.
 * Merge - insert all of one map into another.
 * 
 * We build all of our algorithms up from these.  One other noteworthy algorithm: "TopoIntegration"
 * just means pre-inserting the intersections of all edges from two maps into both so that we know
 * that there are no edge-edge intersections between the two.  See the topointegrate notes for why
 * we would want this.
 *
 * Besides the algs derived from swap, and merge, some of the "cleaning" algorithms simply go around
 * deleting edges.  These routines are slow because the topological transformations they can induce
 * are complex and must be computed one-at-a-time.  
 *
 * (Where possible algorithms that work on defined extents like "crop" use swap ops, which are MUCH 
 * faster.  While swap algs are still linear to the number of elements "swapped", almost all 
 * topological operations - inserting and removing edges fundamentally change topology - have a time
 * complexity greater than constant, so a topological op on a linear set is worse than linear time,
 * often by a lot!)
 *
 */

/*
 * CropMap
 *
 * Crop a map along a square box and keep one half.  This is a higher level version of the other
 * crop-map.
 *
 * Performance: O(N) + O(K*M) where
 *	N = number of halfedges inserted to form the cropped boundary and
 *  K = number of halfedges outside crop that are deleted and
 *  M = averge number of halfedges in a CCB.
 *
 */
void	CropMap(
			Pmwx&			ioMap,
			double			inWest,
			double			inSouth,
			double			inEast,
			double			inNorth,
			bool			inKeepOutside,	// If true, keep outside crop zone (cut a hole), otherwise keep only inside (normal crop)
			ProgressFunc	inProgress);

/*
 * CropMap - advanced form.
 *
 * Pass in a map, and a blank map to receive what is inside the ring passed in inRingCCW.  
 * The ring MUST be counterclockwise.  This gives you more precise control over what is cropped
 * and what is saved and chucked.  (This can be used to do cut, copy, paste, clear, etc.)
 *
 * (This is a convenient high level swap.)
 *
 */
void	CropMap(
			Pmwx&					ioMap,
			Pmwx&					outCutout,
			const vector<Point2>&	inRingCCW,
			ProgressFunc			inProgress);

/*
 * SwapFace 
 *
 * Given two maps, replace the face in the master map with the contents of the submap.  
 * This routine destroys interior antennas - halfedges connected to the outer CCB that have
 * the face on both sides.  This allows for a clean cut.  
 *
 * The remaining contents of the master face are swapped with the target face, which is chopped
 * to make the cut possible.
 *
 * The holes of the master face are then swapped back.
 *
 * (This is a convenient high level swap.)
 *
 */
void	SwapFace(
			Pmwx&			inMaster,
			Pmwx&			inSlave,
			GISFace *		inFace,
			ProgressFunc	inFunc);


/*
 * CleanFace
 * 
 * Given a face on a map, this routine 'cleans' its interior, removing any
 * antennas, holes, or anything else in its interior.
 *
 * (This is a convenient high level swap.)
 *
 */
void	CleanFace(
			Pmwx&				inMap,
			Pmwx::Face_handle	inFace);

/*
 * OverlayMap
 *
 * Inserts all part of inSrc into inDst.  inSrc must not have antennas outside of the holes in
 * the unbounded face.  InSrc is left with gutted holes of inDst's remains where land was, 
 * inDst has contents overwritten.
 *
 */
void OverlayMap(
			Pmwx& 	inDst, 
			Pmwx& 	inSrc);

/*
 * ReduceToWaterBodies
 *
 * This routine removes edges until the map consists only of faces that represent contiguous
 * water bodies, and the infinite face.  Please note that implicit in this is that edges
 * be constructed to form discrete water bodies up to the edge of the map's useful area.
 *
 * Performance: O(N*M) where N = number of removed halfedges, and M = average number
 * of halfedges in a CCB. 
 *
 */
void ReduceToWaterBodies(Pmwx& ioMap);


/*
 * SimplifyMap
 *
 * SimplifyMap removes all edges that do not separate distinct land uses, form the outer
 * CCB, or contain rivers/transportation.  This can include lines from unused data, like
 * geopolitical boundaries, or lines that are artifacts of the import.
 *
 * Performance: O(N*M) where N = number of removed halfedges, and M = average number
 * of halfedges in a CCB.
 *
 */
int SimplifyMap(Pmwx& ioMap);

/*
 * RemoveUnboundedWater
 *
 * Similar to the routines above, this routine removes all vectors with water on both sides
 * and no transportation links.  The result is (among other things) a removal of unbounded water
 * from a map.  This can be useful for reducing a map to dry land and embedded lakes.
 *
 * This also removes antennas into the unbounded face.
 *
 * Performance: O(N*M) where N = number of removed halfedges, and M = average number
 * of halfedges in a CCB.
 *
 */
int RemoveUnboundedWater(Pmwx& ioMap);


/*
 * MergeMaps
 *
 * This routine copies the contents of ioSrcMap into ioDstMap.
 *
 * Performance: O((N+F)*M) where N is the number of halfedges inserted into the
 * dest map and M is the average number of halfedges in a CCB in the dest map, and
 * F is the number of faces in the source map that have important data that must be copied.
 *
 * For optimal performance, ioDstMap should have faces with small numbers of bounds
 * and ioSrcMap should have fewer or shorter halfedges, and fewer faces that have 
 * data that need to be copied.
 *
 * If inForceProps is true, when there is a property conflict for terrain type or area property
 * on a face, the srcMap will win; otherwise the dstMap will win.  A merge takes place where 
 * there is no conflicts.
 *
 * If outFaces is not NULL, then the handle of every face in the dst map that had a property
 * in the source map is returned.  Two warnings: "empty" faces (terrain natural, no area 
 * feature) are not included, and faces that are non-empty are copied even if the dest-map has
 * a property and inForceProps is false (in which case the face in outFaces did not receive a
 * property from the source.  (A typical use might be to put a bogus mark or terrain on all
 * source faces and thus receive an idea of where in the destination map your source map 
 * ended up, without having to do a bunch of fac-relocates from edge bounds.
 *
 */
void MergeMaps(Pmwx& ioDstMap, Pmwx& ioSrcMap, bool inForceProps, set<GISFace *> * outFaces, bool pre_integrated);

/*
 * SwapAreas
 *
 * This routine does an optimized exchange of an area contained by a CCB.
 *
 * You pass in: two "rings" of halfedges that form an outer CCB around a finite area.
 * Requirement: the two rings must correlate 1:1 - each halfedge must have the same start/end
 * as its friend.
 * Requirement: the rings must be closed.
 *
 * This routine then swaps the contents of the rings using an optimized swap.
 *
 */
void	SwapMaps(	Pmwx& 							ioMapA, 
					Pmwx& 							ioMapB, 
					const vector<GISHalfedge *>&	inBoundsA,
					const vector<GISHalfedge *>&	inBoundsB);
			
/*
 * TopoIntegrateMaps
 *
 * Given two maps, guarantees that each map could only cross each other at vertices, and that
 * these vertices have the same numeric values.
 *
 */		
void TopoIntegrateMaps(Pmwx * mapA, Pmwx * mapB);

/*
 * SafeInsertRing
 *
 * This alternative to insert_ring fixes a few limitations of the low-level insertion routine:
 * 1. It can insert rings with antennas on them.
 * 2. It can insert rings that share vertices with the existing mesh.  
 * It does an insert_ring if possible, otherwise it does a slow edge insert.  Please note that
 * this routine does NOT handle non-simple polygons (except for antennas), nor does it handle
 * rings that intersect the existing mesh, so you do need to ensure some topological integration
 * of yoour input data.
 *
 */
GISFace * SafeInsertRing(Pmwx * inPmwx, GISFace * parent, const vector<Point2>& inPoints);

/************************************************************************************************
 * MAP ANALYSIS AND RASTERIZATION/ANALYSIS
 ************************************************************************************************/

/*
 * ValidateMapDominance
 *
 * The scenery system depends on the 'dominant' system
 * to correctly deal with dominance issues...this routine
 * makes sure things aren't FUBAR.
 *
 */
bool	ValidateMapDominance(const Pmwx& inMap);


/*
 * CalcBoundingBox
 *
 * Given a map, find its boundingbox.
 *
 */
void	CalcBoundingBox(
			const Pmwx&		inMap,
			Point2&		sw,
			Point2&		ne);

/*
 * GetMapFaceAreaMeters
 *
 * Given a map in lat/lon and a face, return its area in meters.
 *
 */
double	GetMapFaceAreaMeters(const Pmwx::Face_handle f);

/*
 * GetMapEdgeLengthMeters
 * 
 * Given an edge in lat/lon, return is length in meters.
 *
 */
double	GetMapEdgeLengthMeters(const Pmwx::Halfedge_handle e);

/*
 * GetParamAverage
 * GetParamHistogram
 * 
 * Given a face and a raster DEM in the same coordinate system, find either the min, max and average
 * of the value in the DEM over the face area, or find a full histogram for the face erea.
 * Please note that the histogram is NOT initialized; so that you can run it on multiple faces.
 *
 */
float	GetParamAverage(const Pmwx::Face_handle f, const DEMGeo& dem, float * outMin, float * outMax);
int		GetParamHistogram(const Pmwx::Face_handle f, const DEMGeo& dem, map<float, int>& outHistogram);

/*
 * ClipDEMToFaceSet
 *
 * Given a set of faces, copy the points in the src DEM to the dest DEM only if we're in the faces.  
 * Return the bounds (inclusive min, exclusive max) of the copied area.  Returns true if any points
 * were copied, otherwise the Xa and Y params may nto be valid.
 *
 */
bool	ClipDEMToFaceSet(const set<GISFace *>& inFaces, const DEMGeo& inSrcDEM, DEMGeo& inDstDEM, int& outX1, int& outY1, int& outX2, int& outY2);

/*
 * SetupRasterizerForDEM
 *
 * Given a face (or edge set containing a finite area) and a DEM in the same coordinates, set up the polygon
 * rasterizer to rasterize the DEM over the face set.  
 *
 * This is useful for preparing iterating to iterate over every DEM point contained within a face or edge set.
 * The lowest Y coordinate in the DEM that is within the rasterized area is returned as a good start value to
 * the rasterize outer loop.
 *
 */
int		SetupRasterizerForDEM(const Pmwx::Face_handle f, const DEMGeo& dem, PolyRasterizer& rasterizer);
int		SetupRasterizerForDEM(const set<GISHalfedge *>& inEdges, const DEMGeo& dem, PolyRasterizer& rasterizer);

/************************************************************************************************
 * POLYGON TRUNCATING AND EDITING
 ************************************************************************************************/

/*
 * InsetPmwx
 *
 * WARNING WARNING WARNING: This routine's implementation is INCORRECT and UNRELIABLE.
 * The SK_Skeleton APIs are designed to provide correct straight-skeleton-based inset
 * calculations; InsetPmwx is an old attempt to write an inset routine without proper
 * skeleton treatmant and should not be used!
 *
 * Given a Pmwx and a face, inset the face.  This is a complex and powerful inset routine;
 * unlike InsetPolygon, it can handle (1) holes in the polygon and (2) generacy (e.g. the 
 * resulting polygon may be massively different than the first).
 *
 * The API is pretty strange: you pass in a map with a face to be inset.  While there is no
 * requirement that this face be in the unbounded face, it is strongly recommended for performance
 * and stability that you pass in a Pmwx where the face is the only hole in the CCB.
 *
 * Make sure the face's terrain type is not water.  Set each halfedge of the face to the inset
 * distance in meters.  
 *
 * On output, you will get the map back where every bounded face whose terrain type is not water
 * is an empty usable area not consumed by the inset.  You can then iterate across all bounded
 * faces checking terrain type to receive a bunch of polygons (with potential holes) that represent
 * the non-inset space.
 *
 * There is no guarantee that any given edge will continue to exist or that the face will not be
 * destroyed and recreated.  The algorithm has to do a lot of processing to produce the inset, so
 * the map gets pretty badly beaten up.
 *
 */
void	InsetPmwx(Pmwx& inMap, GISFace * inFace);

/************************************************************************************************
 * INLINE STUFF
 ************************************************************************************************/



template <typename InputIterator>
Point2	FindRefPoint(InputIterator begin, InputIterator end)
{
	if (begin == end) return CGAL::ORIGIN;
	Point2	best = *begin;
	for (InputIterator i = begin; i != end; ++i)
	{
		if ((*i).x < best.x)
			best = Point2((*i).x, best.y);
		if ((*i).y < best.y)
			best = Point2(best.x, (*i).y);
	}
	
	return best;
}

template <typename ForwardIterator>
void LatLonToLocalMeters(ForwardIterator begin, ForwardIterator end, const Point2& ref)
{
	Vector_2	offset(ref);
	double		DEG_TO_MTR_LON = DEG_TO_MTR_LAT * cos(CGAL::to_double(ref.y) * DEG_TO_RAD);
	for (ForwardIterator i = begin; i != end; ++i)
	{
		Point2 p = *i - offset;
		Point2	p2(p.x * DEG_TO_MTR_LON / kOverscale,
				   p.y * DEG_TO_MTR_LAT / kOverscale);
		*i = p2;
	}
}

template <typename ForwardIterator>
void LocalMetersToLatLon(ForwardIterator begin, ForwardIterator end, const Point2& ref)
{
	Vector_2	offset(ref);
	double		DEG_TO_MTR_LON = DEG_TO_MTR_LAT * cos(CGAL::to_double(ref.y) * DEG_TO_RAD);
	for (ForwardIterator i = begin; i != end; ++i)
	{
		Point2	p ((*i).x * kOverscale / DEG_TO_MTR_LON,
				   (*i).y * kOverscale / DEG_TO_MTR_LAT);
		Point2 p2 = p + offset;
		*i = p2;
	}
}


#endif
