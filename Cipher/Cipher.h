#ifndef CIPHER
#define CIPHER

#include "Needed_libs.h"

class Cipher {
private:
	std::string pt1, pt2, pt3;
	bool isNum(std::string s);
	void splitByDots(std::vector<std::string>& vec, const std::string& input);
public:
	// Полный конструктор
	Cipher();
	Cipher(std::string p1, std::string p2, std::string p3);
	Cipher(std::string full);

	// Установка полного шифра
	void setParts(std::string p1, std::string p2, std::string p3);
	void setFullCipher(std::string cipher);

	// Оператор сравнения и присвоения
	Cipher& operator=(const Cipher& other);
	bool operator==(const Cipher& other) const;
	friend std::ostream& operator<<(std::ostream& out, const Cipher& c);

	// Получение полного шифра учебного плана
	std::string getCipher() const;
};

#endif 
