#ifndef TOTAL_DISCIPLINES
#define TOTAL_DISCIPLINES

#include "Discipline.h"
#include "Needed_libs.h"

class TotalDiscip {
private:
	std::vector <Discipline> disciplines;
public:
	// Оператор вывода в поток
	friend std::ostream& operator<<(std::ostream& out, const TotalDiscip& d);

	// Обращение к вектору значений
	std::vector <Discipline> getDisciplines() const;

	// Методы добавления элементов в контейнер
	void addDisc(Discipline d);
	void addDisc(short TCU, std::string name);

	// Метод проверки элементов контейнера на уникальность
	bool uniqueDisc();

	// Удаление по дисциплины значению
	void deleteDisc(Discipline d);

	// Установка полей 
	void redoDiscCCU(short ccu, int pos);
	void redoDiscName(std::string name, int pos);

	// Поиск существующих дисциплин
	Discipline search(Discipline d);
	Discipline search(short CCU, std::string name);
};

#endif
