#include "And.h"


And::And(){
    executable = "&&";
}

And::And( Component* leftChild, Component* rightChild){
    LHS = leftChild;
    RHS = rightChild;
    
    executable = "&&";
}

And::~And(){
    //nothing to erase
}

//functions inherited from Component
bool And::run(){
    bool lhsPassed = LHS->run();
    
    if( lhsPassed ){
        RHS->run();
        return true;
    }
    return false;
}

void And::print(){
    cout << "Connector Command:\t" << executable << endl;
}


void And::add_parameter( string str ){
    //no params for connectors 
}

string And::get_command(){
    return executable;
}

bool And::isCommand(){
    return falseP:;
}

void And::SetLHS( Component* lhs ){
    LHS = lhs;
}

void And::SetRHS( Component* rhs ){
    RHS = rhs;
}
