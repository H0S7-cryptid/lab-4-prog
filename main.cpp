#include "SYLLABUS.h"

int main() {
	Syllabus s{ Cipher{}, Bachelor, "AVTF Syllabus", 40, 5, 2 };

	try {
		s.addDiscipline(Discipline{ 10, "Mathematical Analisys", Bachelor });
	}
	catch (std::logic_error& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		s.addDiscipline(Discipline{ 10, "L25ar Alge5ra", Bachelor });
	}
	catch (std::logic_error& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		s.addDiscipline(Discipline{ 10, "V#ct0r ana1isys", Bachelor });
	}
	catch (std::logic_error& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << s << std::endl;

	Syllabus s1{ Cipher{}, Bachelor, "FTF Syllabus", 25, 7, 3 };

	try {
		s1.getDisciplines().redoDiscCCU(15, 1);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		s1.addCreators(Creator{ Person{"Anna 4stin 34st3r"}, Dean });
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		s1.addCreators(Creator{ Person{"Anna ;s4in ::№st№r"}, Dean });
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << s1;

	return 0;
}
