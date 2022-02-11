#include <fstream>

constexpr int INDEX_LIMIT       = 143;
constexpr char INDEX_NAME[]     = "AppListIndex.txt";
constexpr char INDEX_SYMBOL[]   = "=";
constexpr char INDEX_COM[]      = "#";
constexpr char VERSION[]        = "3.0.0";

class AppList
{
    private:
        std::ifstream indexFile;

    public:
        AppList();
        ~AppList();
        void addToAppList();
        void deleteAppList();
};