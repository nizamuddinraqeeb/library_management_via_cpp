#include "../include/library.h"
#include <algorithm>
#include<fstream>

Library::Library() {
    books = std::vector<Book>();
    members = std::vector<Member>();
    records = std::vector<Record>();
}
Library::~Library() {
}
void Library::addBook(const Book& b) {
    books.push_back(b);
}

bool Library::removeBook(const std::string& bookId) {
    auto it = std::find_if(books.begin(), books.end(), 
    [&bookId](const Book& b){return bookId == b.getBookId();});
    if (it != books.end()) {
        books.erase(it);
        return true;
    }
    return false;
}

void Library::registerMember(const Member& m) {
    members.push_back(m);
}

Book* Library::searchBook(const std::string& idOrTitle) {
    for (auto& b : books) {
        if (b.getBookId() == idOrTitle || b.getTitle() == idOrTitle)
            return &b;
    }
    return nullptr;
}

Member* Library::searchMember(const std::string& memberId) {
    for (auto& m : members) {
        if (m.getMemberId() == memberId)
            return &m;
    }
    return nullptr;
}

bool Library::issueBook(const std::string& bookId, const std::string& memberId, Date borrowDate) {
    Book* b = searchBook(bookId);
    Member* m = searchMember(memberId);
    if (b && m && b->BorrowBook(1)) {
        records.emplace_back(Record(generateRecordId(), memberId, bookId,
                                    borrowDate.getDay(), borrowDate.getMonth(), borrowDate.getYear()));
        m->BorrowBook(b);
        return true;
    }
    return false;
}

bool Library::returnBook(const std::string& bookId, const std::string& memberId, Date returnDate) {
    for (auto& r : records) {
        if (r.getBookId() == bookId && r.getMemberId() == memberId && r.getDateReturned().isEmpty()) {
            r.setDateReturned(returnDate.getDay(), returnDate.getMonth(), returnDate.getYear());
            Book* b = searchBook(bookId);
            if (b) b->ReturnBook(1);
            Member* m = searchMember(memberId);
            if (m) m->ReturnBook(b);
            return true;
        }
    }
    return false;
}

std::string Library::generateRecordId() {
    return "R" + std::to_string(records.size() + 1);
}


void Library::viewAllBooks() {
    for (auto& b : books) {
        b.getBookInfo();
    }
}

void Library::viewAllMembers() {
    for (auto& m : members) {
        m.displayMember();
    }
}

void Library::viewAllRecords() {
    for (auto& r : records) {
        r.displayRecord();
    }
}