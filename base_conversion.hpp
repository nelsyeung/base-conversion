#ifndef BASE_CONVERSION_BASE_CONVERSION_HPP
#define BASE_CONVERSION_BASE_CONVERSION_HPP

#include <iostream>
#include <string>

namespace n {
    const std::string alphanum = "0123456789ABCDEFGHIJKLMOPQRSTUVWXYZ";

    unsigned long to_base10(const std::string &input, int baseFrom) {
        // Convert input to base 10
        unsigned inputNum = 0;

        for (int i = 0; i < input.length(); ++i) {
            inputNum = inputNum * baseFrom + alphanum.find(input[i]);
        }

        return inputNum;
    }

    std::string base10_to_new(unsigned long input, int baseTo) {
        // Convert base 10 number to a new base
        std::string output = "";

        while (input > 0) {
            std::string c(1, alphanum[input % baseTo]);
            output.insert(0, c);
            input /= baseTo;
        }

        return output;
    }

    std::string convert_base(const std::string &input, int baseFrom, int baseTo) {
        unsigned long inputNum = 0;

        // No conversion is needed for the same base
        if (baseFrom == baseTo) {
            return input;
        }

        // Make sure the base range from 2 to 36
        if (baseFrom < 2 or baseTo < 2 or baseFrom > 36 or baseTo > 36) {
            std::cerr << "Error: Base need to range from 2 to 36." << std::endl;
            return "-1";
        }

        if (baseFrom == 10) {
            inputNum = std::stoi(input);
        }
        else {
            inputNum = to_base10(input, baseFrom);
        }

        // No conversion is needed when input is 0
        if (inputNum == 0) {
            return "0";
        }

        return base10_to_new(inputNum, baseTo);
    }

    std::string convert_base(unsigned long input, int baseFrom, int baseTo) {
        std::string output = "";
        unsigned long inputNum = 0;

        // No conversion is needed for the same base
        if (baseFrom == baseTo) {
            return std::to_string(input);
        }

        if (baseFrom == 10) {
            inputNum = input;
        }
        else {
            inputNum = to_base10(std::to_string(input), baseFrom);
        }

        // Make sure the base range from 2 to 36
        if (baseFrom < 2 or baseTo < 2 or baseFrom > 36 or baseTo > 36) {
            std::cerr << "Error: Base need to range from 2 to 36." << std::endl;
            return "-1";
        }

        // No conversion is needed when input is 0
        if (input == 0) {
            return "0";
        }

        return base10_to_new(inputNum, baseTo);
    }
} // namespace n

#endif
