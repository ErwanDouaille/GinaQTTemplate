#ifndef MYGENERATOR_H
#define MYGENERATOR_H

#include "LgGenerator.h"

using namespace lg;

class MyGenerator: public Generator
{
public:
    MyGenerator(string name);
    ~MyGenerator();

    /*!
        * \brief Get a pointer to a copy of this MyGenerator
        * \param[in] cloneName : name for the clone
        * \return A pointer to a copy of this Node
        */
    Node* clone(string cloneName) const;

    /*!
        * \brief Start the MyGenerator by initializing streams
        * Initialize RGB, IR or Depth stream depending on the output mode.
        * \return true if success
        */
    bool start();

    /*!
        * \brief Stop the MyGenerator by closing streams
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
    bool generate(map<string,Group3D*>& groups3D,map<string,Group2D*>& groups2D,map<string,Group1D*>&,map<string,GroupSwitch*>&);

    /*!
        * \brief Return a set of string describing what kind of type this Node produces (adds to output).
        * LG_ORIENTEDPOINT3D_HEAD, LG_ORIENTEDPOINT3D_NECK, LG_ORIENTEDPOINT3D_RIGHT_HAND ...
        * and/or LG_ORIENTEDPOINT2D_RIGHTHAND ...
        * \return A set of type
        */
    set<string> produce() const;


};

#endif // MYGENERATOR_H
