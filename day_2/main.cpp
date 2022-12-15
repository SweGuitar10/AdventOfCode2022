#include <fstream>
#include <string>
#include <map>
#include <string>
#include <iostream>

#define CHOICES 3

// Rock = 1, Paper = 2, Scissors = 3
// Loss = 0, Draw = 3, Win = 6
// A, X = Rock; B, Y = Paper; C, Z = Scissors

int main()
{
	std::ifstream file("input.txt");
	std::map<char, int> rps;

	rps = {
		{'A', 1},
		{'X', 1},
		{'B', 2},
		{'Y', 2},
		{'C', 3},
		{'Z', 3},
	};
	int sum = 0;
	

	while (!file.eof())
	{
		// Get inputs
		char opponent, outcome;
		file.get(opponent);
		file.get(); // discard empty space
		file.get(outcome);
		file.get(); // discard empty space
		

		// Determine result
		int opVal = rps[opponent], playVal;
		
		// Need loss
		if(outcome == 'X')
		{
			playVal = 1 + (opVal + 4) % 3;	
		}
		// Need draw
		else if(outcome == 'Y')
		{
			playVal = opVal;
		}
		// Need win
		else if(outcome == 'Z')
		{
			playVal = 1 + (opVal + 3) % 3;
		}

		sum += playVal;

		// player wins
		if(playVal % CHOICES == (opVal +1) % CHOICES)
		{
			sum += 6;
		}
		// draw
		else if(playVal == opVal)
		{
			sum += 3;
		}
		// opponent wins, no need to calculate anything.
		/*
		std::cout << "O: " << opponent << " " << opVal << "\t";
		std::cout << "P: " << player << " " << playVal;
		std::cout << std::endl << std::endl;
		std::cout << "Current sum: " << sum <<std::endl;	
		*/
	}
	std::cout << "Total score: " << sum << std::endl;
	return 0;
}
