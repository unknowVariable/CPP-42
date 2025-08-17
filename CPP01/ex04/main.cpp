#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string &line, const std::string &s1, const std::string &s2)
{
    std::string result;
    size_t pos = 0, found;

    while ((found = line.find(s1, pos)) != std::string::npos)
    {
        result.append(line, pos, found - pos); // ajoute la partie avant s1
        result.append(s2);                     // ajoute s2
        pos = found + s1.length();             // avance après s1
    }
    result.append(line, pos, line.length() - pos); // ajoute le reste
    return result;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./sed_is_for_losers <filename> <s1> <s2>\n";
        return 1;
    }
    std::ifstream in(argv[1]);
    if (!in)
    {
        std::cerr << "Error: cannot open input file\n";
        return 1;
    }
    std::ofstream out(std::string(argv[1]) + ".replace");
    if (!out)
    {
        std::cerr << "Error: cannot create output file\n";
        return 1;
    }
    std::string line;
    while (std::getline(in, line))
    {
        out << replaceAll(line, argv[2], argv[3]) << "\n";
    }
    return 0;
}
