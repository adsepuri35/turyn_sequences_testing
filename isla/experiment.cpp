#include <vector>
#include <iostream>

void helper(int r, int left, int right, std::vector<int>& w, std::vector<int>& x, std::vector<int>& y, std::vector<int>& z) {
    
}


int main() {
    int r = 4;

    int unknownEq = r / 2;
    int nonUnknownEq = r - (r / 2);

    // store solutions
    std::vector<int> w(r);
    std::vector<int> x(r);
    std::vector<int> y(r);
    std::vector<int> z(r);

    // pointers
    int left = 0;
    int right = r - 1;

    helper(r, left, right, w, x, y, z);
    
    return 0;
}