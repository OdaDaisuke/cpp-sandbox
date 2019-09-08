#ifndef _MP4_CONTAINER_ATOM_
#pragma once
#define _MP4_CONTAINER_ATOM_
#include "map"
#include "mp4.h"
#include "MP4.Atom.h"

namespace MP4 {
    class ContainerAtom : public Atom {
        private:
        protected:
            std::multimap<std::string, Atom * > _children;
        public:
            ContainerAtom(char * type);
            ~ContainerAtom(void);

            void addChild(Atom * a);
            Atom * findChild(const std::string &type);
            bool hasChildren(void);
            unsigned int numberOfChildren(void);
            std::string description(void);
    };
}

#endif