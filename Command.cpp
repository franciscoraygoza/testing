#include "Command.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/types.h>

Command::Command(){
    
}

Command::~Command(){
    argumentList.clear();
}
        
Command::Command( string exec ){
    // cout << "Command 1 param Ctor\n";
    executable = exec;
}

void Command::add_parameter(  string str ){
    // cout << "Command::add_parameter( string str )\n";
    argumentList.push_back( str );
    // cout << "argumentList.size() = " << argumentList.size() << endl;
}

bool Command::run(){
    int pid = fork();

    switch(pid) {
        case -1:{
            perror ("Error in creating new process");
            exit(0);
        }
            break;
            
        case 0:{
            char* c = const_cast<char*>( executable.c_str() );
            vector<char*> command;
            command.push_back( c );
            for( unsigned i = 0; i < argumentList.size(); ++i ){
                command.push_back(const_cast<char*>(argumentList.at(i).c_str()));
            }
            command.push_back('\0' );
            if (execvp( command[0], &command[0] ) > 0) {
                //execvp used to link together files compiled by program
                return true;
            }
            else {
                perror ("Error in execvp");
                exit(1);
            }
        }
        break;
            
        default:
        {
            int current;
            if (waitpid(pid, &current, 0) == -1) {
                perror("Error in wait");
                return false;
            }
            if(current == 0){
                    return true;
            }
            return false;
        }
        break;
    }
    return false;
}

void Command::print(){
    cout << "Executable Command:\t" << executable << "\tParameters: ";
    for(unsigned i = 0; i < argumentList.size(); i++ )
        cout << argumentList.at( i ) << " ";
    cout << endl;
}


string Command::get_command(){
    return executable;
}

bool Command::isCommand(){
    return true;
}
