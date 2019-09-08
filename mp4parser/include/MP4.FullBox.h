#ifndef _MP4_FULLBOX_
#pragma once
#define _MP4_FULLBOX_

#include "mp4.h"
#include "MP4.DataAtom.h"
#include "MP4.BinaryStream.h"

namespace MP4 {
    class FullBox : public DataAtom {
        private:
        protected:
            uint8_t _version;
            uint32_t _flags;
        public:
            void processData(MP4::BinaryStream * stream, size_t * length);
    };
}

#endif