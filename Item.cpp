#include "Item.h"

std::chrono::year_month_day Item::getCurrentDate(){
    auto now = std::chrono::system_clock::now();
    auto currentDate = std::chrono::floor<std::chrono::days>(now);
    auto date = std::chrono::year_month_day(currentDate);
    return date;
}

std::string Item::getDesc() const {
    return m_desc;
}

bool Item::getCompStatus() const
{
    return m_compStatus;
}

void Item::setCompStatus(bool compStatus)
{
    m_compStatus = compStatus;
}

Item::Item(std::string desc) : m_desc{desc}, m_compStatus{false}, m_dateAdded{getCurrentDate()}
{
}