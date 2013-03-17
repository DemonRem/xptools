/*
 * Copyright (c) 2007, Laminar Research.
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

ENUM_DOMAIN(Airport_Type, "Airport Type")
	ENUM(type_Airport,	"Airport", apt_airport)
	ENUM(type_Heliport,	"Heliport",apt_heliport)
	ENUM(type_Seaport,	"Seaport", apt_seaport)

ENUM_DOMAIN(Edge_Lights, "Runway Edge Light Types")

	ENUM(edge_None, "None", apt_edge_none)
	ENUM(edge_LIRL, "LIRL", apt_edge_LIRL)
	ENUM(edge_MIRL,	"MIRL",	apt_edge_MIRL)
	ENUM(edge_HIRL,	"HIRL", apt_edge_HIRL)

ENUM_DOMAIN(REIL_Lights,"Runway End Identifier Lights")
	ENUM(reil_None,"None",apt_reil_none)
	ENUM(reil_Omni,"Omnidirectional REIL", apt_reil_omni)
	ENUM(reil_Uni,"Unidirectional REIL",apt_reil_uni)

ENUM_DOMAIN(Heli_Lights,"Helipad Edge Lights")
	ENUM(heli_None,"None",apt_heli_edge_none)
	ENUM(heli_Yellow,"Yellow",apt_heli_edge_yellow)
//	ENUM(heli_White,"White", 2)
//	ENUM(heli_Red,"Red",3)

ENUM_DOMAIN(Sign_Size,"Sign Size")
	ENUM(size_SmallTaxi,"Small Taxiway", apt_sign_small)
	ENUM(size_MediumTaxi,"Medium Taxiway", apt_sign_medium)
	ENUM(size_LargeTaxi,"Large Taxiway", apt_sign_large)
	ENUM(size_LargeRemaining,"Large Distance Remaining",apt_sign_large_distance)
	ENUM(size_SmallRemaining,"Small Distance Remaining", apt_sign_small_distance)

ENUM_DOMAIN(Sign_Style,"Sign Style")
	ENUM(style_Default,"Default",apt_sign_style_default)

ENUM_DOMAIN(Surface_Type,"Surface Type")
	ENUM(surf_Asphalt,"Asphalt",apt_surf_asphalt)
	ENUM(surf_Concrete,"Concrete",apt_surf_concrete)
	ENUM(surf_Grass,"Grass",apt_surf_grass)
	ENUM(surf_Dirt,"Dirt",apt_surf_dirt)
	ENUM(surf_Gravel,"Gravel",apt_surf_gravel)
	ENUM(surf_Lake,"Dry Lakebed",apt_surf_dry_lake)
	ENUM(surf_Water,"Water",apt_surf_water)
	ENUM(surf_Snow,"Snow",apt_surf_ice)
	ENUM(surf_Trans,"Transparent",apt_surf_transparent)

ENUM_DOMAIN(Light_Fixt,"Light Fixtures")
	ENUM(light_VASI,"VASI", apt_gls_vasi)
	ENUM(light_PAPI_Left,"PAPI (Left Side)",apt_gls_papi_left)
	ENUM(light_PAPI_Right,"PAPI (Right Side)",apt_gls_papi_right)
	ENUM(light_PAPI20,"PAPI (20 degrees)",apt_gls_papi_20)
	ENUM(light_VASI_Tri,"VASI (Tri-Color)",apt_gls_vasi_tricolor)
	ENUM(light_WigWag,"Wig-Wags",apt_gls_wigwag)

ENUM_DOMAIN(Light_App,"Approach Lights")
	ENUM(app_None,		"None",						apt_app_none)
	ENUM(app_ALSFI,		"ALSF-I",					apt_app_ALSFI)
	ENUM(app_ALSFII,	"ALSF-II",					apt_app_ALSFII)
	ENUM(app_Calvert,	"Calvert",					apt_app_CALVERTI)
	ENUM(app_Calvert2,	"Calvert-II",				apt_app_CALVERTII)

	ENUM(app_SSALR,		"SSALR",					apt_app_SSALR)
	ENUM(app_SSALF,		"SSALF",					apt_app_SSALF)
	ENUM(app_SALS,		"SALS",						apt_app_SALS)

	ENUM(app_MALSR,		"MALSR",					apt_app_MALSR)
	ENUM(app_MALSF,		"MALSF",					apt_app_MALSF)
	ENUM(app_MALS,		"MALS",						apt_app_MALS)

	ENUM(app_ODALS,		"ODALS",					apt_app_ODALS)
	ENUM(app_RAIL,		"RAIL",						apt_app_RAIL)

ENUM_DOMAIN(Shoulder_Type,"Shoulder Type")
	ENUM(shoulder_None,			"None",				apt_shoulder_none)
	ENUM(shoulder_Asphalt,		"Asphalt",			apt_shoulder_asphalt)
	ENUM(shoulder_Concrete,		"Concrete",			apt_shoulder_concrete)

ENUM_DOMAIN(Runway_Markings,"Runway Markings")
	ENUM(mark_None,				"None",						apt_mark_none)
	ENUM(mark_Visual,			"Visual",					apt_mark_visual)
	ENUM(mark_NonPrecis,		"Non-Precision (US)",		apt_mark_non_precision)
	ENUM(mark_Precis,			"Precision (US)",			apt_mark_precision)
	ENUM(mark_NonPrecisUK,		"Non-Precision (UK)",		apt_mark_non_precision_UK)
	ENUM(mark_PrecisUK,			"Precision (UK)",			apt_mark_precision_UK)

ENUM_DOMAIN(Helipad_Markings,"Helipad Markings")
	ENUM(heli_Mark_Default,		"Default",					apt_mark_heli_default)

ENUM_DOMAIN(Airport_Beacon,"Airport Beacon Type")
	ENUM(beacon_Airport,		"Airport",					apt_beacon_airport)
	ENUM(beacon_Seaport,		"Seaport",					apt_beacon_seaport)
	ENUM(beacon_Heliport,		"Heliport",					apt_beacon_heliport)
	ENUM(beacon_MilitaryAirport,"Military Airport",			apt_beacon_military)

ENUM_DOMAIN(LinearFeature, "Linear Markings")
	ENUM(line_SolidYellow,		"Solid Yellow",					apt_line_solid_yellow)
	ENUM(line_BrokenYellow,		"Broken Yellow",				apt_line_broken_yellow)
	ENUM(line_DoubleSolidYellow,"Double Solid Yellow",			apt_line_double_solid_yellow)
	ENUM(line_RunwayHold,		"Runway Hold",					apt_line_runway_hold)
	ENUM(line_OtherHold,		"Other Hold",					apt_line_other_hold)
	ENUM(line_ILSHold,			"ILS Hold",						apt_line_ils_hold)
	ENUM(line_ILSCriticalCenter,"ILS Critical Centerline",		apt_line_ils_center)
	ENUM(line_WideBrokenSingle,	"Wide Broken Single Yellow",	apt_line_wide_broken_yellow)
	ENUM(line_WideBrokenDouble,	"Wide Broken Double Yellow",	apt_line_wide_double_broken_yellow)

	ENUM(line_SolidWhite,		"Solid White (Roadway)",				apt_line_solid_white)
	ENUM(line_Chequered,		"Chequered White (Roadway)",			apt_line_chequered_white)
	ENUM(line_BrokenWhite,		"Broken White (Roadway)",				apt_line_broken_white)

	ENUM(line_BSolidYellow,		"Solid Yellow (Black)",					apt_line_Bsolid_yellow)
	ENUM(line_BBrokenYellow,	"Broken Yellow (Black)",				apt_line_Bbroken_yellow)
	ENUM(line_BDoubleSolidYellow,"Double Solid Yellow (Black)",			apt_line_Bdouble_solid_yellow)
	ENUM(line_BRunwayHold,		"Runway Hold (Black)",					apt_line_Brunway_hold)
	ENUM(line_BOtherHold,		"Other Hold (Black)",					apt_line_Bother_hold)
	ENUM(line_BILSHold,			"ILS Hold (Black)",						apt_line_Bils_hold)
	ENUM(line_BILSCriticalCenter,"ILS Critical Centerline (Black)",		apt_line_Bils_center)
	ENUM(line_BWideBrokenSingle,"Wide Broken Single Yellow (Black)",	apt_line_Bwide_broken_yellow)
	ENUM(line_BWideBrokenDouble,"Wide Broken Double Yellow (Black)",	apt_line_Bwide_double_broken_yellow)

	ENUM(line_TaxiCenter,		"Taxiway Centerline Lights (Green)",	apt_light_taxi_centerline)
	ENUM(line_TaxiEdge,			"Taxiway Edge Lights (Blue)",			apt_light_taxi_edge)
	ENUM(line_HoldLights,		"Hold Short Lights (Amber)",			apt_light_hold_short)
	ENUM(line_HoldLightsPulse,	"Hold Short Lights (Pulsing Amber)",	apt_light_hold_short_flash)
	ENUM(line_HoldShortCenter,	"Hold Short Centerline Lights (Amber/Green)",apt_light_hold_short_centerline)
	ENUM(line_BoundaryEdge,		"Boundary Edge Lights (Red)",			apt_light_bounary)

ENUM_DOMAIN(ATCFrequency, "ATC Frequency")
	ENUM(atc_AWOS,				"AWOS",									apt_freq_awos)
	ENUM(atc_CTAF,				"CTAF",									apt_freq_ctaf)
	ENUM(atc_Delivery,			"Clearance Delivery",					apt_freq_del)
	ENUM(atc_Ground,			"Ground Control",						apt_freq_gnd)
	ENUM(atc_Tower,				"Tower",								apt_freq_twr)
	ENUM(atc_Approach,			"Approach",								apt_freq_app)
	ENUM(atc_Departure,			"Departure",							apt_freq_dep)

ENUM_DOMAIN(ExclusionTypes, "Exclusion Types")
	ENUM(exclude_Obj,			"Objects",								0)
	ENUM(exclude_Fac,			"Facades",								1)
	ENUM(exclude_For,			"Forests",								2)
	ENUM(exclude_Bch,			"Beaches",								3)
	ENUM(exclude_Net,			"Road Networks",						4)
	ENUM(exclude_Lin,			"Lines",								5)
	ENUM(exclude_Pol,			"Draped Polygons",						6)
	ENUM(exclude_Str,			"String",								7)

ENUM_DOMAIN(TCE_GridSnap, "Grid")
	ENUM(tce_Grid_None,				"None",								0)
	ENUM(tce_Grid_Whole,			"1",								1)
	ENUM(tce_Grid_Half,				"1/2",								2)		
	ENUM(tce_Grid_Quarter,			"1/4",								3)
	
	
ENUM_DOMAIN(ATCPatternSide,"Pattern Side")
	ENUM(atc_Left,					"Left",								apt_pattern_left)
	ENUM(atc_Right,					"Right",							apt_pattern_right)		

ENUM_DOMAIN(ATCTrafficType,"Traffic Type")
	ENUM(atc_Heavies,				"Heavy Jets",						atc_traffic_heavies)
	ENUM(atc_Jets,					"Jets",								atc_traffic_jets)
	ENUM(atc_Props,					"Props",							atc_traffic_props)	
	ENUM(atc_Helicopters,			"Helicopters",						atc_traffic_helis)		
	
ENUM_DOMAIN(ATCOperationType,"Operations")
	ENUM(atc_Arrivals,				"Arrivals",							atc_op_arrivals)
	ENUM(atc_Departures,			"Departures",						atc_op_departures)

ENUM_DOMAIN(ATCRunwayOneway,"Runway Direction")
	ENUM(atc_Runway_None,				"None",		0)
	ENUM(atc_1,							"01",		10)
	ENUM(atc_1L,						"01L",		11)
	ENUM(atc_1C,						"01C",		12)
	ENUM(atc_1R,						"01R",		13)
	ENUM(atc_2,							"02",		20)
	ENUM(atc_2L,						"02L",		21)
	ENUM(atc_2C,						"02C",		22)
	ENUM(atc_2R,						"02R",		23)
	ENUM(atc_3,							"03",		30)
	ENUM(atc_3L,						"03L",		31)
	ENUM(atc_3C,						"03C",		32)
	ENUM(atc_3R,						"03R",		33)
	ENUM(atc_4,							"04",		40)
	ENUM(atc_4L,						"04L",		41)
	ENUM(atc_4C,						"04C",		42)
	ENUM(atc_4R,						"04R",		43)
	ENUM(atc_5,							"05",		50)
	ENUM(atc_5L,						"05L",		51)
	ENUM(atc_5C,						"05C",		52)
	ENUM(atc_5R,						"05R",		53)
	ENUM(atc_6,							"06",		60)
	ENUM(atc_6L,						"06L",		61)
	ENUM(atc_6C,						"06C",		62)
	ENUM(atc_6R,						"06R",		63)
	ENUM(atc_7,							"07",		70)
	ENUM(atc_7L,						"07L",		71)
	ENUM(atc_7C,						"07C",		72)
	ENUM(atc_7R,						"07R",		73)
	ENUM(atc_8,							"08",		80)
	ENUM(atc_8L,						"08L",		81)
	ENUM(atc_8C,						"08C",		82)
	ENUM(atc_8R,						"08R",		83)
	ENUM(atc_9,							"09",		90)
	ENUM(atc_9L,						"09L",		91)
	ENUM(atc_9C,						"09C",		92)
	ENUM(atc_9R,						"09R",		93)
	ENUM(atc_10,						"10",		100)
	ENUM(atc_10L,						"10L",		101)
	ENUM(atc_10C,						"10C",		102)
	ENUM(atc_10R,						"10R",		103)
	ENUM(atc_11,						"11",		110)
	ENUM(atc_11L,						"11L",		111)
	ENUM(atc_11C,						"11C",		112)
	ENUM(atc_11R,						"11R",		113)
	ENUM(atc_12,						"12",		120)
	ENUM(atc_12L,						"12L",		121)
	ENUM(atc_12C,						"12C",		122)
	ENUM(atc_12R,						"12R",		123)
	ENUM(atc_13,						"13",		130)
	ENUM(atc_13L,						"13L",		131)
	ENUM(atc_13C,						"13C",		132)
	ENUM(atc_13R,						"13R",		133)
	ENUM(atc_14,						"14",		140)
	ENUM(atc_14L,						"14L",		141)
	ENUM(atc_14C,						"14C",		142)
	ENUM(atc_14R,						"14R",		143)
	ENUM(atc_15,						"15",		150)
	ENUM(atc_15L,						"15L",		151)
	ENUM(atc_15C,						"15C",		152)
	ENUM(atc_15R,						"15R",		153)
	ENUM(atc_16,						"16",		160)
	ENUM(atc_16L,						"16L",		161)
	ENUM(atc_16C,						"16C",		162)
	ENUM(atc_16R,						"16R",		163)
	ENUM(atc_17,						"17",		170)
	ENUM(atc_17L,						"17L",		171)
	ENUM(atc_17C,						"17C",		172)
	ENUM(atc_17R,						"17R",		173)
	ENUM(atc_18,						"18",		180)
	ENUM(atc_18L,						"18L",		181)
	ENUM(atc_18C,						"18C",		182)
	ENUM(atc_18R,						"18R",		183)
	ENUM(atc_19,						"19",		190)
	ENUM(atc_19L,						"19L",		191)
	ENUM(atc_19C,						"19C",		192)
	ENUM(atc_19R,						"19R",		193)
	ENUM(atc_20,						"20",		200)
	ENUM(atc_20L,						"20L",		201)
	ENUM(atc_20C,						"20C",		202)
	ENUM(atc_20R,						"20R",		203)
	ENUM(atc_21,						"21",		210)
	ENUM(atc_21L,						"21L",		211)
	ENUM(atc_21C,						"21C",		212)
	ENUM(atc_21R,						"21R",		213)
	ENUM(atc_22,						"22",		220)
	ENUM(atc_22L,						"22L",		221)
	ENUM(atc_22C,						"22C",		222)
	ENUM(atc_22R,						"22R",		223)
	ENUM(atc_23,						"23",		230)
	ENUM(atc_23L,						"23L",		231)
	ENUM(atc_23C,						"23C",		232)
	ENUM(atc_23R,						"23R",		233)
	ENUM(atc_24,						"24",		240)
	ENUM(atc_24L,						"24L",		241)
	ENUM(atc_24C,						"24C",		242)
	ENUM(atc_24R,						"24R",		243)
	ENUM(atc_25,						"25",		250)
	ENUM(atc_25L,						"25L",		251)
	ENUM(atc_25C,						"25C",		252)
	ENUM(atc_25R,						"25R",		253)
	ENUM(atc_26,						"26",		260)
	ENUM(atc_26L,						"26L",		261)
	ENUM(atc_26C,						"26C",		262)
	ENUM(atc_26R,						"26R",		263)
	ENUM(atc_27,						"27",		270)
	ENUM(atc_27L,						"27L",		271)
	ENUM(atc_27C,						"27C",		272)
	ENUM(atc_27R,						"27R",		273)
	ENUM(atc_28,						"28",		280)
	ENUM(atc_28L,						"28L",		281)
	ENUM(atc_28C,						"28C",		282)
	ENUM(atc_28R,						"28R",		283)
	ENUM(atc_29,						"29",		290)
	ENUM(atc_29L,						"29L",		291)
	ENUM(atc_29C,						"29C",		292)
	ENUM(atc_29R,						"29R",		293)
	ENUM(atc_30,						"30",		300)
	ENUM(atc_30L,						"30L",		301)
	ENUM(atc_30C,						"30C",		302)
	ENUM(atc_30R,						"30R",		303)
	ENUM(atc_31,						"31",		310)
	ENUM(atc_31L,						"31L",		311)
	ENUM(atc_31C,						"31C",		312)
	ENUM(atc_31R,						"31R",		313)
	ENUM(atc_32,						"32",		320)
	ENUM(atc_32L,						"32L",		321)
	ENUM(atc_32C,						"32C",		322)
	ENUM(atc_32R,						"32R",		323)
	ENUM(atc_33,						"33",		330)
	ENUM(atc_33L,						"33L",		331)
	ENUM(atc_33C,						"33C",		332)
	ENUM(atc_33R,						"33R",		333)
	ENUM(atc_34,						"34",		340)
	ENUM(atc_34L,						"34L",		341)
	ENUM(atc_34C,						"34C",		342)
	ENUM(atc_34R,						"34R",		343)
	ENUM(atc_35,						"35",		350)
	ENUM(atc_35L,						"35L",		351)
	ENUM(atc_35C,						"35C",		352)
	ENUM(atc_35R,						"35R",		353)
	ENUM(atc_36,						"36",		360)
	ENUM(atc_36L,						"36L",		361)
	ENUM(atc_36C,						"36C",		362)
	ENUM(atc_36R,						"36R",		363)

ENUM_DOMAIN(ATCRunwayTwoway,"Runway Name")
	ENUM(atc_rwy_None,					"None",		0)
	ENUM(atc_rwy_1_xxx,					"01/XXX",		10)
	ENUM(atc_rwy_1L_xxx,				"01L/XXX",		11)
	ENUM(atc_rwy_1C_xxx,				"01C/XXX",		12)
	ENUM(atc_rwy_1R_xxx,				"01R/XXX",		13)
	ENUM(atc_rwy_2_xxx,					"02/XXX",		20)
	ENUM(atc_rwy_2L_xxx,				"02L/XXX",		21)
	ENUM(atc_rwy_2C_xxx,				"02C/XXX",		22)
	ENUM(atc_rwy_2R_xxx,				"02R/XXX",		23)
	ENUM(atc_rwy_3_xxx,					"03/XXX",		30)
	ENUM(atc_rwy_3L_xxx,				"03L/XXX",		31)
	ENUM(atc_rwy_3C_xxx,				"03C/XXX",		32)
	ENUM(atc_rwy_3R_xxx,				"03R/XXX",		33)
	ENUM(atc_rwy_4_xxx,					"04/XXX",		40)
	ENUM(atc_rwy_4L_xxx,				"04L/XXX",		41)
	ENUM(atc_rwy_4C_xxx,				"04C/XXX",		42)
	ENUM(atc_rwy_4R_xxx,				"04R/XXX",		43)
	ENUM(atc_rwy_5_xxx,					"05/XXX",		50)
	ENUM(atc_rwy_5L_xxx,				"05L/XXX",		51)
	ENUM(atc_rwy_5C_xxx,				"05C/XXX",		52)
	ENUM(atc_rwy_5R_xxx,				"05R/XXX",		53)
	ENUM(atc_rwy_6_xxx,					"06/XXX",		60)
	ENUM(atc_rwy_6L_xxx,				"06L/XXX",		61)
	ENUM(atc_rwy_6C_xxx,				"06C/XXX",		62)
	ENUM(atc_rwy_6R_xxx,				"06R/XXX",		63)
	ENUM(atc_rwy_7_xxx,					"07/XXX",		70)
	ENUM(atc_rwy_7L_xxx,				"07L/XXX",		71)
	ENUM(atc_rwy_7C_xxx,				"07C/XXX",		72)
	ENUM(atc_rwy_7R_xxx,				"07R/XXX",		73)
	ENUM(atc_rwy_8_xxx,					"08/XXX",		80)
	ENUM(atc_rwy_8L_xxx,				"08L/XXX",		81)
	ENUM(atc_rwy_8C_xxx,				"08C/XXX",		82)
	ENUM(atc_rwy_8R_xxx,				"08R/XXX",		83)
	ENUM(atc_rwy_9_xxx,					"09/XXX",		90)
	ENUM(atc_rwy_9L_xxx,				"09L/XXX",		91)
	ENUM(atc_rwy_9C_xxx,				"09C/XXX",		92)
	ENUM(atc_rwy_9R_xxx,				"09R/XXX",		93)
	ENUM(atc_rwy_10_xxx,				"10/XXX",		100)
	ENUM(atc_rwy_10L_xxx,				"10L/XXX",		101)
	ENUM(atc_rwy_10C_xxx,				"10C/XXX",		102)
	ENUM(atc_rwy_10R_xxx,				"10R/XXX",		103)
	ENUM(atc_rwy_11_xxx,				"11/XXX",		110)
	ENUM(atc_rwy_11L_xxx,				"11L/XXX",		111)
	ENUM(atc_rwy_11C_xxx,				"11C/XXX",		112)
	ENUM(atc_rwy_11R_xxx,				"11R/XXX",		113)
	ENUM(atc_rwy_12_xxx,				"12/XXX",		120)
	ENUM(atc_rwy_12L_xxx,				"12L/XXX",		121)
	ENUM(atc_rwy_12C_xxx,				"12C/XXX",		122)
	ENUM(atc_rwy_12R_xxx,				"12R/XXX",		123)
	ENUM(atc_rwy_13_xxx,				"13/XXX",		130)
	ENUM(atc_rwy_13L_xxx,				"13L/XXX",		131)
	ENUM(atc_rwy_13C_xxx,				"13C/XXX",		132)
	ENUM(atc_rwy_13R_xxx,				"13R/XXX",		133)
	ENUM(atc_rwy_14_xxx,				"14/XXX",		140)
	ENUM(atc_rwy_14L_xxx,				"14L/XXX",		141)
	ENUM(atc_rwy_14C_xxx,				"14C/XXX",		142)
	ENUM(atc_rwy_14R_xxx,				"14R/XXX",		143)
	ENUM(atc_rwy_15_xxx,				"15/XXX",		150)
	ENUM(atc_rwy_15L_xxx,				"15L/XXX",		151)
	ENUM(atc_rwy_15C_xxx,				"15C/XXX",		152)
	ENUM(atc_rwy_15R_xxx,				"15R/XXX",		153)
	ENUM(atc_rwy_16_xxx,				"16/XXX",		160)
	ENUM(atc_rwy_16L_xxx,				"16L/XXX",		161)
	ENUM(atc_rwy_16C_xxx,				"16C/XXX",		162)
	ENUM(atc_rwy_16R_xxx,				"16R/XXX",		163)
	ENUM(atc_rwy_17_xxx,				"17/XXX",		170)
	ENUM(atc_rwy_17L_xxx,				"17L/XXX",		171)
	ENUM(atc_rwy_17C_xxx,				"17C/XXX",		172)
	ENUM(atc_rwy_17R_xxx,				"17R/XXX",		173)
	ENUM(atc_rwy_18_xxx,				"18/XXX",		180)
	ENUM(atc_rwy_18L_xxx,				"18L/XXX",		181)
	ENUM(atc_rwy_18C_xxx,				"18C/XXX",		182)
	ENUM(atc_rwy_18R_xxx,				"18R/XXX",		183)
	ENUM(atc_rwy_19_xxx,				"19/XXX",		190)
	ENUM(atc_rwy_19L_xxx,				"19L/XXX",		191)
	ENUM(atc_rwy_19C_xxx,				"19C/XXX",		192)
	ENUM(atc_rwy_19R_xxx,				"19R/XXX",		193)
	ENUM(atc_rwy_20_xxx,				"20/XXX",		200)
	ENUM(atc_rwy_20L_xxx,				"20L/XXX",		201)
	ENUM(atc_rwy_20C_xxx,				"20C/XXX",		202)
	ENUM(atc_rwy_20R_xxx,				"20R/XXX",		203)
	ENUM(atc_rwy_21_xxx,				"21/XXX",		210)
	ENUM(atc_rwy_21L_xxx,				"21L/XXX",		211)
	ENUM(atc_rwy_21C_xxx,				"21C/XXX",		212)
	ENUM(atc_rwy_21R_xxx,				"21R/XXX",		213)
	ENUM(atc_rwy_22_xxx,				"22/XXX",		220)
	ENUM(atc_rwy_22L_xxx,				"22L/XXX",		221)
	ENUM(atc_rwy_22C_xxx,				"22C/XXX",		222)
	ENUM(atc_rwy_22R_xxx,				"22R/XXX",		223)
	ENUM(atc_rwy_23_xxx,				"23/XXX",		230)
	ENUM(atc_rwy_23L_xxx,				"23L/XXX",		231)
	ENUM(atc_rwy_23C_xxx,				"23C/XXX",		232)
	ENUM(atc_rwy_23R_xxx,				"23R/XXX",		233)
	ENUM(atc_rwy_24_xxx,				"24/XXX",		240)
	ENUM(atc_rwy_24L_xxx,				"24L/XXX",		241)
	ENUM(atc_rwy_24C_xxx,				"24C/XXX",		242)
	ENUM(atc_rwy_24R_xxx,				"24R/XXX",		243)
	ENUM(atc_rwy_25_xxx,				"25/XXX",		250)
	ENUM(atc_rwy_25L_xxx,				"25L/XXX",		251)
	ENUM(atc_rwy_25C_xxx,				"25C/XXX",		252)
	ENUM(atc_rwy_25R_xxx,				"25R/XXX",		253)
	ENUM(atc_rwy_26_xxx,				"26/XXX",		260)
	ENUM(atc_rwy_26L_xxx,				"26L/XXX",		261)
	ENUM(atc_rwy_26C_xxx,				"26C/XXX",		262)
	ENUM(atc_rwy_26R_xxx,				"26R/XXX",		263)
	ENUM(atc_rwy_27_xxx,				"27/XXX",		270)
	ENUM(atc_rwy_27L_xxx,				"27L/XXX",		271)
	ENUM(atc_rwy_27C_xxx,				"27C/XXX",		272)
	ENUM(atc_rwy_27R_xxx,				"27R/XXX",		273)
	ENUM(atc_rwy_28_xxx,				"28/XXX",		280)
	ENUM(atc_rwy_28L_xxx,				"28L/XXX",		281)
	ENUM(atc_rwy_28C_xxx,				"28C/XXX",		282)
	ENUM(atc_rwy_28R_xxx,				"28R/XXX",		283)
	ENUM(atc_rwy_29_xxx,				"29/XXX",		290)
	ENUM(atc_rwy_29L_xxx,				"29L/XXX",		291)
	ENUM(atc_rwy_29C_xxx,				"29C/XXX",		292)
	ENUM(atc_rwy_29R_xxx,				"29R/XXX",		293)
	ENUM(atc_rwy_30_xxx,				"30/XXX",		300)
	ENUM(atc_rwy_30L_xxx,				"30L/XXX",		301)
	ENUM(atc_rwy_30C_xxx,				"30C/XXX",		302)
	ENUM(atc_rwy_30R_xxx,				"30R/XXX",		303)
	ENUM(atc_rwy_31_xxx,				"31/XXX",		310)
	ENUM(atc_rwy_31L_xxx,				"31L/XXX",		311)
	ENUM(atc_rwy_31C_xxx,				"31C/XXX",		312)
	ENUM(atc_rwy_31R_xxx,				"31R/XXX",		313)
	ENUM(atc_rwy_32_xxx,				"32/XXX",		320)
	ENUM(atc_rwy_32L_xxx,				"32L/XXX",		321)
	ENUM(atc_rwy_32C_xxx,				"32C/XXX",		322)
	ENUM(atc_rwy_32R_xxx,				"32R/XXX",		323)
	ENUM(atc_rwy_33_xxx,				"33/XXX",		330)
	ENUM(atc_rwy_33L_xxx,				"33L/XXX",		331)
	ENUM(atc_rwy_33C_xxx,				"33C/XXX",		332)
	ENUM(atc_rwy_33R_xxx,				"33R/XXX",		333)
	ENUM(atc_rwy_34_xxx,				"34/XXX",		340)
	ENUM(atc_rwy_34L_xxx,				"34L/XXX",		341)
	ENUM(atc_rwy_34C_xxx,				"34C/XXX",		342)
	ENUM(atc_rwy_34R_xxx,				"34R/XXX",		343)
	ENUM(atc_rwy_35_xxx,				"35/XXX",		350)
	ENUM(atc_rwy_35L_xxx,				"35L/XXX",		351)
	ENUM(atc_rwy_35C_xxx,				"35C/XXX",		352)
	ENUM(atc_rwy_35R_xxx,				"35R/XXX",		353)
	ENUM(atc_rwy_36_xxx,				"36/XXX",		360)
	ENUM(atc_rwy_36L_xxx,				"36L/XXX",		361)
	ENUM(atc_rwy_36C_xxx,				"36C/XXX",		362)
	ENUM(atc_rwy_36R_xxx,				"36R/XXX",		363)

	ENUM(atc_rwy_1_19,					"01/19",		370)
	ENUM(atc_rwy_1L_19R,				"01L/19R",		371)
	ENUM(atc_rwy_1C_19C,				"01C/19C",		372)
	ENUM(atc_rwy_1R_19L,				"01R/19L",		373)
	ENUM(atc_rwy_2_20,					"02/20",		380)
	ENUM(atc_rwy_2L_20R,				"02L/20R",		381)
	ENUM(atc_rwy_2C_20C,				"02C/20C",		382)
	ENUM(atc_rwy_2R_20L,				"02R/20L",		383)
	ENUM(atc_rwy_3_21,					"03/21",		390)
	ENUM(atc_rwy_3L_21R,				"03L/21R",		391)
	ENUM(atc_rwy_3C_21C,				"03C/21C",		392)
	ENUM(atc_rwy_3R_21L,				"03R/21L",		393)
	ENUM(atc_rwy_4_22,					"04/22",		400)
	ENUM(atc_rwy_4L_22R,				"04L/22R",		401)
	ENUM(atc_rwy_4C_22C,				"04C/22C",		402)
	ENUM(atc_rwy_4R_22L,				"04R/22L",		403)
	ENUM(atc_rwy_5_23,					"05/23",		410)
	ENUM(atc_rwy_5L_23R,				"05L/23R",		411)
	ENUM(atc_rwy_5C_23C,				"05C/23C",		412)
	ENUM(atc_rwy_5R_23L,				"05R/23L",		413)
	ENUM(atc_rwy_6_24,					"06/24",		420)
	ENUM(atc_rwy_6L_24R,				"06L/24R",		421)
	ENUM(atc_rwy_6C_24C,				"06C/24C",		422)
	ENUM(atc_rwy_6R_24L,				"06R/24L",		423)
	ENUM(atc_rwy_7_25,					"07/25",		430)
	ENUM(atc_rwy_7L_25R,				"07L/25R",		431)
	ENUM(atc_rwy_7C_25C,				"07C/25C",		432)
	ENUM(atc_rwy_7R_25L,				"07R/25L",		433)
	ENUM(atc_rwy_8_26,					"08/26",		440)
	ENUM(atc_rwy_8L_26R,				"08L/26R",		441)
	ENUM(atc_rwy_8C_26C,				"08C/26C",		442)
	ENUM(atc_rwy_8R_26L,				"08R/26L",		443)
	ENUM(atc_rwy_9_27,					"09/27",		450)
	ENUM(atc_rwy_9L_27R,				"09L/27R",		451)
	ENUM(atc_rwy_9C_27C,				"09C/27C",		452)
	ENUM(atc_rwy_9R_27L,				"09R/27L",		453)
	ENUM(atc_rwy_10_28,					"10/28",		460)
	ENUM(atc_rwy_10L_28R,				"10L/28R",		461)
	ENUM(atc_rwy_10C_28C,				"10C/28C",		462)
	ENUM(atc_rwy_10R_28L,				"10R/28L",		463)
	ENUM(atc_rwy_11_29,					"11/29",		470)
	ENUM(atc_rwy_11L_29R,				"11L/29R",		471)
	ENUM(atc_rwy_11C_29C,				"11C/29C",		472)
	ENUM(atc_rwy_11R_29L,				"11R/29L",		473)
	ENUM(atc_rwy_12_30,					"12/30",		480)
	ENUM(atc_rwy_12L_30R,				"12L/30R",		481)
	ENUM(atc_rwy_12C_30C,				"12C/30C",		482)
	ENUM(atc_rwy_12R_30L,				"12R/30L",		483)
	ENUM(atc_rwy_13_31,					"13/31",		490)
	ENUM(atc_rwy_13L_31R,				"13L/31R",		491)
	ENUM(atc_rwy_13C_31C,				"13C/31C",		492)
	ENUM(atc_rwy_13R_31L,				"13R/31L",		493)
	ENUM(atc_rwy_14_32,					"14/32",		500)
	ENUM(atc_rwy_14L_32R,				"14L/32R",		501)
	ENUM(atc_rwy_14C_32C,				"14C/32C",		502)
	ENUM(atc_rwy_14R_32L,				"14R/32L",		503)
	ENUM(atc_rwy_15_33,					"15/33",		510)
	ENUM(atc_rwy_15L_33R,				"15L/33R",		511)
	ENUM(atc_rwy_15C_33C,				"15C/33C",		512)
	ENUM(atc_rwy_15R_33L,				"15R/33L",		513)
	ENUM(atc_rwy_16_34,					"16/34",		520)
	ENUM(atc_rwy_16L_34R,				"16L/34R",		521)
	ENUM(atc_rwy_16C_34C,				"16C/34C",		522)
	ENUM(atc_rwy_16R_34L,				"16R/34L",		523)
	ENUM(atc_rwy_17_35,					"17/35",		530)
	ENUM(atc_rwy_17L_35R,				"17L/35R",		531)
	ENUM(atc_rwy_17C_35C,				"17C/35C",		532)
	ENUM(atc_rwy_17R_35L,				"17R/35L",		533)
	ENUM(atc_rwy_18_36,					"18/36",		540)
	ENUM(atc_rwy_18L_36R,				"18L/36R",		541)
	ENUM(atc_rwy_18C_36C,				"18C/36C",		542)
	ENUM(atc_rwy_18R_36L,				"18R/36L",		543)

ENUM_DOMAIN(RoadSubType, "Road Type")
	ENUM(road_Highway,				"Highway",									1)
	ENUM(road_Local,				"Local",									2)
