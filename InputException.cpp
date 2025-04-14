#include "InputException.h"

InputException::InputException(std::string msg) : message(msg) {}

std::string InputException::what() {
	return this->message;
}
