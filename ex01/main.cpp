#include "Serializer.hpp"
#include "Log.hpp"

int	main(void)
{
	//Serializer s;	// -> compile error;

	Data data;
	data.member = 10;
	std::cout << "data address:   " << &data << "\n";

	Log::nl("serialize...", YELLOW);
	uintptr_t raw = Serializer::serialize(&data);
	Log::nl("deserialize...", YELLOW);
	Data *res = Serializer::deserialize(raw);
	std::cout << "result address: " << res << "\n";

	return 0;
}
