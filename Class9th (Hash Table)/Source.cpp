﻿#include <iostream>

using namespace std;

template<typename KEY, typename VALUE>
class HashTable
{
private:
    struct Node
    {
        KEY key;
        VALUE value;

        Node* next;
    };

    struct Bucket
    {
        int count;
        Node* head;
    };

    int size;
    int capacity;

    Bucket* bucket;

public:
    HashTable()
    {
        size = 0;
        capacity = 8;

        bucket = new Bucket[capacity];

        for (int i = 0; i < capacity;i++)
        {
            bucket[i].head = nullptr;
            bucket[i].count = 0;
        }
    }

    template<typename KEY>
    unsigned int hash_function(KEY key)
    {
        return (unsigned int)key % capacity;
    }

    template<>
    unsigned int hash_function(const char* key)
    {
        int sum = 0;
        for (int i = 0;*key != '\0';i++)
        {
            sum += key[i];

            key = key + 1;
        }

        return (unsigned int)sum % capacity;
    }

    void insert(KEY key, VALUE value)
    {
        //해시 함수를 통해서 값을 받는 임시 변수
        int hashIndex = hash_function(key);

        //새로운 노드 생성
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->next = nullptr;

        //노드가 1개라도 존재하지 않는다면
        if (bucket[hashIndex].count == 0)
        {
            //bucket[hashIndex]의 head 포인터가 newNode를 가리키게 합니다.
            bucket[hashIndex].head = newNode;
        }
        else
        {
            newNode->next = bucket[hashIndex].head;
            bucket[hashIndex].head = newNode;
        }

        //bucket[hashIndex]의 count 증가
        bucket[hashIndex].count++;

    }

    void erase(KEY key)
    {
        //1. 해시 함수를 통해서 값을 받는 임시 변수
        int hashIndex = hash_function(key);

        //2. Node를 탐색할 수 있는 포인터 변수 선언
        Node* currentNode = bucket[hashIndex].head;

        //3. 이전 Node를 저장할 수 있는 포인터 변수 선언
        Node* previousNode = nullptr;

        //4. currentNode가 nullptr과 같다면 함수를 종료
        if (currentNode == nullptr)
        {
            cout << "not key found..." << endl;
        }
        else
        {
            //5.currentNode를 이용해 내가 찾고자 하는 key 값을 찾습니다.
            while (currentNode != nullptr)
            {
                if (currentNode->key == key)
                {
                    if (currentNode == bucket[hashIndex].head)
                    {
                        bucket[hashIndex].head = currentNode->next;
                    }
                    else
                    {
                        previousNode->next = currentNode->next;
                    }

                    size--;

                    bucket[hashIndex].count--;

                    delete currentNode;

                    return;
                }
                else
                {
                    previousNode = currentNode;
                    currentNode = currentNode->next;
                }
            }
            cout << "not key found..." << endl;
        }
    }

    const float& load_factor()
    {
        return(float)size / capacity;
    }

    const int& bucket_count()
    {
        return capacity;
    }

    ~HashTable()
    {
        for (int i = 0; i < capacity; i++)
        {
            Node* deleteNode = bucket[i].head;
            Node* nextNode = bucket[i].head;

            if (bucket[i].head == nullptr)
            {
                continue;
            }
            else
            {
                while (nextNode != nullptr)
                {
                    nextNode = deleteNode->next;
                    delete deleteNode;
                    deleteNode = nextNode;
                }
            }
        }
        delete[] bucket;
    }
};


int main()
{
    HashTable<const char*, int>hashtable;

    hashtable.insert("mask", 3000);
    hashtable.insert("cinder", 1000);
    hashtable.insert("vest", 800);

    hashtable.erase("mask");
    hashtable.erase("force");

    return 0;
}
