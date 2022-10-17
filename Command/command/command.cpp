#include "command.h"

Command::~Command() {
	std::cout << "Command dtor \n";
}

Command::Command() {
	std::cout << "Command ctor \n";
}
