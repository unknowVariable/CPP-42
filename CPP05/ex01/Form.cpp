#include "Form.hpp"
#include "Bureaucrat.hpp"

void Form::checkGradeBounds(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() { return "grade too high"; }
const char *Form::GradeTooLowException::what() const throw() { return "grade too low"; }

Form::Form() : name("DefaultForm"), isSigned(false), signGrade(150), execGrade(150) {}
Form::Form(const std::string &n, int s, int e) : name(n), isSigned(false), signGrade(s), execGrade(e)
{
    checkGradeBounds(s);
    checkGradeBounds(e);
}
Form::Form(const Form &o) : name(o.name), isSigned(o.isSigned), signGrade(o.signGrade), execGrade(o.execGrade) {}
Form &Form::operator=(const Form &o)
{
    if (this != &o)
        isSigned = o.isSigned;
    return *this;
}
Form::~Form() {}

const std::string &Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getSignGrade() const { return signGrade; }
int Form::getExecGrade() const { return execGrade; }

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << "Form " << f.getName() << ": signed=" << (f.getIsSigned() ? "yes" : "no")
       << ", signGrade=" << f.getSignGrade() << ", execGrade=" << f.getExecGrade();
    return os;
}