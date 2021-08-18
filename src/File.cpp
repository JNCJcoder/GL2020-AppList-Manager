#include <fstream>

class FileExplorer
{
    private:
        std::ifstream& m_file;
    
    public:
        FileExplorer(std::ifstream& file, const char* fileName): m_file(file)
        {
            m_file.open(fileName);
        }
        
        ~FileExplorer()
        {
            m_file.close();
        }
};