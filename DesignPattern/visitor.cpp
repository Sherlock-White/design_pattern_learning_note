#include"visitor.h"

VisitorPricing::VisitorPricing(){}
VisitorPricing::~VisitorPricing(){}
void VisitorPricing::Visit(FloppyDisk* e) {
	_total += e->NetPrice();
}
void VisitorPricing::Visit(Chassis* e) {
	_total += e->DiscountPrice();
}

VisitorPricing2::VisitorPricing2() {}
VisitorPricing2::~VisitorPricing2() {}
void VisitorPricing2::Visit(FloppyDisk* e) {
	_total += e->NetPrice();
}
void VisitorPricing2::Visit(Chassis* e) {
	_total += e->DiscountPrice();
}

VisitorInventory::VisitorInventory(){}
VisitorInventory::~VisitorInventory(){}
void VisitorInventory::Visit(FloppyDisk* e) {
	_inventory.Accumulate(e);
}
void VisitorInventory::Visit(Chassis* e) {
	_inventory.Accumulate(e);
}