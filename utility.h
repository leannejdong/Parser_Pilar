/*!
 * Created by leanne on 2/5/21.
 */

#ifndef PARSER_PILA_UTILITY_H
#define PARSER_PILA_UTILITY_H
#include "matrix.h"
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::string;
//using std::vector;
using std::cerr;
using Pair = std::vector<std::pair<int, int>>;
using std::make_pair;

inline static Pair parseGraph(std::istream &streamA)
{
    string line;
    Pair V;

    while (getline(streamA, line))
    {
        std::istringstream streamB(line);
        string word;
        streamB >> word;

        if (word == "S") {
            // Start of a block;
            int block_number;
            streamB >> block_number;

            if (!streamB) {
                assert(false); // not implemented
            }

            string block_type;
            streamB >> block_type;

            //  cerr << word << " " << block_number << " " << block_type << "\n";
            if(block_type == "CURRENTEDGE") {
                getline(streamA, line);
                std::istringstream streamC(line);
                int blk_num_x/*, blk_num_y*/;
                streamC >> blk_num_x /*>> blk_num_y*/;
                V.push_back(make_pair(blk_num_x, block_number));
            } else if(block_type == "VERTEX") {
                getline(streamA, line);
                std::istringstream streamV(line);
                while(streamV){
                    int x;
                    streamV >> x;
                    if(streamV.fail())
                        break;
                    V.push_back(make_pair(block_number,x));
                }
            }
        }
    }
    return V;

}
inline void printVecPair(Pair &V)
{
    std::ofstream pairs("pairs.txt");
    for(auto &v : V)
    {
        pairs <<  v.first << " " << v.second << "\n";
    }
    pairs << "\n";

}
inline void addEdge(matrix &adj, int u, int v)
{
    adj(u, v) += 1;
    adj(v, u) += 1;
}
inline void displayMatrix(matrix const& adj)
{
    std::ofstream output("output.txt");

    for(/*std::size_t*/int i = 0; i < adj.size(); i++)
    {
        for(/*std::size_t*/int j = 0; j < adj.size(); j++)
        {
            output << adj(i,j) << "  ";
        }
        output << "\n";
    }
}


#endif //PARSER_PILA_UTILITY_H
