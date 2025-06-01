#ifndef PERSON
#define PERSON

#include "Needed_libs.h"

class Person {
private:
	std::string fname, mname, lname;
	bool tryName(std::string n);
public:
	// Конструкторы без параметров и с параметрами
	Person();
	Person(std::string name);
	Person(std::string first, std::string middle, std::string last);

	// оператор присваивания и равенства
	Person& operator=(const Person& other);
	bool operator==(const Person& other);
	friend std::ostream& operator<<(std::ostream& out, const Person& p);
	bool operator<(const Person& other) const;

	// Сеттеры ФИО
	void setFname(std::string name);
	void setMname(std::string name);
	void setLname(std::string name);
	void setFullName(std::string name);

	// Геттеры ФИО
	std::string getFname();
	std::string getMname();
	std::string getLname();
	std::string getFullName();
};


#endif 
