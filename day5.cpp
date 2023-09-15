#include <bits/stdc++.h>
#include <vector>
using namespace std;

class node {
    public:
    int val;
    node* next;
    node(int x) : val(x), next(nullptr) {}
};

//merging linked lists of an array
node* mergeKLists(vector<node*>& lists) 
    {
        vector<pair<int,node*>>v;
        for(int i = 0; i<lists.size(); i++)
        {
            node* temp = lists[i];
            while(temp)
            {
                v.push_back({temp->val,temp});
                temp = temp->next;
            }
        }

        if(v.empty()) return NULL;

        sort(v.begin(),v.end());
        for(int i = 0; i<v.size()-1; i++)
        {
            v[i].second->next = v[i+1].second;
        }
        v[v.size()-1].second->next = NULL;

        return v[0].second;
    }

//print the linked list
void print(node* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << std::endl;
}

int main() {
    vector<node*> lists;
    // Creating sorted lists
    node* list1 = new node(1);
    list1->next = new node(4);
    list1->next->next = new node(5);

    node* list2 = new node(1);
    list2->next = new node(3);
    list2->next->next = new node(4);

    node* list3 = new node(2);
    list3->next = new node(6);

    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    node* mergedList = mergeKLists(lists);

    cout << "Merged List: ";
    print(mergedList);

    // Free memory
    for (node* list : lists) {
        delete list;
    }

    return 0;
}
