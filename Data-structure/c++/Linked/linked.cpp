#include <iostream>
using namespace std;

typedef int ElementType;
struct Node
{
    ElementType Element;
    Node *Next;
};

typedef Node *Position;
typedef Position List;

void makeListNull(List &Header)
{
    (Header) = (Node *)malloc(sizeof(Node));
    Header->Next = NULL;
}

// Check empty list
int emptyList(List L)
{
    return (L->Next == NULL);
}

// Insert list
void insertList(ElementType x, Position p)
{
    Position T = (Node *)malloc(sizeof(Node));
    T->Element = x;
    T->Next = p->Next;
    p->Next = T;
}

// Delete element in list
void deleteElement(Position p, List &l)
{
    Position t;
    if (p->Next != NULL)
    {
        t = p->Next;
        p->Next = t->Next;
        free(t);
    }
}

// locate
Position locate(ElementType x, List l)
{
    Position p = l;
    while (p->Next != NULL)
    {
        if (p->Next->Element == x)
            break;
        else
            p = p->Next;
    }
    return p;
}

// print a list
void printList(List l)
{
    Position p = l;
    while (p->Next != NULL)
    {
        cout << p->Next->Element << " ";
        p = p->Next;
    }
}
// Review the value of element
ElementType retrieve(Position p, List l)
{
    if (p->Next != NULL)
    {
        return p->Next->Element;
    }
    else
        return 9999999;
}
int main()
{
    List l;
    makeListNull(l);
    for (int i = 0; i < 10; i++)
    {
        // insertList(rand() % 100, l);
        insertList(i, l);
    }
    cout << retrieve(locate(7, l), l);
    cout << endl;
    deleteElement(locate(8, l), l);

    printList(l);
    // Position p = locate(10, l);
    // cout << l->Next->Element;
    // cout << emptyList(l);
    cout << endl;

    cout << "Hello c++, i'm come back with you";
}