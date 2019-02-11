#pragma once
#include "Sequence.h"
class String :
	public Sequence
{
public:
	String(std::string value);
	virtual ~String();
	virtual const bool isPrintable();
	virtual const std::string toString();
	virtual std::unique_ptr<Type> clone() const;

private:
	std::string _value;
};

