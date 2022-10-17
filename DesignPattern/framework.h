#pragma once
#ifndef __FRAMEWORK_H__
#define __FRAMEWORK_H__
#include<list>
#include<string>
#include"../command/command.h"

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

class Document {
private:
	std::string _name;
	//Observer
	std::list<View*> _views;
	bool _changed = false;
public:
	Document(std::string& name);
	//actually operation open and paste should be declared as virtual function
	//and defined in derived class,but here just write like this for convenience
	void open();
	void paste();
	virtual void Serialize();
	virtual ~Document() {}
	void attach(View* view);
	void detach(View* view);
	void notify();
	virtual void changeData() = 0;
	void dataChanged();
};

//Observer 
class View {
public:
	virtual ~View() {}
	virtual void update() = 0;
};

class PasteCommand :public Command {
private:
	Document* _doc;
public:
	PasteCommand(Document* doc) :_doc(doc) {}
	void execute();
};

class OpenCommand : public Command {
private:
	Application* _app;
public:
	OpenCommand(Application* app) :_app(app) {}
	void execute();
protected:
	std::string askUser();
};

#endif // !__FRAMEWORK_H__
