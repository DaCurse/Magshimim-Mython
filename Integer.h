#pragma once
#include "type.h"
class Integer :
	public Type
{
public:
	Integer(int value);
	virtual ~Integer();
	virtual const bool isPrintable();
	virtual const std::string toString();
	virtual std::unique_ptr<Type> clone() const;

private:
	int _value;
};

