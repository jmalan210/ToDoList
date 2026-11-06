#include <iostream>
#include "Item.h"
#include "List.h"
#include "ListManager.h"

int main() {

    // List todoList("My To-Do List");
    // Item groceries("Go grocery shopping");
    // Item bills("Pay bills");
    // Item laundry("Wash laundry");

    // todoList.addItem(groceries);
    // todoList.addItem(bills);
    // todoList.addItem(laundry);
    

    // todoList.toggleCompStatus(2);
    // // todoList.editDesc(2, "Go to the post office");
    // todoList.deleteItem(2);
    // todoList.displayItems();

    ListManager library;
    library.loadSavedLists();
    library.displayLibrary();
    
};