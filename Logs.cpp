#include <iostream>
#include "InputProcessor.h"
#include "FileProcessor.h"

int main()
{
	try
	{
		std::cout << "Hello World!\n";

		InputProcessor ip;
		FileProcessor fp;

		std::string input = ip.GetInput();

		if (input.find("read log: ") != std::string::npos) {
			size_t pos = input.rfind(' ') + 1;
			
			std::string filepath = input.substr(pos) + ".txt";

			for (auto& line : fp.ReadFile(filepath)) {
				std::cout << line;
			}
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what();
	}
}
