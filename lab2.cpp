#include <iostream>
#include <fstream>
#include <string>


void ex_one() {
    int a,b,c,d;

    std::cout << "write a,b,c,d: "<< std::endl;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;


    int op_1 = (a << 5) + (a<<1);    // 34*a
    int op_2 = (a << 4) - (a<<2) +a; // 13*a
    int op_3 = (c << 4) - (c<<2);    // 12*c

    int op_4 = (b << 11) + (b<<9);   // 2560*b
    int op_5 = (d << 7) - d;         // 127*d
    int op_6 = (c << 4) +c+c;        // 18*c

    int op_7 = (op_2 + op_3)>>5;     // (13*a+12*c)/64

    int res = op_1 + op_7-op_4+op_5-op_6;
    int test = (a*34)+(13*a+12*c)/64-(b*2560)+(d*127)-c*18;

    std::cout << res << std::endl;
    std::cout << test << std::endl;
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