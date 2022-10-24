#include"compositePattern.h"

std::string Entry::toString() {
	return getName() + "(" + std::to_string(getSize()) + ")";
}

void File::printList(std::string prefix) {
	if(prefix!="") std::cout << prefix << "/" << this->toString()<<std::endl;
}

int Directory::getSize() {
	int size = 0;
	auto iter = _directory.begin();
	while (iter != _directory.end()) {
		Entry* entry = *iter++;
		size += entry->getSize();
	}
	return size;
}

Entry* Directory::add(Entry* entry) {
	_directory.push_back(entry);
	return this;
}

void Directory::printList(std::string prefix) {
	if(prefix!="") std::cout << prefix << "/" << this;
	//print all path to File object under this directory
	auto iter = _directory.begin();
	while (iter != _directory.end()) {
		Entry* entry = *iter++;
		if (File* file = dynamic_cast<File*>(entry)) {
			file->printList(prefix + "/" + _name);
		}
		if (Directory* directory = dynamic_cast<Directory*>(entry)) {
			if (prefix != "") directory->printList(prefix + "/" + _name);
			else directory->printList("");
		}
	}
}