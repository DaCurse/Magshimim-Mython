#include "Integer.h"

Integer::Integer(int value) : _value(value)
{
}

Integer::~Integer()
{
}

const bool Integer::isPrintable()
{
	return true;
}

const std::string Integer::toString()
{
	return std::to_string(_value);
}

std::unique_ptr<Type> Integer::clone() const
{
	return std::make_unique<Integer>(*this);
}
