#include "Semicolon.h"


Semicolon::Semicolon(){
    executable = ";";
}

//current implementation does not use this constructor but future implementations might
Semicolon::Semicolon( Component* leftChild, Component* rightChild){
    LHS = leftChild;
    RHS = rightChild;
    
    executable = ";";
}

Semicolon::~Semicolon(){
    
}

//functions inherited from Component
bool Semicolon::run(){
    LHS->run();
    RHS->run();
    
    return true;
}

//testing functions
void Semicolon::print(){
    cout << "Connector Command:\t" << executable << endl;
}


void Semicolon::add_parameter( string str ){
    //connectors dont have parameters... yet, but needs to be here because
    //function is inherited from Component.h
}


string Semicolon::get_command(){
    return executable;
}

bool Semicolon::isCommand(){
    return false;
}

void Semicolon::SetLHS( Component* lhs ){
    LHS = lhs;
}

void Semicolon::SetRHS( Component* rhs ){
    RHS = rhs;
}
