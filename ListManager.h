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
        bool createList(std::string listName);

        bool displayLibrary();

        List& returnList(int libraryPosition);

        List &returnLastList();

        void deleteList(int libraryPosition);

        void saveList(int libraryPosition); //creates SavedLists directory if it doesn't already exist

        void saveAllLists();

        void deleteFile(int libraryPosition);

        void loadSavedLists();

        bool validatePosition(int libraryPosition);
};