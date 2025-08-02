#include <iostream>
#include <cctype>
#include "atoi_util.h"

int libatoi(const std::string& str) {
    int i = 0, sign = 1, result = 0;

    // Skip leading spaces
    while (i < str.length() && isspace(str[i])) i++;

    // Handle optional sign
    if (i < str.length() && (str[i] == '-' || str[i] == '+')) {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }

    // Convert digits to integer
    while (i < str.length() && isdigit(str[i])) {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return sign * result;
}

#ifndef UNIT_TEST
int main() {
    std::string input;
    std::cout << "Enter a number: ";
    std::getline(std::cin, input);

    int number = libatoi(input);
    std::cout << "Converted number: " << number << std::endl;
}
#endif