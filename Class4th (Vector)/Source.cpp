#include <iostream>

using namespace std;

template<typename T>
class Vector
{
private:
    int count;
    int capacity;

    T* pointer;

public:
    Vector()
    {
        count = 0;
        capacity = 0;
        pointer = nullptr;
    }

    void resize(int newSize)
    {
        //1. capacity에 새 size 값 저장
        capacity = newSize;

        //2. 새 포인터 변수 생성 후 새롭게 만들어진 메모리 공간 지정
        T* temporary = new T[capacity];

        //3. 새 메모리 공간 값 초기화
        for (int i = 0; i < capacity; i++)
        {
            temporary[i] = NULL;
        }

        //4. 기존 배열에 있는 값을 복사해 새 배열에 삽입
        for (int i = 0; i < count;i++)
        {
            temporary[i] = pointer[i];
        }

        //5. 기본 배열의 메모리를 해제합니다.
        delete[] pointer;

        //6. 기존 배열을 가리키던 포인터 변수의 값을 새 배열의 시작 주소로 지정
        pointer = temporary;

    }

    void push_back(T data)
    {
        if (capacity <= 0)
        {
            resize(1);
        }
        else if (count >= capacity)
        {
            resize(capacity * 2);
        }
        pointer[count++] = data;
    }

    void pop_back()
    {
        if (count <= 0)
        {
            cout << "vector is empty" << endl;
        }
        else
        {
            pointer[--count] = NULL;
        }
    }

    const int& size()
    {
        return count;
    }

    const T& operator [] (const int& index)
    {
        return pointer[index];
    }

    ~Vector()
    {
        delete[] pointer;
    }
};

int main()
{
    Vector<int> vector;

    vector.push_back(10);
    vector.push_back(20);
    vector.push_back(30);
    vector.push_back(40);
    vector.push_back(50);

    vector.pop_back();

    for (int i = 0;i < vector.size();i++)
    {
        cout << vector[i] << endl;
    }

    return 0;
}
