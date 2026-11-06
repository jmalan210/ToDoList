#include <iostream>
#include <iomanip>
#include <fstream>
#include "List.h"

//List constructor
List::List (std::string name): m_name{name} {

}

//returns the name of the List
std::string List::getName() const {
    return m_name;
}

//adds an item to the back of the list
void List::addItem(Item item) {
    m_list.push_back(item);
}

//displays each item on the list
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

//toggles the boolean value of the indicated List item 
void List::toggleCompStatus(int listPosition) {

    if (isValidPosition(listPosition) == false) {
        std::cout << "Invalid input. Please try again.";
        return;
    }
    else
    m_list[listPosition - 1].setCompStatus(!m_list[listPosition -1].getCompStatus());

}

//edits the description of the indicated List item
void List::editDesc(int listPosition, std::string newDesc) {

    if (isValidPosition(listPosition) == false)
    {
        std::cout << "Invalid input. Please try again.";
        return;
    }
    else
        m_list[listPosition - 1].setDesc(newDesc);
}

//deletes an item at the indicated List position
void List::deleteItem(int listPosition) {
    if (isValidPosition(listPosition) == false) {
        std::cout << "Invalid input. Please try again.";
        return;
    }
    else
        m_list.erase(m_list.begin() + listPosition -1);
}

//writes the file to the SavedLists/ directory
void List::saveToFile() const{
    std::ofstream outFile("SavedLists/" + m_name + ".txt");
    if (outFile) {
        outFile << m_name << "\n";
        for (Item item : m_list) {

            outFile << item.getDesc() << "|" << item.getCompStatus() << "|" << item.getDateAdded().year() << "-" << static_cast<unsigned>(item.getDateAdded().month()) << "-" << item.getDateAdded().day() << "\n";
        }
    }
    else
        std::cerr <<"File failed to save";
}
