#include <iostream>
#include <signal.h>

#include "LgEnvironment.h"
#include "mygenerator.h"
#include "myprocessor.h"
#include "myobserver.h"

using namespace std;
using namespace lg;

bool finish = false;

void killHandler (int param)
{
    finish = true;
}

int main(int argc, char *argv[])
{
#ifdef SIGBREAK
    signal (SIGBREAK, killHandler);
#endif
    signal (SIGINT, killHandler);
    signal (SIGABRT, killHandler);
    signal (SIGTERM, killHandler);

    // Environment declaration
    Environment* environment = new Environment();
    environment->enableDataCopy(false);
    environment->setHistoricLength(3);

    // HERE, declare your generators/processors/observers and add it to the environment
    /******************************************************************* GENERATOR
    ******************************************************************************/
    MyGenerator* myGen = new MyGenerator("myGenerator");
    if(environment->registerNode(myGen))
        printf("Register MyGenerator OK.\n");
    else
        printf("%s.\n",environment->getLastError().c_str());

    /******************************************************************* PROCESSOR
    ******************************************************************************/
    MyProcessor* myProc = new MyProcessor("myProcessor");
    if(environment->registerNode(myProc))
        printf("Register MyProcessor OK.\n");
    else
        printf("%s.\n",environment->getLastError().c_str());

    /******************************************************************** OBSERVER
    ******************************************************************************/
    MyObserver* myObs = new MyObserver("myObserver");
    if(environment->registerNode(myObs))
        printf("Register MyObserver OK.\n");
    else
        printf("%s.\n",environment->getLastError().c_str());


    // Check if your generators/processors/observers are commpatible
    if(!environment->checkCompatibility())
    {
        cerr << "Nodes are not compatible." << endl;
        return 2;
    }

    // Check if you started the environment
    if(!environment->start())
    {
        cerr << "Environnement not started." << endl;
        return 2;
    }

    while(!finish)
    {
        environment->update();
    }

    environment->stop();

    delete environment;

    return 0;
}
