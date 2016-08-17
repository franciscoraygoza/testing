#ifndef AND_H
#define AND_H

#include "Connector.h"

class And : public Connector{
    private:
    
    public:
        And();
        And( Component* leftChild, Component* rightChild);
        ~And();
        //functions inherited from Component
        bool run();
        void print();
        void add_parameter( string str );
        string get_command();
        
        //ftns inherited from connector
        bool isCommand();
        void SetLHS( Component* lhs );
        void SetRHS( Component* rhs );
};

#endif
