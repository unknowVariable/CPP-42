#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

int ft_atoi(const std::string &str)
{
    int result = 0;

    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        result = result * 10 + (str[i] - '0');
    }
    return result;
}


PhoneBook::PhoneBook()
{
    index = 0;
    contactCount = 0;
}

static std::string formatField(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::addContact()
{
    Contact newContact;
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    if (input.empty())
    {
        std::cout << "First name required. Contact not saved." << std::endl;
        return;
    }
    newContact.setFirstName(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    if (input.empty())
    {
        std::cout << "Last name required. Contact not saved." << std::endl;
        return;
    }
    newContact.setLastName(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    if (input.empty())
    {
        std::cout << "Nickname required. Contact not saved." << std::endl;
        return;
    }
    newContact.setNickname(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    if (input.empty())
    {
        std::cout << "Phone number required. Contact not saved." << std::endl;
        return;
    }
    newContact.setPhoneNumber(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    if (input.empty())
    {
        std::cout << "Secret required. Contact not saved." << std::endl;
        return;
    }
    newContact.setDarkestSecret(input);

    contacts[index] = newContact;
    index = (index + 1) % 8;
    if (contactCount < 8)
        contactCount++;

    std::cout << "Contact saved." << std::endl;
}

void PhoneBook::searchContacts() const
{
    if (contactCount == 0)
    {
        std::cout << "No contacts available." << std::endl;
        return;
    }

    std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
    std::cout << "----------|----------|----------|----------" << std::endl;

    for (int i = 0; i < contactCount; ++i)
    {
        std::cout << "         " << i + 1 << "|"
                  << formatField(contacts[i].getFirstName()) << "|"
                  << formatField(contacts[i].getLastName()) << "|"
                  << formatField(contacts[i].getNickname()) << std::endl;
    } 
    std::cout << "Enter the index of the contact to view details: ";
    std::string input;
    std::getline(std::cin, input);
    int index = ft_atoi(input);

    if (index < 1 || index > contactCount)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    contacts[index - 1].getContactInfo();
}