#pragma once
#ifndef __PASTE_COMMAND_H__
#define __PASTE_COMMAND_H__
#include"../../Command/command/command.h"
#include"../document/document.h"

class PasteCommand :public Command {
private:
	Document* _doc;
public:
	PasteCommand(Document* doc) :_doc(doc) {}
	void execute();
};

#endif // !__PASTE_COMMAND_H__
