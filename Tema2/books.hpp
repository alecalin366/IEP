#include<iostream>
#include<map>
#include<list>
#include<string>
#include <iterator>
#include<memory>

class Books
{
public:
    Books(std::string author, std::string title, int bookRating) : author_(author),title_(title), bookRating_(bookRating){} 
    Books(const Books&); 
    Books& operator=(const Books&); 
    ~Books(); 
    virtual void print(std::ostream&);

protected:
    std::string author_;
    std::string title_;
    int bookRating_;
};

template<typename T>
void add(std::list<std::shared_ptr<Books>> &list,const T &a)
{
    auto x=std::make_shared<T>(a);
    list.push_back(x);;
}

template<typename T>
std::ostream& operator<<(std::ostream& os,const std::list<std::shared_ptr<T>>& b){
    for(auto it : b){
        it->print(os);
        os<<"\n";
    }
    return os;
}
