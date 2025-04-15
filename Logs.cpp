#include <iostream>
#include "InputProcessor.h"
#include "FileProcessor.h"

int main()
{
	try
	{
		// TODO: clean this up!

		InputProcessor ip;
		FileProcessor fp;

		while (true)
		{
			std::string input = ip.GetInput();

			if (input.find("read log: ") != std::string::npos) {
				size_t pos = input.rfind(' ') + 1;

				std::string filepath = input.substr(pos) + ".txt";

				for (auto& line : fp.ReadFile(filepath)) {
					std::cout << line;
				}

				std::cout << "\n";
			}

			if (input.find("write log") != std::string::npos) {
				std::list<std::string> lines = ip.GetInputs();
				fp.WriteFile(lines);
			}

			if (input == "peridot out" || input == "peridot, out") break;
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what();
	}
}
