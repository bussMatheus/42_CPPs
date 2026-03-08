#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "./AAnimal.hpp"
# include "./Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain	*brain;
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();

	void			makeSound() const;
	std::string		getBrainIdea(int i) const;
	void			setBrainIdea(int i, const std::string &idea);
};


#endif