/*----------------------------------
file: NumRoma.cpp
autore: Alessandro Gorassini 168518
date: 21/10/2025
descr: Program to convert Roman numerals to integers, including a helper function for character values and a main function for user input.
------------------------------------*/

#include <iostream>
#include <string>

int getValue(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

unsigned int romanToInt(std::string s) {
    unsigned int total = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        int current = getValue(s[i]);
        if (i + 1 < s.length() && current < getValue(s[i + 1])) {
            total -= current;
        } else {
            total += current;
        }
    }
    return total;
}

int main() {
    std::string roman;
    std::cout << "Inserisci un numero romano: ";
    std::cin >> roman;
    unsigned int result = romanToInt(roman);
    std::cout << "Il numero intero corrispondente è: " << result << std::endl;
    return 0;
}
