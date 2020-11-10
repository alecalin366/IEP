#include"books.hpp"

class Ebooks : public Books
{
    private:
            int sizeMB_;
    public:
            Ebooks(std::string author_, std::string title_, int bookRating_, int sizeMB) : Books(author_, title_, bookRating_), sizeMB_(sizeMB){}
            Ebooks& operator=(const Ebooks&);
            void print(std::ostream& os);
};