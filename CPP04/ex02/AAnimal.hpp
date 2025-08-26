#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>
# include <string>

class AAnimal
{
  protected:
	std::string type;

  public:
	AAnimal();
	AAnimal(const AAnimal &);
	AAnimal &operator=(const AAnimal &);
	virtual ~AAnimal();

	const std::string &getType() const;
	virtual void makeSound() const = 0;
};
#endif
