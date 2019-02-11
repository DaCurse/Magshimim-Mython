#pragma once
#include "type.h"
class Void :
	public Type
{
public:
	Void();
	~Void();
	virtual const bool isPrintable();
	virtual const std::string toString();
	virtual std::unique_ptr<Type> clone() const;
};

