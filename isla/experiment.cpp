#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

void helper(int r, int left, int right, std::vector<int> w, std::vector<int> x, std::vector<int> y, std::vector<int> z) {
   // Print the vectors
    std::cout << "w: ";
    for (int i : w) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "x: ";
    for (int i : x) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "y: ";
    for (int i : y) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "z: ";
    for (int i : z) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}


int main() {
    int r = 3;

    int unknownEq = r / 2;
    int nonUnknownEq = r - (r / 2);

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

        w[left] = row[0];
        w[right] = row[1];
        x[left] = row[2];
        x[right] = row[3];
        y[left] = row[4];
        y[right] = row[5];
        z[left] = row[6];
        z[right] = row[7];
        helper(r, left + 1, right - 1, w, x, y, z);
    }

    file.close();
    
    return 0;
}