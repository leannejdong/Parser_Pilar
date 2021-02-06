#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "utility.h"
using std::cerr;
using std::string;
using std::pair;
using std::vector;

int main() {
    std::ifstream file( "pila.txt");
    Pair result = parseGraph(file);
    printVecPair(result);
    matrix adj(8);
    for (auto &v : result)
    {
        addEdge(adj, v.first, v.second);
    }

    displayMatrix(adj);
}

//https://godbolt.org/z/rvbY9G