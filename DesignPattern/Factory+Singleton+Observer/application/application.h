#pragma once
#ifndef __APPLICATION_H__
#define __APPLICATION_H__
#include<list>
#include"../document/document.h"
#include<string>

class Application {
private:
	//container
	std::list<Document*> _docList;
	//Singleton
	static int _counter;
public:
	Application();
	void add(Document* doc);
	Document* getLastDoc();
	//Factory Method
	virtual Document* createDocument(std::string&) = 0;
	virtual ~Application();
};

#endif // !__APPLICATION_H__
