#include <iostream>
#include "Item.h"
#include "List.h"

int main() {

    List todoList("My To-Do List");
    Item groceries("Go grocery shopping");
    Item bills("Pay bills");
    Item laundry("Wash laundry");

    todoList.addItem(groceries);
    todoList.addItem(bills);
    todoList.addItem(laundry);
    todoList.displayItems();
}