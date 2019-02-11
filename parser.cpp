#include "parser.h"

std::unordered_map<std::string, Type*> Parser::_variables = {};

Type* Parser::parseString(std::string str) throw()
{
	if (str[0] == ' ' || str[0] == '\t')
	{
		throw IndentationException();
	}
	if (str.length() > 0)
	{
		Helper::rtrim(str);

		if (isLegalVarName(str))
		{
			Type* type = getVariableValue(str);

			if (type == NULL)
			{
				throw NameErrorException(str);
			}
			else
			{
				return type;
			}

		}

		Type* type = getType(str);

		if (type == NULL)
		{
			if (makeAssignment(str))
			{
				Void* vptr = new Void();
				vptr->setTemp(true);
				return vptr;
			}
			else
			{
				throw SyntaxException();
			}
		}
		if (type->isPrintable())
		{
			std::cout << type->toString() << std::endl;
		}
		if (type->isTemp())
		{
			delete[] type;
		}
	}

	return NULL;
}

Type * Parser::getType(std::string & str)
{
	Type* type;
	Helper::trim(str);

	/*const std::regex int_exp("-?[0-9]+");
	const std::regex bool_exp("true|false");
	const std::regex str_exp("'([^']+)?'|\"([^\"]+)?\"");*/
	const std::regex list_exp("\[((-?[0-9]+|True|False|'([^']+)?'|\"([^\"]+)?\"),?)*\]");

	if (Helper::isInteger(str))
	{
		Helper::removeLeadingZeros(str);
		type = new Integer(atoi(str.c_str()));
	}
	else if (Helper::isBoolean(str))
	{
		type = new Boolean((str == "True"));
	}
	else if (Helper::isString(str))
	{
		str[0] = '\'';
		str[str.length() - 1] = '\'';
		type = new String(str);
	}
	else if (std::regex_match(str, list_exp))
	{

	}
	else
	{
		type = NULL;
	}

	if(type != NULL) type->setTemp(true);

	return type;
}

bool Parser::isLegalVarName(const std::string & str)
{
	const std::regex varname_regex("[a-zA-Z_][a-zA-Z_0-9]*");
	return std::regex_match(str, varname_regex);
}

bool Parser::makeAssignment(const std::string & str)
{
	const std::regex ass_regex("[^=]+=[^=]+");

	if (std::regex_match(str, ass_regex))
	{
		std::string tokenl = str.substr(0, str.find("="));
		std::string tokenr = str.substr(str.find("=") + 1, str.length() - 1);

		tokenl.erase(remove_if(tokenl.begin(), tokenl.end(), isspace), tokenl.end());
		tokenr.erase(remove_if(tokenr.begin(), tokenr.end(), isspace), tokenr.end());

		if (!isLegalVarName(tokenl))
		{
			throw SyntaxException();
		}

		Type* type;

		if (isLegalVarName(tokenr))
		{
			Type* copy_type = getVariableValue(tokenr);

			if (copy_type == NULL)
			{
				throw NameErrorException(tokenr);
			}

			type = copy_type->clone().release();
			
		}
		else
		{
			type = getType(tokenr);
		}

		if (type == NULL)
		{
			throw SyntaxException();
		}

		auto map_it = _variables.find(tokenl);
		
		if (map_it != _variables.end())
		{
			map_it->second = type;
		}
		else
		{
			_variables.insert(std::pair<std::string, Type*>(tokenl, type));
		}

		return true;
	}

	return false;
}

Type * Parser::getVariableValue(const std::string & str)
{
	auto var_it = _variables.find(str);

	if (var_it != _variables.end())
	{
		return var_it->second;
	}
	else
	{
		return NULL;
	}
}

void Parser::freeVariables()
{
	for (auto map_it = _variables.begin(); map_it != _variables.end(); map_it++)
	{
		delete[] map_it->second;
	}
}


