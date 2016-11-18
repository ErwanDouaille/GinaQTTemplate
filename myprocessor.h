#ifndef MYPROCESSOR_H
#define MYPROCESSOR_H

#include "LgProcessor.h"

using namespace lg;

class MyProcessor: public Processor
{
public:
    MyProcessor(string);
    ~MyProcessor();

    /*!
        * \brief Get a pointer to a copy of this MyProcessor
        * \param[in] cloneName : name for the clone
        * \return A pointer to a copy of this Node
        */
    Node* clone(string cloneName) const;

    /*!
        * \brief Start the MyProcessor by initializing streams
        * Initialize RGB, IR or Depth stream depending on the output mode.
        * \return true if success
        */
    bool start();

    /*!
        * \brief Stop the MyProcessor by closing streams
        * \return true if success
        */
    bool stop();

    /*!
        * \brief Generate Groups and data from the device
        * Do not generate 1D and Switch.
        * \param[in] groups3D : Groups of HOrientedPoint3D (Skeletons/Users)
        * \param[in] groups2D : Groups of HOrientedPoint2D (Projections of 3D)
        * \return true if success
        */
    bool update(map<string,Group3D*>& groups3D,map<string,Group2D*>& groups2D,map<string,Group1D*>&,map<string,GroupSwitch*>&);

    /*!
        * \brief Return a set of string describing what kind of type this Node produces (adds to output).
        * LG_ORIENTEDPOINT3D_HEAD, LG_ORIENTEDPOINT3D_NECK, LG_ORIENTEDPOINT3D_RIGHT_HAND ...
        * and/or LG_ORIENTEDPOINT2D_RIGHTHAND ...
        * \return A set of type
        */
    set<string> produce() const;

    /*!
     * \brief Return a set of string describing what kind of type this Node consumes (need in input then destroy).
     * This function is used by the Environment to check if the registered Node are compatible (ie Node require data types which is present).
     * \return A set of type
     */
    set<string> consume() const;

    /*!
     * \brief Return a set of string describing what kind of type this Node needs in input.
     * This function is used by the Environment to check if the registered Node are compatible (ie Node require data types which is present).
     * \return A set of type
     */
    set<string> need() const;
};

#endif // MYPROCESSOR_H
