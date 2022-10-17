#pragma once
#include<iostream>

#ifndef __COMMAND_H__
#define __COMMAND_H__
class Command {
public:
	virtual ~Command();
	//define pure virtual function here.
	virtual void execute() = 0;
	/* virtual void execute(std::initializer_list<int>) = 0;
	[¡ü if you want to pass some parameters,write just like this.] */
protected:
	Command();
};
#endif // !__COMMAND_H__