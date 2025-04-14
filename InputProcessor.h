#pragma once
#include <iostream>
#include <list>

class InputProcessor
{
public:
	std::list<std::string> GetInputs();
	std::string GetInput();
};

