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

void print(node* head);

//Make the Linked List
node* make(node* head, int val) {
    node* nn = new node;
    if (nn == NULL) return 0;
    nn->init(val);
    nn->next = head;
    head = nn;
    return head;
} 

//Reversing Linked List(as it was printing reversed before)
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

//Reversing K times (Time Complexity O(n))
node* reversek(node* head, int k) {
    if (!head) return head;
    node* temp = head;
    int c = 1;
    node* fh = NULL;
    while (temp) {
        c++;
        temp = temp->next;
    }
    if (k>c) return head;
    node* curr = head;
    node* prev = NULL;
    node* next;
    node* f;
    while (k--) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    node* p = prev;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = curr;
    return prev;
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
    head = reversek(head, k);
    print(head);
    return 0;
}
