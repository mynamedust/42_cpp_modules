#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

typedef std::string string;

class Brain {
private:
	string ideas[100];
	unsigned int ideasCount;
public:
	Brain();
	~Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);

	void addIdea(const string& idea);
	string getIdea(unsigned int number) const;
};


#endif
