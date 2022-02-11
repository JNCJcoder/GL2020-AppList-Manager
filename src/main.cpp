#include <iostream>
#include <algorithm>
#include "argparser.cpp"
#include "AppList.cpp"


int main(int argc, char *argv[])
{
    AppList manager;

    const auto argcv = argv + argc;

    if(cmdOptionExists(argv, argcv, "-D"))
    {
        manager.deleteAppList();
    }

    manager.addToAppList();

    return 0;
}