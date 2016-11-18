#include "myprocessor.h"

#include "LgProcessor.h"

MyProcessor::MyProcessor(string name) : Processor(name)
{
}

MyProcessor::~MyProcessor()
{
}

Node* MyProcessor::clone(string cloneName) const
{
    return (Node*)this;
}

bool MyProcessor::start()
{
    cout << "Start MyProcessor" << endl;
    return true;
}

bool MyProcessor::stop()
{
    cout << "Stop MyProcessor" << endl;
    return true;
}

bool MyProcessor::update(map<string,Group3D*>& g3D,map<string,Group2D*>& g2D,map<string,Group1D*>&,map<string,GroupSwitch*>&)
{
    for(map<string,Group3D*>::iterator mit = g3D.begin();mit != g3D.end();mit++){
        set<HOrientedPoint3D*> hand = mit->second->getElementsByType(LG_ORIENTEDPOINT3D_RIGHT_HAND);

        if(hand.size() > 0)
        {
            HOrientedPoint3D* h = *hand.begin();
            if(h)
            {
                OrientedPoint3D* hp = h->getLast();
                Point3D newPos = hp->getPosition();
                newPos.setX(newPos.getX()/10);
                newPos.setY(newPos.getY()/10);
                newPos.setZ(newPos.getZ()/10);

                updateData(_environment, g3D, "ID1", "aName", "LG_ORIENTEDPOINT3D_RIGHT_HAND_PROCESSED", "LG_ORIENTEDPOINT3D_RIGHT_HAND_PROCESSED", _timestamp, OrientedPoint3D(newPos, hp->getOrientation(), 1.0, 1.0));
            }
        }
    }
    return true;
}

set<string> MyProcessor::need() const
{
    set<string> need;
    need.insert(LG_ORIENTEDPOINT3D_RIGHT_HAND);
    return need;
}

set<string> MyProcessor::consume() const
{
    set<string> consume;
    // we don't consume data inside update function
    //    consume.insert(LG_ORIENTEDPOINT3D_RIGHT_HAND);
    return consume;
}

set<string> MyProcessor::produce() const
{
    set<string> produce;
    produce.insert("LG_ORIENTEDPOINT3D_RIGHT_HAND_PROCESSED");
    return produce;
}
