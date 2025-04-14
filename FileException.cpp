#include "FileException.h"

FileException::FileException(std::string msg) : message(msg) {}

std::string FileException::what() {
	return this->message;
}