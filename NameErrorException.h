#ifndef NAME_ERROR_EXCEPTION_H
#define NAME_ERROR_EXCEPTION_H
#pragma warning(disable: 4996)

#include "InterperterException.h"
#include <string>

class NameErrorException : public InterperterException
{
public:
	NameErrorException(std::string name);
	~NameErrorException();
	virtual const char* what() const throw();

private:
	std::string _name;
};


#endif // NAME_ERROR_EXCEPTION_H