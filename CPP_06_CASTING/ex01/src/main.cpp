#include "Data.hpp"
#include "Serializer.hpp"

int	main()
{
	std::cout << "Initializing a Data struct and its data members, ";
	Data	data;
	data.id = 5;
	data.content = "Hello";
	Data*	pData = &data;
	std::cout << "with a pointer to Data at address " << pData << std::endl;


	std::cout << "Serializing the pointer to Data." << std::endl;
	uintptr_t	raw = Serializer::serialize(pData);
	std::cout << "Its value is " << raw << " or in hex ";
	std::cout << std::hex << raw << std::dec << std::endl;


	std::cout << "Deserializing the pointer to Data into a new variable." << std::endl;
	Data*		unserializedPData = Serializer::deserialize(raw);
	std::cout << "Its value is " << unserializedPData << std::endl;

	std::cout << "Of course the deserialized pointer can still access the content: ";
	std::cout << "[" << unserializedPData->content << "]" << std::endl;

	return (0);
}
