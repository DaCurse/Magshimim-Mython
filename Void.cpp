#include "Void.h"

Void::Void()
{
}


Void::~Void()
{
}

const bool Void::isPrintable()
{
	return false;
}

const std::string Void::toString()
{
	return NULL;
}

std::unique_ptr<Type> Void::clone() const
{
	return std::make_unique<Void>(*this);
}
