#include "mygenerator.h"

MyGenerator::MyGenerator(string name) : Generator(name)
{
}

MyGenerator::~MyGenerator()
{
}

Node* MyGenerator::clone(string cloneName) const
{
    return (Node*)this;
}

bool MyGenerator::start()
{
    cout << "Start MyGenerator" << endl;
    return true;
}

bool MyGenerator::stop()
{
    cout << "Stop MyGenerator" << endl;
    return true;
}

bool MyGenerator::generate(map<string,Group3D*>& g3D,map<string,Group2D*>& g2D,map<string,Group1D*>&,map<string,GroupSwitch*>&)
{
    updateData(_environment, g3D, "ID1", "aName", LG_ORIENTEDPOINT3D_RIGHT_HAND, LG_ORIENTEDPOINT3D_RIGHT_HAND, _timestamp, OrientedPoint3D(Point3D(((float) rand()) / (float) RAND_MAX, ((float) rand()) / (float) RAND_MAX, ((float) rand()) / (float) RAND_MAX), Point3D(0.0, 0.0, 0.0),1.0,1.0));
    return true;
}

set<string> MyGenerator::produce() const
{
    set<string> produce;
    produce.insert(LG_ORIENTEDPOINT3D_RIGHT_HAND);
    return produce;
}
