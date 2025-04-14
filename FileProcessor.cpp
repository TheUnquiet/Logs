#include "FileProcessor.h"
#include "FileException.h"
#include <fstream>
#include <string>

std::string FileProcessor::GetFilePath() {
	return FileProcessor::filePath;
}

void FileProcessor::SetFilePath(std::string filePath) {
	if (filePath.empty()) {
		throw FileException("filePath must be fill");
	}
	this->filePath = filePath;
}

void FileProcessor::WriteFile(std::list<std::string> lines) {
	try {
		std::ofstream file(this->filePath + "log 1.txt");

		if (file.is_open()) {

			for (auto& line : lines) {
				file << line;
			}

			file.close();
		}
		else throw FileException("Unable to open file.");
	}
	catch (FileException& ex) {
		std::cerr << ex.what();
	}
}

std::list<std::string>  FileProcessor::ReadFile(std::string fileName) {
	try
	{
		std::string line;
		std::list<std::string> lines;
		std::ifstream file(this->filePath + fileName);

		if (file.is_open()) {
			while (std::getline(file, line))
			{
				lines.push_back(line);
			}
			file.close();
		}
		else throw FileException("Unable to open file.");

		return lines;
	}
	catch (FileException& ex)
	{
		std::cerr << ex.what();
	}
}