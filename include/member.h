#ifndef MEMBER_H
#define MEMBER_H

#include<string>
#include<stdexcept>
#include<iostream>
#include<vector>
#include<algorithm>

class Book;
class Member
{
    public:
        Member(std::string MemberId, std::string Name, std::string Email);
        ~Member();

        std::string getMemberId(){return MemberId;}
        std::string getName(){return Name;}
        std::string getEmail(){return Email;}

        void setMemberId(std::string m);
        void setName(std::string n);
        void setEmail(std::string e);

        void displayMember();
        bool BorrowBook(Book* b);
        bool ReturnBook(Book* b);
        void DisplayBorrowed();
        std::string check_trim(std::string s, int maxSize);

        const int MemberIdMaxSize = 10;
        const int NameMaxSize = 20;
        const int EmailMaxSize = 30;
        std::vector<Book* > BorrowedBooks;
    protected:  
        std::string MemberId;
        std::string Name;
        std::string Email;
        double Fine = 0;  
};

#endif