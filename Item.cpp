#include "Item.h"

//function gets current date from the system and converts it into a year_month_day object
std::chrono::year_month_day Item::getCurrentDate(){
    auto now = std::chrono::system_clock::now();
    auto currentDate = std::chrono::floor<std::chrono::days>(now);
    auto date = std::chrono::year_month_day(currentDate);
    return date;
}

//returns the description of the Item
std::string Item::getDesc() const {
    return m_desc;
}

//returns the completion status of the Item
bool Item::getCompStatus() const
{
    return m_compStatus;
}

//sets the completion status of the Item
void Item::setCompStatus(bool compStatus)
{
    m_compStatus = compStatus;
}

//sets the description of the Item
void Item::setDesc( std::string desc) {
    m_desc = desc;
}

//returns the date that the item was added to the list
std::chrono::year_month_day Item::getDateAdded() const
{
    return m_dateAdded;
}

//Item constructors
Item::Item(std::string desc) : m_desc{desc}, m_compStatus{false}, m_dateAdded{getCurrentDate()}
{
}

Item::Item(std::chrono::year_month_day dateAdded, std::string desc, bool compStatus) : m_desc{desc}, m_compStatus{compStatus}, m_dateAdded {dateAdded} {}