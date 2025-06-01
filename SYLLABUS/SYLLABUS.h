#ifndef SYLLABUS
#define SYLLABUS

#include "Cipher.h"
#include "CompOfCreators.h"
#include "TotalDisciplines.h"

class Syllabus {
private:
	Cipher cipher; CompOfCreators creators;
	LvlOfEdu lvl; SylStatus stat;
	TotalDiscip disciplines;
	std::string name;
	short TargetCreditUnit;
	short TotalCreditUnit;
	// обновление общего числа зачётных единиц по данному учебному плану
	void updateTotalCU();
public:
	// Конструкторы 
	Syllabus();
	Syllabus(Cipher cipher, LvlOfEdu lvl,
		std::string name, short TargetCreditUnit);

	// Оператор вывода в поток
	friend std::ostream& operator<<(std::ostream& out, const Syllabus& s);

	// Геттеры
	Cipher getCipher() const;
	CompOfCreators getCreators() const;
	LvlOfEdu getLvlOfEdu() const;
	SylStatus getSylStatus() const;
	TotalDiscip getDisciplines() const;
	std::string getSylName() const;
	short getTotalCU() const;
	short getTargetCU() const;

	// Сеттеры
	void setCipher(Cipher c);
	void setCipher(std::string p1, std::string p2, std::string p3);
	void addCreators(Creator p);
	void addCreators(Person p, StatusInUni s);
	void setLvlOfEdu(LvlOfEdu l);
	void setSylName(std::string s);
	void addDiscipline(Discipline d);
	void addDiscipline(short TCU, std::string name);
	void setTargetCU(short TCU);

	// Ввод плана в действие
	void Activate();
};

#endif
