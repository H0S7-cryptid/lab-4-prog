#include "SYLLABUS.h"

Syllabus::Syllabus() : cipher{ Cipher{} },
lvl{ UNDEFL }, stat{ Inactive }, name{ "Unknonw" }, TargetCreditUnit{ 0 }, TotalCreditUnit{ 0 } {}

Syllabus::Syllabus(Cipher cipher, LvlOfEdu lvl,
	std::string name, short TargetCreditUnit) {
	this->cipher = cipher;
	this->lvl = lvl;
	this->name = name;
	this->stat = Inactive;
	this->TargetCreditUnit = TargetCreditUnit;
	this->TotalCreditUnit = 0;
}

std::ostream& operator<<(std::ostream& out, const Syllabus& s) {
	out << "\tName of the Syllabus: " << s.name << std::endl;
	out << "Cipher: " << s.cipher << std::endl;
	out << s.creators << std::endl;
	out << "Level of Higher Education: " << NameLvl[s.lvl] << std::endl;
	out << s.disciplines;
	out << "Target unist of all disciplines: " << s.TargetCreditUnit << std::endl;
	out << "Total credit unit of all disciplines: " << s.TotalCreditUnit << std::endl;
	return out;
}

Cipher Syllabus::getCipher() const {
	return cipher;
}

CompOfCreators Syllabus::getCreators() const {
	return creators;
}

LvlOfEdu Syllabus::getLvlOfEdu() const {
	return lvl;
}

SylStatus Syllabus::getSylStatus() const {
	return stat;
}

TotalDiscip Syllabus::getDisciplines() const {
	return disciplines;
}

std::string Syllabus::getSylName() const {
	return name;
}

short Syllabus::getTotalCU() const {
	return TargetCreditUnit;
}

short Syllabus::getTargetCU() const {
	return TargetCreditUnit;
}

void Syllabus::setCipher(Cipher c) {
	if (stat == Active) throw std::runtime_error("The Syllabus is an active!\nYou can`t redact it, until it is inactive");
	cipher = c;
}

void Syllabus::setCipher(std::string p1, std::string p2, std::string p3) {
	if (stat == Active) throw std::runtime_error("The Syllabus is an active!\nYou can`t redact it, until it is inactive");
	cipher.setParts(p1, p2, p3);
}

void Syllabus::addCreators(Creator p) {
	if (stat == Active) throw std::runtime_error("The Syllabus is an active!\nYou can`t redact it, until it is inactive");
	creators.addCreator(p);
}

void Syllabus::addCreators(Person p, StatusInUni s) {
	if (stat == Active) throw std::runtime_error("The Syllabus is an active!\nYou can`t redact it, until it is inactive");
	creators.addCreator(p, s);
}

void Syllabus::setLvlOfEdu(LvlOfEdu l) {
	if (stat == Active) throw std::runtime_error("The Syllabus is an active!\nYou can`t redact it, until it is inactive");
	lvl = l;
}

void Syllabus::addDiscipline(Discipline d) {
	if (stat == Active) throw std::runtime_error("The Syllabus is an active!\nYou can`t redact it, until it is inactive");
	if (disciplines.uniqueDisc()) {
		disciplines.addDisc(d);
		updateTotalCU();
	}
}

void Syllabus::addDiscipline(short TCU, std::string name) {
	if (stat == Active) throw std::runtime_error("The Syllabus is an active!\nYou can`t redact it, until it is inactive");
	if (disciplines.uniqueDisc()) {
		disciplines.addDisc(TCU, name);
		updateTotalCU();
	}
}

void Syllabus::setSylName(std::string s) {
	if (stat == Active) throw std::runtime_error("The Syllabus is an active!\nYou can`t redact it, until it is inactive");
	name = s;
}

void Syllabus::setTargetCU(short TCU) {
	if (stat == Active) throw std::runtime_error("The Syllabus is an active!\nYou can`t redact it, until it is inactive");
	TargetCreditUnit = TCU;
}

void Syllabus::updateTotalCU() {
	TotalCreditUnit = 0;
	for (const Discipline& d : disciplines.getDisciplines()) {
		TotalCreditUnit += d.getCurrentCU();
	}
}

void Syllabus::Activate() {
	if ((TotalCreditUnit == TargetCreditUnit) && !disciplines.getDisciplines().empty() && (name != "Unknonw") &&
		!(cipher == Cipher{}) && !creators.getCreators().empty())
		stat = Active;
	else throw std::exception("Incorrect/not full fields data!");
}
