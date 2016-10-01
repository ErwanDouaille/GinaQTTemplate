#pragma once

/*!
 * \file LgData.h
 * \brief File containing Data definitions : OrientedPoint3D, HOrientedPoint3D, Group3D, OrientedPoint2D, HOrientedPoint2D, Group2D, OrientedPoint1D, HOrientedPoint1D, Group1D and types
 * \author Bremard Nicolas
 * \version 0.2
 * \date 02 july 2014
 */

#ifndef LGDATA_H_
#define LGDATA_H_

// Some types for oriented point 3D

#define LG_ORIENTEDPOINT3D_INVALID "LG_ORIENTEDPOINT3D_INVALID"
#define LG_ORIENTEDPOINT3D_UNDEFINED "LG_ORIENTEDPOINT3D_UNDEFINED"
#define LG_ORIENTEDPOINT3D_TOOL "LG_ORIENTEDPOINT3D_TOOL"
#define LG_ORIENTEDPOINT3D_HEAD "LG_ORIENTEDPOINT3D_HEAD"
#define LG_ORIENTEDPOINT3D_NECK "LG_ORIENTEDPOINT3D_NECK"
#define LG_ORIENTEDPOINT3D_TORSO "LG_ORIENTEDPOINT3D_TORSO"
#define LG_ORIENTEDPOINT3D_STOMACH "LG_ORIENTEDPOINT3D_STOMACH"
#define LG_ORIENTEDPOINT3D_RIGHT_SHOULDER "LG_ORIENTEDPOINT3D_RIGHT_SHOULDER"
#define LG_ORIENTEDPOINT3D_RIGHT_ELBOW "LG_ORIENTEDPOINT3D_RIGHT_ELBOW"
#define LG_ORIENTEDPOINT3D_RIGHT_WRIST "LG_ORIENTEDPOINT3D_RIGHT_WRIST"
#define LG_ORIENTEDPOINT3D_RIGHT_HAND "LG_ORIENTEDPOINT3D_RIGHT_HAND"
#define LG_ORIENTEDPOINT3D_RIGHT_THUMB "LG_ORIENTEDPOINT3D_RIGHT_THUMB"
#define LG_ORIENTEDPOINT3D_RIGHT_INDEX "LG_ORIENTEDPOINT3D_RIGHT_INDEX"
#define LG_ORIENTEDPOINT3D_RIGHT_MIDDLE "LG_ORIENTEDPOINT3D_RIGHT_MIDDLE"
#define LG_ORIENTEDPOINT3D_RIGHT_RING "LG_ORIENTEDPOINT3D_RIGHT_RING"
#define LG_ORIENTEDPOINT3D_RIGHT_PINKY "LG_ORIENTEDPOINT3D_RIGHT_PINKY"
#define LG_ORIENTEDPOINT3D_LEFT_SHOULDER "LG_ORIENTEDPOINT3D_LEFT_SHOULDER"
#define LG_ORIENTEDPOINT3D_LEFT_ELBOW "LG_ORIENTEDPOINT3D_LEFT_ELBOW"
#define LG_ORIENTEDPOINT3D_LEFT_WRIST "LG_ORIENTEDPOINT3D_LEFT_WRIST"
#define LG_ORIENTEDPOINT3D_LEFT_HAND "LG_ORIENTEDPOINT3D_LEFT_HAND"
#define LG_ORIENTEDPOINT3D_LEFT_THUMB "LG_ORIENTEDPOINT3D_LEFT_THUMB"
#define LG_ORIENTEDPOINT3D_LEFT_INDEX "LG_ORIENTEDPOINT3D_LEFT_INDEX"
#define LG_ORIENTEDPOINT3D_LEFT_MIDDLE "LG_ORIENTEDPOINT3D_LEFT_MIDDLE"
#define LG_ORIENTEDPOINT3D_LEFT_RING "LG_ORIENTEDPOINT3D_LEFT_RING"
#define LG_ORIENTEDPOINT3D_LEFT_PINKY "LG_ORIENTEDPOINT3D_LEFT_PINKY"
#define LG_ORIENTEDPOINT3D_RIGHT_HIP "LG_ORIENTEDPOINT3D_RIGHT_HIP"
#define LG_ORIENTEDPOINT3D_RIGHT_KNEE "LG_ORIENTEDPOINT3D_RIGHT_KNEE"
#define LG_ORIENTEDPOINT3D_RIGHT_ANKLE "LG_ORIENTEDPOINT3D_RIGHT_ANKLE"
#define LG_ORIENTEDPOINT3D_RIGHT_FOOT "LG_ORIENTEDPOINT3D_RIGHT_FOOT"
#define LG_ORIENTEDPOINT3D_LEFT_HIP "LG_ORIENTEDPOINT3D_LEFT_HIP"
#define LG_ORIENTEDPOINT3D_LEFT_KNEE "LG_ORIENTEDPOINT3D_LEFT_KNEE"
#define LG_ORIENTEDPOINT3D_LEFT_ANKLE "LG_ORIENTEDPOINT3D_LEFT_ANKLE"
#define LG_ORIENTEDPOINT3D_LEFT_FOOT "LG_ORIENTEDPOINT3D_LEFT_FOOT"

