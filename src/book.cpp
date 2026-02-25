#include "../include/book.h"

Book::Book(std::string t, std::string a, std::string b, int q, std::string g)
{
    setTitle(t);
    setAuthor(a);
    setBookId(b);
    setQuantity(q);
    setGenre(g);
}
Book::~Book() {}
void Book::setTitle(std::string t){
    Title = Book::check_trim(t, TitleMaxSize);
}
void Book::setAuthor(std::string a){
    Author = Book::check_trim(a, AuthorMaxSize);
}
void Book::setBookId(std::string b){
    BookId = Book::check_trim(b, BookIdMaxSize);
}
void Book::setGenre(std::string g){
    Genre = Book::check_trim(g, GenreMaxSize);
}
void Book::setQuantity(int q){
    if(q<1)
        throw std::invalid_argument("Quantity should be atleast 1 to make an entry.");
    Quantity = q;
}
void Book::getBookInfo(){
    std::cout<<"Title: "<<Title<<" | Author: "<<Author
        <<" | Book Id: "<<BookId<<" | Genre: "
        <<Genre<<" | Copies Left: "<<((Quantity>0)? 
        std::to_string(Quantity) : "Not Available right now.")<<std::endl;
}
std::string Book::check_trim(std::string s, int m){
    if(s.empty())
        throw std::invalid_argument("This text can't be empty!");
    std::string temp;
    (s.length()<m)? temp = s : temp = s.substr(0, m);
    return temp;
}
bool Book::BorrowBook(int q){
    if(q>Quantity || q <1)
        return false;
    Quantity -= q;
    return true;
}
bool Book::ReturnBook(int q){
    if(q>0){
        Quantity += q;
        return true;
    }
    return false;
}
bool Book::AddBook(int q){
    if(q>1){
        Quantity += q;
        return true;
    }
    return false;
}