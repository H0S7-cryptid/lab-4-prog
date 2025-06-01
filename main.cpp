#include "SYLLABUS.h"

int main() {
	Syllabus s{ Cipher{"01","01","01"}, Master, "AFTV Syllabus", 37};

	s.addCreators(Creator{ Person{"Natasha Dildakova Skibidishkina"}, Dean });
	s.addCreators(Creator{});

	s.addDiscipline(15, "Mathematical Analisys");
	s.addDiscipline(10, "Linear Algebra");
	s.addDiscipline(12, "OLKK");

	std::cout << s;

	try {
		s.Activate();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		s.setLvlOfEdu(Bachelor);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
