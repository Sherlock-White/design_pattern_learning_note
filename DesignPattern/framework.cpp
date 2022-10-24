#include"framework.h"
#include<iostream>

Application::Application() {
	++_counter;
	if (_counter > 1) throw std::exception();
}

void Application::add(Document* doc) {
	_docList.push_back(doc);
}

Document* Application::getLastDoc() {
	return _docList.back();
}

Application::~Application() {
	for (auto doc : _docList) {
		delete doc;
	}
}

//static member variables should be initialized outside
//remember initialize it in cpp file rather than head file
int Application::_counter = 0;

void Document::open() {
	std::cout << "Document::open()\n";
	Serialize();
}

void Document::paste() {
	std::cout << "Document::paste()\n";
}

void Document::Serialize() {
	std::cout << "Document::Serialize()\n";
}

void Document::attach(View* view) {
	_views.push_back(view);
}

void Document::detach(View* view) {
	_views.remove(view);
}

void Document::notify() {
	if (_changed) {
		for (auto x : _views) {
			x->update();
		}
	}
	_changed = false;
}

void Document::dataChanged() {
	_changed = true;
}

void PasteCommand::execute() {
	_doc->paste();
}

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