#pragma once
#include <string>
#include <chrono>


class Item {
    private:
        std::string m_desc;
        bool m_compStatus = false;
        std::chrono::year_month_day m_dateAdded;
        std::chrono::year_month_day getCurrentDate();

    public:
        Item(std::string desc);

        std::string getDesc() const;

        bool getCompStatus() const;

        void setCompStatus(bool compStatus);
};
