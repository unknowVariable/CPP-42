#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp" 
#include <iostream>

class PhoneBook
{
  private:
    Contact contacts[8];
    int contactCount;
    int index;

  public:
    PhoneBook();
    void addContact();
    void searchContacts() const;
};

#endif