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
            
            std::cout << "\nWhat would you like to do?\nSelect a number from the list:\n1. Create a new list\n2. Open a saved list\n3. Delete a saved list\n4. Save and quit.\n";
            
            std::cin >> response;
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //instructs the program to ignore new line 
                std::cout << "Invalid response. Try again.\n";
                response = 1; //satisfies do-while loop condition so loop continues (otherwise response defaults to 0)
                continue;
            }
            else if (response !=0 && response != 1 && response != 2 && response != 3 && response != 4)
                
            {
                std::cout << "Invalid response. Try again.\n";
                continue;
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

                if (library.displayLibrary() == false) {
                    std::cout << "No lists to display. Please select 1 to create a new list";
                }
                else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // instructs the program to ignore new line
                
                std::cout << "Please select a number: ";
                int listNumber;
                std::cin >> listNumber;
                if (!std::cin)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // instructs the program to ignore new line
                    std::cout << "Invalid response. Try again.\n";
                    continue;
                }

                if (library.validatePosition(listNumber) == true) {

                library.returnList(listNumber).displayItems();}
                 
                else {
                    std::cout << "Invalid input.";
                    continue;
                }

                int editChoice = 6;
                
                do {
                    std::cout << "\nWhat would you like to do?\n1. Add a new item\n2. Edit an item description\n3. Change an item's completion status\n4. Delete a list item\n5. Return to main menu\n";
                    std::cin >> editChoice;
                    if (!std::cin)
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // instructs the program to ignore new line
                        std::cout << "Invalid response. Try again.\n";
                        continue;
                    }

                    if (editChoice == 1){
                        library.returnList(listNumber).displayItems();
                        std::cout << "Please enter a new item description: ";
                        std::string newDesc;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // instructs the program to ignore new line
                        std::getline(std::cin, newDesc);
                        library.returnList(listNumber).addItem(newDesc);
                        library.returnList(listNumber).displayItems();
                    }
                                        

                    else if (editChoice == 2){
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

                    else if (editChoice == 3) {
                        library.returnList(listNumber).displayItems();
                        std::cout << "Please select the number of the item you would like to mark complete or incomplete: ";
                        int editItem;
                        std::cin >> editItem;
                        library.returnList(listNumber).toggleCompStatus(editItem);
                        std::cout << "Item status changed!\n";
                        library.returnList(listNumber).displayItems();
                    }

                    else if (editChoice == 4) {
                        library.returnList(listNumber).displayItems();
                        std::cout << "Please select the number of the item you would like to delete: ";
                        int editItem;
                        std::cin >> editItem;
                        library.returnList(listNumber).deleteItem(editItem);
                        std::cout << "Item deleted!\n";
                        library.returnList(listNumber).displayItems();
                    }
                    else if (editChoice !=5) {

                        
                            std::cout << "Invalid response. Try again.\n";
                        
                    }
                } while (editChoice != 5);
            }
        }
            else if (response == 3) {
                if (library.displayLibrary() == false) {
                    std::cout << "No libraries to delete. Please select 1 to create a new list.";
                }
                else {
                    
                    std::cout << "Please select the number of the list you would like to delete.";
                    int delFile;
                    std::cin >> delFile;
                    if (!std::cin)
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // instructs the program to ignore new line
                        std::cout << "Invalid response. Try again.\n";
                        response = 1; // satisfies do-while loop condition so loop continues (otherwise response defaults to 0)
                        continue;
                    }

                    else {
                        if (library.validatePosition(delFile) ==true) {
                            library.deleteList(delFile);
                            std::cout << "List successfully deleted.";
                        }
                        else {
                            std::cout << "No file exists at that number. Please try again";
                        }
                    }
                }
            }
            else if ( response == 4) {
                library.saveAllLists();
                std::cout << "All lists saved! Goodbye!";
               
            }
           
            
        } while (response != 4);

    
};