#include"macroCommand.h"

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

/*void MacroCommand::execute(std::initializer_list<int> inizer) {
	for (auto cp : _cmds) {
		cp->execute(inizer);
	}
}
[¡ü if you want to pass some parameters,write just like this.]*/