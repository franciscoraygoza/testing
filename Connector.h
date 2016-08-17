#ifndef CONNECTOR_H
#define CONNECTOR_H


#include "Component.h"
#include <string> 
#include <iostream>

using namespace std;

class Connector : public Component{
    protected:
        Component* LHS;
        Component* RHS;
        
    public:
        Connector();
        ~Connector();
        
        virtual void SetLHS( Component* lhs ) = 0;
        virtual void SetRHS( Component* rhs ) = 0;
};

#endif
