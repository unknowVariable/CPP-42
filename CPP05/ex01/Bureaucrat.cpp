#include "Bureaucrat.hpp"
#include "Form.hpp"

static void checkGradeBounds(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "grade too high"; }
const char *Bureaucrat::GradeTooLowException::what() const throw() { return "grade too low"; }

Bureaucrat::Bureaucrat() : name("Unnamed"), grade(150) {}
Bureaucrat::Bureaucrat(const std::string &n, int g) : name(n), grade(g) { checkGradeBounds(grade); }
Bureaucrat::Bureaucrat(const Bureaucrat &o) : name(o.name), grade(o.grade) {}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &o)
{
    if (this != &o)
        grade = o.grade;
    return *this;
}
Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return grade; }
void Bureaucrat::incrementGrade()
{
    checkGradeBounds(grade - 1);
    grade -= 1;
}
void Bureaucrat::decrementGrade()
{
    checkGradeBounds(grade + 1);
    grade += 1;
}

void Bureaucrat::signForm(Form &f) const
{
    try
    {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << name << " couldn’t sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}