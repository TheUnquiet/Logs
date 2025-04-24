#include "FileProcessor.h"
#include "FileException.h"

#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

std::string& FileProcessor::GetFilePath() {
	return FileProcessor::filePath;
}

void FileProcessor::SetFilePath(std::string filePath) {
	if (filePath.empty()) {
		throw FileException("filePath must be fill");
	}
	this->filePath = filePath;
}

void FileProcessor::WriteFile(std::list<std::string>& lines) {
	try {
		std::time_t t = std::time(nullptr);
		std::tm tm{};

		localtime_s(&tm, &t);

		std::ostringstream oss;
		oss << std::put_time(&tm, "%Y-%m-%d");
		std::string dateStr = oss.str();
		std::ofstream file(this->filePath + dateStr + ".txt");

		if (file.is_open()) {
			file << "LOGDATE: [" + dateStr + "]\n";
			file << "FASET: [ 5 ]\n\n";
			for (auto& line : lines) {
				file << line;
			}

			file.close();

			// TODO: copy the command to the clip board
			std::cout << ">> File Saved\n" << "Run this command to read the file: read log: " << dateStr << "\n";
		}
		else throw FileException("Unable to open file.");
	}
	catch (FileException& ex) {
		std::cerr << ex.what();
	}
}

std::list<std::string> FileProcessor::ReadFile(std::string fileName) {
	try
	{
		std::string line;
		std::list<std::string> lines;
		std::ifstream file(this->filePath + fileName);

		if (file.is_open()) {
			while (std::getline(file, line))
			{
				lines.push_back(line + "\n");
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