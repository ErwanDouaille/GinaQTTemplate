

/*! \mainpage libGina Documentation
 *
 * \section intro_sec Introduction
 *
 * libGina is a library designed for easing interaction prototyping.
 *
 * libGina contains and manages groups of 3D, 2D, and 1D data. Those data are used by Node.
 *
 * A Node can be a Generator , a Processor or an Observer .
 *
 * \subsection Generator
 *
 * A Generator is a Node specifically created for injecting data from outside the library in the groups.
 *
 * \subsection Processor
 *
 * A Processor modifies the groups by using all data inside the library.
 * It can be used, by example, for filterring the data.
 *
 * Processors are divided in 2 sub-categories : SimpleProcessor and CompositeProcessor .
 *
 * \subsubsection SimpleProcessor
 *
 * A SimpleProcessor is a Processor which doesn't need other Node to work. (A filter by example)
 *
 * \subsubsection CompositeProcessor
 *
 * A CompositeProcessor is a Processor which needs other Node to work. (Keeping groups which satisfy an Observer by example)
 *
 * \subsection Observer
 *
 * An Observer is a Node which doesn't modify the groups. They only watch them for detecting gestures and creating event data which indicates the probability of the wanted gesture.
 *
 * Observers are divided in 2 sub-categories : SimpleObserver and CompositeObserver .
 *
 * \subsubsection SimpleObserver
 *
 * A SimpleObserver is an Observer which doesn't need other Observer to work.
 * It is used for recognizing basic gestures : directions, speeds, ...
 *
 * \subsubsection CompositeObserver
 *
 * A CompositeObserver is an Observer designed for recognizing complex gestures by a combination of SimpleObserver.
 * The combination can be done for gestures done at the same time or one after the other.
 *
 * \section install_sec Installation
 *
 * Use libGina.lib with the given headers.
 *
 *
 *
 */


/*!
 * \file LgEnvironment.h
 * \brief File containing the Environment class, the main class for libGina.
 * \author Bremard Nicolas
 * \version 0.2
 * \date 02 july 2014
 */

#ifndef LGENVIRONMENT_H_
#define LGENVIRONMENT_H_


/*!
 * \def LG_ENV_HISTORIC_LENGTH_LONG
 * \brief Value for setting a long historic (ie storing a lot (30) of successive values for data). To use as parameter in the setHistoricLength function.
 * Each HOrientedPoint can store several successive values of OrientedPoint. This constant defines a high number of successive values.
 * Useful if you have Nodes which need to access to a lot of different successive values of data.
*/
#define LG_ENV_HISTORIC_LENGTH_LONG 10

/*!
 * \def LG_ENV_HISTORIC_LENGTH_NORMAL
 * \brief Value for setting a normal historic (ie storing an acceptable (10) number of successive values for data). To use as parameter in the setHistoricLength function.
 * Each HOrientedPoint can store several successive values of OrientedPoint. This constant defines a number, which should be enough for most Nodes, of successive values.
 * Default value.
*/
#define LG_ENV_HISTORIC_LENGTH_NORMAL 3

/*!
 * \def LG_ENV_HISTORIC_LENGTH_SHORT
 * \brief Value for setting a short historic (ie storing just 3 successive values for data). To use as parameter in the setHistoricLength function.
 * Each HOrientedPoint can store several successive values of OrientedPoint. This constant defines a small number of successive values.
 * Can be used when no Nodes requires no old values (or at least no more than just the previous one).
*/
#define LG_ENV_HISTORIC_LENGTH_SHORT 1

/*!
 * \def LG_ENV_STEP_BIG
 * \brief Value for providing a lot (10000) of avalaible ids for data to each node. To use as parameter in the setIDStep function.
 * Each Node will have a set of 10000 IDs to give to their Groups and HOrientedPoints.
*/
#define LG_ENV_STEP_BIG 10000

/*!
 * \def LG_ENV_STEP_NORMAL
 * \brief Value for providing an acceptable (1000) number of avalaible ids for data to each node. To use as parameter in the setIDStep function.
 * Each Node will have a set of 1000 IDs to give to their Groups and HOrientedPoints.
*/
#define LG_ENV_STEP_NORMAL 1000

/*!
 * \def LG_ENV_STEP_SMALL
 * \brief Value for providing a few (100) number of avalaible ids for data to each node. To use as parameter in the setIDStep function.
 * Each Node will have a set of 100 IDs to give to their Groups and HOrientedPoints.
*/
#define LG_ENV_STEP_SMALL 100

