#include"objectStructure.h"
#include"visitor.h"
Equipment::Equipment(const std::string& name):_name(name){}
Equipment::~Equipment(){}
const std::string& Equipment::Name() { return _name; }
void Equipment::Add(Equipment*) { throw MyException(); }
void Equipment::Remove(Equipment*) { throw MyException(); }

FloppyDisk::FloppyDisk(const std::string& name):Equipment(name){}
FloppyDisk::~FloppyDisk(){}
Watt FloppyDisk::Power() { return 0.1; }
Currency FloppyDisk::NetPrice() { return 10; }
Currency FloppyDisk::DiscountPrice() { return 9;}
void FloppyDisk::Accept(VisitorEquipment& visitor) { visitor.Visit(this); }

Card::Card(const std::string& name):Equipment(name){}
Card::~Card(){}
Watt Card::Power() { return 0.2; }
Currency Card::NetPrice() { return 20; }
Currency Card::DiscountPrice() { return 18; }
void Card::Accept(VisitorEquipment& visitor) { visitor.Visit(this); }

CompositeEquipment::CompositeEquipment(const std::string& name):Equipment(name){}
CompositeEquipment::~CompositeEquipment(){}
Watt CompositeEquipment::Power() {
	Watt total = 0;
	for (auto& i : _equipment) {
		total += i->Power();
	}
	return total;
}
Currency CompositeEquipment::NetPrice() {
	Currency total = 0;
	for (auto& i : _equipment) {
		total += i->NetPrice();
	}
	return total;
}
Currency CompositeEquipment::DiscountPrice() {
	Currency total = 0;
	for (auto& i : _equipment) {
		total += i->DiscountPrice();
	}
	return total;
}
void CompositeEquipment::Add(Equipment* newOne) {
	_equipment.push_back(newOne);
}

void CompositeEquipment::Remove(Equipment* oldOne) {
	_equipment.remove(oldOne);
}

void CompositeEquipment::Accept(VisitorEquipment& visitor) {
	visitor.Visit(this);
}

Chassis::Chassis(const std::string& name) :CompositeEquipment(name){}
Chassis::~Chassis(){}
Watt Chassis::Power() { return 0.1 + CompositeEquipment::Power(); }
Currency Chassis::NetPrice() { return 100 + CompositeEquipment::NetPrice(); }
Currency Chassis::DiscountPrice() { return 10 + CompositeEquipment::DiscountPrice(); }
void Chassis::Accept(VisitorEquipment& visitor) {
	for (auto& i : _equipment) {
		i->Accept(visitor);
	}
	visitor.Visit(this);
}

Cabinet::Cabinet(const std::string& name):CompositeEquipment(name){}
Cabinet::~Cabinet(){}
Watt Cabinet::Power() { return 0.2 + CompositeEquipment::Power(); }
Currency Cabinet::NetPrice() { return 200 + CompositeEquipment::NetPrice(); }
Currency Cabinet::DiscountPrice() { return 20 + CompositeEquipment::DiscountPrice(); }
void Cabinet::Accept(VisitorEquipment& visitor) {
	visitor.Visit(this);
}

Bus::Bus(const std::string& name):CompositeEquipment(name){}
Bus::~Bus(){}
Watt Bus::Power() { return 0.3 + CompositeEquipment::Power(); }
Currency Bus::NetPrice() { return 300 + CompositeEquipment::NetPrice(); }
Currency Bus::DiscountPrice() { return 30 + CompositeEquipment::DiscountPrice(); }
void Bus::Accept(VisitorEquipment& visitor) {
	visitor.Visit(this);
}