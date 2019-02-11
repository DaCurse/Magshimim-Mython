#include "List.h"

List::List(std::vector<Type> value) : _value(value)
{

}

List::~List()
{
}

const bool List::isPrintable()
{
	return true;
}

const std::string List::toString()
{
	std::string list_str = "[";
	int i = 0;

	for (Type & item : _value)
	{
		if (item.isPrintable())
		{
			list_str += item.toString();
			if (i < _value.size() - 1)
			{
				list_str += ", ";
			}
		}
		i++;
	}

	return list_str + "]";

}

std::unique_ptr<Type> List::clone()
{
	return std::make_unique<List>(*this);
}
