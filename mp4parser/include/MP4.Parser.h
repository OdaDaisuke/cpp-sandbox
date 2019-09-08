#ifndef _MP4_PARSER_
#include <exception>
#pragma once
#define _MP4_PARSER_

namespace MP4 {
    class ParserException : public std::exception {
        private:
        protected:
            unsigned int code;
        public:
            enum {
                NoFileName = 0x00
            };
            ParserException(void);
            ParserException(unsigned int c);
            virtual const char * what(void) const throw();
    };

    class Parser {
        private:
        protected:
        public:
            Parser(void);
            Parser(char* filename);
            ~Parser(void);
    };
};

#endif