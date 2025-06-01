#ifndef COMP_OF_CREATORS
#define COMP_OF_CREATORS

#include "Creator.h"

class CompOfCreators {
private:
	std::set <Creator> creators;
public:
	// Установка (добавление) значений в контейнер с разными параметрами
	void addCreator(Creator&& creator);
	void addCreator(const Creator& creator);
	void addCreator(const Person& name, StatusInUni& status);

	friend std::ostream& operator<<(std::ostream& os, const CompOfCreators& s);
	CompOfCreators& operator=(const CompOfCreators& other);

	// Удаление значений с разными параметрами
	void deleteCreator(Creator&& creator);
	void deleteCreator(const Creator& creator);
	void deleteCreator(const Person& name, StatusInUni& status);
	void deleteCreator(int pos);

	const std::set<Creator>& getCreators() const;
};

#endif
