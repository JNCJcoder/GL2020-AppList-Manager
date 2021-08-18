#include <fstream>

class FileExplorer
{
    private:
        std::ofstream& m_file;
    
    public:
        FileExplorer(std::ofstream& file, const char* fileName): m_file(file)
        {
            m_file.open(fileName);
        }
        
        ~FileExplorer()
        {
            m_file.close();
        }
};