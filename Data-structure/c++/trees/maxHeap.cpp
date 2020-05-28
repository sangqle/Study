#include <iostream>
using namespace std;

struct Heap
{
    int data[];
    int size;
    int maxSize;
};

void init_heap(Heap *heap, int maxSize)
{
    heap->data[maxSize];
    heap->size = 0;
}

void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
int main()
{
    Heap *heap;
    init_heap(heap, 10);
    cout << heap->size;
}