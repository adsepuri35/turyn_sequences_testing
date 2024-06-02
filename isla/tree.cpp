#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>

int r = 9;

std::vector<int> W(r);
std::vector<int> X(r);
std::vector<int> Y(r);
std::vector<int> Z(r);

std::vector<std::vector<int>> equations;

void intializeEquationVectors(int r) {
    for (int i = 1; i < r; i++) {
        std::vector<int> equation(i * 8, 0);
        equations.push_back(equation);
    }
}

void printEquations(int r) {
    std::string seq[] = {"w", "x", "y", "z"};
    for (int s = 1; s < r; s++) {
        std::string equation = "Equation " + std::to_string(s) + " = ";
        std::string lastTerm;
        int termCount = 0;

        for (int i = 0; i < 4; i++) {
            for (int j = 1; j < r; j++) {
                if (j + s > r) {
                    break;
                }
                if (!lastTerm.empty()) {
                    equation += lastTerm + " + ";
                }
                lastTerm = seq[i] + "_" + std::to_string(j) + " * " + seq[i] + "_" + std::to_string(j + s);
                termCount++;
            }
        }
        equation += lastTerm;
        std::cout << equation << std::endl;
        std::cout << "Number of terms: " << termCount << std::endl;
    }
}

int main() {
    if (r < 3) {
        throw std::runtime_error("r must be at least 3");
    } else if (r % 2 == 0) {
        throw std::runtime_error("r must be odd");
    }

    printEquations(r);
    //intializeEquationVectors(r);

    return 0;
}