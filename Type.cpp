#include "type.h"

bool Type::isTemp() const
{
	return _isTemp;
}

void Type::setTemp(const bool isTemp)
{
	_isTemp = isTemp;
}
