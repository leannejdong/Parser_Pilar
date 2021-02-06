/*!
 * Created by leanne on 2/5/21.
 */

#ifndef PARSER_PILA_MATRIX_H
#define PARSER_PILA_MATRIX_H
#include <cassert>
//#include <iostream>
//#include <string>
#include <vector>

using std::vector;
//using std::cerr;

struct matrix
{
    matrix(int r) : storage_(r*r), size_(r) {}

    int& operator()(int i, int j)       noexcept {
        // std::cerr << "i= " << i << " and j= " << j << " and size_ =" << size_ << "\n";
        return storage_[i-1 + size_*(j-1)]; }
    int  operator()(int i, int j) const noexcept { return storage_[i + size_*j]; }

    int size() const noexcept { return size_; }

private:
    std::vector<int> storage_;
    int size_;
};

#endif //PARSER_PILA_MATRIX_H
