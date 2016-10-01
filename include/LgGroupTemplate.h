#pragma once

/*!
 * \file LgGroupTemplate.h
 * \brief File containing the template class for creating an group of HistoricTemplate
 * \author Bremard Nicolas
 * \version 0.2
 * \date 02 july 2014
 */

#ifndef LGGROUPTEMPLATE_H_
#define LGGROUPTEMPLATE_H_

#include <map>
#include <set>
#include <string>

using namespace std;

/*! 
 * \namespace lg
 * \brief Namespace containing everything for managing libGina Environment, Node and Groups.
*/
namespace lg
{
	class Environment;

	/*!
	 * \brief Template class for creating a Group of HistoricTemplate
	 * A Group has a unique id, a type, a parent Environment and a set of HistoricTemplate
	*/
	template <typename H> class GroupTemplate
	{
	protected:
		//! Unique id
		string _id;

		//! Type
		string _type;

		//! Parent Environment
		Environment* _environment;

		//! Map of HistoricTemplate by their unique ids
		map<string,H*> _group;
	public:
		/*!
		 * \brief Default constructor
		 * An GroupTemplate must have some attributes, it cannot be created without parameters.
		 * \param[in] parent : the parent Environment
		 * \param[in] id : a unique id
		 * \param[in] type : a type
		 */
		GroupTemplate(Environment* parent, string id, string type) : _environment(parent),_id(id),_type(type){}

		/*!
		 * \brief Constructor by copy, copy all the stored data from another GroupTemplate<H> class instance
		 * \param[in] copy : another GroupTemplate<H> from which copy the values
		 */
		//GroupTemplate(const GroupTemplate<typename H> &copy)
		GroupTemplate(const GroupTemplate &copy)
		{
			_environment = copy.getEnvironment();
			_id = copy.getID();
			_type = copy.getType();

			map<string,H*> copyGroup = copy.getAll();

			for(typename map<string,H*>::iterator it = _group.begin();it != _group.end();it++)
				delete it->second;
			_group.clear();
	
			for(typename map<string,H*>::iterator it = copyGroup.begin();it != copyGroup.end();it++)
				_group[it->first] = new H(*it->second);
		}

		/*!
		 * \brief Destructor
		 */
		virtual ~GroupTemplate(void)
		{
			for(typename map<string,H*>::iterator it = _group.begin();it != _group.end();it++) delete it->second;
			_group.clear();
		}

		/*!
		 * \brief Get the unique id associated with this group
		 * \return The unique id associated with this group
		 */
		inline string getID() const {return _id;}
		
		/*!
		 * \brief Get the type of this group
		 * \return The type of this group
		 */
		inline string getType() const {return _type;}
		
		/*!
		 * \brief Get the parent Environment
		 * \return The parent Environment
		 */
		inline Environment* getEnvironment() const {return _environment;}

		/*!
		 * \brief Add an element to this group by spefiying its id
		 * \param[in] elementID : id of the element to add
		 * \param[in] element : element to add
		 */
		void addElement(string elementID,H* element){_group[elementID] = element;}

		/*!
		 * \brief Add an element to this group
		 * \param[in] element : element to add
		 */
		void addElement(H* element){
			HistoricTemplate<int>* ho = (HistoricTemplate<int>*)(element); 
			_group[ho->getID()] = element;
		}
		
		/*!
		 * \brief Remove an element of this group from its id
		 * \param[in] elementID : id of the element to remove
		 * \return true if the elemnt was present and has been removed, false otherwise
		 */
		bool removeElementByID(string elementID)
		{
			// Find if a vector has this ID and delete it if found
			typename map<string,H*>::iterator dit = _group.find(elementID);
			if(dit != _group.end()){
				delete dit->second;
				_group.erase(dit);
				return true;
			}
			return false;
		}
	
		/*!
		 * \brief Get the element of this group with its id
		 * \param[in] elementID : id of the element to get
		 * \return A pointer to the element with the wanted id if present in the group, NULL otherwise
		 */
		H* getElementByID(string elementID)
		{
			// Find if a vector has this ID and return it, or return 0
			typename map<string,H*>::iterator dit = _group.find(elementID);
			if(dit != _group.end())
				return dit->second;
			else 
				return 0;
		}

		/*!
		 * \brief Get all the elements of this group which are of a given type
		 * \param[in] elementType : type of the elements to get
		 * \return A set of elements of the wanted type from the group (can be empty)
		 */
		set<H*> getElementsByType(string elementType)
		{
			// Add all vector of this type in a set, return set
			set<H*> onlyT;
			for(typename map<string,H*>::iterator mit = _group.begin();mit != _group.end();mit++){
				//LgHistoricTemplate* v = (LgHistoricTemplate*)mit->second; // Even if it is a LgHVector or a LgOrientedPoint, we just need to use getType

				HistoricTemplate<int>* v = (HistoricTemplate<int>*)(mit->second); 

				//LgSlicer* v = (LgHSlicer*)mit->second; // Even if it is a LgHVector or a LgOrientedPoint, we just need to use getType
				if(elementType.compare(v->getType()) == 0)
					onlyT.insert(mit->second);
			}
			return onlyT;
		}

		/*!
		 * \brief Get all the elements of this group
		 * \return Map of the elements of the group (elements id as keys)
		 */
		inline const map<string,H*>& getAll() const {return _group;}

		/*!
		 * \brief Indicates if the group has no elements
		 * \return true if the group is empty, false otherwise
		 */
		bool isEmpty() const {return (_group.size() == 0);}

	};
}

#endif /* LGGROUPTEMPLATE_H_ */