#pragma once


class PrioElement
{
public:
	PrioElement() { static int fortNummer = 0; id = fortNummer++; }
	int priority() const { return prio; }
	void set_priority(int p) { this->prio = p; }
	bool operator<(const PrioElement& e) const { return prio < e.prio; }
	operator int() { return prio; }
	int getId() { return id; }
private:
	int prio;
	int id;
};