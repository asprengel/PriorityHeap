#pragma once


class PrioElement
{
public:
	PrioElement() { static int fortNummer = 0; nummer = fortNummer++; }
	int priority() const { return prio; }
	void set_priority(int p) { this->prio = p; }
	bool operator<(const PrioElement& e) const { return prio < e.prio; }
	operator int();
private:
	int prio;
	int nummer;
};


PrioElement::operator int()
{
	return prio;
}
