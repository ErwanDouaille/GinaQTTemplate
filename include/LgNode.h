#pragma once

/*!
 * \file LgNode.h
 * \brief File containing the Node class, the mother class for implementing any Generator, Processor or Observer.
 * \author Bremard Nicolas
 * \version 0.2
 * \date 02 july 2014
 */

#ifndef LGNODE_H_
#define LGNODE_H_

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
#include "LgFunctions.h"
#include "LgEnvironment.h"

using namespace std;

/*! 
 * \namespace lg
 * \brief Namespace containing everything for managing libGina Environment, Node and Groups.
*/
namespace lg
{
	/*!
	 * \class Node
	 * \brief Mother class for Generator , Processor and Observer.
	*/
	class Node
	{
	private:
		//! Node name
		string _name;

		//! Node type (Generator,SimpleProcessor,CompositeProcessor,...)
		string _type;

	protected:
		//! The environment in which this Node is registered, useful for retrieving Environment settings
		Environment* _environment;

		//! Id of this Node, useful for giving unique ids to data
		int _id;

		//! Current time
		int _timestamp;

	public:
		/*!
		 * \brief Constructor for creating a new Node from a name and a type.
		 * The name and type parameters are just informations stored in the Node for differenciating it from other instances and linked them to their data.
		 * \param[in] name : a name for the instance of this Node
		 * \param[in] type : the type of this Observer
		 */
		Node(string name,string type);

		/*!
		 * \brief Constructor by copy
		 * \param[in] copy : another instance of this Node from which copy the details (name, id...)
		 */
		Node(const Node &copy);

		/*!
		 * \brief Destructor
		 */
		~Node(void);


		/*!
		 * \brief Get a pointer to an instance of this Node
		 * 
		 * Virtual function returning a pointer to a Node.
		 * Useful for implementing a NodeFactory.
		 *
		 * \param[in] cloneName : the name of the clone to retrieve
		 *
		 * \return A pointer to an instance of this Node
		 */
		virtual Node* clone(string cloneName) const = 0;

		/*!
		 * \brief Get the Node name
		 * \return The name of the Node
		 */
		inline string getName() const {return _name;}

		/*!
		 * \brief Get the Node type
		 * \return The type of the Node
		 */
		inline string getType() const {return _type;}

		/*!
		 * \brief Set a ID for this Node
		 * The ID is used to identify uniquely data. A Node needs a unique ID for creating new data.
		 * \param[in] newID : the id to associate to the Node
		 */
		inline void setID(int newID){_id = newID;}
		
		/*!
		 * \brief Get the Node ID
		 * The ID is used to identify uniquely data. A Node needs a unique ID for creating new data.
		 * \return The ID of the Node
		 */
		inline int getID() const {return _id;}

		/*!
		 * \brief Set the Environment in which this Node is registered
		 * Useful for getting settings from the Environment
		 * \param[in] environment : the parent Environment
		 */
		inline void setEnvironment(Environment* environment){_environment = environment;}

		/*!
		 * \brief Get the Environment in which this Node is registered
		 * Useful for getting settings from the Environment
		 * \return The parent Environment if the Node is registered in one, NULL otherwise
		 */
		inline Environment* getEnvironment() const {return _environment;}

		/*!
		 * \brief Update the current time (done by the parent Environment during update)
		 * Useful for working with the current time during the update
		 * \param[in] newTimestamp : the current time
		 */
		inline void updateTime(int newTimestamp){_timestamp = newTimestamp;}

		/*!
		 * \brief Get the last time the Node has been updated
		 * \return The last time the Node has been updated
		 */
		inline int getTime() const {return _timestamp;}

		/*!
		 * \brief Start the Node by initializing what is needed
		 * Virtual function that must be implemented by any Node. Every required initialization must be done here.
		 * \return true if success
		 */
		virtual bool start() = 0;

		/*!
		 * \brief Stop the Node by closing what is needed
		 * Virtual function that must be implemented by any Node. Every required destruction must be done here.
		 * \return true if success
		 */
		virtual bool stop() = 0;

		/*!
		 * \brief Update the Node with current data
		 * Virtual function that must be implemented by any Node. It is the main function of the Node.
		 * \param[in] groups3D : Groups of HOrientedPoint3D
		 * \param[in] groups2D : Groups of HOrientedPoint2D
		 * \param[in] groups1D : Groups of HOrientedPoint1D
		 * \param[in] groupsSwitch : Groups of HSwitch
		 * \return true if success
		 */
		virtual bool update(map<string,Group3D*>& groups3D, map<string,Group2D*>& groups2D, map<string,Group1D*>& groups1D, map<string,GroupSwitch*>& groupsSwitch) = 0;

		/*!
		 * \brief Return a set of string describing what kind of type this Node consumes (need in input then destroy).
		 * This function is used by the Environment to check if the registered Node are compatible (ie Node require data types which is present).
		 * \return A set of type
		 */
		virtual set<string> consume() const = 0;

		/*!
		 * \brief Return a set of string describing what kind of type this Node needs in input.
		 * This function is used by the Environment to check if the registered Node are compatible (ie Node require data types which is present).
		 * \return A set of type
		 */
		virtual set<string> need() const = 0;

		/*!
		 * \brief Return a set of string describing what kind of type this Node produces (adds to output).
		 * This function is used by the Environment to check if the registered Node are compatible (ie Node require data types which is present).
		 * \return A set of type
		 */
		virtual set<string> produce() const = 0;


	};
}

#endif /* LGNODE_H_ */
