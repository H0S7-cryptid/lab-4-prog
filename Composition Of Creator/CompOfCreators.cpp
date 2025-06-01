#include "CompOfCreators.h"

void CompOfCreators::addCreator(Creator&& creator) {
	creators.insert(creator);
}

void CompOfCreators::addCreator(const Creator& creator) {
	creators.insert(creator);
}

void CompOfCreators::addCreator(const Person& name, StatusInUni& status) {
	creators.insert(Creator{ name, status });
}

void CompOfCreators::deleteCreator(Creator&& creator) {
	creators.erase(creator);
}

void CompOfCreators::deleteCreator(const Creator& creator) {
	creators.erase(creator);
}

void CompOfCreators::deleteCreator(const Person& name, StatusInUni& status) {
	creators.erase(Creator{ name, status });
}

void CompOfCreators::deleteCreator(int pos) {
	if (pos > creators.size()) throw std::out_of_range("Position is beyond range!");
	auto it = creators.begin();
	std::advance(it, pos);
	creators.erase(it);
}

const std::set<Creator>& CompOfCreators::getCreators() const {
	return creators;
}

std::ostream& operator<<(std::ostream& out, const CompOfCreators& s) {
	out << "Current creators: ";
	if (s.getCreators().empty()) {
		out << "None";
		return out;
	}
	out << std::endl;
	int i = 1;
	for (const auto& item : s.getCreators()) {
		out << i << ". " << item;
		i++;
	}
	return out;
}

CompOfCreators& CompOfCreators::operator=(const CompOfCreators& other) {
	if (this != &other) {
		creators = other.creators;
	}
	return *this;
}
