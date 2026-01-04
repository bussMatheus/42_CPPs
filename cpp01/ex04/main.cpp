#include "./replaceLine.hpp"

int	main(int argc, char **argv){
	if (checkArgs(argc, argv))
		return (1);
	std::ifstream	infile(argv[1]);
	std::ofstream	outfile((std::string(argv[1]) + ".replace").c_str());

	std::string	line;
	std::string	s1(argv[2]);
	std::string	s2(argv[3]);

	while (std::getline(infile, line))
	{
		replaceLine(line, s1, s2);
		outfile << line;
		if (!infile.eof())
			outfile << std::endl;
	}
	return (0);
}