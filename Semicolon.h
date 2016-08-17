#ifndef SEMICOLON_H
#define SEMICOLON_H

#include "Connector.h"

class Semicolon : public Connector{
    private:
    
    public:
        Semicolon();
        Semicolon( Component* leftChild, Component* rightChild);
        ~Semicolon();
        
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
