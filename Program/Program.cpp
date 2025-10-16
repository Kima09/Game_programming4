#include <iostream>

using namespace std;

template<typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node* previous;
        Node* next;
    };

    int size;
    Node* head;
    Node* tail;

public:
    List()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void push_front(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = nullptr;
            newNode->previous = nullptr;
        }
        else
        {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        size++;
    }

};

int main()
{
    List<int> list;
    

    return 0;
}
