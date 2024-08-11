#include "Utils.hpp"

bool	isDegit(const char c)
{
	return ('0' <= c && c <= '9');
}

bool	isChar(const std::string &literal)
{
	if (literal.size() != 1)
		return false;
	char c = literal[0];
	return ((33 <= c && c <= 47) || (58 <= c && c <= 126));
}

// -?[1-9][0-9]*^
bool	isInt(const std::string &literal)
{
	if (literal == "0")
		return true;
	std::string::size_type i = 0;
	if (literal[0] == '+' || literal[0] == '-')
		i++;
	if (literal[i] < '1' || '9' < literal[i])
		return false;
	while (i < literal.size())
	{
		if (!isDegit(literal[i++]))
			return false;
	}
	return true;
}

// -?0.[0-9]*f^
// -?[1-9][0-9]*.[0-9]*f^
bool	isFloat(const std::string &literal)
{
	std::string::size_type i = 0;
	if (literal[0] == '+' || literal[0] == '-')
		i++;
	if (literal[i] == '0')
		i++;
	else if ('1' <= literal[i] && literal[i] <= '9')
	{
		while (isDegit(literal[i]))
			i++;
	}
	else
		return false;
	if (literal[i++] != '.')
		return false;
	if (!isDegit(literal[i]))
		return false;
	while (i < literal.size() - 1)
	{
		if (!isDegit(literal[i++]))
			return false;
	}
	return (literal[i] == 'f');
}

bool	isPseudoFloat(const std::string &literal)
{
	return (literal == "-inff" || literal == "+inff" || literal == "nanf");
}

// -?0.[0-9]*^
// -?[1-9][0-9]*.[0-9]*^
bool	isDouble(const std::string &literal)
{
	std::string::size_type i = 0;
	if (literal[0] == '+' || literal[0] == '-')
		i++;
	if (literal[i] == '0')
		i++;
	else if ('1' <= literal[i] && literal[i] <= '9')
	{
		while (isDegit(literal[i]))
			i++;
	}
	else
		return false;
	if (literal[i++] != '.')
		return false;
	if (!isDegit(literal[i]))
		return false;
	while (i < literal.size())
	{
		if (!isDegit(literal[i++]))
			return false;
	}
	return true;
}

bool	isPseudoDouble(const std::string &literal)
{
	return (literal == "-inf" || literal == "+inf" || literal == "nan");
}

bool	isIntRange(const std::string &literal)
{
	try
	{
		std::stoi(literal);
		return true;
	}
	catch (std::out_of_range &e)
	{
		return false;
	}
}

bool	isFloatRange(const std::string &literal)
{
	try
	{
		std::stof(literal);
		return true;
	}
	catch (std::out_of_range &e)
	{
		return false;
	}
}

bool	isDoubleRange(const std::string &literal)
{
	try
	{
		std::stod(literal);
		return true;
	}
	catch (std::out_of_range &e)
	{
		return false;
	}
}

bool	hasDecimals(const float nbr)
{
	return (nbr != std::floor(nbr));
}

bool	hasDecimals(const double nbr)
{
	return (nbr != std::floor(nbr));
}

std::string::size_type	findPrecision(const std::string &literal)
{
	return (literal.find_last_not_of("f") - literal.find_first_not_of("-") + 1);
}
