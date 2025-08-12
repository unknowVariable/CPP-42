#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    // Addresses
    std::cout << "Addresses:" << std::endl;
    std::cout << "str:       " << &str << std::endl;
    std::cout << "stringPTR: " << stringPTR << std::endl;
    std::cout << "stringREF: " << &stringREF << std::endl;

    // Valeurs
    std::cout << "Values:" << std::endl;
    std::cout << "str:       " << str << std::endl;
    std::cout << "stringPTR: " << *stringPTR << std::endl;
    std::cout << "stringREF: " << stringREF << std::endl;

    return 0;
}