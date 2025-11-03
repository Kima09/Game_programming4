#include <iostream>

using namespace std;

template<typename T>
class Graph
{
private:
    int size;//정점 개수
    int count;//인접 행렬 크기
    int capacity;//최대 용량

    T* vertex;//정점의 집합
    int** matrix;//인접 행렬

public:
    Graph()
    {
        size = 0;
        count = 0;
        capacity = 0;

        vertex = nullptr;
        matrix = nullptr;
    }

    void resize(int newSize)
    {
        capacity = newSize;
        T* container = new T[capacity];

        for (int i = 0; i < capacity;i++)
        {
            container[i] = NULL;
        }

        for (int i = 0; i < size; i++)
        {
            container[i] = vertex[i];
        }

        delete[] vertex;

        vertex = container;
    }

    void push(T data)
    {
        if (capacity <= 0)
        {
            resize(1);
        }
        else if (size >= capacity)
        {
            resize(capacity * 2);
        }

        vertex[size++] = data;
    }

    void edge(int i, int j)
    {
        if (vertex[0] = NULL)
        {
            cout << "adjacency matrix is empty" << endl;
        }
    }
};



int main()
{
    //그래프의 표현
    // 
    //인접 행렬
    //2차원 배열로 그래프를 나타내는 자료 구조
    //노드의 개수를 n이라고 할 때 n*n 크기의 행렬을 사용해
    //노드 사이의 연결을 표현
    // 연결된 노드끼리는 1, 단절은 0
    // 
    // 0 - 1
    //    /ㅣ
    // 3 - 2
    // 
    //     0  1  2  3
    // 0  0  1  0  0
    // 1  1  0  1  1
    // 2  0  1  0  1
    // 3  0  1  1  0

    Graph<char> graph;

    graph.push('A');
    graph.push('B');
    graph.push('C');

    return 0;
}
