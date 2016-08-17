#include <iostream>
#include <vector>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/types.h>


#include "Command.h"
#include "Semicolon.h"
#include "Or.h"
#include "And.h"
#include "Component.h"
#include "Connector.h"
#include "Comment.h"

using namespace std;

#include <boost/tokenizer.hpp>
using namespace boost;


string getUserName (char *userName) {
    char hostName[500];
    if(gethostname(hostName, sizeof hostName) == -1) {
    		perror("Cannot get Host Name");
          //if equals -1 that means the host name was not found
    }

	if (getlogin() == NULL) {
	    perror("Cannot get User Name");
	    //as long as a number is returned from getlogin(), 
        //then there is a pointer pointing to a string
    }

    else {}
    return hostName;
}



typedef tokenizer<char_separator<char> > mytoken;

int main() {
    string commandString; 
    vector <string> parse;
    vector< Component*> cmds;
    char* userName;
    
    
    while (true) {
        cmds.clear();
        parse.clear();
        
        userName = getlogin();
        cout << userName << "@" << (getUserName(userName)) <<  "$ ";        
        
        //////////////////////////////////////////////////////////////////////////////////////
        /*                      Parsing Command string                                      */
        getline(cin, commandString);
        char_separator<char> delim(" ", ";#");
        tokenizer< char_separator<char> > mytoken(commandString, delim);
        for (mytoken::iterator it = mytoken.begin(); it != mytoken.end(); it++) 
            parse.push_back(*it);//parsing through the tokenizer until there are no more commands
        
        
        
        
        //////////////////////////////////////////////////////////////////////////////////////
        /*                          printing parse vector (test only)                       
        cout << "--------------------------------------------------\n";
        for (unsigned i = 0; i < parse.size(); i++) 
            cout << parse.at( i ) << endl;
        cout << "==================================================\n";
        */
       
        /////////////////////////////////////////////////////////////////////////////////////
        /* Creates the necessary Connector, Comment, and Command Object and adds them to a Component */
        unsigned i = 0;
        while( i < parse.size() ){
            if( parse.at( i ) == "&&" ){
                cmds.push_back( new And() );
                i++;
            }
            else if( parse.at( i ) == "||" ){
                cmds.push_back( new Or() );
                i++;
            }
            else if( parse.at( i ) == ";" ){
                cmds.push_back( new Semicolon() );
                i++;
            }
            else if( parse.at( i ) == "#" ){
                cmds.push_back( new Comment() );
                i++;
                while ( i < parse.size() ){                     //adds the remaining strings in parse vector to Comment object parameters
                    cmds.back()->add_parameter( parse.at( i ) );
                    i++;
                }
            }
            else{
                cmds.push_back( new Command(parse.at( i ) ));
                i++;                                                //adds until the next identifier. i.e. Connector or Comment or end of parsed vector
                while ( i < parse.size() && parse.at(i) != ";" && parse.at(i) != "&&" && parse.at(i) != "||" && parse.at(i) != "#" ){
                    cmds.back()->add_parameter( parse.at(i) );
                    i++;
                }
            }
        }
        
        
        /////////////////////////////////////////////////////////////////////////////////////
        //                  DEVELOP TREE, REMOVE COMMENTS, CHECK FOR VALID FIRST COMMAND
        
        //Make sure that the first Command is not a connector
        if( !cmds.front()->isCommand() ){
            cout << "bash: syntax error near unexpected token `" << cmds.front()->get_command() << "'" << endl;
            continue;
        }
        
        //Comments, if present should and will be the last in cmds vector, here if present we get rid of the
        if( cmds.back()->get_command() == "#" ){//|| cmds.back()->get_command() == "&&" || cmds.back()->get_command() == "" ||){
            cmds.pop_back();
        }
        if( cmds.front()->get_command() == "exit")
            exit(0);
        //if there are multiple commands. i.e. there are connectors
        if( cmds.size() > 1 ){
            vector<Component*> temp;
            Connector* tempConnector = NULL;
    
            for( int i = cmds.size() - 1; i >= 0; --i ){
                cmds.at(i)->print();                                    ///addeed this 
                if( cmds.at(i)->get_command() == "exit")
                    exit(0);
                if( !cmds.at(i)->isCommand() ){
                    tempConnector = static_cast<Connector*>(cmds.at(i));
                }
                else{//not connector
                    temp.push_back( cmds.at(i) );
                    if( temp.size() == 2 ){
                        tempConnector->SetLHS( temp.back() );
                        temp.pop_back();
                        tempConnector->SetRHS( temp.back() );
                        temp.pop_back();
                        temp.push_back( tempConnector );
                    }
                }
            }
            cmds.push_back( temp.back() );
        }
        
        
        /////////////////////////////////////////////////////////////////////////////////////
        //                      EXECUTE COMMAND
        //wether there is only one command or a tree the tree will be the last element
        Component* finalRun = cmds.back();
        if( !cmds.empty() )
            finalRun->run();
    }
    return 0;
}

