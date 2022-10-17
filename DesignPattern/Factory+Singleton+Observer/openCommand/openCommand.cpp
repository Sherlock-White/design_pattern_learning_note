#include"openCommand.h"

void OpenCommand::execute() {
	std::string name = askUser();
	Document* doc = _app->createDocument(name);
	//this is not correct,because we should use the derived class of Document
	//but we cannot write so in the framework,it will cause coupling
	_app->add(doc);
	doc->open();
}

std::string OpenCommand::askUser() {
	std::cout << "OpenCommand::askUser()\n";
	//simplified this case, directly set the document name
	return std::string("test.txt");
}