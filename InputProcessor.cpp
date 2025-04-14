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
		
		while (true)
		{
			std::string input = GetInput();

			lines.push_back(input + "\n");

			if (input == "Faset 5" || input == "faset 5" || input == "peridot, faset 5" || input == "peridot faset 5") break;
		}

		return lines;
	}
	catch (InputException& ex)
	{
		std::cerr << ex.what();
	}
}