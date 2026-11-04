#include <iostream>
#include <iomanip>
#include <cstddef>
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
    
        for (int i = 0; i < m_list.size(); i++) {
            
            
        std::cout << i+1 <<". " << std::left << std::setw(30) << m_list[i].getDesc();

        if (m_list[i].getCompStatus() == true)
        {
            std::cout << "[X]\n";
        }
        else
        {
            std::cout << "[ ]\n";
        }
        }
    }

//helper function to make sure that the number entered matches a position on the List
bool List::isValidPosition(int listPosition) {
    if (listPosition <= 0 )
    {
        
        return false;
    }

    if (static_cast<std::size_t>(listPosition) <= m_list.size())
        {
            return true;
        }

        return false;
}

void List::toggleCompStatus(int listPosition) {

    if (isValidPosition(listPosition) == false) {
        std::cout << "Invalid input. Please try again.";
        return;
    }
    else
    m_list[listPosition - 1].setCompStatus(!m_list[listPosition -1].getCompStatus());

}

void List::editDesc(int listPosition, std::string newDesc) {

    if (isValidPosition(listPosition) == false)
    {
        std::cout << "Invalid input. Please try again.";
        return;
    }
    else
        m_list[listPosition - 1].setDesc(newDesc);
}

void List::deleteItem(int listPosition) {
    if (isValidPosition(listPosition) == false) {
        std::cout << "Invalid input. Please try again.";
        return;
    }
    else
        m_list.erase(m_list.begin() + listPosition -1);
}
