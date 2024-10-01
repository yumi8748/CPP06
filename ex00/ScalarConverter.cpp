#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &				ScalarConverter::operator=( ScalarConverter const & rhs )
{
	if ( this != &rhs )
		return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	isChar(std::string input)
{

}

std::string	isInt(std::string input)
{

}

std::string	isFloat(std::string input)
{

}

std::string	isDouble(std::string input)
{

}

void	ScalarConverter::convert(std::string input)
{
	size_t	idx = 0;
	try
	{
		std::stof(input, &idx); //Pointer to an object of type size_t, whose value is set by the function to position of the next character in str after the numerical value. This parameter can also be a null pointer, in which case it is not used.
	}
	catch(const std::exception& e)
	{
		std::cout << "This is not a valid input" << std::endl;
        return;
	}

	if ((idx != input.length() || idx != input.length() - 1)
			|| (idx == input.length() - 1 && input[idx] != 'f' && input[idx] != 'F'))
	{
		std::cout << "This is not a valid input" << std::endl;
        return;
	}
	//check below print session, should create other functions?
	if (input == "nan" || input == "nanf"
        || input == "inf" || input == "inff"
        || input == "+inf" || input == "+inff"
        || input == "-inf" || input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
		if (input == "nanf" || input == "inff" || input == "+inff" || input == "-inff")
        {
            std::cout << "float: " << input << std::endl;
            std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
        }
        else
        {
            std::cout << "float: " << input << "f" << std::endl;
            std::cout << "double: " << input << std::endl;
        }
        return; 
	}
	
	std::cout << "char: " << isChar(input) << std::endl;
	std::cout << "int: " << isInt(input) << std::endl;
	std::cout << "float: " << isFloat(input)<< std::endl;
	std::cout << "double: " << isDouble(input)<< std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */