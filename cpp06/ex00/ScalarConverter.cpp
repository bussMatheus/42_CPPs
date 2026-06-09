#include "./ScalarConverter.hpp"
#include <climits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{}

static void	printChar(double value)
{
	if (std::isnan(value) || std::isinf(value)
		|| value < 0 || value > 127)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (!std::isprint(static_cast<char>(value)))
	{		
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

static void	printInt(double value)
{
	if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX)
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void	printFloat(double value)
{
	float	f = static_cast<float>(value);

	std::cout << "float: " << f;
	if(!std::isnan(f) && !std::isinf(f) && f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

static void	printDouble(double value)
{
	std::cout << "double: " << value;
	if (!std::isnan(value) && !std::isinf(value) && value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << std::endl;
}

static size_t	skipSign(const std::string &literal)
{
	if (literal[0] == '+' || literal[0] == '-')
		return (1);
	return (0);
}

static void	convertFromChar(char c)
{
	std::cout << "char: " << "'" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void	convertFromInt(const std::string &literal)
{
	long	longValue;
	double	doubleValue;

	longValue = std::strtol(literal.c_str(), NULL, 10);
	doubleValue = std::strtod(literal.c_str(), NULL);

	if (longValue < INT_MIN || longValue > INT_MAX)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		printFloat(doubleValue);
		printDouble(doubleValue);
		return ;
	}
	printChar(static_cast<double>(longValue));
	std::cout << "int: " << static_cast<int>(longValue) << std::endl;
	printFloat(static_cast<double>(longValue));
	printDouble(static_cast<double>(longValue));
}
static void	convertFromFloat(const std::string &literal)
{
	float	value;

	value = static_cast<float>(std::strtod(literal.c_str(), NULL));
	printChar(static_cast<double>(value));
	printInt(static_cast<double>(value));
	printFloat(static_cast<double>(value));
	printDouble(static_cast<double>(value));
}
static void	convertFromDouble(const std::string &literal)
{
	double	value;

	value = std::strtod(literal.c_str(), NULL);
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

static void	convertFromPseudo(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

static bool	isDoubleLiteral(const std::string &literal)
{
	size_t	i;
	bool	hasDot = false;
	bool	digitAfterDot = false;
	bool	digitBeforeDot = false;

	i = skipSign(literal);
	while (i < literal.length())
	{
		if (std::isdigit(literal[i]))
		{
			if (!hasDot)
				digitBeforeDot = true;
			else
				digitAfterDot = true;
		}
		else if (literal[i] == '.' && !hasDot)
			hasDot = true;
		else
			return (false);
		i++;
	}
	return (hasDot && digitAfterDot && digitBeforeDot);
}

static bool	isFloatLiteral(const std::string &literal)
{
	size_t	i;
	bool	hasDot = false;
	bool	digitBeforeDot = false;
	bool	digitAfterDot = false;

	i = skipSign(literal);
	while (i < literal.length())
	{
		if (std::isdigit(literal[i]))
		{
			if (!hasDot)
				digitBeforeDot = true;
			else
				digitAfterDot = true;
		}
		else if (literal[i] == '.' && !hasDot)
			hasDot = true;
		else if (literal[i] == 'f' && i == literal.length() - 1)
			return (hasDot && digitAfterDot && digitBeforeDot);
		else
			return (false);
		i++;
	}
	return (false);
}

static bool	isCharLiteral(const std::string &literal)
{
	return (literal.length() == 1 && !std::isdigit(literal[0]));
}

static bool	isPseudoLiteral(const std::string &literal)
{
	return (literal == "nan" || literal == "-inf" || literal == "+inf"
			|| literal == "nanf" || literal == "-inff" || literal == "+inff");
}

static bool isIntLiteral(const std::string &literal)
{
	size_t	i;

	i = skipSign(literal);
	while (i < literal.length())
	{
		if (!std::isdigit(literal[i]))
			return (false);
		i++;
	}
	return (true);
}

static e_type	detectType(const std::string &literal)
{
	if (literal.empty())
		return (TYPE_INVALID);
	if (isPseudoLiteral(literal))
		return (TYPE_PSEUDO);
	if (isCharLiteral(literal))
		return (TYPE_CHAR);
	if (isIntLiteral(literal))
		return (TYPE_INT);
	if (isFloatLiteral(literal))
		return (TYPE_FLOAT);
	if (isDoubleLiteral(literal))
		return (TYPE_DOUBLE);
	return (TYPE_INVALID);
}

static void	printInvalid(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void	ScalarConverter::convert(const std::string &literal)
{
	e_type	type;

	type = detectType(literal);
	switch (type)
	{
	case TYPE_CHAR:
		convertFromChar(literal[0]);
		break;
	case TYPE_INT:
		convertFromInt(literal);
		break;
	case TYPE_FLOAT:
		convertFromFloat(literal);
		break;
	case TYPE_DOUBLE:
		convertFromDouble(literal);
		break;
	case TYPE_PSEUDO:
		convertFromPseudo(literal);
		break;
	default:
		printInvalid();
		break;
	}
}