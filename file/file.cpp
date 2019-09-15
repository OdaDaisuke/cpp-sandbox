#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <list>
#include <vector>
#include <sstream>
#include "util.h"

std::string mp4_to_bin_str(std::ifstream&);
std::string hex_to_ascii(std::string);
std::string to_utf8_char_le(char*);
std::string to_utf8_char(char*);
std::string string_to_hex(const std::string);

// boxes
typedef std::string atom;
atom box_ftype = "ftyp";
atom box_moov = "moov";
atom box_moof = "moof";
atom box_mdat = "mdat";
atom box_mved = "mvex";
atom box_tenc = "tenc";
atom box_trak = "trak";
atom box_tkhd = "tkhd";
atom box_mdhd = "mdhd";
atom box_minf = "minf";
std::string ftyp_box = string_to_hex(box_ftype);

int main() {
    char filename[] = "./video.mp4";

    std::ifstream mp4(filename, std::ios::in | std::ios::binary);
    if (!mp4) {
        std::cerr << "Failed to open faile." << std::endl;
        return -1;
    }

    std::string mp4_bin_str = mp4_to_bin_str(mp4);

    int ftyp_size = 8;
    int ftyp_start = mp4_bin_str.find(ftyp_box) + ftyp_box.size();
    int ftyp_end = ftyp_start + ftyp_size;

    std::string ftype;
    for (int i = ftyp_start; i < ftyp_end; i++) {
        ftype.push_back(mp4_bin_str[i]);
    }

    std::cout << "ftyp: " << hex_to_ascii(ftype) << std::endl;

    mp4.close();

    return 0;
}

std::string string_to_hex(const std::string input)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = input.length();

    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
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

std::string hex_to_ascii(std::string s) {
    std::string output;
    int l = s.size();
    for (int i = 0; i < l; i += 2) {
        std::string byte = s.substr(i, 2);
        char chr = (char)(int)std::strtol(byte.c_str(), NULL, 16);
        output.push_back(chr);
    }
    return output;
}

std::string mp4_to_bin_str(std::ifstream &mp4) {
    std::string output;

    int i = 0;
    unsigned char low, high;
    while(mp4.read((char*)&high, 1) && mp4.read((char*)&low, 1) && i < 30) {
        unsigned int value = high << 8 | low;
        std::stringstream cur_digit;
        cur_digit << std::hex << value;
        output += cur_digit.str();
        i++;
    }
    return output;
}
