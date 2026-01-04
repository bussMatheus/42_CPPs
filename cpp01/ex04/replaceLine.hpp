#ifndef REPLACELINE_HPP
# define REPLACELINE_HPP

# include <string>
# include <iostream>
# include <fstream>

int		checkArgs(int ac, char **av);
void	replaceLine(std::string &line, const std::string s1, const std::string &s2);

#endif