#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

// template <class Item>
typedef int Item;
struct node
{
    Item item;
    node *next;
    node(int x, node *n)
    {
        item = x;
        next = n;
    }
};
typedef node *link;
typedef link Node;

void construct(int);
Node newNode(int);
void deleteNode(Node);
Node remove(Node);
Node next(Node);
Item item(Node);

void print_node(link x)
{
    link t = x;
    cout << "Linked-List Head to Tail : ";
    while (t)
    {
        cout << t->item << " -> ";
        t = t->next;
    }
    cout << endl;
    return;
}

void circular_list(int N, int M)
{
    int i = 0;
    link t = new node(1, 0);
    t->next = t;
    link x = t;
    for (i = 2; i <= N; i++)
    {
        x = (x->next = new node(i, t));
    }

    while (x != x->next)
    {
        for (i = 1; i < M; i++)
            x = x->next;
        x->next = x->next->next;
    }
    cout << x->item << endl;
    return;
}

link reverse(link x)
{
    link temp;
    link ret;
    link y = x;
    while (y)
    {
        temp = y->next;
        y->next = ret;
        ret = y;
        y = temp;
    }
    return ret;
}

void list_inseration_sort(int N)
{
    node heada(0, 0);
    link a = &heada;
    link t = a;

    for (int i = 0; i < N; i++)
    {
        t = (t->next = new node(rand() % 1000, 0));
    }

    print_node(&heada);

    node headb(0, 0);
    link u, x, b = &headb;
    for (t = a->next; t != 0; t = u)
    {
        u = t->next;
        for (x = b; x->next != 0; x = x->next)
        {
            if (x->next->item > t->item)
                break;
        }
        t->next = x->next;
        x->next = t;
    }
    print_node(&headb);
    return;
}

void construct(int i)
{
}
Node newNode(int i)
{
    Node n = new node(i, 0);
    return n;
}

void deleteNode(Node n)
{
    delete n;
}

Node remove(Node n)
{
    Node r = n->next;
    delete r;
    n->next = 0;
    return n;
}

Node next(Node n)
{
    return n->next;
}
Item item(Node n)
{
    return n->item;
}

int main()
{
    // Fast IOs
    ios_base::sync_with_stdio(false);

    // circular_list(10,9);
    list_inseration_sort(10);
    return 0;
}