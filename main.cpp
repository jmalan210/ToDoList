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
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //instructs the program to ignore new line 
                std::cout << "Invalid response. Try again.\n";
            }
            else if (response !=0 && response != 1 && response != 2)
                
            {
                std::cout << "Invalid response. Try again.\n";
            }
            
            else if (response == 1) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // instructs the program to ignore new line
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
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // instructs the program to ignore new line
                library.displayLibrary();
                std::cout << "Please select a number: ";
                int listNumber;
                std::cin >> listNumber;
                library.returnList(listNumber).displayItems();
                int editChoice;
                
                do {
                    std::cout << "\nWhat would you like to do?\n1. Edit an item description\n 2. Change an item's completion status\n3. Delete a list item\n4. Return to main menu\n";
                    std::cin >> editChoice;

                    if (editChoice == 1){
                        library.returnList(listNumber).displayItems();
                        std::cout << "Please select the number of the item you would like to edit: ";
                        int editItem;
                        std::cin >> editItem;
                        std::cout << "Please enter a new item description: ";
                        std::string newDesc;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // instructs the program to ignore new line

                        std::getline(std::cin, newDesc);
                        library.returnList(listNumber).editDesc(editItem, newDesc);
                        library.returnList(listNumber).displayItems();
                    }

                    else if (editChoice == 2) {
                        library.returnList(listNumber).displayItems();
                        std::cout << "Please select the number of the item you would like to mark complete or incomplete: ";
                        int editItem;
                        std::cin >> editItem;
                        library.returnList(listNumber).toggleCompStatus(editItem);
                        std::cout << "Item status changed!";
                        library.returnList(listNumber).displayItems();
                    }

                    else if (editChoice == 3) {
                        library.returnList(listNumber).displayItems();
                        std::cout << "Please select the number of the item you would like to delete: ";
                        int editItem;
                        std::cin >> editItem;
                        library.returnList(listNumber).deleteItem(editItem);
                        std::cout << "Item deleted!";
                        library.returnList(listNumber).displayItems();
                    }
                } while (editChoice != 4);
            }

            else if ( response == 0) {
                library.saveAllLists();
                std::cout << "All lists saved! Goodbye!";
            }
           
            
        } while (response != 0);

    
};