#include <iostream>
#include "../library_management/include/Library.h"
#include "../library_management/include/Date.h"

int main() {
    Library lib;
    int choice;

    do {
        std::cout << "\n1. Add Book\n2. Register Member\n3. Issue Book\n4. Return Book\n5. View All Books\n6. View All Members\n7. View All Records\n8. Exit\nChoice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string bookid, title, author, genre;
            int quantity;
            std::cout << "Book ID: "; std::getline(std::cin, bookid);
            std::cout << "Title: "; std::getline(std::cin, title);
            std::cout << "Author: "; std::getline(std::cin, author);
            std::cout << "Genre: "; std::getline(std::cin, genre);
            std::cout << "Total Copies: "; std::cin >> quantity; std::cin.ignore();
            lib.addBook(Book(title, author, bookid, quantity, genre));
        } 
        else if (choice == 2) {
            std::string id, name;
            std::cout << "Member ID: "; std::getline(std::cin, id);
            std::cout << "Name: "; std::getline(std::cin, name);
            std::cout << "Email: "; std::string email; std::getline(std::cin, email);
            lib.registerMember(Member(id, name, email));
        } 
        else if (choice == 3) {
            std::string bookId, memberId;
            int bd, bm, by;
            std::cout << "Book ID: "; std::getline(std::cin, bookId);
            std::cout << "Member ID: "; std::getline(std::cin, memberId);
            std::cout << "Borrow Date (day)";
            std::cin >> bd;
            std::cout << "Borrow Date (month)";
            std::cin >> bm;
            std::cout << "Borrow Date (year)";
            std::cin >> by; std::cin.ignore();
            lib.issueBook(bookId, memberId, Date(bd, bm, by));
        } 
        else if (choice == 4) {
            std::string bookId, memberId;
            int rd, rm, ry;
            std::cout << "Book ID: "; std::getline(std::cin, bookId);
            std::cout << "Member ID: "; std::getline(std::cin, memberId);
            std::cout << "Return Date (day month year): "; std::cin >> rd >> rm >> ry; std::cin.ignore();
            lib.returnBook(bookId, memberId, Date(rd, rm, ry));
        } 
        else if (choice == 5) {
            lib.viewAllBooks();
        } 
        else if (choice == 6) {
            lib.viewAllMembers();
        } 
        else if (choice == 7) {
            lib.viewAllRecords();
        }

    } while (choice != 8);

    return 0;
}