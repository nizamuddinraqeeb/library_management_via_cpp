#ifndef RECORD_H
#define RECORD_H

#include<iostream>
#include<string>
#include<vector>
#include "../include/date.h"

class Date;
class Record{
    public:
        Record(std::string r, std::string m, std::string b,int day, int mon, int yr);
        ~Record();

        std::string getRecordId(){return RecordId;}
        std::string getMemberId(){return MemberId;}
        std::string getBookId(){return BookId;}
        Date getDateBorrowed(){return DateBorrowed;}
        Date getDateReturned(){return DateReturned;}

        void displayRecord();
        void setRecordId(std::string r);
        void setMemberId(std::string m);
        void setBookId(std::string b);
        void setDateReturned(int day, int mon, int yr);

        std::string check_trim(std::string s, int maxSize);
    protected:
        std::string RecordId;
        std::string MemberId;
        std::string BookId;
        Date DateBorrowed;
        Date DateReturned = Date(0, 0 , 0);

        const int IdMaxSize = 10;
};



#endif