#include"ebooks.hpp"

Books::Books(const Books& b) : author_(b.author_),title_(b.title_),bookRating_(b.bookRating_) {}

Books& Books::operator=(const Books& b)
{
    if(this!=&b)
    {
        this->author_=b.author_;
        this->title_=b.title_;
        this->bookRating_=b.bookRating_;
    }
    return *this;
}

Books::~Books(){}

void Books::print(std::ostream& os)
{
    os<<"Author:"<<author_<<"-"<<"Title:"<<title_<<"-"<<"-"<<"Rating:"<<bookRating_;
}

int main()
{
std::list<std::shared_ptr<Books>> borrowedBooks ;

Ebooks b1("Dostoievski","Crima si Pedeapsa",5,354);
Ebooks b2("Charlotte Bronte","Jane Eyre",5,127);
Books b3("Bacovia","Plumb",1);
Books b4("Hector Malot","Singur pe lume",3);
Ebooks b5("George Calinescu","Enigma Otiliei",2,259);
Books b6(b5);
b6=b1;

add(borrowedBooks,b1);
add(borrowedBooks,b2);
add(borrowedBooks,b3);
add(borrowedBooks,b4);
add(borrowedBooks,b5);
add(borrowedBooks,b6);


std::cout<<"All Books borrowed:"<<std::endl;
std::cout<<borrowedBooks<<std::endl;
}
