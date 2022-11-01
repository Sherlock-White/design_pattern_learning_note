#pragma once
#ifndef  __VISITOR_H__
#define  __VISITOR_H__
#include "objectStructure.h"

class VisitorEquipment {
protected:
	VisitorEquipment() {};
public:
	virtual ~VisitorEquipment() {};
	virtual void Visit(FloppyDisk*) {};
	virtual void Visit(Card*) {};
	virtual void Visit(Chassis*) {};
	virtual void Visit(Bus*) {};
	virtual void Visit(Cabinet*) {};
	virtual void Visit(CompositeEquipment*) {};
};

class VisitorPricing : public VisitorEquipment {
private:
	Currency _total = 0;
public:
	VisitorPricing();
	~VisitorPricing()override;
	Currency& GetTotalPrice() { return _total; }

	virtual void Visit(FloppyDisk*)override;
	virtual void Visit(Chassis*)override;
};

class VisitorPricing2 :public VisitorEquipment {
private:
	Currency _total = 0;
public:
	VisitorPricing2();
	~VisitorPricing2()override;
	Currency& GetTotalPrice() { return _total *= 0.8; }

	virtual void Visit(FloppyDisk*)override;
	virtual void Visit(Chassis*)override;
};

class Inventory {
private:
	int sum = 0;
public:
	void Accumulate(const Equipment* e) {
		//...
	}
	operator int() { return sum; }
};


class VisitorInventory :public VisitorEquipment {
private:
	Inventory _inventory;
public:
	VisitorInventory();
	~VisitorInventory()override;
	Inventory& GetInventory() { return _inventory; }

	virtual void Visit(FloppyDisk*)override;
	virtual void Visit(Chassis*)override;
};

#endif // ! __VISITOR_H__
