#include "ScalarConverter.hpp"

void	ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
	{
		std::cout << "char:   " << "impossible" << "\n";
		std::cout << "int:    " << "impossible" << "\n";
		std::cout << "float:  " << "impossible" << "\n";
		std::cout << "double: " << "impossible" << "\n";
	}
	else if (isChar(literal))
	{
		char c = literal[0];
		std::cout << "char:   " << c << "\n";
		std::cout << "int:    " << static_cast<int>(c) << "\n";
		std::cout << "float:  " << static_cast<float>(c) << ".0f" << "\n";
		std::cout << "double: " << static_cast<double>(c) << ".0" << "\n";
	}
	else if (isInt(literal) && isIntRange(literal))
	{
		int	i = std::stoi(literal);
		if (32 <= i && i <= 126)
			std::cout << "char:   " << static_cast<char>(i) << "\n";
		else if ((0 <= i && i <= 31) || (127 <= i && i <= 255))
			std::cout << "char:   " << "Non displayable" << "\n";
		else
			std::cout << "char:   " << "impossible" << "\n";
		std::cout << "int:    " << i << "\n";
		std::string::size_type presicion = findPrecision(literal);
		std::cout << "float:  " << std::setprecision(presicion) << static_cast<float>(i) << ".0f" << "\n";
		std::cout << "double: " << std::setprecision(presicion) << static_cast<double>(i) << ".0" << "\n";
	}
	else if (isFloat(literal) && isFloatRange(literal))
	{
		float f = std::stof(literal);
		if (32 <= f && f < 127)
			std::cout << "char:   " << static_cast<char>(f) << "\n";
		else if ((0 <= f && f < 32) || (127 <= f && f < 256))
			std::cout << "char:   " << "Non displayable" << "\n";
		else
			std::cout << "char:   " << "impossible" << "\n";
		if (-2147483649 < f && f < 2147483648)
			std::cout << "int:    " << static_cast<int>(f) << "\n";
		else 
			std::cout << "int:    " << "impossible" << "\n";
		std::string::size_type presicion = findPrecision(literal);
		if (hasDecimals(f))
			std::cout << "float:  " << std::setprecision(presicion) << f << "f" << "\n";
		else
			std::cout << "float:  " << std::setprecision(presicion) << f << ".0f" << "\n";
		double d = static_cast<double>(f);
		if (hasDecimals(d))
			std::cout << "double: " << std::setprecision(presicion) << d << "\n";
		else
			std::cout << "double: " << std::setprecision(presicion) << d << ".0" << "\n";
	}
	else if (isPseudoFloat(literal))
	{
		std::cout << "char:   " << "impossible" << "\n";
		std::cout << "int:    " << "impossible" << "\n";
		std::cout << "float:  " << literal << "\n";
		std::cout << "double: " << literal.substr(0, literal.size() - 1) << "\n";
	}
	else if (isDouble(literal) && isDoubleRange(literal))
	{
		double d = std::stod(literal);
		if (32 <= d && d < 127)
			std::cout << "char:   " << static_cast<char>(d) << "\n";
		else if ((0 <= d && d < 32) || (127 <= d && d < 256))
			std::cout << "char:   " << "Non displayable" << "\n";
		else
			std::cout << "char:   " << "impossible" << "\n";
		if (-2147483649 < d && d < 2147483648)
			std::cout << "int:    " << static_cast<int>(d) << "\n";
		else 
			std::cout << "int:    " << "impossible" << "\n";
		std::string::size_type presicion = findPrecision(literal);
		float f = static_cast<float>(d);
		if (!isFloatRange(literal))
			std::cout << "float:  " << "impossible" << "\n";
		else if (hasDecimals(f))
			std::cout << "float:  " << std::setprecision(presicion) << f << "f" << "\n";
		else
			std::cout << "float:  " << std::setprecision(presicion) << f << ".0f" << "\n";
		if (hasDecimals(d))
			std::cout << "double: " << std::setprecision(presicion) << d << "\n";
		else
			std::cout << "double: " << std::setprecision(presicion) << d << ".0" << "\n";
	}
	else if (isPseudoDouble(literal))
	{
		std::cout << "char:   " << "impossible" << "\n";
		std::cout << "int:    " << "impossible" << "\n";
		std::cout << "float:  " << literal << "f" << "\n";
		std::cout << "double: " << literal << "\n";
	}
	else 
	{
		std::cout << "char:   " << "impossible" << "\n";
		std::cout << "int:    " << "impossible" << "\n";
		std::cout << "float:  " << "impossible" << "\n";
		std::cout << "double: " << "impossible" << "\n";
	}
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs)
{
	(void)rhs;
}

ScalarConverter ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return *this;
}

