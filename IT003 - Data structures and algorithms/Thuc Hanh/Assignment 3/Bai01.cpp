/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -

struct Point
{
    int x, y;
    Point *next;

    Point(int x_, int y_) : x(x_), y(y_), next(NULL) {}
};

class LinkedList
{
public:
    Point *head;
    Point *tail;

    LinkedList() : head(NULL), tail(NULL) {}

    void Append(int x, int y)
    {
        Point *new_point = new Point(x, y);
        if (!head)
        {
            head = new_point;
            tail = new_point;
        }
        else
        {
            tail->next = new_point;
            tail = new_point;
        }
    }

    void PrintList()
    {
        Point *temp = head;
        while (temp)
        {
            cout << temp->x << " " << temp->y << endl;
            temp = temp->next;
        }
    }

    static int KCTuO(Point *p)
    {
        return p->x * p->x + p->y * p->y;
    }

    void SortList()
    {
        if (!head || !head->next)
        {
            return;
        }

        Point *sorted = nullptr;
        Point *current = head;

        while (current)
        {
            Point *next = current->next;
            SortedInsert(&sorted, current);
            current = next;
        }

        head = sorted;
    }

private:
    void SortedInsert(Point **sorted, Point *new_point)
    {
        if (!*sorted || ComparePoints(new_point, *sorted))
        {
            new_point->next = *sorted;
            *sorted = new_point;
        }
        else
        {
            Point *temp = *sorted;
            while (temp->next && !ComparePoints(new_point, temp->next))
            {
                temp = temp->next;
            }
            new_point->next = temp->next;
            temp->next = new_point;
        }
    }

    static bool ComparePoints(Point *a, Point *b)
    {
        int KCA = KCTuO(a);
        int KCB = KCTuO(b);
        if (KCA == KCB)
        {
            return a->x < b->x;
        }
        return KCA < KCB;
    }
};

int main()
{
    int n;
    cin >> n;

    LinkedList list;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        list.Append(x, y);
    }

    list.SortList();
    list.PrintList();

    return 0;
}