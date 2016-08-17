#ifndef COMMAND_H
#define COMMAND_H


#include "Component.h"


class Command : public Component{
    private:
        
    public:
        Command();
        ~Command();
        
        Command ( string exec );
        
        void add_parameter ( string str );
        bool run();
        void print();
        string get_command();
        bool isCommand();
};

#endif
