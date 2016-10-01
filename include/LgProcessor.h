#pragma once

/*!
 * \file LgProcessor.h
 * \brief File containing the Processor class, the mother class of any Node that need to modify the Groups.
 * \author Bremard Nicolas
 * \version 0.2
 * \date 02 july 2014
 */

#ifndef LGPROCESSOR_H_
#define LGPROCESSOR_H_

/*!
* \brief Type of Node for Processors
*/
#define LG_NODE_PROCESSOR "LG_NODE_PROCESSOR"

#include "LgNode.h"

/*! 
 * \namespace lg
 * \brief Namespace containing everything for managing libGina Environment, Node and Groups.
*/
namespace lg
{
	/*!
	* \brief Mother class of any Node that need to modify the Groups.
	* A Processor is a Node that modify the Groups or that generate data from them.
	* These can be, by example, some kind of filters or pointing (generating 2D data from 3D data).
	*/
	class Processor : public Node {
		protected:
		
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

		public:

			/*!
			 * \brief Constructor for creating a new Processor
			 * Create a new Processor with a name and a type
			 * \param[in] name : a name for the instance of this Node
			 * \param[in] name : the type of this Processor
			 */
			Processor(string name) : Node(name,LG_NODE_PROCESSOR){}
		
			/*!
			 * \brief Constructor by copy
			 * \param[in] copy : another instance of this Node from which copy the details (name, id...)
			 */
			Processor(const Processor &copy) : Node(copy) {}
		
			/*!
			 * \brief Destructor
			 */
			virtual ~Processor(void){}

			/*!
			 * \brief Set a specific group to process
			 * If not used -> Process all (depend on observed type)
			 * \param[in] groupID : the id of the Group which must be processed
			 */
			inline void onlyProcessGroupIDs(string groupID){_observedGroups.insert(groupID);}

			/*!
			 * \brief Set a specific type of group to process
			 * If not used -> Process all (depend on observed ids)
			 * \param[in] typeToProcess : the type of points to process
			 */
			inline void onlyProcessGroupType(string typeToProcess) {_observedGroupType.insert(typeToProcess);} 

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
			 * \brief Check if a specific group must be processed
			 * \return true if this Pocessor must process
			 */
			bool isProcessedGroup(string groupID,string groupType) const{return(((_observedGroups.size() == 0)||(_observedGroups.count(groupID)))&&((_observedGroupType.size() == 0)||(_observedGroupType.count(groupType)))&&((_ignoredGroups.size() == 0)||(_ignoredGroups.count(groupID) == 0))&&((_ignoredGroupType.size() == 0)||(_ignoredGroupType.count(groupType) == 0)));}

			/*!
			 * \brief Set a specific type of point to process
			 * If not used -> Process all (depend on observed groups)
			 * \param[in] typeToProcess : the type of points to process
			 */
			inline void onlyProcessPointType(string typeToProcess) {_observedPointType.insert(typeToProcess);} 

			/*!
			 * \brief Set a specific type of point to ignore
			 * If not used -> Ignore nothing (depend on observed groups)
			 * \param[in] typeToIgnore : the type of points to ignore
			 */
			inline void ignorePointType(string typeToIgnore) {_ignoredPointType.insert(typeToIgnore);} 

			/*!
			 * \brief Check if a specific type must be processed
			 * \param[in] processedType : the type of points to process
			 * \return true if this Pocessor must proces
			 */
			inline bool isProcessedType(string processedType) const {return (((_observedPointType.size() == 0)||(_observedPointType.count(processedType)))&&(_ignoredPointType.count(processedType) == 0));} 

	};
}

#endif /* LGPROCESSOR_H_ */