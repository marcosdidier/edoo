#include <iostream>
#include <ctime>
#include "date.h"

void Date::print(){
    std::cout << month << '/' << day << '/' << year << std::endl;
}

void Date::init(int month, int day, int year){
    this->month = month;
    this->day = day;
    this->year = year;
}

void Date::init(void){
    time_t now = time(nullptr);
    struct tm *local = localtime(&now);

    this->month = local->tm_mon + 1;
    this->day = local->tm_mday;
    this->year = local->tm_year + 1900;
}

