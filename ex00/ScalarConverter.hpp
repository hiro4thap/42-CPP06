#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "Utils.hpp"
# include <iostream>
# include <iomanip>

class	ScalarConverter
{
public:
	static void	convert(const std::string &literal);

private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &rhs);
	ScalarConverter operator=(const ScalarConverter &rhs);
};

#endif
