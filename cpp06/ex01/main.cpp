#include "./Serializer.hpp"

int main()
{
	Data		data;
	Data		*original;
	Data		*deserialized;
	uintptr_t	raw;
	
	data.name = "Joe";
	data.age = 32;
	data.value = 21.3;

	original = &data;
	raw = Serializer::serialize(original);
	deserialized = Serializer::deserialize(raw);

	std::cout << "Og pointer: " << original << std::endl;
	std::cout << "Serialized uintptr_t: " << raw << std::endl;
	std::cout << "Desserialized pointer: " << deserialized << std::endl;

	std::cout << std::endl;

	if (deserialized == original)
		std::cout << "Success: Pointers are equal!" << std::endl;
	else
		std::cout << "Fail: Pointers are not equal!" << std::endl;

	std::cout << std::endl;

	std::cout << "====Original data====" << std::endl;
	std::cout << "name: " << data.name << std::endl;
	std::cout << "age: " << data.age << std::endl;
	std::cout << "value: " << data.value << std::endl;

	std::cout << "====Deserialized data====" << std::endl;
	std::cout << "name: " << deserialized->name << std::endl;
	std::cout << "age: " << deserialized->age << std::endl;
	std::cout << "value: " << deserialized->value << std::endl;

	return (0);
}
