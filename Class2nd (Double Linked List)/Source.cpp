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
        newNode->next = nullptr;
        newNode->previous = nullptr;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        size++;
    }

    void pop_front()
    {

        if (head == nullptr)
        {
            cout << "Double linked list is empty._pop_front" << endl;
        }
        else
        {
            Node* deleteNode = head;
            if (head->next != nullptr)
            {
                deleteNode->next->previous = nullptr;
                head = head->next;
            }
            else
            {
                head = nullptr;
                tail = nullptr;
            }

            delete deleteNode;

        }
        size--;
    }

    void push_back(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;
        newNode->previous = nullptr;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->previous = tail;

            tail = newNode;
        }
        size++;
    }

    void pop_back()
    {
        if (tail == nullptr)
        {
            cout << "Double linked list is empty._pop_back" << endl;
        }
        else
        {
            Node* deleteNode = tail;
            if (tail == head)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                tail = deleteNode->previous;

                //deleteNode->previous = nullptr;
                //없어도 됨

                tail->next = nullptr;
            }

            delete deleteNode;

        }
        size--;
    }

    const bool& empty()
    {
        return(head == nullptr);
    }

    ~List()
    {
        while (head != nullptr)
        {
            pop_front();
        }
    }

};

int main()
{
    List<int> list;

    //list.push_front(10);
    //list.push_front(5);
    //
    //list.pop_front();
    //list.pop_front();
    //list.pop_front();

    list.push_back(20);
    list.push_back(30);

    list.pop_back();
    list.pop_back();
    list.pop_back();


    return 0;
}
