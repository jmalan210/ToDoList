#include "ListManager.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <filesystem>
#include <fstream>

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
    else {
        deleteFile(libraryPosition);
        m_library.erase(m_library.begin() + libraryPosition - 1);
    }
        

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

void ListManager::loadSavedLists(){
    if (!std::filesystem::exists("SavedLists")) {
        return;
    }
    for (std::filesystem::directory_entry file : std::filesystem::directory_iterator("SavedLists")) {

        if (file.path().extension() == ".txt") {
           std::string fileName = file.path().stem().string();

           createList(fileName);

           std::ifstream inputFile(file.path());

           std::string line;
           
           if (std::getline(inputFile, line)) {
                       

                while (std::getline(inputFile, line)) {

                    std::string desc = line.substr(0, line.find('|'));
                    std::string status = line.substr(line.find('|') + 1, 1);
                    bool compStatus = (status == "1");
                    std::string date = line.substr(line.find('|') + 3);
                    int year = std::stoi(date.substr(0, 4));
                    int month = std::stoi(date.substr(date.find('-') + 1, 2));
                    int day = std::stoi(date.substr(date.find('-') + 4));

               std::chrono::year_month_day wholeDate = std::chrono::year(year) / std::chrono::month(month) / std::chrono::day(day);

               Item item(wholeDate, desc, compStatus);

               returnList(m_library.size()).addItem(item);
           }
            
                }
        
    }
}
}
   
