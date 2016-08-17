#include "Comment.h"


Comment::Comment(){
    executable = "#";
}

Command::~Command(){
    argumentList.clear();    
}
        
void Comment::add_parameter(  string str ){
    argumentList.push_back( str );
}

bool Comment::run(){
    return true;
}

void Comment::print(){
    cout << "Executable Command:\t" << executable << "\tParamters: ";
    for(unsigned i = 0; i < argumentList.size(); i++ )
        cout << argumentList.at( i ) << ", ";
    cout << endl;
}


string Comment::get_command(){
    return executable;
}

bool Comment::isCommand(){
    return true;                //need a better implementation, just a temp quick fix
}
