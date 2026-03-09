#include <cstdlib>
#include <ctime>
#include <experimental/random>
#include <iostream>


int main(){
	bool solved = false;
	std::srand(std::time({}));
	int gues_from_pc = std::experimental::randint(0, 9);

	while (! solved)
	{
		

		std::cout << "guess a number :";
		int gues_from_usr;
		std::cin >> gues_from_usr ;
		if (gues_from_usr == gues_from_pc)
		{
			solved = true;
			std::cout << "you win" << std::endl;
		}
		else if (gues_from_usr >= gues_from_pc)
		{
			std::cout << "try a smaller one" << std::endl;
		}
		else 
		{
			std::cout << "try a bigger one" << std::endl;
		}

	}


	
}