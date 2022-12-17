#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char** argv)
{
	std::string filename = argv[1];
	std::ifstream file(filename);
	std::string line;

	int fully = 0;
	int overlap = 0;

	while(!file.eof())
	{
		
		// break if next line doesn't start with digit
		if(!std::isdigit(file.peek()))
		{
			break;
		}
		// Get a line
		std::getline(file, line);	

		// Split line into two (by ',')
		std::string elf1, elf2;
		size_t spl = line.find(',');
		elf1 = line.substr(0, spl);
		elf2 = line.substr(spl + 1);
		
		// if (split1[0] > split2[0] && split1[1] < split2[1]) and vice versa
		size_t elf1Spl = elf1.find('-');
		size_t elf2Spl = elf2.find('-');

		int elf1val1 = std::stoi(elf1.substr(0, elf1Spl));
		int	elf1val2 = std::stoi(elf1.substr(elf1Spl + 1));

		int elf2val1 = std::stoi(elf2.substr(0, elf2Spl));
		int elf2val2 = std::stoi(elf2.substr(elf2Spl + 1));

		
		if((elf1val1 >= elf2val1 && elf1val2 <= elf2val2) ||
			(elf2val1 >= elf1val1 && elf2val2 <= elf1val2))
		{
			fully++;
		}

		for(int i = elf1val1; i <= elf1val2; i++)
		{
			for(int j = elf2val1; j <= elf2val2; j++)
			{
				if(i == j)
				{
					overlap++;
					i = elf1val2;
					j = elf2val2;
				}
			}
		}
	}
	std::cout << "Total fully contained sections: " << fully << std::endl;
	std::cout << "Total overlapping sections: " << overlap  << std::endl;
	return 0;
}
