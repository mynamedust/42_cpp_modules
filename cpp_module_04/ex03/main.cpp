#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void test1() {
	std::cout << "----------Constructors test----------" << std::endl;
	Character char1("Igor");
	Character char2("VOVCHIK");
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();

	std::cout << "--------Equip/Unequip/Use test--------" << std::endl;
	char1.equip(ice);
	char1.unequip(0);
	char2.equip(cure);
	char2.use(0, char1);
	char2.unequip(0);

	std::cout << "--------Materia Source test----------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void test2() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void test3() {
	AMateria* ice1 = new Ice();
	AMateria* ice2 = new Ice();
	AMateria* cure1 = new Cure();
	AMateria* cure2 = new Cure();
	ICharacter* me = new Character("me");

	me->equip(ice1);
	me->equip(ice2);
	me->equip(cure1);
	me->equip(cure2);
	me->unequip(1);
	me->equip(ice2);
	delete me;
}

int main() {
	test1();
	test2();
	test3();
	system("leaks materia");
}