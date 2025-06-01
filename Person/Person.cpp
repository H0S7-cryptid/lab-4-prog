#include "Person.h"

bool Person::tryName(std::string n) {
	return std::all_of(n.begin(), n.end(), isalpha);
}

Person::Person() : fname{ "Unknown" }, mname{ " " }, lname{ " " } {}

Person::Person(std::string name) {
	setFullName(name);
}

Person::Person(std::string first, std::string middle, std::string last) {
	if (!(tryName(first) && tryName(middle) && tryName(last))) {
		fname = "Unknown"; mname = " "; lname = " ";
	}
	fname = first;
	mname = middle;
	lname = last;
}

Person& Person::operator=(const Person& other) {
	if (this != &other) {
		fname = other.fname;
		mname = other.mname;
		lname = other.lname;
	}
	return *this;
}

bool Person::operator==(const Person& other) {
	return ((fname == other.fname) && (lname == other.lname) && (mname == other.mname));
}

std::ostream& operator<<(std::ostream& out, const Person& p) {
	out << p.fname << " " << p.mname << " " << p.lname;
	return out;
}

bool Person::operator<(const Person& other) const {
	if (lname != other.lname) return lname < other.lname;
	if (fname != other.fname) return fname < other.fname;
	return mname < other.mname;
}

void Person::setFname(std::string name) {
	if (!tryName(name)) throw std::exception("Wrong name!");
	fname = name;
}

void Person::setMname(std::string name) {
	if (!tryName(name)) throw std::exception("Wrong name!");
	mname = name;
}

void Person::setLname(std::string name) {
	if (!tryName(name)) throw std::exception("Wrong name!");
	lname = name;
}

void Person::setFullName(std::string name) {
	std::vector<std::string> nameParts;
	std::istringstream inputStream(name);
	std::string word;

	while (inputStream >> word) {
		nameParts.push_back(word);
	}

	if (tryName(nameParts[0]) && tryName(nameParts[1]) && tryName(nameParts[2])) {
		fname = nameParts[0];
		mname = nameParts[1];
		lname = nameParts[2];
	}
	else {
		fname = "Unknown"; mname = " "; lname = " ";
	}
}

std::string Person::getFname() {
	return fname;
}

std::string Person::getMname() {
	return mname;
}

std::string Person::getLname() {
	return lname;
}

std::string Person::getFullName() {
	std::string s;
	s.append(fname + " " + mname + " " + lname);
	return s;
}

