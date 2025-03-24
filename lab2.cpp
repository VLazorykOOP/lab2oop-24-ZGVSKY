#include <iostream>
#include <fstream>
#include <string>


void ex_one() {


}

void crypt() {

}

void decrypt() {

}

int main() {
    std::cout << "#################" << std::endl;
    std::cout << "1: EX_1" << std::endl;
    std::cout << "2: crypt file" << std::endl;
    std::cout << "3: decrypt file" << std::endl;
    std::cout << "#################" << std::endl;
    int N;
    std::cout << "Enter number: ";
    std::cin >> N;
    if (N == 1) {ex_one();}
    if (N == 2) {crypt();}
    if (N == 3) {decrypt();}
    return 0;
}