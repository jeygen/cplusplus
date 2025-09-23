#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <iomanip>  // for std::hex, std::setw, std::setfill

int main() {
    // ================================
    // 🔢 INTEGER LITERAL FORMATS
    // ================================

    // Decimal (default)
    int decVal = 42;

    // Hexadecimal (prefix 0x)
    int hexVal = 0x2A;  // 42 in hex
    std::cout << "hex literal 0x2A → int: " << hexVal << '\n';

    // Binary (prefix 0b) — requires C++14 or later
    int binVal = 0b101010;  // 42 in binary
    std::cout << "binary literal 0b101010 → int: " << binVal << '\n';

    // Octal (prefix 0) — rarely used
    int octVal = 052;  // 42 in octal
    std::cout << "octal literal 052 → int: " << octVal << '\n';


    // ================================
    // 🔢 INT → STRING
    // ================================
    int n = 42;
    std::string s1 = std::to_string(n);
    std::cout << "\nint → string: " << s1 << '\n';

    // ================================
    // 🔢 INT → BINARY STRING (8-bit)
    // ================================
    std::bitset<8> b(n);  // fixed-width binary representation
    std::cout << "int → binary (bitset): " << b << '\n';

    // ================================
    // 🔢 INT → HEX STRING
    // ================================
    std::stringstream ss;
    ss << std::hex << n;
    std::string hexStr = ss.str();
    std::cout << "int → hex string: " << hexStr << '\n';

    // ================================
    // 🔡 STRING → INT
    // ================================
    std::string s2 = "123";
    int val1 = std::stoi(s2);
    std::cout << "string → int: " << val1 << '\n';

    // ================================
    // 🔡 HEX STRING → INT
    // ================================
    std::string hexIn = "2A";  // 42 in hex
    int val2 = std::stoi(hexIn, nullptr, 16); // 2nd arg is where/index to end processing string, 3rd arg is base
    std::cout << "hex string → int: " << val2 << '\n';

    // ================================
    // 🔡 BINARY STRING → INT
    // ================================
    std::string binIn = "101010";  // 42 in binary
    int val3 = std::stoi(binIn, nullptr, 2);
    std::cout << "binary string → int: " << val3 << '\n';

    // ================================
    // 🔢 INT → CHAR DIGIT ('0' + n)
    // ================================
    char digit = '0' + 5; // this is trick to covert to string, works 0-9 
    std::cout << "int 5 → char digit: " << digit << '\n';
    std::cout << "type: " << typeid(digit).name() << '\n';

    // ================================
    // 🔡 CHAR DIGIT → INT (c - '0')
    // ================================
    char c = '7';
    int digitVal = c - '0'; // this is a string to convert to int, works 0-9
    std::cout << "char '7' → int: " << digitVal << '\n';
    std::cout << "type: " << typeid(digitVal).name() << '\n';

    // ================================
    // 🎨 OUTPUT FORMATTING
    // ================================
    std::cout << std::hex << std::showbase;
    std::cout << "\nstd::hex with showbase: " << n << '\n';  // shows "0x2a"

    std::cout << std::dec << std::noshowbase;  // reset flags
    std::cout << "std::dec: " << n << '\n';

    // Manual binary formatting with bitset
    std::cout << "binary with bitset<16>: " << std::bitset<16>(n) << '\n';

    return 0;
}

