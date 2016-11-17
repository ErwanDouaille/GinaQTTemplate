#include <iostream>
#include <signal.h>

#include "LgEnvironment.h"

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

    // HERE, declare your generators/processors/observers and add it to the environment

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
