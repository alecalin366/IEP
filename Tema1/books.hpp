#include<iostream>
#include<map>
#include<list>
#include<string>

class Books
{
public:
Books(std::string author, std::string title, int bookRating) : author_(author),title_(title), bookRating_(bookRating){} 
Books(const Books&); 
~Books();
void print(std::ostream& os);

private:
std::string author_;
std::string title_;
int bookRating_;

Books& operator=(const Books&);
};

template<typename T>
void add(std::list<Books> &list,const T &a)
{
    list.push_back(a);
}

std::ostream& operator<<(std::ostream& os,const std::list<Books>& b){
    for(auto it : b){
        it.print(os);
        os<<"\n";
    }
    return os;
}
