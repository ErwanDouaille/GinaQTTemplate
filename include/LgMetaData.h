#pragma once

/*!
 * \file LgMetaData.h
 * \brief File containing the MetaData class, a Mother class for storing any possible informations.
 * \author Bremard Nicolas
 * \version 0.2
 * \date 02 july 2014
 */

#ifndef LGMETADATA_H_
#define LGMETADATA_H_

#include <map>
#include <set>
#include <string>
#include <typeinfo>
#include <fstream>
#include<sstream>
#include <stdlib.h>

using namespace std;

/*! 
 * \namespace lg
 * \brief Namespace containing everything for managing libGina Environment, Node and Groups.
*/
namespace lg
{
	/*!
	 * \class MetaData
	 * \brief Class for storing any possible informations.
	 * This class is used for adding additional informations in an OrientedPoint
	 * An instance of MetaData contains several instances of several types that are accessible by their associated key.
	*/
	class MetaData
	{
	private:
	
		/*!
		 * \brief Set a specified data with a new boolean value (the data must be boolean when created)
		 * \param[in] key : the key for accessing the wanted data (this must refers to a boolean value)
		 * \param[in] value : the new value for the specified key
		 */
		bool setBool(string key,bool value);

		/*!
		 * \brief Set a specified data with a new int value (the data must be int when created)
		 * \param[in] key : the key for accessing the wanted data (this must refers to a int value)
		 * \param[in] value : the new value for the specified key
		 */
		bool setInt(string key,int value);
		
		/*!
		 * \brief Set a specified data with a new short value (the data must be short when created)
		 * \param[in] key : the key for accessing the wanted data (this must refers to a short value)
		 * \param[in] value : the new value for the specified key
		 */
		bool setShort(string key,short value);
		
		/*!
		 * \brief Set a specified data with a new long value (the data must be long when created)
		 * \param[in] key : the key for accessing the wanted data (this must refers to a long value)
		 * \param[in] value : the new value for the specified key
		 */
		bool setLong(string key,long value);

		/*!
		 * \brief Set a specified data with a new double value (the data must be double when created)
		 * \param[in] key : the key for accessing the wanted data (this must refers to a double value)
		 * \param[in] value : the new value for the specified key
		 */
		bool setDouble(string key,double value);

		/*!
		 * \brief Set a specified data with a new float value (the data must be float when created)
		 * \param[in] key : the key for accessing the wanted data (this must refers to a float value)
		 * \param[in] value : the new value for the specified key
		 */
		bool setFloat(string key,float value);

		/*!
		 * \brief Set a specified data with a new char value (the data must be char when created)
		 * \param[in] key : the key for accessing the wanted data (this must refers to a char value)
		 * \param[in] value : the new value for the specified key
		 */
		bool setChar(string key,char value);

		/*!
		 * \brief Set a specified data with a new string value (the data must be string when created)
		 * \param[in] key : the key for accessing the wanted data (this must refers to a string value)
		 * \param[in] value : the new value for the specified key
		 */
		bool setString(string key,string value);
		
		/*!
		 * \brief Set a specified data with a new pointer value (the data must be of this type when created)
		 * \param[in] key : the key for accessing the wanted data (this must refers to a pointer value)
		 * \param[in] value : the new value for the specified key
		 */
		bool setVoid(string key,void* value);

		//! A map of keys to the type they are associated with
		map<string,int> _types;

		//! Map containing all the boolean values
		map<string,bool> _bools;

		//! Map containing all the int values
		map<string,int> _ints;
		
		//! Map containing all the short values
		map<string,short> _shorts;
		
		//! Map containing all the long values
		map<string,long> _longs;
		
		//! Map containing all the double values
		map<string,double> _doubles;
		
		//! Map containing all the float values
		map<string,float> _floats;
		
		//! Map containing all the char values
		map<string,char> _chars;
		
		//! Map containing all the string values
		map<string,string> _strings;
		
		//! Map containing all the pointer values
		map<string,void*> _voids;

	public:
		/*!
		 * \brief Default constructor
		 */
		MetaData(void);

