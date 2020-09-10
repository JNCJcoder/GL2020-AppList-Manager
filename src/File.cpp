#include <fstream>

class FileExplorer
{
private:
    std::fstream& m_file;

public:
    FileExplorer(std::fstream& file, const char* fileName): m_file(file)
    {
        m_file.open(fileName);
    }
    ~FileExplorer()
    {
        m_file.close();
    }
};