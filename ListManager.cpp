#include "ListManager.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <filesystem>

bool ListManager::listExists(std::string listName) {
    for (List list : m_library) {
       
        if (list.getName() == listName) {
            return true;
        }
    }
        return false;
    }

void ListManager::createList(std::string listName) {
    if (listExists(listName) == false) {
        List newList({listName});
        m_library.push_back(newList);
    }
    else
        std::cout << "\n" << listName << " already exists. Please try again. \n";
}

void ListManager::displayLibrary() {
    
        for (int i = 0; i < m_library.size(); i++)
           
            {
                std::cout << i+1 << ". "<< m_library[i].getName() << "\n";
            }
}

bool ListManager::isValidPosition(int libraryPosition) {
    if (libraryPosition <= 0 || libraryPosition > m_library.size()) {
        return false;
    }
    return true;
}

List& ListManager::returnList(int libraryPosition) {

    if (isValidPosition(libraryPosition) == false) {
        throw std::out_of_range("That number is not on the list");
    }
    else
        return m_library[libraryPosition-1];
}

void ListManager::deleteList(int libraryPosition){
    if (isValidPosition(libraryPosition) == false) {
        throw std::out_of_range("That number is not on the list");
    }
    else
        m_library.erase(m_library.begin() + libraryPosition - 1);

}

//creates SavedFiles directory if it doesn't already exist
void ListManager::saveList(int libraryPosition) {
    if (isValidPosition(libraryPosition) == false)
    {
        throw std::out_of_range("That number is not on the list");
    }
   else if (!std::filesystem::exists("SavedLists")) {
       std::filesystem::create_directory("SavedLists");
   }

   m_library[libraryPosition - 1].saveToFile();

}

void ListManager::deleteFile(int libraryPosition){
    if (isValidPosition(libraryPosition) == false)
    {
        throw std::out_of_range("That number is not on the list");
    }
    else {
        std::filesystem::remove("SavedLists/" + m_library[libraryPosition-1].getName() + ".txt");
    }
}
