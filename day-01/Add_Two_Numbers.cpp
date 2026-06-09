#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class node
{
public:
    int val;
    node *next;

    node(int v)
    {
        val = v;
        next = NULL;
    }
};

class linkedlist
{
    node *head;
    node *tail;
    int size;

public:
    linkedlist()
    {
        head = tail = NULL;
        size = 0;
    }

    void insert(int v)
    {
        node *newnode = new node(v);

        if (head == NULL)
        {
            head = tail = newnode;
            size++;
        }

        else
        {
            tail->next = newnode;
            newnode->next = NULL;
            tail = newnode;
            size++;
        }
    }

    void traverse(vector<int> &arr)
    {
        node *temp = head;
        while (temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
    }

    void display()
    {
        node *temp = head;

        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int addtwonumbers(vector<int> &arr1, vector<int> &arr2)
{
    int num1 = 0;
    int num2 = 0;

    for (int i = 0; i < arr1.size(); i++)
    {
        num1 = num1 * 10 + arr1[i];
    }

    for (int i = 0; i < arr2.size(); i++)
    {
        num2 = num2 * 10 + arr2[i];
    }

    return num1 + num2;
}

int main()
{
    linkedlist l1, l2, ans;

    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        l1.insert(x);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        l2.insert(x);
    }

    vector<int> arr1, arr2;

    l1.traverse(arr1);
    l2.traverse(arr2);

    reverse(arr1.begin(), arr1.end());
    reverse(arr2.begin(), arr2.end());

    int sum = addtwonumbers(arr1, arr2);

    cout << "Sum = " << sum << endl;
    if (sum == 0)
    {
        ans.insert(0);
    }
    else
    {
        while (sum > 0)
        {
            ans.insert(sum % 10);
            sum /= 10;
        }
    }

    cout << "Result Linked List: ";
    ans.display();

    return 0;
}