#pragma once
#ifndef __OBJECT_STRUCTURE_H__
#define __OBJECT_SRTUCTURE_H__

#include<list>
#include<string>
using namespace std;

#define Currency int
#define Watt float
class MyException{};

class VisitorEquipment;

class Equipment {
private:
	const std::string _name;
protected:
	Equipment(const std::string& name);
public:
	virtual ~Equipment();
	const std::string& Name();
	virtual Watt Power() = 0;
	virtual Currency NetPrice() = 0;
	virtual Currency DiscountPrice() = 0;
	virtual void Add(Equipment*);
	virtual void Remove(Equipment*);
	virtual void Accept(VisitorEquipment&) = 0;
};

class FloppyDisk : public Equipment {
public:
	FloppyDisk(const std::string& name);
	virtual ~FloppyDisk()override;
	virtual Watt Power()override;
	virtual Currency NetPrice()override;
	virtual Currency DiscountPrice() override;
	virtual void Accept(VisitorEquipment& visitor) override;
};

class Card : public Equipment
{
public:
	Card(const std::string& name);
	virtual ~Card()override;
	virtual Watt Power()override;
	virtual Currency NetPrice()override;
	virtual Currency DiscountPrice() override;
	virtual void Accept(VisitorEquipment& visitor) override;
};

class CompositeEquipment : public Equipment {
protected:
	std::list<Equipment*> _equipment;
	CompositeEquipment(const std::string& name);
public:
	virtual ~CompositeEquipment()override;
	virtual Watt Power()override;
	virtual Currency NetPrice()override;
	virtual Currency DiscountPrice() override;
	virtual void Add(Equipment*) override;
	virtual void Remove(Equipment*) override;
	virtual void Accept(VisitorEquipment& visitor) override;
};

class Chassis : public CompositeEquipment {
public:
	Chassis(const std::string& name);
	virtual ~Chassis()override;
	virtual Watt Power()override;
	virtual Currency NetPrice()override;
	virtual Currency DiscountPrice() override;
	virtual void Accept(VisitorEquipment& visitor) override;

};

class Cabinet : public CompositeEquipment {
public:
	Cabinet(const std::string& name);
	virtual ~Cabinet()override;
	virtual Watt Power()override;
	virtual Currency NetPrice()override;
	virtual Currency DiscountPrice() override;
	virtual void Accept(VisitorEquipment& visitor) override;

};

class Bus : public CompositeEquipment {
public:
	Bus(const std::string& name);
	virtual ~Bus()override;
	virtual Watt Power()override;
	virtual Currency NetPrice()override;
	virtual Currency DiscountPrice() override;
	virtual void Accept(VisitorEquipment& visitor) override;

};
#endif // !__OBJECT_STRUCTURE_H__
