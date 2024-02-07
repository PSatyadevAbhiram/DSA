#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(){
            data = 0;
            next = NULL;
        }
};

void addElementAtEnd(Node *head, int data){
    Node *newNode = new Node();
    newNode->data = data;
    Node* temp = head;
    if(temp == NULL){
        head = newNode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void addElementAtStart(Node *head, int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = head->next;
    head->next = newNode;
}

void DeleteElementAtPositionX(Node* head, int pos){
    Node *temp = head;
    Node *tr = head;
    for(int i = 0; i < pos; i++){
        tr = temp;
        temp = temp->next;
    }
    tr->next = temp->next;
}

void printLinkedList(Node* head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter the number of elements in the linked list: ";
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        cout<<"Enter the element: ";
        int input;
        cin>>input;
        v.push_back(input);
    }
    Node* head = new Node();
    for(int i = 0; i < n; i++){
        addElementAtEnd(head, v[i]);
    }
    printLinkedList(head);
    Node* reverseHead = new Node();
    for(int i = 0;i < n; i++){
        addElementAtStart(reverseHead, v[i]);
    } 
    printLinkedList(reverseHead);
    int pos;
    cout<<"Enter the position of the element to be deleted: ";
    cin>>pos;
    DeleteElementAtPositionX(head, pos);
    printLinkedList(head);
    cout<<"Detecting if there is a cycle in this LinkedList.....";
    cout<<endl;
    detectCycle(head) ? cout<<"Cycle detected\n" : cout<<"No cycle detected\n";
}