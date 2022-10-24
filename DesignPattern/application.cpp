#include"application.h"

Document* MyApp::createDocument(std::string& name) {
	std::cout << "MyApp::createDocument()\n";
	return new MyDoc(name);
}

void MyDoc::Serialize() {
	std::cout << "MyDoc::serialize()\n";
}

void MyDoc::changeData() {
	_subjectState *= 5;
	dataChanged();
	notify();
}

int MyDoc::getState() {
	return _subjectState;
}

void MyDoc::setState(int i) {
	_subjectState = i;
}

View* MyDoc::getLastView() {
	return _views.back();
}

void MyView::update() {
	std::cout << "MyView::update() data=" << _subject->getState() << std::endl;
}