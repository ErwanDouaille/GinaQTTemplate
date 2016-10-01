#pragma once

/*!
 * \file LgNodeFactory.h
 * \brief File containing the NodeFactory class, factory for getting new instance of Node 
 * \author Bremard Nicolas
 * \version 0.2
 * \date 02 july 2014
 */

#ifndef LGNODEFACTORY_H_
#define LGNODEFACTORY_H_

#include <map>
#include <string>
#include <windows.h>

#include "LgNode.h"

using namespace std;

/*! 
 * \namespace lg
 * \brief Namespace containing everything for managing libGina Environment, Node and Groups.
*/
namespace lg
{
	/*!
	 * \class NodeFactory
	 * \brief Class for managing Node and getting new instance from them by name, used for loading Node from dll/so/dylib file
	*/
	class NodeFactory
	{
	private:

		//! Save the instance of loaded Node
		static map<string,HINSTANCE> _instances;

		//! Registered Node in the NodeFactory
		static map<string,Node*> _nodes;

		//! Counter for giving new name to clones and making them unique
		static int _cloneCounter;

	public:
		/*!
		 * \brief Register a new Node with its pointer
		 * 
		 * Register a new Node for creating instances just by name.
		 * The pointer is used here, it is the normal way to register a class in the NodeFactory when you have its implementation.
		 *
		 * \param[in] genericNodeName : the name of the Node to which refer when calling create
		 * \param[in] node : a pointer to the Node to register
		 */
		static void registerNode(const string& genericNodeName,Node* node);

		/*!
		 * \brief Register a new Node from its file
		 * 
		 * Register a new Node for creating instances just by name.
		 * The file is used here, it is the way to register a class in the NodeFactory when you have its file.
		 * Saving a Node in a file is useful when you don't want to make the code public by example.
		 *
		 * \param[in] genericNodeName : the name of the Node to which refer when calling create
		 * \param[in] filePath : the path of the Node to load
		 */
		static void registerNodeFromFile(const string& genericNodeName,string& filePath);

		/*!
		 * \brief Unregister a Node by its name
		 * 
		 * Unregister a Node from the NodeFactory
		 * If the file has been loaded, it is unloaded.
		 *
		 * \param[in] genericNodeName : the name of the Node to unregister
		 */
		static void unregister(const string& genericNodeName);

		/*!
		 * \brief Get an instance of a Node by calling its name
		 *
		 * \param[in] genericNodeName : the name of the Node from which to get an instance
		 * \return A pointer to a new instance of the wanted Node, the same instance if the Node cannot be cloned
		 */
		Node* create(const string& genericNodeName) const;

	};

	/*!
	* \brief Type for loading a Node from a file (it is the declared extern function)
	*/
	typedef Node* create_t();
}

#endif /* LGNODEFACTORY_H_ */
