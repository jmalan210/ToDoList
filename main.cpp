#include <iostream>
#include "Item.h"

int main() {

    Item groceries("Go grocery shopping");
    std::string description = groceries.getDesc();
    groceries.setCompStatus(true);
    bool compStatus = groceries.getCompStatus();
    

    std::cout << description << compStatus;
}