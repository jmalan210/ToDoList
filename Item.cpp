#include "Item.h"

std::chrono::year_month_day Item::getCurrentDate(){
    auto now = std::chrono::system_clock::now();
    auto currentDate = std::chrono::floor<std::chrono::days>(now);
    auto date = std::chrono::year_month_day(currentDate);
    return date;
}
Item::Item(std::string desc) : m_desc{desc}, m_compStatus{false}, m_dateAdded{getCurrentDate()}
{
}