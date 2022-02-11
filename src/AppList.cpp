#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include "AppList.hpp"

AppList::AppList()
{
    std::cout << "  GL2020 AppList Manager" << "\n";
    std::cout << "      Version: " << VERSION << "\n\n";

    indexFile.open(INDEX_NAME);
}

AppList::~AppList()
{
    indexFile.close();
}

void AppList::addToAppList()
{
    std::cout << "  Populating AppList..." << "\n";
    std::string line;

    int index = 0;
    
    while(std::getline(indexFile, line))
    {
        if(line.find(INDEX_COM) != std::string::npos || line.empty()) continue;

        std::string appId = line.substr(0, line.find(INDEX_SYMBOL));
        appId = line.substr(0, line.find(' '));

        std::ofstream addApp;

        addApp.open(
            "AppList/" + std::to_string(index) + ".txt",
            std::ios::out | std::ios::trunc | std::ios::in
        );

        std::cout << "    " << index << " - " << appId << " | Status:  ";

        if (addApp.is_open())
        {
            addApp << appId;
            std::cout << "Done!" << "\n";
        }
        else
        {
            std::cout << "Error! Unable to save file" << "\n";
        }

        addApp.close();

        index++;
    }

    std::cout << "\n  Completed!";
}

void AppList::deleteAppList()
{
    std::cout << "  Deleting AppList..." << "\n";

    for (unsigned short item = 0; item < INDEX_LIMIT; ++item)
    {
        std::string fileApp = "AppList/" + std::to_string(item) + ".txt";
        if (remove(fileApp.c_str()) != 0) continue;
        std::cout << "    "  << item << " | Status: Deleted." << "\n";
    }
    std::cout << "\n  Completed!" << "\n\n";
}