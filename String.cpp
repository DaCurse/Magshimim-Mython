#include "String.h"

String::String(std::string value) : _value(value)
{
}

String::~String()
{
}

const bool String::isPrintable()
{
	return true;
}

const std::string String::toString()
{
	return _value;
}

std::unique_ptr<Type> String::clone() const
{
	return std::make_unique<String>(*this);
}
