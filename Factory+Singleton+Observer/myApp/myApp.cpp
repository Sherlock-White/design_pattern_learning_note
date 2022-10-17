#include"myApp.h"

Document* MyApp::createDocument(std::string& name) {
	std::cout << "MyApp::createDocument()\n";
	return new MyDoc(name);
}