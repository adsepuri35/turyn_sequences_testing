#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int r = 3;
int unknownEq = r / 2 + 1;
int nonUnknownEq = (r - 1) - (r / 2);

void solver(int r, int equation, int left, int right, std::vector<int> w, std::vector<int> x, std::vector<int> y, std::vector<int> z) {
   if (equation <= 0) {
        return;
   }

   if (equation >= r - unknownEq) {
        // brute force solutions
   } else {
        // test solutions
   } 
}

int main() {
    // Parse the CSV file
    std::ifstream file("96_solutions/96_solutions.csv");
    if (!file) {
        std::cout << "Unable to open file\n";
        return 1; // or exit the program
    }
    std::string line;

    // Skip the header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::vector<int> row;
        std::stringstream ss(line);

        std::string value;
        while (std::getline(ss, value, ',')) {
            row.push_back(std::stoi(value));
        }

        std::vector<int> w(r);
        std::vector<int> x(r);
        std::vector<int> y(r);
        std::vector<int> z(r);

        // pointers
        int left = 0;
        int right = r - 1;

        int equation = r - 1;

        w[left] = row[0];
        w[right] = row[1];
        x[left] = row[2];
        x[right] = row[3];
        y[left] = row[4];
        y[right] = row[5];
        z[left] = row[6];
        z[right] = row[7];
        solver(r, equation - 1, left + 1, right - 1, w, x, y, z);
    }

    file.close();
    
    return 0;
}