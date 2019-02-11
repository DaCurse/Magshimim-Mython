#include "type.h"
#include "InterperterException.h"
#include "parser.h"
#include <iostream>

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "Daniel"


int main(int argc,char **argv)
{
	std::cout << WELCOME << YOUR_NAME << std::endl;

	std::string input_string;

	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);
	
	while (input_string != "quit()")
	{
		// prasing command
		try
		{
			Type* type = Parser::parseString(input_string);
			if (type != NULL  && type->isPrintable())
			{
				std::cout << type->toString() << std::endl;
			}
		}
		catch (InterperterException & ex)
		{
			std::cout << ex.what() << std::endl;
		}

		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}

	Parser::freeVariables();
	return 0;
}


