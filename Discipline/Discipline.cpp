#include "Discipline.h"

bool Discipline::tryName(std::string n) {
	for (char ch : n) {
		if (!std::isalpha(ch) && !std::isspace(ch)) {
			return false;
		}
	}
	return true;
}

Discipline::Discipline() : CCU{ 0 }, discName{ "Unknown" } {}

Discipline::Discipline(short CCU, std::string discName) {
	if (tryName(discName)) {
		this->discName = discName;
	}
	else {
		this->discName = "Unknown";
	}
	this->CCU = CCU;
}

Discipline& Discipline::operator=(const Discipline& d) {
	if (this != &d) {
		this->CCU = d.CCU;
		this->discName = d.discName;
	}
	return *this;
}

bool Discipline::operator==(const Discipline& d) const {
	return ((CCU == d.CCU) && (discName == d.discName));
}

std::ostream& operator<<(std::ostream& out, const Discipline& d) {
	out << "\tName of the discipline: " << d.discName << std::endl;
	out << "\t\tNumber of current credit units of discipline: " << d.CCU << std::endl;
	return out;
}

short Discipline::getCurrentCU() const {
	return CCU;
}

std::string Discipline::getDiscName() const {
	return discName;
}

void Discipline::setCurrentCU(short ccu) {
	CCU = ccu;
}

void Discipline::setDName(std::string name) {
	discName = name;
}
