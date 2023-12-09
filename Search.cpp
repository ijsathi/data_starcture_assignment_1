#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};
// insert head & tail
void insert_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}
// print list
/* void print_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
} */

int find_position(Node *head, int val)
{
    int index = 0;
    while (head != NULL)
    {
        if (head->value == val)
        {
            return index;
        }
        head = head->next;
        index++;
    }
    return -1;
}
int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        Node *head = NULL;
        Node *tail = NULL;
        int val;
        while (true)
        {
            cin >> val;
            if (val == -1)
                break;
            insert_tail(head, tail, val);
        }
        // print_list(head);
        int x;
        cin >> x;
        int result = find_position(head, x);
        cout << result << endl;

        // delete
        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}