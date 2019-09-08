#include "MP4.Parser.h"
#include "atoms.h"

using namespace MP4;

ParserException::ParserException(void) {
    this->code = -1;
}

ParserException::ParserException(unsigned int c) {
    this->code = c;
}

const char * ParserException::what(void) const throw() {
    switch(this->code) {
        case ParserException::NoFileName:
            return "No input file";
    }
    return "Unknown exception";
}

Parser::Parser(void) {
    ParserException e = ParserException(ParserException::NoFileName);
    throw e;
}

Parser::Parser(char * filename) {
    bool container;
    uint32_t length;
    uint64_t dataLength;
    char type[5];
    char *data;
    MP4::Atom * atom;
    MP4::ContainerAtom * containerAtom;
    MP4::ContainerAtom * parentAtom;
}