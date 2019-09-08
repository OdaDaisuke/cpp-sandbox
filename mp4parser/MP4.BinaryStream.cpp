#include "ios"
#include "MP4.BinaryStream.h"

using namespace MP4;

BinaryStreamException::BinaryStreamException(void) {
    this->code = -1;
}

BinaryStreamException::BinaryStreamException(unsigned int c) {
    this->code = code;
}

BinaryStream::BinaryStream(char * filename) {
    this->stream.open(filename, std::ios::binary | std::ios::in);
    if (this->stream.is_open() == false || this->stream.good() == false) {
        BinaryStreamException e = BinaryStreamException(BinaryStreamException::OpenError);
        throw e;
    }
}

BinaryStream::~BinaryStream(void) {
    if (this->stream.is_open()) {
        this->stream.close();
    }
}