#include "MP4.ContainerAtom.h"

using namespace MP4;

ContainerAtom::ContainerAtom(char * type) {
    this->_type = type;
    std::transform(this->_type.begin(), this->_type.end(), this->_type.begin(), ::toupper);
}