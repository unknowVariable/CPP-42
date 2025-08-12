#include "Contact.hpp"


void Contact::setFirstName(const std::string &name) {
    firstName = name;
}

void Contact::setLastName(const std::string &name) {
    lastName = name;
}

void Contact::setNickname(const std::string &name) {
    nickname = name;
}

void Contact::setPhoneNumber(const std::string &number) {
    phoneNumber = number;
}

void Contact::setDarkestSecret(const std::string &secret) {
    darkestSecret = secret;
}


std::string Contact::getFirstName() const {
    return firstName;
}
std::string Contact::getLastName() const {
    return lastName;
}
std::string Contact::getNickname() const {          
    return nickname;
}
std::string Contact::getPhoneNumber() const {       
    return phoneNumber;
}
std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}
void Contact::getContactInfo() const {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}