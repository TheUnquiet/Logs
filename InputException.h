#pragma once
#include <iostream>

class InputException
{
private:
	std::string message;
	
public:
	InputException(std::string msg);
	std::string what();
};

