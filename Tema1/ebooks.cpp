#include<iostream>
#include "ebooks.hpp"

Ebooks& Ebooks::operator=(const Ebooks& b)
{
    if(&b!=this)
    {
        Books::operator=(b);
        this->sizeMB_=b.sizeMB_;   
    }
    return *this;
}

void Ebooks::print(std::ostream& os)
{
    Books::print(os);
    os << "-SizeMB :"<<sizeMB_;
}