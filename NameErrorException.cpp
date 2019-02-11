#include "NameErrorException.h"

NameErrorException::NameErrorException(std::string name) : _name(name)
{
}

NameErrorException::~NameErrorException()
{
}

const char * NameErrorException::what() const throw()
{
	std::string what_str = "NameError: name " + _name + " is not defined";
	char* what_cstr = new char[what_str.length() + 1];
	std::strcpy(what_cstr, what_str.c_str());
	what_cstr[what_str.length() + 1] = '\0';
	return what_cstr;
}
