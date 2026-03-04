#include "./Animal.hpp"
#include "./Dog.hpp"
#include "./Cat.hpp"
#include "./Brain.hpp"

int main()
{
	int k;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	std::cout << "Array test" << std::endl;

	const	int size = 8;
	Animal*	animals[size];

	for (k = 0; k < size / 2; k++)
		animals[k] = new Dog();
	for (k = size / 2; k < size; k++)
		animals[k] = new Cat();
	for (k = 0; k < size; k++)
		delete animals[k];

	std::cout << "---------------" << std::endl;
	std::cout << "Deep copy testing" << std::endl;

	Dog og;

	og.setBrainIdea(0, "Woffff Wof");

	Dog clone = og;

	og.setBrainIdea(0, "bark");
	std::cout	<< "original idea: "
				<< og.getBrainIdea(0) << std::endl;
	std::cout	<< "clone idea: "
				<< clone.getBrainIdea(0) << std::endl;
	std::cout << "---------------" << std::endl;
	return 0;
}