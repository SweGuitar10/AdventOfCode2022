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
	int prio = 1;

	// setup priority values
	for (char c = 'a'; c <= 'z'; c++) 
	{
		letters.push_back(c);
		prio++;
	}

	for (char c = 'A'; c <= 'Z'; c++) 
	{
		letters.push_back(c);
		prio++;
	}

	while(!file.eof())
	{
		std::string line;
		std::getline(file, line);

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
	}

	// Sum priority of items
	int sum = 0;
	for (int i = 0; i < items.size(); i++) 
	{
		char c = items[i];
		int in = std::distance(letters.begin(), std::find(letters.begin(), 
					letters.end(), c)) + 1;
		sum += in;
	}

	std::cout << "Sum of unique items: " << sum << std::endl;
}