/*!
 * \def LG_ENV_VERBOSE_HIGH
 * \brief Value for sending a lot of informations on the standard output. (Debug mode)
 * Each process in the library (Environment, Nodes ...) must write informations about what is happenning to the standard output.
 * These processes can be important (such as starting a function) or unexpected (ie errors), and then will be on a normal level. Other informations will be labelled as high level.
*/
#define LG_ENV_VERBOSE_HIGH 2

/*!
 * \def LG_ENV_VERBOSE_NORMAL
 * \brief Value for sending some informations on the standard output. (Development mode)
 * Each process in the library (Environment, Nodes ...) must write informations about what is happenning to the standard output.
 * These processes can be important (such as starting a function) or unexpected (ie errors), and then will be on a normal level. Other informations will be labelled as high level.
*/
#define LG_ENV_VERBOSE_NORMAL 1

/*!
 * \def LG_ENV_VERBOSE_MUTE
 * \brief Value for sending no information on the standard output. (Runtime mode)
 * Each process in the library (Environment, Nodes ...) must write informations about what is happenning to the standard output.
 * These processes can be important (such as starting a function) or unexpected (ie errors), and then will be on a normal level. Other informations will be labelled as high level.
*/
#define LG_ENV_VERBOSE_MUTE 0

#include <sys/types.h>
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <set>

#include "LgData.h"
#include "LgTimer.h"

#if defined _WIN32  || defined _WIN64
#define EXTENSION ".dll"
#include "windows.h"
#else
#if __APPLE__
#define EXTENSION ".dylib"
#else
#define EXTENSION ".so"
#endif
#include <dlfcn.h>
#include <pthread.h>
#endif

using namespace std;

/*!
 * \namespace lg
 * \brief Namespace containing everything for managing libGina Environment, Node and Groups.
*/
namespace lg
{

class Node;
/*!
     * \class Environment
     * \brief Class for managing nodes and their priorities, and data (3D,2D and 1D Groups) between them.
    */
class Environment
{
private:
    //! Current id to give to the next registered node.
    int _uniqueID;

    //! Time informations : for getting current time and computing elapsed time.
    Timer _timer;

    //! Store the current time.
    int _timestamp;

    //! Structure for storing Switch Data (will be generated/processed/observed by Nodes, only if they target Switch).
    map<string, GroupSwitch*> _groupsSwitch;

    //! Structure for storing 1D Data (will be generated/processed/observed by Nodes, only if they target 1D).
    map<string, Group1D*> _groups1D;

    //! Structure for storing 2D Data (will be generated/processed/observed by Nodes, only if they target 2D).
    map<string, Group2D*> _groups2D;

    //! Structure for storing 3D Data (will be generated/processed/observed by Nodes, only if they target 3D).
    map<string, Group3D*> _groups3D;

    //! Registered Nodes, stored by their names.
    map<string, Node*> _nodes;

    //! Registered Nodes, ordered priorities to Nodes' names.
    map<int, string> _priorities;

    //! Information whether the current instance of the environment has started.
    bool _started;

    //! String for returning error message (updated by all environment functions)
    string _error;

    //! Store the current maximum number of successive Orientedpoint an HOrientedPoint must have.
    int _historicLength;

    //! Store the current number of avalaible ids for each Node.
    int _step;

    //! Store whether the data copy mode is enabled.
    bool _dataCopy;

    //! Store whether changes (such as registered a new Node) can be done after the current Environment has started.
    bool _runtimeChange;

    //! Store the current level of verbosity.
    int _verboseLevel;

    //! Store the maximum number of tries for starting or stopping a Node before counting it as an error.
    int _tries;

public:

    /*!
         * \brief Constructor
         */
    Environment(void);

    /*!
         * \brief Destructor
         */
    ~Environment(void);


    /*!
         * \brief Register a new Node
         *
         * Register a new Node without unique name nor priority.
         * A unique name will be created from the Node name and its unique id
         * The priority will be as the most important which is not used
         *
         * \param[in] node : a pointer to the Node to register
         * \return true if success, false in other cases (use getLastError() for getting the problem)
         */
    bool registerNode(Node* node);

    /*!
         * \brief Register a new Node with its priority
         *
         * Register a new Node without unique name
         * A unique name will be created from the Node name and its unique id
         *
         * \param[in] node : a pointer to the Node to register
         * \param[in] priority : the wanted priority for this node (0 is fully prioritary, 1 is less prioritary ...)
         * \return true if success, false in other cases (use getLastError() for getting the problem)
         */
    bool registerNode(Node* node,int priority);

