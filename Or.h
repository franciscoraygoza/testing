#ifndef OR_H
#define OR_H


#include "Connector.h"

class Or : public Connector{
    private:
        
    public:
        Or();
        Or( Component* leftChild, Component* rightChild);
        ~Or();
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
