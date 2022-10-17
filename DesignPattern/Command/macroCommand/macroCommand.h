#pragma once
#include"../command/command.h"
#include<list>

#ifndef __MACRO_COMMAND_H__
#define __MACRO_COMMAND_H__

class MacroCommand : public Command {
private:
	//container
	std::list<Command*> _cmds;
public:
	virtual void add(Command* c);
	virtual void remove(Command* c);
	virtual void execute();
	/*virtual void execute(std::initializer_list<int> inizer);
	[¡ü if you want to pass some parameters,write just like this.]*/
};

#endif