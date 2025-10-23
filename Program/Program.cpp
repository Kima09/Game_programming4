#include <iostream>

using namespace std;

#define SIZE 5

template<typename T>
class Queue
{
private:
    int front;
    int rear;

    T container[SIZE];

public:
    Queue()
    {
        front = 0;
        rear = 0;
        for (int i = 0;i < SIZE;i++)
        {
            container[i] = NULL;
        }
    }

    const bool& empty()
    { }

    const T& peek()
    { }

    void push(T data)
    {
        if (rear >= SIZE - 1)
        {
            cout << "linear queue overflow" << endl;
        }
    }
};


int main()
{
    Queue<int> queue;

    return 0;
}
