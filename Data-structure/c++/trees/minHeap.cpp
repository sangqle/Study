#include <iostream>
#include <queue> // functional,iostream,ctime,cstdlib
using namespace std;

#define MaxLength 100
typedef int ElementType;
typedef struct
{
    ElementType Data[MaxLength];
    int Last;
} PriorityQueue;

int p(ElementType x)
{
    return x;
}

// make null priority queue
void MakeNullPriorityQueue(PriorityQueue &L)
{
    L.Last = 0;
}

// swap
void swap(ElementType &x, ElementType &y)
{
    ElementType temp = x;
    x = y;
    y = temp;
}
// insert a element into priority queue that is order
void InsertPriority(ElementType X, PriorityQueue &L)
{
    ElementType temp;
    if (L.Last > MaxLength - 1)
    {
        printf("Priority is full.");
    }
    else
    {
        int i = L.Last;
        L.Data[L.Last] = X;
        L.Last++;
        // // Float up
        while (i > 0 && p(L.Data[i]) < p(L.Data[(i - 1) / 2]))
        {
            swap(L.Data[i], L.Data[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
}

ElementType ExtractMin(PriorityQueue &L)
{
    if (L.Last == -1)
    {
        printf("Queue is empty.");
    }
    else
    {
        ElementType min = L.Data[0];
        L.Data[0] = L.Data[L.Last--];
        // Push down
        int i = 0;
        int j;
        while (i <= (L.Last - 1) / 2)
        {
            if (L.Data[2 * i + 1] < L.Data[2 * i + 2] || (2 * i + 1 == L.Last))
            {
                j = 2 * i + 1;
            }
            else
            {
                j = 2 * i + 2;
            }
            if (L.Data[i] > L.Data[j])
            {
                swap(L.Data[i], L.Data[j]);
                i = j;
            }
            else
            {
                break;
            }
        }
        return min;
    }
}
// Delete an element from priority queue
ElementType DeleteMin(PriorityQueue &L)
{
    int i, j;
    ElementType temp;
    if (L.Last == 0)
    {
        printf("Queue is empty.");
    }
    else
    {
        ElementType minimum = L.Data[1];
        L.Data[1] = L.Data[L.Last];
        L.Last--;
        // Push down
        i = 1;
        while (i <= L.Last / 2)
        {
            if ((p(L.Data[2 * i]) < p(L.Data[2 * i + 1])) || (2 * i == L.Last))
            {
                j = 2 * i;
            }
            else
            {
                j = 2 * i + 1;
            }
            if (p(L.Data[i]) > p(L.Data[j]))
            {
                swap(L.Data[i], L.Data[j]);
                i = j;
            }
            else
            {
                break;
            }
        }
        return minimum;
    }
}

int main(int argc, char *argv[])
{
    int n, x;
    PriorityQueue L;
    MakeNullPriorityQueue(L);
    // printf("Hang co may phan tu: ");
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("Nhap phan tu thu %d: ", i);
    //     scanf("%d", &x);
    //     InsertPriority(x, L);
    // }
    InsertPriority(3, L);
    InsertPriority(9, L);
    InsertPriority(2, L);
    InsertPriority(1, L);
    InsertPriority(8, L);
    InsertPriority(7, L);
    InsertPriority(17, L);
    InsertPriority(5, L);
    InsertPriority(20, L);
    InsertPriority(6, L);
    InsertPriority(4, L);

    printf("Xoa phan tu nho nhat\n");
    while (L.Last > 0)
    {
        printf("%d\n", ExtractMin(L));
        // break;
    }
}