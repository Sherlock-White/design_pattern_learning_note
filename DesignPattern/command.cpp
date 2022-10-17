#include "command.h"

Command::~Command() {
	std::cout << "Command dtor \n";
}

Command::Command() {
	std::cout << "Command ctor \n";
}

void MacroCommand::add(Command* c) {
	_cmds.push_back(c);
}

void MacroCommand::remove(Command* c) {
	_cmds.remove(c);
}

void MacroCommand::execute() {
	for (auto cp : _cmds) {
		cp->execute();
	}
}
