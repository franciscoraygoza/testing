#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Component {
    protected:
        string executable;
        vector<string> argumentList;
        
    public:
        Component();
        ~Component();
        virtual bool run() = 0;
        virtual void add_parameter( string str ) = 0;
        virtual void print() = 0;
        virtual string get_command() = 0;
        virtual bool isCommand() = 0;
};


#endif
