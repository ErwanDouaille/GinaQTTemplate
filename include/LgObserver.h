#pragma once

/*!
 * \file LgObserver.h
 * \brief File containing the Observer class, the mother class for recognizing gestures.
 * \author Bremard Nicolas
 * \version 0.2
 * \date 02 july 2014
 */

#ifndef LGOBSERVER_H_
#define LGOBSERVER_H_

/*!
* \brief Type of Node for Observers
*/
#define LG_NODE_OBSERVER "LG_NODE_OBSERVER"

#include <string>
#include <map>
#include <set>

#include "LgNode.h"
#include "LgData.h"

using namespace std;
/*! 
 * \namespace lg
 * \brief Namespace containing everything for managing libGina Environment, Node and Groups.
*/
namespace lg
{	
	/*!
	 * \class Observer
	 * \brief Mother class for recognizing gestures.
	 * An Observer is a Node which recognizes a specific gesture and computes a probability indicating if it has been detected.
	*/
	class Observer : public Node
	{
	private:
		// Each Group is associated with a probability that the associated gesture has been recognized
		map<string, float> _probabilities;

	protected:
		// A gesture can have parameters (such as speed,...) that can be retrieved from the Observer
		map<string, void*> _parameters;

		// Variable for resraining groups to observe (if empty,unused -> observe all)
		set<string> _observedGroups;

		// Variable for resraining types of groups to observe (if empty,unused -> observe all)
		set<string> _observedGroupType;

		// Variable for resraining types of points to observe (if empty,unused -> observe all)
		set<string> _observedPointType;

		// Variable for ignoring groups (if empty,unused -> observe all)
		set<string> _ignoredGroups;

		// Variable for ignoring types of groups  (if empty,unused -> observe all)
		set<string> _ignoredGroupType;

		// Variable for ignoring types of points (if empty,unused -> observe all)
		set<string> _ignoredPointType;
		

		// Update the probability of the given group with the given value
		void updateProbability(string groupID,float newValue);

	public:
		/*!
		 * \brief Constructor for creating a new Generator
		 * Create a new Generator with a name and a type (children of Observer are mother classes for simple or complex gestures)
		 * \param[in] name : a name for the instance of this Node
		 * \param[in] type : the type of this Observer
		 */
		Observer(string name);

		/*!
		 * \brief Constructor by copy
		 * \param[in] copy : another instance of this Node from which copy the details (name, id...)
		 */
		Observer(const Observer &copy);

		/*!
		 * \brief Destructor
		 */
		virtual ~Observer(void);

		/*!
		 * \brief Update the Observer with current data 
		 * Function calling the virtual observe function and implementing the Data Copy option
		 * For avoiding side effect, Groups can be copied before being observed.
		 * The Observer is recognizing gestures from copies of Groups, but if it modifies them,by error, no problems occurs.
		 * \param[in] groups3D : Groups of HOrientedPoint3D
		 * \param[in] groups2D : Groups of HOrientedPoint2D
		 * \param[in] groups1D : Groups of HOrientedPoint1D
		 * \param[in] groupsSwitch : Groups of HSwitch
		 * \return true if success
		 */
		bool update(map<string,Group3D*>& groups3D, map<string,Group2D*>& groups2D, map<string,Group1D*>& groups1D, map<string,GroupSwitch*>& groupsSwitch);

		/*!
		 * \brief Observe specific gesture 
		 * Virtual function that must be implemented by any Observer. It is the main function of the Observer, where the gesture is actually recognized.
		 * \param[in] groups3D : Groups of HOrientedPoint3D
		 * \param[in] groups2D : Groups of HOrientedPoint2D
		 * \param[in] groups1D : Groups of HOrientedPoint1D
		 * \param[in] groupsSwitch : Groups of HSwitch
		 * \return true if success
		 */
		virtual bool observe(map<string,Group3D*> groups3D,map<string,Group2D*> groups2D, map<string,Group1D*> groups1D, map<string,GroupSwitch*> groupsSwitch) = 0;

