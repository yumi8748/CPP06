#include "Serializer.hpp"

int main(void)
{
    Data ptr;
    ptr.name = "Yumi";
    ptr.age = 18;

    std::cout << "Address of ptr: "<< &ptr<<std::endl;
    std::cout << "Name: " << ptr.name << std::endl;
    std::cout << "Age: " << ptr.age << std::endl;

    uintptr_t a = Serializer::serialize(&ptr);
    std::cout << "\nUnsigned int: " << a << std::endl;

    Data *newptr = Serializer::deserialize(a);
    std::cout << "\nAddress of newptr: " << newptr << std::endl;
    std::cout << "Name: " << newptr->name << std::endl;
    std::cout << "Age: " << newptr->age << std::endl;
}