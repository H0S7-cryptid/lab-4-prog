#include "Creator.h"

Creator::Creator() : fullname{ Person{} }, status{ UNDEFSIN } {}

Creator::Creator(Person fullname, StatusInUni status) {
	this->fullname = fullname;
	this->status = status;
}

Creator::Creator(std::string fname, std::string mname, std::string lname, StatusInUni status) {
	this->fullname = Person{ fname, mname, lname };
	this->status = status;
}

Creator& Creator::operator=(const Creator& other) {
	if (this != &other) {
		fullname = other.fullname;
		status = other.status;
	}
	return *this;
}

bool Creator::operator==(const Creator& other) {
	return (fullname == other.fullname && status == other.status);
}

bool Creator::operator<(const Creator& other) const {
	if (fullname < other.fullname)
		return true;
	if (other.fullname < fullname)
		return false;
	return status < other.status;
}

std::ostream& operator<<(std::ostream& out, const Creator& creator) {
	out << "\t" << creator.fullname << ", ";
	out << NameUniStatus[creator.status] << std::endl;
	return out;
}

Person Creator::getPerson() const {
	return fullname;
}

StatusInUni Creator::getStatus() const {
	return status;
}

void Creator::setPerson(Person p) {
	fullname = p;
}

void Creator::setPerson(std::string fname, std::string mname, std::string lname) {
	fullname = Person{ fname, mname, lname };
}

void Creator::setStatus(StatusInUni s) {
	status = s;
}
