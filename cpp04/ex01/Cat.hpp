#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "./Animal.hpp"
# include "./Brain.hpp"

class Cat : public Animal
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