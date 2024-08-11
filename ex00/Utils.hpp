#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <cmath>

bool	isDegit(const char c);
bool	isChar(const std::string &literal);
bool	isInt(const std::string &literal);
bool	isFloat(const std::string &literal);
bool	isPseudoFloat(const std::string &literal);
bool	isDouble(const std::string &literal);
bool	isPseudoDouble(const std::string &literal);

bool	isIntRange(const std::string &literal);
bool	isFloatRange(const std::string &literal);
bool	isDoubleRange(const std::string &literal);

bool	hasDecimals(const float nbr);
bool	hasDecimals(const double nbr);

std::string::size_type	findPrecision(const std::string &literal);

#endif
