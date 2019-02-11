#ifndef PARSER_H
#define PARSER_H

#include "stdafx.h"
#include <unordered_map>
#include <sstream>
#include <regex>

class Parser
{
public:
	static Type* parseString(std::string str) throw();
	static Type* getType(std::string &str);
	static void freeVariables();

private:
	static bool isLegalVarName(const std::string& str);
	static bool makeAssignment(const std::string& str) throw();
	static Type* getVariableValue(const std::string &str);


	static std::unordered_map<std::string, Type*> _variables;


};

#endif //PARSER_H
