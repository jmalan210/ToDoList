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

void Item::setDesc( std::string desc) {
    m_desc = desc;
}

std::chrono::year_month_day Item::getDateAdded() const
{
    return m_dateAdded;
}

Item::Item(std::string desc) : m_desc{desc}, m_compStatus{false}, m_dateAdded{getCurrentDate()}
{
}

Item::Item(std::chrono::year_month_day dateAdded, std::string desc, bool compStatus) : m_desc{desc}, m_compStatus{compStatus}, m_dateAdded {dateAdded} {}