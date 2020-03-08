#pragma once
#include <fstream>
#include <iostream>

void OpenFile(std::string fileName)
{
	std::ifstream file(fileName);
	if (!file)
	{
		std::cout << "nie ma takiego pliku!!!";
		return;
	}
	file.close();
}