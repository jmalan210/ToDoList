#pragma once
#include <string>
#include <vector>
#include "Item.h"

class List {
    private:
        std::string m_name;
        std::vector<Item> m_list;

    public:
        List(std::string name);

        std::string getName() const;

        void addItem(Item item);

        void displayItems();
};