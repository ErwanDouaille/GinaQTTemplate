#pragma once

/*!
 * \file LgHistoricTemplate.h
 * \brief File containing the template class for creating an historic of a DataTemplate
 * \author Bremard Nicolas
 * \version 0.2
 * \date 02 july 2014
 */

#ifndef LGHISTORICTEMPLATE_H_
#define LGHISTORICTEMPLATE_H_

#include <map>

using namespace std;

/*!
 * \namespace lg
 * \brief Namespace containing everything for managing libGina Environment, Node and Groups.
*/
namespace lg
{
// Forward definition of Environment and a global (Environment friendly) function for accessing historic length
class Environment;

extern int getHistoricLengthOfEnvironment(Environment* e);

/*!
     * \brief Template class for creating an historic of a given type.
     * An historic is a class with an id, a type, a parent Environment and a succession of value of the given type.
    */
template <typename T> class HistoricTemplate
{
protected:
    //! A unique id
    string _id;

    //! Type of the historic
    string _type;

    //! Parent
    Environment* _environment;

    //! Succession of values
    map<int,T> _historic;

public:
    /*!
         * \brief Default constructor
         * An HistoricTemplate must have some attributes, it cannot be created without parameters.
         * \param[in] parent : the parent Environment
         * \param[in] id : a unique id
         * \param[in] type : a type
         */
    HistoricTemplate(Environment* parent, string id, string type) : _environment(parent),_id(id),_type(type){}

    /*!
         * \brief Constructor by copy, copy all the stored data from another HistoricTemplate<T> class instance
         * \param[in] copy : another HistoricTemplate<T> from which copy the values
         */
    //HistoricTemplate(const HistoricTemplate<T> &copy){
    HistoricTemplate(const HistoricTemplate &copy){
        _environment = copy.getEnvironment();
        _id = copy.getID();
        _type = copy.getType();

        map<int,T> copyHist = copy.getHistoric();

        _historic.clear();
        for(typename map<int,T>::iterator it = copyHist.begin();it != copyHist.end();it++)
            _historic[it->first] = T(it->second);
    }

    /*!
         * \brief Destructor
         */
    ~HistoricTemplate(void){}

    /*!
         * \brief Get the unique id associated with this historic
         * \return The unique id associated with this historic
         */
    inline string getID() const {return _id;}

    /*!
         * \brief Get the type of this historic
         * \return The type of this historic
         */
    inline string getType() const {return _type;}

    /*!
         * \brief Get the parent Environment
         * \return The parent Environment
         */
    inline Environment* getEnvironment() const {return _environment;}

    /*!
         * \brief Add a value to the historic with its timestamp
         * The historic records values and their timestamps
         * \param[in] timestamp : the timestamp of the value to add
         * \param[in] newValue : new value to add
         */

    void updateHistoric(int timestamp,T newValue){
        _historic[timestamp] = newValue;

        if(_environment == 0) return;
        if((int)_historic.size() > getHistoricLengthOfEnvironment(_environment)){
            //if((int)_historic.size() > _environment->getHistoricLength()){
            _historic.erase(_historic.begin());
        }
    }

    /*!
         * \brief Get all the historic
         * \return Map of the historic (timestamps as keys)
         */
    inline const map<int,T>& getHistoric() const {return _historic;}

    /*!
         * \brief Get the last timestamp that has been added to the historic
         * \return The last timestamp that has been added to the historic, 0 if the histric is empty
         */
    int getLastTimestamp() {
        if(_historic.size() > 0)
            return _historic.rbegin()->first;
        else
            return 0;
    }

    /*!
         * \brief Get the last value that has been added to the historic
         * \return The last value that has been added to the historic, NULL if the histric is empty
         */
    T* getLast() {
        if(_historic.size() > 0)
            return &(_historic.rbegin()->second);
        else
            return 0;
    }

    /*!
         * \brief Indicates if the historic has no values
         * \return true if the historic is empty, false otherwise
         */
    bool isEmpty() const {return (_historic.size() == 0);}

    /*!
         * \brief Indicates if the historic is valid
         * \return true if the historic is valid, false otherwise
         */
    bool isValid() const {return ((!_type.empty())&&(_type.find("INVALID") == string::npos));}

};
}

#endif /* LGHISTORICTEMPLATE_H_ */
