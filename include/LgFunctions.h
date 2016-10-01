#pragma once

/*!
 * \file LgFunctions.h
 * \brief File containing useful functions
 * \author Bremard Nicolas
 * \version 0.2
 * \date 07 march 2015
 */

#ifndef LGFUNCTIONS_H_
#define LGFUNCTIONS_H_

#if defined _WIN32  || defined _WIN64
#include "windows.h"
#else
#if __APPLE__
#else
#endif
#endif

#include <string>
#include <map>
#include <set>

#include "LgData.h"

/*! 
 * \namespace lg
 * \brief Namespace containing everything for managing libGina Environment, Node and Groups.
*/
namespace lg
{

	/*!
	* \brief Update a specific horientedpoint of a specific group with new data (if horientedpoint or group doesn't exist, the function creates them)
	* Function updating data in groups and creating group and horientedpoint if needed
	* \param[in] environment : the parent environment for group and horientedpoint (needed when creation is mandatory)
	* \param[in] groups3D : Set of groups in which the group to update is
	* \param[in] groupName : the name of the group to update
	* \param[in] groupType : the name of the group to update (needed when creation is mandatory)
	* \param[in] horientedPointName : the name of the horientedpoint to update
	* \param[in] horientedPointType : the name of the horientedpoint to update (needed when creation is mandatory)
	* \param[in] timestamp : current timestamp of the data to add
	* \param[in] value : current data to add
	* \return true if success
	*/
	bool updateData(Environment* environment,map<string,Group3D*>& groups3D,string groupName,string groupType,string horientedPointName,string horientedPointType,int timestamp,OrientedPoint3D value);
	bool updateData(Environment* environment,map<string,Group2D*>& groups2D,string groupName,string groupType,string horientedPointName,string horientedPointType,int timestamp,OrientedPoint2D value);
	bool updateData(Environment* environment,map<string,Group1D*>& groups1D,string groupName,string groupType,string horientedPointName,string horientedPointType,int timestamp,OrientedPoint1D value);
	bool updateData(Environment* environment,map<string,GroupSwitch*>& groupsSwitch,string groupName,string groupType,string hSwitchName,string hSwitchType,int timestamp,Switch value);

	/*!
	* \brief Delete a specific horientedpoint in a specific group
	* \param[in] groups3D : Set of groups in which the group which contains the point to delete is
	* \param[in] groupName : the name of the group in which the point to delete is
	* \param[in] orientedPointName : the name of the horientedpoint to delete
	* \return true if success
	*/
	bool deleteHOrientedPoint(map<string,Group3D*>& groups3D,string groupName,string orientedPointName);
	bool deleteHOrientedPoint(map<string,Group2D*>& groups2D,string groupName,string orientedPointName);
	bool deleteHOrientedPoint(map<string,Group1D*>& groups1D,string groupName,string orientedPointName);
	bool deleteHSwitch(map<string,GroupSwitch*>& groupsSwitch,string groupName,string orientedPointName);

	/*!
	* \brief Delete a specific group
	* \param[in] groups3D : Set of groups in which the group to delete is
	* \param[in] groupName : the name of the group to delete
	* \return true if success
	*/
	bool deleteGroup(map<string,Group3D*>& groups3D,string groupName);
	bool deleteGroup(map<string,Group2D*>& groups2D,string groupName);
	bool deleteGroup(map<string,Group1D*>& groups1D,string groupName);
	bool deleteGroup(map<string,GroupSwitch*>& groupsSwitch,string groupName);
}


#endif /* LGFUNCTIONS_H_ */