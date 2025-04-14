#include "InputProcessor.h"
#include <string>
#include <list>
#include "InputException.h"

std::string InputProcessor::GetInput() {
	std::string input;

	std::cout << ">> ";
	std::getline(std::cin, input);

	return input;
}

std::list<std::string> InputProcessor::GetInputs() {
	try
	{
		std::list<std::string> lines;
		std::string input = GetInput();

		while (input != "Faset 5" || input != "faset 5" || input != "peridot, faset 5")
		{
			lines.push_back(input);
		}

		return lines;
	}
	catch (InputException& ex)
	{
		std::cerr << ex.what();
	}
}