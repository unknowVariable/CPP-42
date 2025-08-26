#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; ++i)
        ideas[i] = "";
}
Brain::Brain(const Brain &o)
{
    for (int i = 0; i < 100; ++i)
        ideas[i] = o.ideas[i];
}
Brain &Brain::operator=(const Brain &o)
{
    if (this != &o)
        for (int i = 0; i < 100; ++i)
            ideas[i] = o.ideas[i];
    return *this;
}
Brain::~Brain() {}
void Brain::setIdea(int i, const std::string &s)
{
    if (i >= 0 && i < 100)
        ideas[i] = s;
}
const std::string &Brain::getIdea(int i) const
{
    static std::string empty = "";
    return (i >= 0 && i < 100) ? ideas[i] : empty;
}
