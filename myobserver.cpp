#include "myobserver.h"

MyObserver::MyObserver(string name) : Observer(name)
{
}

MyObserver::~MyObserver()
{
}

Node* MyObserver::clone(string cloneName) const
{
    return new MyObserver("CloneMyObserver");
}

bool MyObserver::start()
{
    cout << "Start MyObserver" << endl;
    return true;
}

bool MyObserver::stop()
{
    cout << "Stop MyObserver" << endl;
    return true;
}

bool MyObserver::observe(map<string,Group3D*> g3D,map<string,Group2D*>,map<string,Group1D*>, map<string,GroupSwitch*>)
{
    for(map<string,Group3D*>::iterator mit = g3D.begin();mit != g3D.end();mit++){
        set<HOrientedPoint3D*> hand = mit->second->getElementsByType(LG_ORIENTEDPOINT3D_RIGHT_HAND);
        set<HOrientedPoint3D*> handProc = mit->second->getElementsByType("LG_ORIENTEDPOINT3D_RIGHT_HAND_PROCESSED");

        if(hand.size() > 0 && handProc.size() > 0)
        {
            HOrientedPoint3D* h = *hand.begin();
            HOrientedPoint3D* hproc = *handProc.begin();
            if(h &&  hproc)
            {
                cout << "Processor divides by 10 LG_ORIENTEDPOINT3D_RIGHT_HAND datas" << endl;
                OrientedPoint3D* hp = h->getLast();
                Point3D newPos = hp->getPosition();
                cout << "Original data: " << newPos.getX() << "\t" << newPos.getY() << "\t" << newPos.getZ() << endl;

                OrientedPoint3D* hprocp = hproc->getLast();
                Point3D newPosProc = hprocp->getPosition();
                cout << "Processed data: " << newPosProc.getX() << "\t" << newPosProc.getY() << "\t" << newPosProc.getZ() << "\n" << endl;
            }
        }
    }
    return true;
}

set<string> MyObserver::need() const
{
    set<string> needed;
    needed.insert(LG_ORIENTEDPOINT3D_RIGHT_HAND);
    needed.insert("LG_ORIENTEDPOINT3D_RIGHT_HAND_PROCESSED");
    return needed;
}
