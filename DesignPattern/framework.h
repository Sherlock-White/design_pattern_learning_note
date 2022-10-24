#pragma once
#ifndef __FRAMEWORK_H__
#define __FRAMEWORK_H__
#include<list>
#include<string>
#include"commandPattern.h"

class Document;
class Application;
class View;
class PasteCommand;
class OpenCommand;

class Document {
private:
	std::string _name;
	bool _changed = false;
protected:
	//Observer
	std::list<View*> _views;
public:
	Document(std::string& name) :_name(name) {
		std::cout << "Document ctor.name:" << _name << std::endl;
	}
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
	virtual int getState() = 0;
	virtual void setState(int i) = 0;
	void dataChanged();
	virtual View* getLastView() = 0;
};

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

//Observer 
class View {
protected:
	Document* _subject;
public:
	View(Document* myDoc) :_subject(myDoc){}
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
