#include <iostream>
#include <fstream>
#include <string>
#include <queue>

int main()
{
	const std::string filename = "input.txt";
	std::ifstream file(filename);
	std::priority_queue<int> elfCalories;
	std::string line;

	if (!file.is_open())
	{
		std::cerr << "Failed to open \"" << filename << "\"" << std::endl;
		return -1;
	}
	int sum = 0;

	// Read each line until EOF is met
	// Add each elves calories to a priority queue (max)
	while (!file.eof())
	{
		std::getline(file, line);
		sum += std::stoi(line);
		
		// When next line starts with \n it's presumed to be empty
		if (file.peek() == '\n' || file.peek() == EOF)
		{
			elfCalories.push(sum);
			sum = 0;
			std::getline(file, line); // remove '\n'
		}
	}

	int largest = elfCalories.top();
	std::cout << "Largest total of calories: " << largest << std::endl; 
	
	int top3sum = 0;
	for (size_t i = 0; i < 3; i++)
	{
		top3sum += elfCalories.top();
		elfCalories.pop();
	}
	
	std::cout << "Top three elves' calories summed: " << top3sum <<std::endl;
	return 0;
}