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

ScalarConverter &	ScalarConverter::operator=( ScalarConverter const & rhs )
{
	if ( this != &rhs ){}
		return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	isChar(std::string input)
{
	int i = 0;
	i = std::stoi(input);
	try{
		i = std::stoi(input);
	}
	catch (const std::invalid_argument &e){
		return ("Invalid input");
	}
	catch (const std::out_of_range &e){
		return ("Out of range");
	}
	char c = static_cast<char>(i);
	if (std::isprint(c))
		return (std::string("'") + c + std::string("'"));
	else
		return ("Non displayable");
}

std::string	isInt(std::string input)
{
	try{
		int num = std::stoi(input);
		return (std::to_string(num));
	}catch (...){
		return ("impossible");
	}
}

std::string	isFloat(std::string input)
{
	try{
		float f = std::stof(input);
		return (std::to_string(f).substr(0, std::to_string(f).find('.') + 2) + "f");
	}catch(...){
		return ("nanf");
	}
}

std::string	isDouble(std::string input)
{
	try{
		double d = std::stod(input);
		return (std::to_string(d).substr(0, std::to_string(d).find('.') + 2));
	}catch(...){
		return ("nan");
	}
}

void	ScalarConverter::convert(std::string input)
{
	try
	{
		size_t	idx;
		std::stof(input, &idx); //Pointer to an object of type size_t, whose value is set by the function to position of the next character in str after the numerical value. This parameter can also be a null pointer, in which case it is not used.
		if ((idx != input.length() && idx != input.length() - 1)
			|| (idx == input.length() - 1 && input[idx] != 'f' && input[idx] != 'F'))
		{
			std::cout<< "This is not a valid input"<< std::endl;
			return ;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "This is not a valid input" << std::endl;
        return;
	}
	// check below print session, should create other functions?
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