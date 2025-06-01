#ifndef DISCIPLINE
#define DISCIPLINE

#include "Needed_libs.h"

class Discipline {
private:
	short CCU;
	std::string discName;
	LvlOfEdu lvl;
	bool tryName(std::string n);
public:
	// Конструкторы
	Discipline();
	Discipline(short CCU, std::string discName, LvlOfEdu lvl);

	// Оператор присваивания и сравнения
	Discipline& operator=(const Discipline& d);
	bool operator==(const Discipline& d) const;
	friend std::ostream& operator<<(std::ostream& out, const Discipline& d);

	// Геттеры
	short getCurrentCU() const;
	std::string getDiscName() const;
	LvlOfEdu getLvl() const;

	// Сеттеры значений
	void setCurrentCU(short ccu);
	void setDName(std::string name);
	void setLvl(LvlOfEdu l);
};


#endif
