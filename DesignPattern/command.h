#pragma once
#include<iostream>
#include<list>

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

template<class Receiver>
class SimpleCommand : public Command {
public:
	//Attention: declare the type before using
	typedef void (Receiver::* Action)();
	/*typedef void (Receiver::* Action)(std::initializer_list<int>);
	[¡ü if you want to pass some parameters,write just like this.]*/
	SimpleCommand(Receiver* r, Action a) :_receiver(r), _action(a) {}
	//Attention: if you wannt to override the function,declare it in derived class
	void execute() override;
	/*void execute(std::initializer_list<int>) override;
	[¡ü if you want to pass some parameters,write just like this.]*/
private:
	Action _action;
	Receiver* _receiver;
};

//Attention: define this function it in head file
//because this function is template function
//C++ compiler must make sure declare the template before use
//so we need to define it in head file
template<class Receiver>
void SimpleCommand<Receiver> ::execute() {
	//because the Action type is equal to Receiver::*,which is a pointer
	//so we dereference the pointer here,and let the object call the function
	(_receiver->*_action)();
}
/*template<class Receiver>
void SimpleCommand<Receiver> ::execute(std::initializer_list<int> inizer) {
	(_receiver->*_action)(inizer);
}
[¡ü if you want to pass some parameters,write just like this.]*/

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

#endif // !__COMMAND_H__