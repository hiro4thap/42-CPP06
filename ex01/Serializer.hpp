#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

struct Data
{
	int member;
};

class	Serializer
{
public:
	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);

private:
	Serializer();
	~Serializer();
	Serializer(const Serializer &rhs);
	Serializer &operator=(const Serializer &rhs);
};

#endif
