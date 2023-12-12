// vending machine main

#include <iostream>
#include "Machine.hpp"

using namespace std;

int main()
{
    Machine machine;
    while(1){
        
        machine.handleUserInput();
        machine.handleDisplayProducts();
        
    
    }
    return 0;
}