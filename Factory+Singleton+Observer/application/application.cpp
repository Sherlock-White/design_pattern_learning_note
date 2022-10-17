#include"application.h"

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