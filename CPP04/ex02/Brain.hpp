#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>

class Brain
{
private:
    std::string ideas[100];

public:
    Brain();
    Brain(const Brain &);
    Brain &operator=(const Brain &);
    ~Brain();

    void setIdea(int i, const std::string &s);
    const std::string &getIdea(int i) const;
};
#endif
