#ifndef BOOK_H
#define BOOK_H

#include <string>
#include<stdexcept>
#include<iostream>
class Book
{

    public:
        Book(std::string t, std::string a, std::string b, int q,std::string g);
        ~Book();

        std::string getTitle() const {return Title;}
        std::string getAuthor() const {return Author;}
        std::string getBookId() const {return BookId;}
        int getQuantity() const {return Quantity;}
        std::string getGenre() const {return Genre;}

        void setTitle(std::string t);
        void setAuthor(std::string a);
        void setBookId(std::string b);
        void setQuantity(int q);
        void setGenre(std::string g);

        std::string check_trim(std::string s, int maxSize);
        void getBookInfo();
        bool BorrowBook(int q);
        bool ReturnBook(int q);
        bool AddBook(int q);

    protected:
        std::string Title;
        std::string Author;
        std::string BookId;
        int Quantity;
        std::string Genre;

        static const int TitleMaxSize = 50;
        static const int AuthorMaxSize = 20;
        static const int BookIdMaxSize = 10;
        static const int GenreMaxSize = 15;
        
};

#endif