#define LG_GROUP_3D "LG_GROUP_3D"

// Some types for oriented point 2D

#define LG_ORIENTEDPOINT2D_INVALID "LG_ORIENTEDPOINT2D_INVALID"
#define LG_ORIENTEDPOINT2D_UNDEFINED "LG_ORIENTEDPOINT2D_UNDEFINED"
#define LG_ORIENTEDPOINT2D_MOUSE "LG_ORIENTEDPOINT2D_MOUSE"
#define LG_ORIENTEDPOINT2D_PEN "LG_ORIENTEDPOINT2D_PEN"
#define LG_ORIENTEDPOINT2D_TOOL "LG_ORIENTEDPOINT2D_TOOL"
#define LG_ORIENTEDPOINT2D_RIGHTHAND "LG_ORIENTEDPOINT2D_RIGHTHAND"
#define LG_ORIENTEDPOINT2D_RIGHTHAND_THUMB "LG_ORIENTEDPOINT2D_RIGHTHAND_THUMB"
#define LG_ORIENTEDPOINT2D_RIGHTHAND_INDEX "LG_ORIENTEDPOINT2D_RIGHTHAND_INDEX"
#define LG_ORIENTEDPOINT2D_RIGHTHAND_MIDDLE "LG_ORIENTEDPOINT2D_RIGHTHAND_MIDDLE"
#define LG_ORIENTEDPOINT2D_RIGHTHAND_RING "LG_ORIENTEDPOINT2D_RIGHTHAND_RING"
#define LG_ORIENTEDPOINT2D_RIGHTHAND_PINKY "LG_ORIENTEDPOINT2D_RIGHTHAND_PINKY"
#define LG_ORIENTEDPOINT2D_LEFTHAND "LG_ORIENTEDPOINT2D_LEFTHAND"
#define LG_ORIENTEDPOINT2D_LEFTHAND_THUMB "LG_ORIENTEDPOINT2D_LEFTHAND_THUMB"
#define LG_ORIENTEDPOINT2D_LEFTHAND_INDEX "LG_ORIENTEDPOINT2D_LEFTHAND_INDEX"
#define LG_ORIENTEDPOINT2D_LEFTHAND_MIDDLE "LG_ORIENTEDPOINT2D_LEFTHAND_MIDDLE"
#define LG_ORIENTEDPOINT2D_LEFTHAND_RING "LG_ORIENTEDPOINT2D_LEFTHAND_RING"
#define LG_ORIENTEDPOINT2D_LEFTHAND_PINKY "LG_ORIENTEDPOINT2D_LEFTHAND_PINKY"
#define LG_ORIENTEDPOINT2D_TOUCH "LG_ORIENTEDPOINT2D_TOUCH"

#define LG_GROUP_2D "LG_GROUP_2D"

// Some types for oriented point 1D

#define LG_ORIENTEDPOINT1D_INVALID "LG_ORIENTEDPOINT1D_INVALID"
#define LG_ORIENTEDPOINT1D_UNDEFINED "LG_ORIENTEDPOINT1D_UNDEFINED"
#define LG_ORIENTEDPOINT1D_STANDARD "LG_ORIENTEDPOINT1D_STANDARD"

