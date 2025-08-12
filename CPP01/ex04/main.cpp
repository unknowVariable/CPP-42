#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static std::string replace_all(const std::string& s,
                               const std::string& from,
                               const std::string& to)
{
    if (from.empty())
        return s; 
    std::string out;
    out.reserve(s.size());
    std::string::size_type pos = 0, found;
    while ((found = s.find(from, pos)) != std::string::npos) {
        out.append(s, pos, found - pos);
        out += to;
        pos = found + from.size();
    }
    out.append(s, pos, std::string::npos);
    return out;
}

int main(int argc, char** argv)
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    std::ifstream in(filename.c_str());
    if (!in) {
        std::cerr << "Error: cannot open input file: " << filename << std::endl;
        return 1;
    }

    std::ostringstream buffer;
    buffer << in.rdbuf();
    const std::string content = buffer.str();

    const std::string replaced = replace_all(content, s1, s2);

    const std::string outname = filename + ".replace";
    std::ofstream out(outname.c_str());
    if (!out) {
        std::cerr << "Error: cannot open output file: " << outname << std::endl;
        return 1;
    }
    out << replaced;
    return 0;
}
