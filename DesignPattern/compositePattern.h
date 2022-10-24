#pragma once
#ifndef __COMPOSITE_PATTERN_H__
#define __COMPOSITE_PATTERN_H__
#include<string>
#include<iostream>
#include<vector>
class Entry {
public:
	virtual std::string getName() = 0;
	virtual int getSize() = 0;
	//if a File object try to call add(),then it will throw an exception
	Entry* add(Entry* entry) {
		throw "Invald operation:add()\n";
	}
	void printList() {
		printList("");
	}
	std::string toString();
protected:
	virtual void printList(std::string prefix) = 0;
};

class File : public Entry {
private:
	std::string _name;
	int _size;
	friend class Directory;
public:
	File(std::string name, int size) :_name(name), _size(size){}
	std::string getName() {
		return _name;
	}
	int getSize() {
		return _size;
	}
protected:
	void printList(std::string prefix);
};

class Directory : public Entry {
private:
	std::string _name;
	//a container which can contain File and Directory
	std::vector<Entry*> _directory;
public:
	Directory(std::string name):_name(name){}
	std::string getName() {
		return _name;
	}
	//get the sum size of File objects under this directory
	int getSize();
	Entry* add(Entry* entry);
protected:
	void printList(std::string prefix);
};

#endif // !__COMPOSITE_PATTERN_H__
