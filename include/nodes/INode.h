#ifndef INODE_H_
#define INODE_H_
#include <string>
#include <cmath>

class INode {
    public:
        virtual double calc() = 0;
        virtual std::string print() = 0;
        
        virtual ~INode() = default;
    };
#endif