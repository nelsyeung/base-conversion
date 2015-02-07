# Base Converter
Cpp function to convert numbers from one base representation to another base. Base ranging from 2 to 36.

# Usage
```cpp
convert_base(string input, int baseFrom, int baseTo);
convert_base("100", 2, 10);
returns "4"

#include <iostream>
#include "base_converter.hpp"

int main(int argc, char const* argv[]) {
    std::cout << convert_base("100", 2, 10) << std::endl;

    return 0;
}
```
