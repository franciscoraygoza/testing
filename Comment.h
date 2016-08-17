#ifndef COMMENT_H
#define COMMENT_H

#include "Component.h"

class Comment : public Component{
    private:
        
    public:
        Comment();
        ~Command();
        
        void add_parameter ( string str );
        bool run();
        void print();
        string get_command();
        bool isCommandh();
};

#endif
