#include<iostream>
using namespace std;

class Node
{
    public:
    int rowIdx;
    int colIdx;
    int value;
    Node *next;
};

void createNode(Node **head, int row, int col, int data)
{
    Node *temp = *head;
    Node *newNode;

    if (temp == NULL)
    {
        temp = new Node();
        temp->rowIdx = row;
        temp->colIdx = col;
        temp->value = data;
        temp->next = NULL;
        *head = temp;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        newNode = new Node();
        newNode->rowIdx = row;
        newNode->colIdx = col;
        newNode->value = data;
        newNode->next = NULL;
        temp->next = newNode;
    }
}

void displayList(Node *start)
{
    Node *ptr = start;
    
    cout << "Row Indices: ";
    while (ptr != NULL)
    {
        cout << ptr->rowIdx << " ";
        ptr = ptr->next;
    }
    cout << endl;

    cout << "Column Indices: ";
    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->colIdx << " ";
        ptr = ptr->next;
    }
    cout << endl;

    cout << "Values: ";
    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->value << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    int sparseMatrix[4][5] = 
    { 
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0} 
    };

    Node *head = NULL;
    
    // Creating the linked list representation of the sparse matrix
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparseMatrix[i][j] != 0)
                createNode(&head, i, j, sparseMatrix[i][j]);
        }
    }

    // Displaying the linked list
    displayList(head);

    return 0;
}

Results
Row Indices: 0 0 1 1 3 3 
Column Indices: 2 4 2 3 1 2 
Values: 3 4 5 7 2 6 
