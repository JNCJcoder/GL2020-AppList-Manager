#include "main.hpp"
#include "File.cpp"
#include "patch.cpp"
#include "argparser.cpp"
#include "NewChar.cpp"

int main(int argc, char * argv[])
{
    const auto argcv = argv+argc;
    
    std::cout << "  GL2020 AppList Manager" << "\n";

    if(cmdOptionExists(argv, argcv, "-v"))
    {
        std::cout << "      Version: " << VERSION << "\n";
        return 0;
    }

    if(cmdOptionExists(argv, argcv, "-D"))
    {
        DeleteAppList();
        std::cout << "      AppList deleted." << "\n" << "\n";
        std::cout << "      Repopulating AppList..." << "\n";
    } else std::cout << "       Populating AppList..." << "\n";

    FileExplorer Index(IndexFile, INDEXNAME);
    AddToAppList();

    return 0;
}

inline void DeleteAppList()
{
    std::cout << "      Deleting AppList..." << "\n";
    for (unsigned short i = 0; i < INDEXLIMIT; ++i)
    {
        std::string ss = "AppList/" + patch::to_string(i) + ".txt";
        char* cstr;//= new char[ss.length() + 1];
        NewChar StringToChar(cstr, ss.length() + 1);
        strcpy(cstr, ss.c_str());

        if( remove( cstr ) != 0 ) {
            //delete[] cstr;
            break;
        }
        //delete[] cstr;
    } 
}

inline void AddToAppList()
{
    unsigned short IndexTotal;

    for (IndexTotal = 0; IndexTotal < INDEXLIMIT; ++IndexTotal)
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