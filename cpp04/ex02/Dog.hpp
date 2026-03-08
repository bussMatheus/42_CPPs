#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>
# include "./AAnimal.hpp"
# include "./Brain.hpp"

class Dog : public AAnimal
{
private:
	Brain* brain;
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();

	void			makeSound() const;
	std::string		getBrainIdea(int i) const;
	void			setBrainIdea(int i, const std::string &idea);
};


#endif