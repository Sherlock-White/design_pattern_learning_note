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

MyView::MyView(MyDoc* myDoc) {
	_subject = myDoc;
	_subject->attach(this);
}

void MyView::update() {
	std::cout << "MyView::update() data=" << _subject->getState() << std::endl;
}