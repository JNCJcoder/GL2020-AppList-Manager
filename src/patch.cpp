namespace patch
{
    template < typename T >
    const std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

const unsigned int ConvertToInt(const std::string &ID)
{
    std::istringstream Value(ID);
    int returning = 0;
    Value >> returning;
    return returning;
}

const std::string ParserIndex(const std::string& s, const char& c)
{
    std::string buff{""};
    for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { return buff; }
	}
    return "0";
}