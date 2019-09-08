#ifndef _MP4_BINARY_STREAM_
#pragma once
#define _MP4_BINARY_STREAM_
#include <exception>
#include <string>
#include "mp4.h"
#include "types.h"

namespace MP4 {
    class BinaryStreamException : public std::exception {
        private:
        protected:
            unsigned int code;
        public:
            enum {
                NoFileName = 0x00,
                OpenError  = 0x01
            };
            BinaryStreamException(void);
            BinaryStreamException(unsigned int c);
            virtual const char * what(void) const throw();
    };

    class BinaryStream {
        private:
        protected:
            std::ifstream stream();
        public:
            BinaryStream(void);
            BinaryStream(char *filename);
            ~BinaryStream(void);

            uint8_t readUnsignedChar(void);
            int8_t readSignedchar(void);

            uint16_t readUnsignedShort(void);
            int16_t readSignedShort(void);
            uint16_t readBigEndianUnsignedShort(void);
            uint16_t readLittleEndianUnsignedShort(void);

            uint32_t readUnsignedInteger(void);
            int32_t readSignedInteger(void);
            uint32_t readBigEndianUnsignedInteger(void);
            uint32_t readLittleEndianUnsignedInteger(void);

            uint64_t readUnsignedLong(void);
            int64_t readSignedLong(void);
            uint64_t readBigEndianUnsignedLong(void);
            int64_t readBigEndignSignedLong(void);

            float readFloat(void);
            double readDouble(void);

            float readBigEndianFixedPoint(unsigned int integerLength, unsigned int fractionalLength);
            float readLittleEndianFixedPoint(unsigned int integerLength, unsigned int fractionalLength);

            std::string * readBigEndianISO639Code(void);
            std::string * readNULLTerminatedString(void);
            std::string * readUTF8String(void);
            std::string * readLongUTF8String(void);

            void readMatrix(matrix * m);

            bool good(void) const;
            bool eof(void) const;
            bool fail(void) const;
            bool bad(void) const;
            bool peek(void);
            int get(void);
            int sync(void);
            std::streampos tellg(void);
    }
}
#endif