		/*!
		 * \brief Constructor by copy, copy all the stored data from another MetaData class instance
		 * \param[in] copy : another MetaData from which copy the values
		 */
		MetaData(const MetaData &copy);

		/*!
		 * \brief Destructor
		 */
		~MetaData(void);

		/*!
		 * \brief Create a new boolean MetaData entry 
		 * This creates a new boolean value in the MetaData structure that is accessible with the associated key 
		 * \param[in] key : the key for accessing the data which is being created
		 * \param[in] value : the value for the specified key
		 */
		bool createBool(string key,bool value);

		/*!
		 * \brief Create a new int MetaData entry 
		 * This creates a new int value in the MetaData structure that is accessible with the associated key 
		 * \param[in] key : the key for accessing the data which is being created
		 * \param[in] value : the value for the specified key
		 */
		bool createInt(string key,int value);

		/*!
		 * \brief Create a new short MetaData entry 
		 * This creates a new short value in the MetaData structure that is accessible with the associated key 
		 * \param[in] key : the key for accessing the data which is being created
		 * \param[in] value : the value for the specified key
		 */
		bool createShort(string key,short value);

		/*!
		 * \brief Create a new long MetaData entry 
		 * This creates a new long value in the MetaData structure that is accessible with the associated key 
		 * \param[in] key : the key for accessing the data which is being created
		 * \param[in] value : the value for the specified key
		 */
		bool createLong(string key,long value);

		/*!
		 * \brief Create a new double MetaData entry 
		 * This creates a new double value in the MetaData structure that is accessible with the associated key 
		 * \param[in] key : the key for accessing the data which is being created
		 * \param[in] value : the value for the specified key
		 */
		bool createDouble(string key,double value);

		/*!
		 * \brief Create a new float MetaData entry 
		 * This creates a new float value in the MetaData structure that is accessible with the associated key 
		 * \param[in] key : the key for accessing the data which is being created
		 * \param[in] value : the value for the specified key
		 */
		bool createFloat(string key,float value);

		/*!
		 * \brief Create a new char MetaData entry 
		 * This creates a new char value in the MetaData structure that is accessible with the associated key 
		 * \param[in] key : the key for accessing the data which is being created
		 * \param[in] value : the value for the specified key
		 */
		bool createChar(string key,char value);

		/*!
		 * \brief Create a new string MetaData entry 
		 * This creates a new string value in the MetaData structure that is accessible with the associated key 
		 * \param[in] key : the key for accessing the data which is being created
		 * \param[in] value : the value for the specified key
		 */
		bool createString(string key,string value);

		/*!
		 * \brief Create a new generic pointer MetaData entry 
		 * This creates a new generic pointer value in the MetaData structure that is accessible with the associated key 
		 * \param[in] key : the key for accessing the data which is being created
		 * \param[in] value : the value for the specified key
		 */
		bool createVoid(string key,void* value);

		/*!
		 * \brief Get the boolean value associated with the given key
		 * \param[in] key : the key for accessing the data
		 * \return the boolean value for the specified key if the associated value is boolean, false otherwise (See isBool )
		 */
		bool getBool(string key) const;

		/*!
		 * \brief Get the int value associated with the given key
		 * \param[in] key : the key for accessing the data
		 * \return the int value for the specified key if the associated value is int, 0 otherwise (See isInt )
		 */
		int getInt(string key) const;

		/*!
		 * \brief Get the short value associated with the given key
		 * \param[in] key : the key for accessing the data
		 * \return the short value for the specified key if the associated value is short, 0 otherwise (See isShort )
		 */
		short getShort(string key) const;

		/*!
		 * \brief Get the long value associated with the given key
		 * \param[in] key : the key for accessing the data
		 * \return the long value for the specified key if the associated value is long, 0 otherwise (See isLong )
		 */
		long getLong(string key) const;

		/*!
		 * \brief Get the double value associated with the given key
		 * \param[in] key : the key for accessing the data
		 * \return the double value for the specified key if the associated value is double, 0.0 otherwise (See isDouble )
		 */
		double getDouble(string key) const;

