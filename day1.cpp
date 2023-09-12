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

node* make(node* head, int val) {
    node* nn = new node;
    if (nn == NULL) return 0;
    nn->init(val);
    nn->next = head;
    head = nn;
    return head;
} 

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

void twinsum(node* head) {
    vector<int> v;
    node* temp = head;
    while (temp!=NULL) {
        v.push_back(temp->data);
        temp = temp->next;
    }
    int n= v.size();
    int sum = 0;
    for (int i=0; i<(n/2); i++) {
        sum = max(sum, v[0] + v[n-1]);
        v.erase(v.begin()+0);
        v.erase(v.begin() + (n-1));
    }
    cout<<sum;
}

void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

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
    twinsum(head);
    return 0;
}
