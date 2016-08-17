#include "Or.h"


Or::Or(){
    executable = "||";
}

Or::Or( Component* leftChild, Component* rightChild){
    LHS = leftChild;
    RHS = rightChild;
    
    executable = "||";
}

Or::~Or(){
    
}

//functions inherited from Component
bool Or::run(){
    bool lhsPassed = LHS->run();
    
    if( !lhsPassed ){
        RHS->run();
        return true;
    }
    return false;
}

void Or::print(){
    cout << "Connector Command:\t" << executable << endl;
}

void Or::add_parameter( string str ){
    //no parameters for connectors
}

string Or::get_command(){
    return executable;
}

bool Or::isCommand(){
    return false;
}

void Or::SetLHS( Component* lhs ){
    LHS = lhs;
}

void Or::SetRHS( Component* rhs ){
    RHS = rhs;
}