		/*!
		 * \brief Get the boolean value associated with the given key
		 * \param[in] key : the key for accessing the data
		 * \return the boolean value for the specified key if the associated value is boolean, false otherwise (See isFloat )
		 */
		float getFloat(string key) const;

		/*!
		 * \brief Get the char value associated with the given key
		 * \param[in] key : the key for accessing the data
		 * \return the char value for the specified key if the associated value is char, 0 otherwise (See isChar )
		 */
		char getChar(string key) const;

		/*!
		 * \brief Get the string value associated with the given key
		 * \param[in] key : the key for accessing the data
		 * \return the string value for the specified key if the associated value is string, "" otherwise (See isString )
		 */
		string getString(string key) const;

		/*!
		 * \brief Get the generic pointer value associated with the given key
		 * \param[in] key : the key for accessing the data
		 * \return the generic pointer value for the specified key if the associated value is generic pointer, 0 otherwise (See isVoid )
		 */
		void* getVoid(string key) const;

		/*!
		 * \brief Indicates if the value associated with the key is a boolean
		 * \param[in] key : the key for which checking the type
		 * \return true if the associated value is a boolean, false otherwise
		 */
		bool isBool(string key) const;

		/*!
		 * \brief Indicates if the value associated with the key is a boolean
		 * \param[in] key : the key for which checking the type
		 * \return true if the associated value is a boolean, false otherwise
		 */
		bool isInt(string key) const;

		/*!
		 * \brief Indicates if the value associated with the key is a short
		 * \param[in] key : the key for which checking the type
		 * \return true if the associated value is a short, false otherwise
		 */
		bool isShort(string key) const;

		/*!
		 * \brief Indicates if the value associated with the key is a long
		 * \param[in] key : the key for which checking the type
		 * \return true if the associated value is a long, false otherwise
		 */
		bool isLong(string key) const;

		/*!
		 * \brief Indicates if the value associated with the key is a double
		 * \param[in] key : the key for which checking the type
		 * \return true if the associated value is a double, false otherwise
		 */
		bool isDouble(string key) const;

		/*!
		 * \brief Indicates if the value associated with the key is a float
		 * \param[in] key : the key for which checking the type
		 * \return true if the associated value is a float, false otherwise
		 */
		bool isFloat(string key) const;

		/*!
		 * \brief Indicates if the value associated with the key is a char
		 * \param[in] key : the key for which checking the type
		 * \return true if the associated value is a char, false otherwise
		 */
		bool isChar(string key) const;

		/*!
		 * \brief Indicates if the value associated with the key is a string
		 * \param[in] key : the key for which checking the type
		 * \return true if the associated value is a string, false otherwise
		 */
		bool isString(string key) const;

		/*!
		 * \brief Indicates if the value associated with the key is a generic pointer
		 * \param[in] key : the key for which checking the type
		 * \return true if the associated value is a generic pointer, false otherwise
		 */
		bool isVoid(string key) const;

		/*!
		 * \brief Get a text indicating the type of the MetaData value associated to a key
		 * \param[in] key : the key for which checking the type
		 * \return A text indicating the type of the MetaData value associated to the key , 0 if the key is not present
		 */
		const char* getType(string key);

		/*!
		 * \brief Check if a key is associated with a value
		 * \param[in] key : the key for which checking the type
		 * \return true if the key is present and is associated with a value, false otherwise
		 */
		bool isValidKey(string key);

		/*!
		 * \brief Get a set of all keys present and associated with a value (of any type)
		 * \return A set of all keys present and associated with a value (of any type)
		 */
		std::set<string> getKeyList() const;

		/*!
		 * \brief Loadkeys and values from a file
		 * \param[in] path : the path of the file from where loading MetaData values
		 */
		void fromFile(string path);

		/*!
		 * \brief Save keys and values to a file
		 * \param[in] path : the path of the file in which saving MetaData values
		 */
		void toFile(string path);
	};
}

#endif /* LGMETADATA_H_ */