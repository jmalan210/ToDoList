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
    library.createList("My-Todo-List1");
    library.createList("My-Todo-List2");
    
    try {

        std::cout << library.returnList(2).getName();
}
    catch (std::out_of_range& e) {

    
    std::cout << e.what();
}
    catch(...)  {
        std::cout << "Something went wrong!";
    };

    Item groceries("Go grocery shopping");

    library.returnList(1).addItem(groceries);
    library.saveList(1);
};