# Base Converter
C++ function to convert numbers from one base representation to another base. Base ranging from 2 to 36.

# Usage
```cpp
n::convert_base(string input, int baseFrom, int baseTo);
n::convert_base("100", 2, 10);
returns "4"
```

# Full example
```cpp
#include <iostream>
#include "base_converter.hpp"

int main()
{
    std::cout << n::convert_base("100", 2, 10) << std::endl;

    return 0;
}
```
