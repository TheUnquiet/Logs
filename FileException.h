#pragma once
#include <iostream>

class FileException : public std::exception
{
private:
	std::string message;

public:
	FileException(std::string msg);
	std::string what();
};

