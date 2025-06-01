#ifndef DISCIPLINE
#define DISCIPLINE

#include "Needed_libs.h"

class Discipline {
private:
	short CCU;
	std::string discName;
	bool tryName(std::string n);
public:
	// Конструкторы
	Discipline();
	Discipline(short CCU, std::string discName);

	// Оператор присваивания и сравнения
	Discipline& operator=(const Discipline& d);
	bool operator==(const Discipline& d) const;
	friend std::ostream& operator<<(std::ostream& out, const Discipline& d);

	// Геттеры
	short getCurrentCU() const;
	std::string getDiscName() const;

	// Сеттеры значений
	void setCurrentCU(short ccu);
	void setDName(std::string name);
};


#endif
