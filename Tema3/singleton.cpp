#include<iostream>
#include<memory> 
#include<mutex>

class Mutex 
{
    public:
        Mutex(){std::cout<<"Constructor Mutex called\n";}
        ~Mutex(){std::cout<<"Destructor Mutex called\n";}
 
        void lock(Mutex *pm){std::cout<<"locked\n";}
        void unlock(Mutex *pm){std::cout<<"unlocked\n";}
};

class Singleton : public Mutex
{
private :
        static std::shared_ptr<Singleton> instance;
        int value;
        Mutex *_mutex;

        Singleton()
        {
            std::cout<<"Constructor Singleton called\n";
            value = 0;
            lock(_mutex);
        };
        Singleton(const Singleton&);
        Singleton & operator=(const Singleton&);

public :
        ~Singleton() 
        {
            std::cout<<"Destructor Singleton called\n";
            unlock(_mutex);
        }

        int getValue(){ return value;}
        void setValue(int v){value=v;}

        static std::shared_ptr<Singleton> getInstance()
        {
            if(!instance)
            {   
                instance = std:: shared_ptr<Singleton>(new Singleton());
            }
            return instance;
        }
};

std::shared_ptr<Singleton> Singleton::instance=nullptr;

int main()
{
    std::shared_ptr<Singleton> s1(Singleton::getInstance());
        std::cout<<"s1 = "<<s1->getValue()<<std::endl;
        s1->setValue(44);
        std::cout<<"s1 = "<<s1->getValue()<<std::endl;
        std::cout <<"Memory of s1: " << s1.get() << std::endl; 
        std::cout<<"Reference counting: "<<s1.use_count()<<std::endl;
        std::cout<<"-------------------------------------"<<std::endl;
    std::shared_ptr<Singleton> s2(Singleton::getInstance());
        std::cout<<"s2 = "<<s2->getValue()<<std::endl;
        s2->setValue(3);
        std::cout<<"s2 = "<<s2->getValue()<<std::endl;
        std::cout <<"Memory of s2: " << s2.get() << std::endl; 
        std::cout<<"Reference counting: "<<s2.use_count()<<std::endl;
        std::cout<<"-------------------------------------"<<std::endl;
    std::shared_ptr<Singleton> s3(Singleton::getInstance());
        std::cout<<"s3 = "<<s3->getValue()<<std::endl;
        s2->setValue(143);
        std::cout<<"s3 = "<<s3->getValue()<<std::endl;
        std::cout <<"Memory of s3: " << s3.get() << std::endl; 
        std::cout<<"Reference counting: "<<s3.use_count()<<std::endl;

    return 0;
}