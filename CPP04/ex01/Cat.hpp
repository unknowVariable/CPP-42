#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
  private:
	Brain *brain;

  public:
	Cat();
	Cat(const Cat &);
	Cat &operator=(const Cat &);
	~Cat();

	void makeSound() const;
	void setIdea(int i, const std::string &s);
	std::string getIdea(int i) const;
};
#endif
