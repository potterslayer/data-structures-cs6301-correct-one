#include<bits/stdc++.h>
using namespace std;

class Node{
    public:              /* allows to use variable in main*/

    string name;
    int age;
    Node* next;
    Node* prev;

    Node(string name, int age){
        this->name = name;
        this->age = age;
        next = NULL;
        prev = NULL;
    }
};

Node* create(string *name, int *age, int members)
{
    Node* current=NULL;
    Node* prev_ = NULL;
    Node* next_ = NULL;
    Node* head = NULL;
    for(int j=0;j<members;j++)
    {
        
        current = new Node(name[j],age[j]);
        if(head==NULL)
        {
            head = current;
        }
        current->prev = prev_;
        if(prev_!=NULL)
        {
            prev_->next = current;
        }
        prev_ = current;
    }

    return head;
}

void add(Node* head, int age, string name)
{
    Node* nh = new Node(name, age);
    nh->next = head;
    head->prev = nh;
    head = nh;
}

void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->name<<" "<<head->age<<endl;
        head = head->next;
    }
}

int main()
{
    int k;
    cout<<"Number of members in family: ";
    cin>>k;

    int *age = new int[k];
    string *name = new string[k];

    cout<<"Name of family members with their ages"<<endl;
    for(int j=0;j<k;j++)
    {
        cout<<"Enter details of member :";
        cin>>name[j]>>age[j];
    }
    Node* head = create(name, age, k);
    print(head);
return 0;
}