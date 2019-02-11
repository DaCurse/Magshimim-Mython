#include "Boolean.h"

Boolean::Boolean(bool value) : _value(value)
{
}

Boolean::~Boolean()
{
}

const bool Boolean::isPrintable()
{
	return true;
}

const std::string Boolean::toString()
{
	return _value ? "True" : "False";
}

std::unique_ptr<Type> Boolean::clone() const
{
	return std::make_unique<Boolean>(*this);
}
