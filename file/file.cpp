#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <list>
#include <vector>
#include <sstream>

const std::string FTYP = "ftyp";

std::string to_utf8_char(char*);

int main() {
    char filename[] = "./video.mp4";

    std::ifstream mp4(filename, std::ios::in | std::ios::binary);
    if (!mp4) {
        std::cerr << "Failed to open faile." << std::endl;
        return -1;
    }

    int i = 0;
    unsigned char low, high;
    std::vector<std::string> bins;
    while(mp4.read((char*)&high, 1) && mp4.read((char*)&low, 1) && i < 30) {
        unsigned int value = high << 8 | low;
        std::stringstream cur_dig;
        cur_dig << std::hex << value;
        bins.push_back(cur_dig.str());
        i++;
    }

    for (std::size_t i = 0; i < bins.size(); ++i) {
        std::cout << bins[i];
    }

    mp4.close();
    std::cout << "-----" << std::endl;
    char a[] = "pssh";
    std::cout << to_utf8_char_le(a) << std::endl;

    return 0;
}

std::string to_utf8_char_le(char * str) {
    std::stringstream utf8_code;
    int limit = sizeof(str);
    for (int i = 0; i < limit; i++) {
        int char_code = static_cast<int>(str[i]);
        if (char_code == 0) {
            continue;
        }
        utf8_code << std::hex << char_code;
    }
    return utf8_code.str();
}