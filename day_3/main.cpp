#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	std::ifstream file("test_input.txt");
	std::vector<char> items;
	
	// setup priority values
	

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
}

