#include "commandPattern.h"

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
