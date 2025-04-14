#pragma once
#include <iostream>
#include <list>

class FileProcessor
{
private:
	std::string filePath = "C:/Logs/";

public:
	std::string GetFilePath();
	void SetFilePath(std::string filePath);
	void WriteFile(std::list<std::string> lines);
	std::list<std::string> ReadFile(std::string fileName);
};

