#pragma once
#include "List.h"
#include <string>
#include <vector>
#include <iostream>

class ListManager {
    private:
        std::vector<List> m_library;
        bool listExists(std::string listName);
        bool isValidPosition(int libraryPosition);

    public:
        void createList(std::string listName);

        void displayLibrary();

        List& returnList(int libraryPosition);

        void deleteList(int libraryPosition);

        void saveList(int libraryPosition); //creates SavedFiles directory if it doesn't already exist

        void deleteFile(int libraryPosition);
};