#include <iostream>

using namespace std;

#define SIZE 4

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
        front = SIZE-1;
        rear = SIZE-1;
        for (int i = 0;i < SIZE;i++)
        {
            container[i] = NULL;
        }
    }

    const bool& empty()
    {
        return front == rear;
    }

    const T& peek()
    {
        if (empty())
        {
            exit(1);
        }
        else
        {
            return container[(front + 1) % SIZE];
        }
    }

    //프론트 이전 까지만 푸쉬가 가능하다. 
    //기본 상태에서 3은 불가, 0,1,2에만 값이 들어간다.
    void push(T data)
    {
        if (front == (rear+1) % SIZE )
        {
            cout << "overflow" << endl;
        }
        else
        {
            rear = (rear + 1) % SIZE;
            container[rear] = data;
        }
    }

    //팝의 경우 프론트++를 널로 바꾼다.
    //기본 프론트는 사이즈-1이므로 첫 팝에서 0이 널이 된다.
    void pop()
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            front = (front + 1) % SIZE;

            container[front] = NULL;
        }
    }

    const int& size()
    {
        int count = 0;
        for (int i = 0;i < SIZE;i++)
        {
            if (container[i] != NULL)
            {
                count++;
            }
        }
        return count;
    }

};

int main()
{
    Queue<int> queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);
    //queue.push(50);
    //queue.push(60);
    //
    cout << queue.empty()<<endl;
    //
    while (queue.empty() == false)
    {
        cout << queue.peek() << endl;
        queue.pop();
    }
    //
    //cout << "size: " << queue.size() << endl;

    return 0;
}
