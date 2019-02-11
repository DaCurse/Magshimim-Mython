#pragma once
#include "type.h"
class Boolean :
	public Type
{
public:
	Boolean(bool value);
	virtual ~Boolean();
	virtual const bool isPrintable();
	virtual const std::string toString();
	virtual std::unique_ptr<Type> clone() const;

private:
	bool _value;
};

