#include "TotalDisciplines.h"

std::ostream& operator<<(std::ostream& out, const TotalDiscip& d) {
	out << "Current Disceplines: ";
	
	if (d.getDisciplines().empty()) {
		out << "None" << std::endl;
		return out;
	}
	out << std::endl;
	for (Discipline data : d.getDisciplines()) {
		out << data;
	}
	return out;
}

std::vector <Discipline> TotalDiscip::getDisciplines() const {
	return disciplines;
}

void TotalDiscip::addDisc(Discipline d) {
	disciplines.push_back(d);
	uniqueDisc();
}

void TotalDiscip::addDisc(short TCU, std::string name, LvlOfEdu lvl) {
	disciplines.push_back(Discipline{ TCU, name, lvl });
	uniqueDisc();
}

bool TotalDiscip::uniqueDisc() {
	bool duplicatesFound = false;

	for (auto it = disciplines.begin(); it != disciplines.end(); ++it) {
		for (auto jt = it + 1; jt != disciplines.end(); ) {
			if (*it == *jt) {
				jt = disciplines.erase(jt);
				duplicatesFound = true;
			}
			else ++jt;
		}
	}
	return !duplicatesFound;
}

void TotalDiscip::deleteDisc(Discipline d) {
	disciplines.erase(std::remove(disciplines.begin(), disciplines.end(), d), disciplines.end());
}

void TotalDiscip::redoDiscCCU(short ccu, int pos) {
	if (pos > disciplines.size()) throw std::out_of_range("Position is beyond range!");
	disciplines[pos].setCurrentCU(ccu);
}

void TotalDiscip::redoDiscName(std::string name, int pos) {
	if (pos > disciplines.size()) throw std::out_of_range("Position is beyond range!");
	disciplines[pos].setDName(name);
}

void TotalDiscip::redoDisclvl(LvlOfEdu lvl, int pos) {
	if (pos > disciplines.size()) throw std::out_of_range("Position is beyond range!");
	disciplines[pos].setLvl(lvl);
}

Discipline TotalDiscip::search(Discipline d) {
	for (const Discipline& find : disciplines) {

		std::string name = find.getDiscName();
		std::string name_to_find = d.getDiscName();
		if ((name != name_to_find) || (name.empty() || name_to_find.empty()))
			continue;

		short CCU = find.getCurrentCU();
		short CCU_to_find = d.getCurrentCU();
		if (CCU != CCU_to_find) 
			continue;

		return find;
	}
}

Discipline TotalDiscip::search(short CCU, std::string name) {
	for (const Discipline& find : disciplines) {
		if ((name != find.getDiscName()) || (name.empty() || find.getDiscName().empty()))
			continue;

		if (CCU != find.getCurrentCU())
			continue;

		return find;
	}
}
