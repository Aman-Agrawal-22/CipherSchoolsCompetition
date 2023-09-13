#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* next;

    void init(int d) {
        data = d;
        next = NULL;
    }
};

//Make the Linked List
node* make(node* head, int val) {
    node* nn = new node;
    if (nn == NULL) return 0;
    nn->init(val);
    nn->next = head;
    head = nn;
    return head;
} 

//Reversing Linked List
node* reverse(node* head) {
    if(!head || !head->next)return head;
    node*prev = NULL;
    node*temp = head;
    while(temp){
        node* n = temp->next;
        temp->next = prev;
        prev = temp ; 
        temp = n;
    }

    return prev;
}

//Time Complexity O(n^2)
node* rotate1(node* head, int k) {
    if ( head == NULL || head->next == NULL) return head;
    node* temp = head;
    for (int i=0; i<k; i++) {
        temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        temp->next->next = head;
        head = temp->next;
        temp->next = NULL;
    }
    return head;
}

//Time Complexity O(n)
node* rotate2(node* head, int k) {
    if ( head == NULL || head->next == NULL) return head;
    node* temp = head;
    int size = 1;
    while (temp->next != NULL) {
        size++;
        temp = temp->next;
    }
    temp->next = head;
    k = k%size;
    int last = size - k;
    while (last--) temp = temp->next;
    head = temp->next;
    temp->next = NULL;

    return head;
}

//Printing the nodes of Linked List
void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

//Main function
int main() {
    node* head = NULL;
    int n;
    cin>>n;
    int val;
    for (int i=0; i<n; i++) {
        cin>>val;
        head = make(head, val);
    }
    head = reverse(head);
    int k;
    cin>>k;
    //head = rotate1(head, k);
    head = rotate2(head, k);
    print(head);
    return 0;
}
