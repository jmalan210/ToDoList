#include <iostream>
#include "List.h"

List::List (std::string name): m_name{name} {

}

std::string List::getName() const {
    return m_name;
}

void List::addItem(Item item) {
    m_list.push_back(item);
}

void List::displayItems() {
    for (Item item : m_list) {
        if (item.getCompStatus() == true) {
            std::cout << "✓";
        }
        else {
            std::cout << "__";
        }

        std::cout << item.getDesc() << "\n";
    }
}