#define LG_GROUP_1D "LG_GROUP_1D"

// Some types for switch

#define LG_SWITCH_MOUSE_CLICK "LG_SWITCH_MOUSE_CLICK"
#define LG_SWITCH_MOUSE_RIGHT_CLICK "LG_SWITCH_MOUSE_RIGHT_CLICK"
#define LG_SWITCH_MOUSE_MIDDLE_CLICK "LG_SWITCH_MOUSE_MIDDLE_CLICK"
#define LG_SWITCH_MOUSE_LEFT_CLICK "LG_SWITCH_MOUSE_LEFT_CLICK"
#define LG_SWITCH_MOUSE_DOUBLE_CLICK "LG_SWITCH_MOUSE_DOUBLE_CLICK"
#define LG_SWITCH_KEY_ENTER "LG_SWITCH_KEY_ENTER"
#define LG_SWITCH_KEY_SPACE "LG_SWITCH_KEY_SPACE"
#define LG_SWITCH_KEY_UP "LG_SWITCH_KEY_UP"
#define LG_SWITCH_KEY_DOWN "LG_SWITCH_KEY_DOWN"
#define LG_SWITCH_KEY_LEFT "LG_SWITCH_KEY_LEFT"
#define LG_SWITCH_KEY_RIGHT "LG_SWITCH_KEY_RIGHT"

#define LG_GROUP_SWITCH "LG_GROUP_SWITCH"

#include "LgDataTemplate.h"
#include "LgHistoricTemplate.h"
#include "LgGroupTemplate.h"
#include "LgPoint2D.h"
#include "LgPoint3D.h"
#include "LgSwitch.h"

/*! 
 * \namespace lg
 * \brief Namespace containing everything for managing libGina Environment, Node and Groups.
*/
namespace lg
{
	/*!
	 * \brief Represents the Data (from DataTemplate) in 3D 
	 * in 3D, positions are Point3d and orientations are Orientation3D
	*/
	typedef DataTemplate<Point3D,Point3D> OrientedPoint3D;

	/*!
	 * \brief Represents an historic (from HistoricTemplate) in 3D 
	 * in 3D, its an historic of OrientedPoint3D
	*/
	typedef HistoricTemplate<OrientedPoint3D> HOrientedPoint3D;

	/*!
	 * \brief Represents a group (from GroupTemplate) in 3D 
	 * in 3D, groups are composed of HOrientedPoint3D
	*/
	typedef GroupTemplate<HOrientedPoint3D> Group3D;

	/*!
	 * \brief Represents the Data (from DataTemplate) in 2D 
	 * in 2D, positions are Point2d and orientations are float
	*/
	typedef DataTemplate<Point2D,float> OrientedPoint2D;

	/*!
	 * \brief Represents an historic (from HistoricTemplate) in 2D 
	 * in 2D, its an historic of OrientedPoint2D
	*/
	typedef HistoricTemplate<OrientedPoint2D> HOrientedPoint2D;

	/*!
	 * \brief Represents a group (from GroupTemplate) in 2D 
	 * in 2D, groups are composed of HOrientedPoint2D
	*/
	typedef GroupTemplate<HOrientedPoint2D> Group2D;

	/*!
	 * \brief Represents the Data (from DataTemplate) in 1D 
	 * in 1D, positions are float and orientations are bool
	*/
	typedef DataTemplate<float,bool> OrientedPoint1D;

	/*!
	 * \brief Represents an historic (from HistoricTemplate) in 1D 
	 * in 1D, its an historic of OrientedPoint1D
	*/
	typedef HistoricTemplate<OrientedPoint1D> HOrientedPoint1D;

	/*!
	 * \brief Represents a group (from GroupTemplate) in 1D 
	 * in 1D, groups are composed of HOrientedPoint1D
	*/
	typedef GroupTemplate<HOrientedPoint1D> Group1D;


	////////////////

	/*!
	 * \brief Represents an historic (from HistoricTemplate) of Switch
	*/
	typedef HistoricTemplate<Switch> HSwitch;

	/*!
	 * \brief Represents a group (from GroupTemplate) of HSwitch
	*/
	typedef GroupTemplate<HSwitch> GroupSwitch;
}



#endif /* LGDATA_H_ */