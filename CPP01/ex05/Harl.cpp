#include "Harl.hpp"

void Harl::_debug(void)
{
    std::cout << "[ DEBUG ] "
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
              << std::endl;
}

void Harl::_info(void)
{
    std::cout << "[ INFO ] "
              << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!"
              << std::endl;
}

void Harl::_warning(void)
{
    std::cout << "[ WARNING ] "
              << "I think I deserve to have some extra bacon for free."
              << std::endl;
}

void Harl::_error(void)
{
    std::cout << "[ ERROR ] "
              << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}

void Harl::complain(const std::string &level)
{
    const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*fns[4])() = {
        &Harl::_debug,
        &Harl::_info,
        &Harl::_warning,
        &Harl::_error
    };

    for (int i = 0; i < 4; ++i)
    {
        if (level == levels[i])
        {
            (this->*fns[i])();
            return;
        }
    }
}