    /*!
         * \brief Register a new Node with its name
         *
         * Register a new Node without priority
         * The priority will be as the most important which is not used
         *
         * \param[in] uniqueName : a name for this Node (must be unique)
         * \param[in] node : a pointer to the Node to register
         * \return true if success, false in other cases (use getLastError() for getting the problem)
         */
    bool registerNode(string uniqueName,Node* node);

    /*!
         * \brief Register a new Node with its unique name and its priority
         *
         * Register a new Node with all its necessary informations
         *
         * \param[in] uniqueName : a name for this Node (must be unique)
         * \param[in] node : a pointer to the Node to register
         * \param[in] priority : the wanted priority for this Node (0 is fully prioritary, 1 is less prioritary ...)
         * \return true if success, false in other cases (use getLastError() for getting the problem)
         */
    bool registerNode(string uniqueName,Node* node,int priority);

    /*!
         * \brief Unregister a LgNode by passing the pointer used to register it
         * \param[in] node : the pointer used to register the node
         * \return true if success, false in other cases (use getLastError() for getting the problem)
         */
    bool unregisterNode(Node* node);

    /*!
         * \brief Unregister a Node by passing its name
         * \param[in] uniqueName : the name of the Node to unregister
         * \return true if success, false in other cases (use getLastError() for getting the problem)
         */
    bool unregisterNode(string uniqueName);

    /*!
         * \brief Change the priority of an already-registered Node
         * \param[in] uniqueName : name of the Node to which the priority must be changed
         * \param[in] newPriority : the new priority of the Node
         * \return true if success, false in other cases (use getLastError() for getting the problem)
         */
    bool changePriority(string uniqueName,int newPriority);

    /*!
         * \brief Get the map of all registered Nodes, keys are Nodes'uniqueName
         * \return the map of registered Nodes
         */
    inline map<string, Node*> getNodes() const {return _nodes;}

    /*!
         * \brief Get the map of priorities
         * \return the map of priorities
         */
    inline map<int, string> getPriorities() const {return _priorities;}

    /*!
         * \brief Get the current timestamp of the Environment
         * \return current timestamp
         */
    inline int getTime() const {return _timestamp;}


    /*!
         * \brief Get the probabilities generated by a Node
         * \param[in] nodeName : name of the Node from which the probabilities must be read
         * \return a map of all processed Groups and their generated probabilities
         */
    map<string, float> getProbabilities(string nodeName);

    /*!
         * \brief Get the probabilities generated by a Node for a specific Group
         * \param[in] nodeName : name of the Node from which the probability must be read
         * \param[in] groupName : name of the Group from which the probability has been produced
         * \return the probability associated with the wanted Group from the specified Node, 0 if this Group is not present
         */
    float getProbabilities(string nodeName,string groupName);

    /*!
         * \brief Get the parameters generated by a Node
         * \param[in] nodeName : name of the Node from which the parameters must be read
         * \return a map of all processed Groups and their generated parameters
         */
    map<string, void*> getParameters(string nodeName);

    /*!
         * \brief Get the parameters generated by a Node for a specific Group
         * \param[in] uniqueName : name of the Node from which the parameters must be read
         * \param[in] groupName : name of the Group from which the parameters has been produced
         * \return the parameters associated with the wanted Group from the specified Node, NULL if this Group is not present
         */
    void* getParameters(string uniqueName,string groupName);

    /*!
         * \brief Get the Switch Groups at their current state
         * \return the map of the Switch groups
         */
    map<string, GroupSwitch*> getGroupsSwitch() const {return _groupsSwitch;}

    /*!
         * \brief Get the 1D Groups at their current state
         * \return the map of the 1D groups
         */
    map<string, Group1D*> getGroups1D() const {return _groups1D;}

    /*!
         * \brief Get the 2D Groups at their current state
         * \return the map of the 2D groups
         */
    map<string, Group2D*> getGroups2D() const {return _groups2D;}

    /*!
         * \brief Get the 3D Groups at their current state
         * \return the map of the 3D groups
         */
    map<string, Group3D*> getGroups3D() const {return _groups3D;}

    /*!
         * \brief Start the Environment, by starting all the registered Nodes
         * \return true if success, false in other cases (use getLastError() for getting the problem)
         */
    bool start();

    /*!
         * \brief Stop the Environment, by stopping all the registered Nodes
         * \return true if success, false in other cases (use getLastError() for getting the problem)
         */
    bool stop();

