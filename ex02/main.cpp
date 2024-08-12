#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Type.hpp"
#include "Log.hpp"

int	main()
{
	std::srand(std::time(nullptr));
	for (int i = 0; i < 5; i++)
	{
		Log::nl();
		Base *base = generate();
		identity(base);
		identity(*base);
	}
}
