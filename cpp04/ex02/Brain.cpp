#include "./Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called\n";
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called\n";
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain assignment operator called\n";
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called\n";
}

void    Brain::setIdea(int i, const std::string &idea)
{
    if (i < 0 || i >= 100)
    {
        std::cout << "Invalid idea index!" << std::endl;
        return ;
    }
    ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
    if (i < 0 || i >= 100)
    {
        std::cout << "Invalid idea index!" << std::endl;
        return "";
    }
    return ideas[i];
}