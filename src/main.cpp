#include "main.hpp"
#include "File.cpp"
#include "patch.cpp"
#include "argparser.cpp"
#include "NewChar.cpp"

int main(int argc, char * argv[])
{
    const auto argcv = argv+argc;
    FileExplorer Index(IndexFile, INDEXNAME);
    
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
        if(param >= INDEXLIMIT) return 0;
        if(cmdOptionExists(argv, argcv, "-D")) DeleteAppList();

        AddToAppList(param);
        
        return 0;
    }

    if(cmdOptionExists(argv, argcv, "-D"))
    {
        DeleteAppList();
    } else std::cout << "       Populating AppList..." << "\n";

    AddToAppList(0);

    return 0;
}

void DeleteAppList()
{
    std::cout << "      Deleting AppList..." << "\n";

    for (unsigned short i = 0; i < INDEXLIMIT; ++i)
    {
        std::string ss = "AppList/" + patch::to_string(i) + ".txt";
        char* cstr;
        NewChar StringToChar(cstr, ss.length() + 1);
        strcpy(cstr, ss.c_str());

        if( remove( cstr ) != 0 ) continue;
    }

    std::cout << "      AppList deleted." << "\n" << "\n"
              << "      Repopulating AppList..." << "\n"
              << "      Populating AppList..." << "\n"; 
}

void AddToAppList(const unsigned short InitialIndex)
{
    for (unsigned short IndexTotal = InitialIndex; IndexTotal < INDEXLIMIT; ++IndexTotal)
    {
        std::string line;
        std::getline( IndexFile, line );

        if(line == "") {
            break;
        }

        std::ofstream AddApp;
        std::string AddAppName = "AppList/" + patch::to_string(IndexTotal) + ".txt";
        AddApp.open(AddAppName, std::ios::out | std::ios::trunc | std::ios::in);

        if (AddApp.is_open())
        {
            AddApp << ConvertToInt(ParserIndex(line, INDEXSYMBOL));
            AddApp.close();
        } else { std::cout << "     Unable to save file"; return; }
    }

    std::cout << "Done!";
}