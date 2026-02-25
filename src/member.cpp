#include "../include/member.h"
#include "../include/book.h"

Member::Member(std::string m, std::string n, std::string e)
{
    setMemberId(m);
    setName(n);
    setEmail(e);
}
Member::~Member() {}
void Member::setMemberId(std::string m){
    MemberId = Member::check_trim(m, MemberIdMaxSize);
}
void Member::setName(std::string n){
    Name = Member::check_trim(n, NameMaxSize);
}
void Member::setEmail(std::string e){
    Email = Member::check_trim(e, EmailMaxSize);
}
void Member::displayMember(){
    std::cout<<"Member Name: "<<Name<<" | Member Id: "<<MemberId
             <<" | Email: "<<Email<<" | Borrowed books: "<<std::endl;
    for(auto &b :  BorrowedBooks){
        std::cout<<b->getBookId()<<" ,  ";
    }
}
bool Member::BorrowBook(Book* b){
    BorrowedBooks.push_back(b);
    return true;
}
bool Member::ReturnBook(Book* b){
    auto it = find(BorrowedBooks.begin(), BorrowedBooks.end(), b);
    if(it != BorrowedBooks.end()){
        b->ReturnBook(1);
        BorrowedBooks.erase(it);
        return true;
    }
    return false;
}
void Member::DisplayBorrowed(){
    for(auto b : BorrowedBooks)
        b->getBookInfo();
}
std::string Member::check_trim(std::string s, int m){
    if(s.empty())
        throw std::invalid_argument("This text can't be empty!");
    std::string temp;
    (s.length()<m)? temp = s : temp = s.substr(0, m);
    return temp;
}