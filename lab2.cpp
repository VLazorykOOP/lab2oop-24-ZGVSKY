#include <iostream>
#include <fstream>
#include <fstream>
#include <bitset>


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
    //  функция для шифрування тексту з файлу
    // шляхи до файлів
    const std::string& inputFile = "C:\\Users\\User\\OOPLab2_22\\OOPLab2Tpl\\input.txt";
    const std::string& outputFile = "C:\\Users\\User\\OOPLab2_22\\OOPLab2Tpl\\out\\output.bin";

    // відкриваємо файли
    std::ifstream input(inputFile);
    std::ofstream output(outputFile);

    // Перевірка відкриття файлу
    if (!input) {
        std::cerr << "Error while open: " << inputFile << std::endl;
    }

    char text[4][16] = {}; // Масив для збереження 4 рядків по 16 символів (заповнюється пробілами)
    std::string line;

    // Зчитування тексту з файлу
    for (int i = 0; i < 4 && std::getline(input, line); ++i) {
        for (size_t j = 0; j < line.size() && j < 16; ++j) {
            text[i][j] = line[j]; // Записуємо символи у масив
        }
    }
    input.close();

    // Прохід по всіх символах і їх шифрування максимум 4 рядка по 16 символів на рядок
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 16; ++col) {
            char ch = text[row][col] ? text[row][col] : ' '; // Якщо символ відсутній, замінюємо пробілом

            // записуємо наш зашифрований код
            int encoded = (row << 14) | (col << 10) | (ch << 2); //

            // Додавання біта парності
            encoded |= (__builtin_parity((row << 4) | col) << 1) | __builtin_parity(ch);// використовуємо вбудовану функцію підрахунку біта парності

            std::cout << "char: " << ch << " -> " << std::bitset<16>(encoded) << std::endl;

            // Запис результату у вихідний файл у вигляді двійкового коду
            output.write(reinterpret_cast<char*>(&encoded), sizeof(encoded));
        }
    }
    output.close();

    std::cout << "result: " << outputFile << std::endl;
}



void decrypt() {
    //  функция для розшифрування тексту з файлу
    // шляхи до файлів
    const std::string& inputFile = "C:\\Users\\User\\OOPLab2_22\\OOPLab2Tpl\\out\\output.bin";
    const std::string& outputFile = "C:\\Users\\User\\OOPLab2_22\\OOPLab2Tpl\\out\\decrypted.txt";

    // відкриваємо файли
    std::ifstream input(inputFile);
    std::ofstream output(outputFile);

    // Перевірка відкриття файлу
    if (!input) {
        std::cerr << "Error while open: " << inputFile << std::endl;
    }
    char text[4][16] = {}; // Масив для збереження 4 рядків по 16 символів (заповнюється пробілами)
    int encoded;

    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 16; ++col) {
            input.read(reinterpret_cast<char*>(&encoded), sizeof(encoded));

            // Відновлення символу
            int extracted_row = (encoded >> 14) & 0b11;
            int extracted_col = (encoded >> 10) & 0b1111;
            char ch = (encoded >> 2) & 0xFF;

            text[extracted_row][extracted_col] = ch;
        }
    }
    input.close();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 16; ++j) {
            std::cout << text[i][j];
            output << text[i][j];
        }
        std::cout << std::endl;
        output << std::endl;
    }
    output.close();
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