    /*!
         * \brief Update the Environment, by updating all the registered Nodes ordered by their priorities
         * \return true if success, false in other cases (use getLastError() for getting the problem)
         */
    bool update();

    /*!
         * \brief Check if the registered Nodes have the data they need for working (generated by previous Nodes)
         * \return true if success, false in other cases (use getLastError() for getting the problem)
         */
    bool checkCompatibility();

    /*!
         * \brief Get the last generated error
         * \return a string describing the error
         */
    string getLastError();

    /*!
         * \brief Get the number of successive values for the historic of HOrientedPoint
         * The length of the historic of HOrientedPoint is useful for ease data access to Nodes. (Longer historic = bigger memory space)
         * \return Length of the historic
         */
    int getHistoricLength() const {return _historicLength;}

    /*!
         * \brief Set the number of successive values for the historic of HOrientedPoint
         * The length of the historic of HOrientedPoint is useful for ease data access to Nodes. (Longer historic = bigger memory space)
         * \param[in] newLength : the new length of the Historic
         */
    void setHistoricLength(int newLength) {_historicLength = newLength;}

    /*!
         * \brief Get the number of avalaible ids for each Node
         * The number of avalaible ids set the quantity of data a Node can manage. (Bigger number = bigger memory space)
         * \return Number of avalaible ids for each Node
         */
    int getIDStep() const {return _step;}

    /*!
         * \brief Set the number of avalaible ids for each Node
         * The number of avalaible ids set the quantity of data a Node can manage. (Bigger number = bigger memory space)
         * \param[in] newStep : the new size of the step for each Node
         */
    void setIDStep(int newStep) {_step = newStep;}

    /*!
         * \brief Get the state of the data copy option.
         * The data copy option make the Environment pass empty data to Generators (then copy the data back) and a copy of the data to Observers for avoiding modifications.
         * \return Value of the option.
         */
    bool dataCopyEnabled() const {return _dataCopy;}

    /*!
         * \brief Enable/disable the data copy option for Generators and Observers.
         * The data copy option make the Environment pass empty data to Generators (then copy the data back) and a copy of the data to Observers for avoiding modifications.
         * \param[in] enabled : the new state of the option
         */
    void enableDataCopy(bool enabled) {_dataCopy = enabled;}

    /*!
         * \brief Get the state of the runtime changes option.
         * The runtime changes option allows Nodes to be registered/unregistered after the Environment has started. (Safer when disabled)
         * \return Value of the option.
         */
    bool runtimeChangesEnabled() const {return _runtimeChange;}

    /*!
         * \brief Enable/disable the runtime changes option.
         * The runtime changes option allows Nodes to be registered/unregistered after the Environment has started. (Safer when disabled)
         * \param[in] enabled : the new state of the option
         */
    void enableRuntimeChanges(bool enabled) {_runtimeChange = enabled;}

    /*!
         * \brief Get the verbose level.
         * The verbose level defines the level of informations to write to the standard output.
         * Mute : Nothing; Normal : In and out of functions, errors; High : everything.
         * Each informations to write is linked to a level in the implementation.
         * \return The verbose level.
         */
    int getVerboseLevel() const {return _verboseLevel;}

    /*!
         * \brief Set the verbose level.
         * The verbose level defines the level of informations to write to the standard output.
         * Mute : Nothing; Normal : In and out of functions, errors; High : everything.
         * Each informations to write is linked to a level in the implementation.
         * \param[in] newLevel : the new level of verbosity
         */
    void setVerboseLevel(int newLevel) {_verboseLevel = newLevel;}

    /*!
         * \brief Get the number of try for starting/updating/stopping a Node.
         * Each Node'start/update/stop function indicates whether it succeeded. If it failed, the Environment retries it this number of times.
         * \return Number of try.
         */
    int getTryNumber() const {return _tries;}

    /*!
         * \brief Set the number of try for starting/updating/stopping a Node.
         * Each Node'start/update/stop function indicates whether it succeeded. If it failed, the Environment retries it this number of times.
         * \param[in] newTryNumber : the new number of try to perform for starting/updating/stopping a Node before considering a fail
         */
    void setTryNumber(int newTryNumber) {_tries = newTryNumber;}
};


//map<string, float> getProbabilities(Environment* env,string nodeName) {return env->getProbabilities(nodeName);}
//map<string, void*> getParameters(Environment* env,string nodeName) {return env->getParameters(nodeName);}

}
#endif /* LGENVIRONMENT_H_ */
