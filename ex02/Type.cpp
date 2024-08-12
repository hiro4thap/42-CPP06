#include "Type.hpp"
#include "Log.hpp"

Base	*generate(void)
{
	int	mod = rand() % 3;
	Log::out("generate type: ");
	switch(mod)
	{
		case 0:
			Log::nl("A", RED);
			return (new A());
			break ;
		case 1:
			Log::nl("B", CYAN);
			return (new B());
			break ;
		case 2:
			Log::nl("C", YELLOW);
			return (new C());
			break ;
		default:
			Log::nl("None of A or B or C", PURPLE);
			return NULL;
	}
}

void	identity(Base *p)
{
	Log::out("Pointer type identified: ");
	if (dynamic_cast<A*>(p))
		Log::nl("A", RED);
	else if (dynamic_cast<B*>(p))
		Log::nl("B", CYAN);
	else if (dynamic_cast<C*>(p))
		Log::nl("C", YELLOW);
	else
		Log::nl("None of A or B or C", PURPLE);
}

void	identity(Base &p)
{
	Log::out("Reference type identified: ");
	try
	{
		(void)dynamic_cast<A&>(p);
		Log::nl("A", RED);
		return ;
	}
	catch (...)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		Log::nl("B", CYAN);
		return ;
	}
	catch (...)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		Log::nl("C", YELLOW);
		return ;
	}
	catch (...)
	{
	}
	Log::nl("None of A or B or C", PURPLE);
}
