#include "./replaceLine.hpp"

int		checkArgs(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Error: Invalid number of arguments." << std::endl;
		return (1);
	}
	std::ifstream file(av[1]);
	if (file.fail())
	{
		std::cout << "Error: Can't open file." << std::endl;
		return (1);
	}
	if (std::string(av[2]).empty() || std::string(av[3]).empty())
	{
		std::cout << "Error: Empty string." << std::endl;
		return (1);
	}
	return (0);
}

void	replaceLine(std::string &line, const std::string s1, const std::string &s2)
{
	std::string::size_type pos = 0;

	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
}
