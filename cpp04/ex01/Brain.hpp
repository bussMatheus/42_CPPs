#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
private:
	std::string	ideas[100];
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	void	setIdea(int i, const std::string &idea);
	std::string	getIdea(int i) const;
};

// the use of const std::string &idea is much more
// efficient than just std::string idea, as it makes
// only one copy happens when assigning to ideas[i]

#endif