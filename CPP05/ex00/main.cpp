#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;
        a.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Bob", 149);
        std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
        b.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat c("Ko", 0);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}