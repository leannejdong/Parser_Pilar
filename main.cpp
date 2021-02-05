#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>
#include <utility>
#include <vector>

using std::cerr;
using std::string;
using std::pair;
using std::vector;

int main() {
    std::ifstream file( "pila.txt");
    std::string line;

    std::ofstream output("output.txt");
    while(getline(file, line))
    {
        std::istringstream line_stream(line);
        vector<pair<int, int>> V;
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

            //cerr << word << " " << block_number << " " << block_type << "\n";
          //  output << line << "\n";

//            if ((block_type == "CURRENTEDGE")||(block_type == "VERTEX")) {
//                getline(file, line);
//                std::istringstream line_stream(line);
//                int blk_num_x/*, blk_num_y*/;
//                line_stream >> blk_num_x /*>> blk_num_y*/;
//                output << blk_num_x << " " << block_number << "\n";
//            }
            if(block_type == "CURRENTEDGE") {
                getline(file, line);
                std::istringstream line_stream(line);
                int blk_num_x/*, blk_num_y*/;
                line_stream >> blk_num_x /*>> blk_num_y*/;
                output << blk_num_x << " " << block_number << "\n";

            } else if(block_type == "VERTEX") {
                getline(file, line);
                std::istringstream line_stream(line);
                int blk_num_xx, blk_num_y, blk_num_z;
                line_stream >> blk_num_xx >> blk_num_y >> blk_num_z ;
                output << blk_num_xx << " " << block_number << "\n";
                output << blk_num_y << " " << block_number << "\n";
                output << blk_num_z << " " << block_number << "\n";
            }

        }
        else if (word == "P") {
            int block_number;
            line_stream >> block_number;
       //     output << word << " " << block_number << "\n";
            if (!line_stream) {
                assert(false); // not implemented
            }

            //cerr << "Beginning parameters for block " << block_number << "\n";
            getline(file, line);
        //    output << line << "\n";
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
