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

// std::string	isChar(std::string input)
// {
// 	int i = 0;
// 	i = std::stoi(input);
// 	try{
// 		i = std::stoi(input);
// 	}
// 	catch (const std::invalid_argument &e){
// 		return ("Invalid input");
// 	}
// 	catch (const std::out_of_range &e){
// 		return ("Out of range");
// 	}
// 	char c = static_cast<char>(i);
// 	if (std::isprint(c))
// 		return (std::string("'") + c + std::string("'"));
// 	else
// 		return ("Non displayable");
// }

std::string isChar(std::string input)
{
    // 如果输入只有一个字符，且是可打印的字符，直接返回该字符
    if (input.size() == 1 && std::isprint(input[0]) && !isdigit(input[0]))
        return std::string("'") + input[0] + std::string("'");
    
    // 对于整数转换为字符的情况
    try {
        int i = std::stoi(input);
        char c = static_cast<char>(i);
        if (std::isprint(c))
            return std::string("'") + c + std::string("'");
        else
            return "Non displayable";
    }
    catch (const std::invalid_argument&) {
        return "Invalid input";
    }
    catch (const std::out_of_range&) {
        return "Out of range";
    }
}

std::string	isInt(std::string input)
{
	try{
		int num = std::stoi(input);
		return (std::to_string(num));
	}catch (const std::invalid_argument&) {
        return "Invalid input";
    }
    catch (const std::out_of_range&) {
        return "Out of range";
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

void ScalarConverter::convert(std::string input)
{
    try {
        // 如果输入是单个可打印字符
        if (input.size() == 1 && !isdigit(input[0]) && std::isprint(input[0]))
        {
            char c = input[0];
            std::cout << "char: " << isChar(input) << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(c) << std::endl;
            return;
        }
        else {
            size_t idx;
            std::stof(input, &idx);
            if ((idx != input.length() && idx != input.length() - 1)
                || (idx == input.length() - 1 && input[idx] != 'f' && input[idx] != 'F'))
            {
                std::cout << "This is not a valid input" << std::endl;
                return;
            }
        }
    }
    catch (const std::exception& e) {
        std::cout << "This is not a valid input" << std::endl;
        return;
    }

    // 检查特殊输入
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

    // 输出转换结果
    std::cout << "char: " << isChar(input) << std::endl;
    std::cout << "int: " << isInt(input) << std::endl;
    std::cout << "float: " << isFloat(input) << std::endl;
    std::cout << "double: " << isDouble(input) << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */