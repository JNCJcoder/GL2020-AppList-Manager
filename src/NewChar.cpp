class NewChar
{
    private:
        char* &data;

    public:
        NewChar(char* &Data, const unsigned int size): data(Data) 
        { 
            data = new char[size]; 
        } // acquire
        
        ~NewChar() 
        { 
            delete[] data; 
        } // release
};