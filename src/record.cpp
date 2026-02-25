#include "../include/record.h"
#include "../include/date.h"

Record::Record(std::string r, std::string m, std::string b,
               int day, int mon, int yr)
    : DateBorrowed(day, mon, yr){
    setRecordId(r);
    setMemberId(m);
    setBookId(b);
}
Record::~Record() {}
void Record::setBookId(std::string b){
    BookId = Record::check_trim(b, IdMaxSize);
}
void Record::setMemberId(std::string m){
    MemberId = Record::check_trim(m, IdMaxSize);
}
void Record::setRecordId(std::string r){
    RecordId = Record::check_trim(r, IdMaxSize);
}
void Record::setDateReturned(int day, int mon, int yr){
    DateReturned.setDay(day);
    DateReturned.setMonth(mon);
    DateReturned.setYear(yr);
}
void Record::displayRecord(){
    std::cout<<"Record Id: "<<RecordId<<" | Member id: "<<MemberId
             <<" | Book Id: "<<BookId<<" | Issue date: "<<DateBorrowed.getDay()
             <<","<<DateBorrowed.getMonth()<<","<<DateBorrowed.getYear();
    if(DateReturned.getDay()!= 0){
        std::cout<<" | Return Date: "<<DateReturned.getDay()<<","<<DateReturned.getMonth()
                 <<","<<DateReturned.getYear()<<std::endl;
    }
    else
        std::cout<<std::endl;
}
std::string Record::check_trim(std::string s, int m){
    if(s.empty())
        throw std::invalid_argument("This text can't be empty!");
    std::string temp;
    (s.length()<m)? temp = s : temp = s.substr(0, m);
    return temp;
}