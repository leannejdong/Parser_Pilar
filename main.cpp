#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>

using std::cerr;
using std::string;

int main() {
    std::ifstream file( "pila.txt");
    std::string line;

    std::ofstream output("output.txt");
    while(getline(file, line))
    {
        std::istringstream line_stream(line);
        string word;
        line_stream >> word;
        if (word == "S") {
            // Start of a block;
            int block_number;
            line_stream >> block_number;

            if (!line_stream) {
                assert(false); // not implemented
            }

            string block_type;
            line_stream >> block_type;

            cerr << word << " " << block_number << " " << block_type << "\n";

            if ((block_type == "CURRENTEDGE")||(block_type == "VERTEX")) {
                getline(file, line);
                output << line << "\n";
            }
        }
        else if (word == "P") {
            int block_number;
            line_stream >> block_number;
            cerr << word << " " << block_number << "\n";
            if (!line_stream) {
                assert(false); // not implemented
            }

            //cerr << "Beginning parameters for block " << block_number << "\n";
            getline(file, line);
            output << line << "\n";
        }
        else {
            cerr << "Unknown line: " << line << "\n";
            assert(false); // not implemented
        }

//        if (line[0]=='S')
//        {
//            ++num_lines;
//            std::cout << " The lines start with letter S are " << line << "\n";
//            output << line << "\n";
//        }

    }
   // std::cout << "Number of lines contain S: " << num_lines;
}
