#include"books.hpp"

Books::Books(const Books& b) : author_(b.author_),title_(b.title_),bookRating_(b.bookRating_) {}
Books::~Books(){}

void Books::print(std::ostream& os)
{
    os<<"Author:"<<author_<<"-"<<"Title:"<<title_<<"-"<<"-"<<"Rating:"<<bookRating_;
}

int main()
{
std::list<Books> borrowedBooks;

Books b1("Dostoievski","Crima si Pedeapsa",5);
Books b2("Charlotte Bronte","Jane Eyre",5);
Books b3("Bacovia","Plumb",1);
Books b4("Hector Malot","Singur pe lume",3);
Books b5("George Calinescu","Enigma Otiliei",2);
Books b6(b5);
//b6=b1;

add(borrowedBooks,b1);
add(borrowedBooks,b2);
add(borrowedBooks,b3);
add(borrowedBooks,b4);
add(borrowedBooks,b5);
add(borrowedBooks,b6);


std::cout<<"All Books borrowed:"<<std::endl;
std::cout<<borrowedBooks<<std::endl;
}
