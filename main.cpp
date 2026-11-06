#include <iostream>
#include <string>
#include <limits>
#include "Item.h"
#include "List.h"
#include "ListManager.h"

int main() {

    ListManager library;
    library.loadSavedLists();
    int response = 0;
    do
        {
            std::cout << "Welcome to Your To-Do List Manager!\n";
            std::cout << "What would you like to do today?\nSelect a number from the list:\n1. Create a new list\n2. Open a saved list\n";
            
            std::cin >> response;
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid response. Try again.\n";
            }
            else if (response != 1 && response != 2)
                
            {
                std::cout << "Invalid response. Try again.\n";
            }
        } while (response != 1 && response != 2);
};