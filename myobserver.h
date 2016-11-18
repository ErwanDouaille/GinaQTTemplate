#ifndef MYOBSERVER_H
#define MYOBSERVER_H

#include "LgObserver.h"

using namespace lg;

class MyObserver: public Observer
{
public:
    MyObserver(string);
    ~MyObserver();

    /*!
        * \brief Get a pointer to a copy of this MyObserver
        * \param[in] cloneName : name for the clone
        * \return A pointer to a copy of this Node
        */
    Node* clone(string cloneName) const;

    /*!
        * \brief Start the MyObserver by initializing streams
        * Initialize RGB, IR or Depth stream depending on the output mode.
        * \return true if success
        */
    bool start();

    /*!
        * \brief Stop the MyObserver by closing streams
        * \return true if success
        */
    bool stop();

    /*!
     * \brief Observe specific gesture
     * Virtual function that must be implemented by any Observer. It is the main function of the Observer, where the gesture is actually recognized.
     * \param[in] groups3D : Groups of HOrientedPoint3D
     * \param[in] groups2D : Groups of HOrientedPoint2D
     * \param[in] groups1D : Groups of HOrientedPoint1D
     * \param[in] groupsSwitch : Groups of HSwitch
     * \return true if success
     */
    bool observe(map<string,Group3D*> groups3D,map<string,Group2D*> groups2D, map<string,Group1D*> groups1D, map<string,GroupSwitch*> groupsSwitch);


    /*!
     * \brief Return a set of string describing what kind of type this Node needs in input.
     * This function is used by the Environment to check if the registered Node are compatible (ie Node require data types which is present).
     * \return A set of type
     */
    set<string> need() const;

};

#endif // MYOBSERVER_H
