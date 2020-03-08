#pragma once
#include <fstream>
#include <iostream>
#include "FileException.h"

void OpenFile(std::string fileName)
{
	std::ifstream file(fileName);
	if (!file)
	{
		throw FileException(fileName);
	}
	file.close();
}