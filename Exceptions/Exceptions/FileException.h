#pragma once
#include <iostream>
#include <exception>
#include <string>

class FileException : public std::runtime_error
{
public:
	FileException(std::string fileName) : std::runtime_error("Can't open file: " + fileName)
	{
	}
};