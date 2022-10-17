#include"document.h"

Document::Document(std::string& name){
	_name = name;
	std::cout << "Document ctor.name:" << _name << std::endl;
}

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