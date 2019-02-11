#ifndef TYPE_H
#define TYPE_H
#include <iostream>
#include <string>

class Type
{
public:
	bool isTemp() const;
	void setTemp(const bool isTemp);
	virtual const bool isPrintable() = 0;
	virtual const std::string toString() = 0;
	virtual std::unique_ptr<Type> clone() const = 0;

private:
	bool _isTemp = false;

};

#endif //TYPE_H
