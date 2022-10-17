#pragma once
#ifndef __OPEN_COMMAND_H__
#define __OPEN_COMMAND_H__
#include"../../Command/command/command.h"
#include"../application/application.h"
#include<string>
#include<iostream>

class OpenCommand : public Command {
private:
	Application* _app;
public:
	OpenCommand(Application* app) :_app(app) {}
	void execute();
protected:
	std::string askUser();
};

#endif // !__OPEN_COMMAND_H__
