#include <iostream>

class Entity
{
public:
    Entity()
    {
        std::cout << "1" << std::endl;
    }

    ~Entity()
    {
        std::cout << "2" << std::endl;
    }

    void Print()
    {
        std::cout << "3" << std::endl;
    }
};

template <typename T>
class SharedPointer
{
public:
    T* row_pointer;

    int* counter;

    SharedPointer(T* value)
    {
        row_pointer = value;
        counter = new int(1);
    }

    SharedPointer(const SharedPointer<T>& other)
    {
        row_pointer = other.row_pointer;
        counter = other.counter;
        (*counter)++;
    }

    ~SharedPointer()
    {
        (*counter)--;
        if ((*counter) < 1)
        {
            delete row_pointer;
            delete counter;
        }
    }
    T* operator*() {
		//cout << "In operator *" << endl;
		return row_pointer;
	}

	T* operator ->() {
		//cout << "In operator ->" << endl;
		return row_pointer;
	}

};

int main()
{
    SharedPointer<Entity> test(new Entity());
    std::cout << "Here" << std::endl;
    SharedPointer<Entity> cotest(test);
    std::cout << "Here" << std::endl;
    test->Print();

    return 0;
}
