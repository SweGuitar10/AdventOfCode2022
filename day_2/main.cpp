#include <fstream>
#include <string>
#include <map>
#include <string>

#define CHOICES 3

// Points per choice:
// Rock = 1, Paper = 2, Scissors = 3
// Loss = 0, Draw = 3, Win = 6
// A, X = Rock; B, Y = Paper; C, Z = Scissors

int main()
{
	std::ifstream file("test_input.txt");
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
		char opponent, player;
		file.get(opponent);
		file.get(); // discard empty space
		file.get(player);
	}
}