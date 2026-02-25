#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "../include/Book.h"
#include "../include/Member.h"
#include "../include/Record.h"
#include "../include/Date.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Record> records;

public:
    Library();
    ~Library();
    
    void addBook(const Book& b);
    bool removeBook(const std::string& bookId);
    void registerMember(const Member& m);
    Book* searchBook(const std::string& idOrTitle);
    Member* searchMember(const std::string& memberId);
    bool issueBook(const std::string& bookId, const std::string& memberId, Date borrowDate);
    bool returnBook(const std::string& bookId, const std::string& memberId, Date returnDate);
    std::string generateRecordId();

    void viewAllBooks();
    void viewAllMembers();
    void viewAllRecords();
};

#endif 