#pragma once
#include "InterperterException.h"

class SyntaxException : public InterperterException
{
public:
	virtual const char* what() const throw();
};

