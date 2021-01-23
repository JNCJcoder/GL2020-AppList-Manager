namespace patch
{
    template < typename T >
    const std::string toString(const T& number)
    {
        std::ostringstream newString;
        newString << number;
        return newString.str();
    }
}

const std::string parserIndex(const std::string& s, const char& c)
{
    std::string buff{""};

    for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { return buff; }
	}

    return "0";
}