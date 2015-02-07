#ifndef BASE_CONVERTER_BASE_CONVERTER_HPP
#define BASE_CONVERTER_BASE_CONVERTER_HPP

#include <iostream>
#include <string>

namespace n {
    std::string convert_base(const std::string &inputStr, int baseFrom, int baseTo) {
        const std::string alphanum = "0123456789ABCDEFGHIJKLMOPQRSTUVWXYZ";
        unsigned long inputNum = 0;
        std::string output = "";

        // No conversion is needed for the same base
        if (baseFrom == baseTo) {
            return inputStr;
        }

        // Make sure the base range from 2 to 36
        if (baseFrom < 2 or baseTo < 2 or baseFrom > 36 or baseTo > 36) {
            std::cerr << "Error: Base need to range from 2 to 36." << std::endl;
            return "-1";
        }

        // Convert input to base 10
        for (std::string::size_type pos = 0; pos < inputStr.length(); ++pos) {
            inputNum = inputNum * baseFrom + alphanum.find(inputStr[pos]);
        }

        // No conversion is needed when input is 0
        if (inputNum == 0) {
            return "0";
        }

        // Convert base 10 number to a new base
        while (inputNum > 0) {
            std::string c(1, alphanum[inputNum % baseTo]);
            output.insert(0, c);
            inputNum /= baseTo;
        }

        return output;
    }
} // namespace n

#endif
