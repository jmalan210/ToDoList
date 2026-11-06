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
    std::string listName = "";
    std::cout << "Welcome to Your To-Do List Manager!\n";
    do
        {
            
            std::cout << "\nWhat would you like to do?\nSelect a number from the list:\n1. Create a new list\n2. Open a saved list\nPress 0 to quit at any time.\n";
            
            std::cin >> response;
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid response. Try again.\n";
            }
            else if (response !=0 && response != 1 && response != 2)
                
            {
                std::cout << "Invalid response. Try again.\n";
            }
            
            else if (response == 1) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "What would you like to name your list? ";
                std::getline(std::cin, listName);
                library.createList(listName);
                std::cout << "Add an item to this list? (y/n) ";
                std::string addItem;
                std::getline(std::cin, addItem);

                if (addItem == "y") {
                do {
                    std::cout << "What would you like to add to the list? ";
                    std::string item;
                    std::getline(std::cin, item);
                    library.returnLastList().addItem(item);
                    std::cout << "Add another item? (y/n) ";
                    std::getline(std::cin, addItem);
                } while (addItem == "y");
                }
            }

            else if (response ==2) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                library.displayLibrary();
                std::cout << "Please select a number: ";
                int listNumber;
                std::cin >> listNumber;
            }

            else if ( response == 0) {
                library.saveAllLists();
                std::cout << "All lists saved! Goodbye!";
            }
           
            
        } while (response != 0);

    
};