module;
export module DateFormats;
//#include<time.h>;
#include<chrono>;
#include<iostream>;
//#include<format>;
std::string months[]{
            "JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"
};
namespace my {
export class time {
    int year;
    unsigned month;
    unsigned day;
    int hour;
    int minutes;
    int seconds;
public:
    time(){
        auto time = std::chrono::system_clock::now();
        auto dp = std::chrono::floor<std::chrono::days>(time);
        std::chrono::year_month_day ymd{ dp };
        std::chrono::hh_mm_ss hhmmss{ std::chrono::floor<std::chrono::seconds>(time - dp) };

        year = (int)ymd.year();

        
        month = (unsigned)ymd.month();
        day = (unsigned)ymd.day();
        hour = hhmmss.hours().count();
        minutes = hhmmss.minutes().count();
        seconds = hhmmss.seconds().count();
    }
    time(std::string zulu) {
        try {
            
            day = std::stoi(zulu.substr(0, 2));
            hour = std::stoi(zulu.substr(2, 2));
            minutes = std::stoi(zulu.substr(4, 2));
            

            std::string monthname = zulu.substr(8, 3); 
            

            for (int i = 0;i < 12;i++) {
                if (monthname == months[i])
                    month = i + 1;
            }

            int yeartemp = std::stoi(zulu.substr(12, 2)); 
            if(yeartemp>=26)
                year = 1000 + yeartemp; 
            else
                year = 2000 + yeartemp;

            seconds = 0; 
        }
        catch (...) {
            
            year=month=day=hour=minutes=seconds = 0;
        }
    }
    /*time(std::string GMT) {
        try {

            year = std::stoi(GMT.substr(0, 4));
            month = std::stoi(GMT.substr(5, 2));
            day = std::stoi(GMT.substr(8, 2));
            hour = std::stoi(GMT.substr(11, 2));
            minutes = std::stoi(GMT.substr(14, 2));
            seconds = std::stoi(GMT.substr(17, 2));
        }
        catch (...) {

            year = month = day = hour = minutes = seconds = 0;
        }
    }*/
    time(int _year, unsigned _month, unsigned _day, int _hour, int _minutes, int _seconds):year(_year),month(_month), day(_day), hour(_hour), minutes(_minutes), seconds(_seconds){}

    void printGMT() {
        
        std::cout
            << std::setw(4) << std::setfill('0') << year << "-"
            << std::setw(2) << std::setfill('0') << month << "-"
            << std::setw(2) << std::setfill('0') << day << " "
            << std::setw(2) << std::setfill('0') << hour << ":"
            << std::setw(2) << std::setfill('0') << minutes << ":"
            << std::setw(2) << std::setfill('0') << seconds << " UTC/GMT"<<std::endl;
            
    }
    void printLocal() {
        std::cout << "Local time "
            << std::setw(4) << std::setfill('0') << year << "-"
            << std::setw(2) << std::setfill('0') << month << "-"
            << std::setw(2) << std::setfill('0') << day << " "
            << std::setw(2) << std::setfill('0') << hour+1 << ":"
            << std::setw(2) << std::setfill('0') << minutes << ":"
            << std::setw(2) << std::setfill('0') << seconds << std::endl;
    }
    void printZULU() {
        std::string months[]{
            "JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"
        };
        std::cout
            << std::setw(2) << std::setfill('0') << day
            << std::setw(2) << std::setfill('0') << hour
            << std::setw(2) << std::setfill('0') << minutes
            << "Z " << months[month - 1] << " " << year % 100 << std::endl;
    }
};


}