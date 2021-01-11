#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>

using std::cerr;
using std::string;

int main() {
    int num_lines = 0;
    std::ifstream file( "pila.txt");
    std::string line;

       std::ofstream output("output.txt");
    while(getline(file, line))
    {
        //if(line.find("S") != std::string::npos)
        if (line[0]=='S')
        {
            ++num_lines;
            std::cout << " The lines start with letter S are " << line << "\n";
            output << line << "\n";
        }
    }
    std::cout << "Number of lines contain S: " << num_lines;
}
