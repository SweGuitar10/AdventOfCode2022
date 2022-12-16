#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::ifstream file("input.txt");
	std::vector<char> items;
	std::vector<char> letters;
	std::vector<char> badges;

	// setup priority values
	for (char c = 'a'; c <= 'z'; c++) 
	{
		letters.push_back(c);
	}

	for (char c = 'A'; c <= 'Z'; c++) 
	{
		letters.push_back(c);
	}

	while(!file.eof())
	{
		std::vector<std::string> group;

		for(int i = 0; i < 3; i++)
		{
			std::string line;
			std::getline(file, line);
			group.push_back(line);
			std::cout << line << std::endl;
		}
/*
		std::string comp1,comp2;
		int middle = line.size() / 2;
		comp1 = line.substr(0, middle);
		comp2 = line.substr(middle);
		char item = ' ';

		for(int i = 0; i < comp1.size(); i++)
		{
			for(int j = 0; j < comp2.size(); j++)
			{
				if(comp1[i] == comp2[j])
				{
					item = comp1[i];
					items.push_back(item);
					i = comp1.size();
					j = comp2.size();
				}
			}
		}
*/
		std::string elf1 = group[0], elf2 = group[1], elf3 = group[2];
		int i, j, k;
		for(i = 0; i < elf1.size(); i++)
		{
			for(j = 0; j < elf2.size() && elf1[i] != elf2[j]; j++);

			for(k = 0; k < elf3.size() && elf1[i] != elf3[k]; k++);
			
			if(elf1[i] == elf2[j] && elf1[i] == elf3[k])
			{
				std::cout << "Badge: " << elf1[i] << std::endl;
				badges.push_back(elf1[i]);
				i = elf1.size();
			}
		}
	}

	// Sum priority of items
	int sum = 0;
	for (int i = 0; i < badges.size(); i++) 
	{
		char c = badges[i];
		int in = std::distance(letters.begin(), std::find(letters.begin(), 
					letters.end(), c)) + 1;
		sum += in;
	}

	std::cout << "Sum of unique items: " << sum << std::endl;
}
