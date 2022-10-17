#pragma once
#ifndef __PASTE_COMMAND_H__
#define __PASTE_COMMAND_H__
#include"command.h"
#include"document.h"

class PasteCommand :public Command {
private:
	Document* _doc;
public:
	PasteCommand(Document* doc) :_doc(doc) {}
	void execute();
};

#endif // !__PASTE_COMMAND_H__
