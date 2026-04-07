#include <string>
#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Expected input: ./sed <filename> <s1> <s2>" << std::endl;
		return -1;
	}
	std::string line;
	std::ifstream infile(av[1]);
	if (!infile.is_open())
		return -1;
	std::ofstream outfile(std::string(av[1]) + ".replace");
	std::string s1 = av[2];
	if (s1 == "")
	{
		std::cout << "Error: s1 is empty" << std::endl;
		return -1;
	}
	std::string s2 = av[3];
	while (std::getline(infile, line))
	{
		size_t pos = line.find(s1);
		while (pos != std::string::npos)
		{
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos = line.find(s1, pos + s2.length());
		}
		outfile << line << std::endl;
	}
}