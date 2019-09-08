#include <iostream>
#include <string>
#include <sstream>

class CharSets
{
private:
public:
    static std::string to_hex_le(char * str) {
        std::stringstream utf8_code;
        int limit = sizeof(str);
        for (int i = 0; i < limit; i++) {
            int char_code = static_cast<int>(str[i]);
            if (char_code <= 31) {
                continue;
            }
            utf8_code << std::hex << char_code;
        }
        return utf8_code.str();
    }
    
    static std::string to_utf8_le(char * str) {
        std::stringstream utf8_code;
        int limit = sizeof(str);
        for (int i = 0; i < limit; i++) {
            int char_code = static_cast<int>(str[i]);
            utf8_code << std::hex << char_code;
        }
        return utf8_code.str();
    }

    static std::string to_utf8_le(std::string str) {
        std::stringstream utf8_code;
        int limit = sizeof(str);
        for (int i = 0; i < limit; i++) {
            int char_code = static_cast<int>(str.c_str()[i]);
            utf8_code << std::hex << char_code;
        }
        return utf8_code.str();
    }

    static std::string to_utf16_le(char * str) {
        std::stringstream utf16_code;
        // キャストでutf16, utf32に変換する
        return utf16_code.str();
    }
};

int main()
{
    char s[] = "pssh";
    std::string ss = "pssh";
    std::cout << "to utf8 le(from char): " << CharSets::to_utf8_le(s) << std::endl;
    std::cout << "to utf8 le(from string): " << CharSets::to_utf8_le(ss) << std::endl;
    std::cout << static_cast<char16_t>(s[0]);
    return 0;
}
