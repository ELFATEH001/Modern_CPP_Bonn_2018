#include <iostream>
#include "tool.h"

int main(int argc, char const *argv[])
{
	Print_Hello();
	int num =  Return_Num(5);
	std::cout<<"the retned num is: "<< num << std::endl;
	return 0;
}