#include <iostream>
#include <vector>
#include "OpenFile.h"

//1
double dziel(double a, double b)
{	
	if (b == 0)
	{
		std::string errorMessage = "You can't divide by 0";
		throw errorMessage;
	}
	return a / b;
}

//4 
void niewyjatkowafunkcja() noexcept
{
	throw "rzucam wyjatek";
}

int main()
{	
	//1
	try
	{
		dziel(5, 2);
	}
	catch (const std::string& err)
	{
		std::cout << err << std::endl;
	}

	//2 (nalezy wykonywac podpunkty pojedynczo, dwa pierwsze podpunkty koncza sie przerwaniem programu
	std::vector<int> wektor(5, 2);
	//2.1
	//std::cout << wektor[5];
	//2.2 
	//std::cout << wektor.at(5);
	//2.3
	try {
		std::cout << wektor.at(5);
	}
	catch (std::out_of_range err)
	{
		std::cout << err.what() << std::endl;
	}

	//3
	try {
		OpenFile("notexistingfile");
	}
	catch (const FileException & err) {
		std::cout << err.what() << std::endl;
	}

	//4 
	niewyjatkowafunkcja();

	//5 
	try {
		OpenFile("notexistingfile");
	}
	catch (const std::runtime_error & err) {
		std::cout << "Pierwszy: " << err.what() << std::endl;;
	}
	catch (const FileException & err) {
		std::cout << "Drugi: " << err.what() << std::endl;;
	}
	
	return 0;
}