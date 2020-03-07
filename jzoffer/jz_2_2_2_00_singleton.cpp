/*
 * @brief       单例模式练习
 * @author      xxmcf
 * @version     1.0
 * @date        2020/03/06
*/

#include "pub.h"
#include <algorithm>
#include <memory> //std::shared_ptr
#include <iostream>
#include <mutex>

//返回单例的指针
class Singleton1
{
public:
    static Singleton1* getInstance()
    {
        if (nullptr == ptr_)
        {
            std::lock_guard<std::mutex> guard(mutex_);
            if (nullptr == ptr_)
            {
                ptr_ = std::shared_ptr<Singleton1>(new Singleton1());
            }
        }
        return ptr_.get();
    }

    void print()
    {
        std::cout << "[0x" << this << "] Singleton1" << std::endl;
    }

    Singleton1(const Singleton1&) = delete;
    Singleton1& operator=(const Singleton1&) = delete;
    ~Singleton1()
    {
        std::cout << "[0x" << this << "] Singleton1 destroy." << std::endl;
    }

private:
    Singleton1()
    {
        std::cout << "[0x" << this << "] Singleton1 create." << std::endl;
    }



private:
    static std::shared_ptr<Singleton1> ptr_;
    static std::mutex mutex_;
};

std::shared_ptr<Singleton1> Singleton1::ptr_ = nullptr;
std::mutex Singleton1::mutex_;

//濑汉模式
class Singleton2
{
public:
    static Singleton2& getInstance()
    {
        std::cout << "getInstance" << std::endl;
        static Singleton2 instance;
        return instance;
    }
    void print()
    {
        std::cout << "[0x" << this << "] Singleton2" << std::endl;
    }

    Singleton2(const Singleton2&) = delete;
    Singleton2& operator=(const Singleton2&) = delete;

    ~Singleton2()
    {
        std::cout << "[0x" << this << "] Singleton2 destroy." << std::endl;
    }

protected:
    Singleton2()
    {
        std::cout << "[0x" << this << "] Singleton2 create." << std::endl;
    }
};

//单例模板
template<typename T>
class Singleton3
{
public:
    static T& getInstance()
    {
        static T instance;
        return instance;
    }

    virtual ~Singleton3()
    {
        std::cout << "[0x" << this << "] Singleton3 destroy." << std::endl;
    }

    void print()
    {
        std::cout << "[0x" << this << "] Singleton3" << std::endl;
    }

    Singleton3(const Singleton3&) = delete;
    Singleton3& operator=(const Singleton3&) = delete;

protected:
    Singleton3()
    {
        std::cout << "[0x" << this << "] Singleton3 create." << std::endl;
    }

};

class Singleton4 : public Singleton3<Singleton4>
{
public:
    friend class Singleton3<Singleton4>;
    Singleton4(const Singleton4&) = delete;
    Singleton4& operator=(const Singleton4&) = delete;

protected:
    Singleton4()=default;
};

class Singleton5 : public Singleton3<Singleton5>
{
public:
    friend class Singleton3<Singleton5>;
    Singleton5(const Singleton5&) = delete;
    Singleton5& operator=(const Singleton5&) = delete;

protected:
    Singleton5()=default;
};


void Test1()
{
    log("\n<<<<<<<<<<<<<<<< 线程安全、内存安全的懒汉式单例模式练习 >>>>>>>>>>>>>>>>>\n");

    Singleton1* instance1 = Singleton1::getInstance();
    Singleton1* instance2 = Singleton1::getInstance();
    instance1->print();
    instance2->print();
}

/*
 * 输出：
getInstance
[0x00C6D393] Singleton2 create.
getInstance
[0x00C6D393] Singleton2
[0x00C6D393] Singleton2
 */
void Test2()
{
    log("\n<<<<<<<<<<<<<<<< 懒汉式单例模式练习(静态局部变量) >>>>>>>>>>>>>>>>>\n");

    Singleton2& instance1 = Singleton2::getInstance();
    Singleton2& instance2 = Singleton2::getInstance();
    instance1.print();
    instance2.print();
}

/*
 * 输出：
[0x0016D3A0] Singleton3 create.
[0x0016D388] Singleton3 create.
[0x0016D3A0] Singleton3
[0x0016D3A0] Singleton3
[0x0016D388] Singleton3
[0x0016D388] Singleton3
 */
void Test3()
{
    log("\n<<<<<<<<<<<<<<<< 懒汉式单例模式练习(模板类) >>>>>>>>>>>>>>>>>\n");

    Singleton4& instance1 = Singleton4::getInstance();
    Singleton4& instance2 = Singleton4::getInstance();
    Singleton5& instance3 = Singleton5::getInstance();
    Singleton5& instance4 = Singleton5::getInstance();
    instance1.print();
    instance2.print();
    instance3.print();
    instance4.print();
}


void jz_2_2_2_00_singleton()
{
    log("\n<<<<<<<<<<<<<<<< 单例模式练习 >>>>>>>>>>>>>>>>>\n\n");
    Test1();
    Test2();
    Test3();
}








