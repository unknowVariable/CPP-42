#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
  private:
	Brain *brain;

  public:
	Dog();
	Dog(const Dog &);
	Dog &operator=(const Dog &);
	virtual ~Dog();

	virtual void makeSound() const;
	void setIdea(int i, const std::string &s);
	std::string getIdea(int i) const;
};
#endif
