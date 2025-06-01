#ifndef CREATOR
#define CREATOR

#include "Person.h"

class Creator {
private:
	Person fullname;
	StatusInUni status;
public:
	// Конструкторы
	Creator();
	Creator(Person fullname, StatusInUni status);
	Creator(std::string fname, std::string mname, std::string lname, StatusInUni status);

	Creator& operator=(const Creator& other);
	bool operator==(const Creator& other);
	friend std::ostream& operator<<(std::ostream& out, const Creator& creator);
	bool operator<(const Creator& other) const;

	// Геттеры
	Person getPerson() const;
	StatusInUni getStatus() const;

	// Сеттеры
	void setPerson(Person p);
	void setPerson(std::string fname, std::string mname, std::string lname);
	void setStatus(StatusInUni s);
};

#endif
