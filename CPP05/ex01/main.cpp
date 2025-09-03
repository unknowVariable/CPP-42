#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat a("Alice", 50);
    Form f1("FormA", 30, 20);
    std::cout << f1 << std::endl;
    a.signForm(f1);
    std::cout << f1 << std::endl;

    Bureaucrat b("Bob", 10);
    b.signForm(f1);
    std::cout << f1 << std::endl;

    try
    {
        Form bad("Bad", 0, 10);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}