		/*!
		 * \brief Return an empty set of string because an Observer doesn't have any data to consume, it only observes
		 * This function is used by the Environment to check if the registered Node are compatible (ie Node require data types which is present).
		 * \return An empty set
		 */
		set<string> consume() const {return set<string>();} 

		/*!
		 * \brief Return an empty set of string because an Observer doesn't have any Groups in output, it produces event data (probabilities)
		 * This function is used by the Environment to check if the registered Node are compatible (ie Node require data types which is present).
		 * \return An empty set
		 */
		set<string> produce() const {return set<string>();} 

		/*!
		 * \brief Get all the probabilities specific to the gesture, arranged by Groups ID
		 * Return for each Group, the probability that the Group is doing the gesture
		 * \return Map of Groups ID and the probability of the gesture for this Group
		 */
		inline map<string, float> getProbabilities() const {return _probabilities;}
		
		/*!
		 * \brief Get the probability that the gesture is doing by the given Group (specified by its ID)
		 * \param[in] groupID : the id of the Group for which the probability must be returned
		 * \return The probability that the Group is doing the gesture if the Group exists, 0 otherwise
		 */
		inline float getProbability(string groupID){return _probabilities[groupID];}

		/*!
		 * \brief Get all the parameters specific to the gesture, arranged by Groups ID
		 * Return for each Group, the parameters of the gesture done by the Group
		 * \return Map of Groups ID and the parameters of the gesture for this Group
		 */
		inline map<string,void*> getParameters() const {return _parameters;}
		
		/*!
		 * \brief Get the parameters of the gesture done by a given Group (specified by its ID)
		 * \param[in] groupID : the id of the Group for which the parameters must be returned
		 * \return The parameters of the gesture done by the Group if the Group exists, NULL otherwise
		 */
		inline void* getParameter(string groupID){return _parameters[groupID];}

		/*!
		 * \brief Set a specific group to observe
		 * If not used -> Observe all (depend on observed type)
		 * \param[in] groupID : the id of the Group which must be observed
		 */
		inline void onlyObserveGroupIDs(string groupID){_observedGroups.insert(groupID);}

		/*!
		 * \brief Set a specific type of group to observe
		 * If not used -> Observe all (depend on observed ids)
		 * \param[in] typeToObserve : the type of points to observe
		 */
		inline void onlyObserveGroupType(string typeToObserve) {_observedGroupType.insert(typeToObserve);} 

		/*!
		 * \brief Set a specific group to ignore
		 * If not used -> Ignore nothing (depend on observed type)
		 * \param[in] groupID : the id of the Group which must be ignored
		 */
		inline void ignoreGroupIDs(string groupID){_ignoredGroups.insert(groupID);}

		/*!
		 * \brief Set a specific type of group to ignore
		 * If not used -> Ignore all (depend on observed ids)
		 * \param[in] typeToIgnore : the type of points to ignore
		 */
		inline void ignoreGroupType(string typeToIgnore) {_ignoredGroupType.insert(typeToIgnore);} 

		/*!
		 * \brief Check if a specific group must be observed
		 * \return true if this Observer must observe
		 */
		bool isObservedGroup(string groupID,string groupType) const;

		/*!
		 * \brief Set a specific type of point to observe
		 * If not used -> Observe all (depend on observed groups)
		 * \param[in] typeToObserve : the type of points to observe
		 */
		inline void onlyObservePointType(string typeToObserve) {_observedPointType.insert(typeToObserve);} 

		/*!
		 * \brief Set a specific type of point to ignore
		 * If not used -> Ignore nothing (depend on observed groups)
		 * \param[in] typeToIgnore : the type of points to ignore
		 */
		inline void ignorePointType(string typeToIgnore) {_ignoredPointType.insert(typeToIgnore);} 

		/*!
		 * \brief Check if a specific type must be observed
		 * \return true if this Observer must observe
		 */
		inline bool isObservedType(string observedType) const {return (((_observedPointType.size() == 0)||(_observedPointType.count(observedType)))&&(_ignoredPointType.count(observedType) == 0));} 

	};
}
#endif /* LGOBSERVER_H_ */