#include "image.h"
#include <iostream>
#include <vector>


int main()
{
	igg::Image test;
	test.print_CR();
	std::cout << "cols : " << test.Cols() << std::endl;
	std::cout << "rows : " << test.Rows() << std::endl;
	bool filling_State = false;
	filling_State = test.FillFromPgm("/home/aimane/cpp_ws/homework.data/igg_image/data/lena.ascii.pgm");
	std::cout << "filling_State : " << filling_State << std::endl;
	std::cout << "cols : " << test.Cols() << std::endl;
	std::cout << "rows : " << test.Rows() << std::endl;
	test.WriteToPgm("/home/aimane/cpp_ws/homework.data/igg_image/data/test.ascii.pgm");

	std::vector<float> histo = test.ComputeHistogram(2);

	// test.PrintData();

	for (int i = 0; i < histo.size() ;i++)
	{
		std::cout << histo[i] <<  " "  << std::endl; 
	}

    return 0;
}