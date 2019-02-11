#ifndef LIST_H
#define LIST_H
#include "Sequence.h"
#include <vector>

class List : public Sequence
{
public:
	List(std::vector<Type> value);
	virtual ~List();
	virtual const bool isPrintable();
	virtual const std::string toString();
	virtual std::unique_ptr<Type> clone();

private:
	std::vector<Type> _value;
};

#endif // LIST_H