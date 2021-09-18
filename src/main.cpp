#include "main.hpp"
#include "File.cpp"
#include "argparser.cpp"

int main(int argc, char * argv[])
{
    const auto argcv = argv+argc;
    FileExplorer Index(IndexFile, INDEX_NAME);
    
    std::cout << "  GL2020 AppList Manager" << "\n";

    if(cmdOptionExists(argv, argcv, "-v"))
    {
        std::cout << "      Version: " << VERSION << "\n";
        return 0;
    }

    if(cmdOptionExists(argv, argcv, "-a"))
    {
        std::cout << "\n" << "      Arbitrary AppList." << "\n" << "\n";
        
        const unsigned short param = atoi(getCmdOption(argv, argcv, "-a"));
        
        if(!param) return 0;
        if(param >= INDEX_LIMIT) return 0;
        if(cmdOptionExists(argv, argcv, "-D")) deleteAppList();

        addToAppList(param);
        
        return 0;
    }

    if(cmdOptionExists(argv, argcv, "-D"))
    {
        deleteAppList();
    } else std::cout << "       Populating AppList..." << "\n";

    addToAppList(0);

    return 0;
}

void deleteAppList()
{
    std::cout << "      Deleting AppList..." << "\n";

    for (unsigned short item = 0; item < INDEX_LIMIT; ++item)
    {
        std::string fileApp = "AppList/" + std::to_string(item) + ".txt";
        if (remove(fileApp.c_str()) != 0) continue;
    }

    std::cout << "      AppList deleted." << "\n" << "\n"
              << "      Repopulating AppList..." << "\n"
              << "      Populating AppList..." << "\n"; 
}

void addToAppList(const unsigned short initialIndex)
{
    std::string line;
    int index = initialIndex;

    while(std::getline(IndexFile, line))
    {
        if(line[0] == INDEX_COM || line.empty()) continue;

        std::string appId = line.substr(0, line.find(INDEX_SYMBOL));
        appId = line.substr(0, line.find(' '));

        std::ofstream addApp;

        addApp.open(
            "AppList/" + std::to_string(index) + ".txt",
            std::ios::out | std::ios::trunc | std::ios::in
        );

        if (addApp.is_open())   addApp << appId;
        else                    std::cout << "     Unable to save file";

        addApp.close();

        index++;
    }

    std::cout << "Done!";
}