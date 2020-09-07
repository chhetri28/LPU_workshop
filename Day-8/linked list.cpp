#include<bits/stdc++.h>
using namespace std;
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Node{
    public:
    int data;
    Node*next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
int length(Node*head){
    int cnt(0);
    Node* curr=head;
    while(curr!=NULL){
        curr=curr->next;
        cnt++;
    }
    return cnt;
}
// returning node using reference 
void insertinhead(Node*&head,int data){
    if(head==NULL){
        head=new Node(data);
        return;
    }
    Node* n=new Node(data);
    n->next=head;
    head=n;
}
void insertintail(Node*&head,int data){
    if(head==NULL){
        Node* n=new Node(data);
    }
    Node*curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=new Node(data);
}
void insertinmiddle(Node*&head,int data,int p){
    if(p==0 || head ==NULL){
        insertinhead(head,data);
        return;
    }
    else if(p>length(head)){
        insertintail(head,data);
    }
    else{
        int jump=1;
        Node* curr=head;
        while(jump<=p-1){
            curr=curr->next;
            jump++;
        }
        Node* n=new Node(data);
        n->next=curr->next;
        curr->next=n;
    }
    return;
}
Node *sortedInsert(Node* head, int data) {
    //1 Check if the list is empty
    if(head == NULL)
    {
        head = new Node(data);
    }
    //2 if data is smaller then the first value
    if(data <= head->data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        
        return head;
    }
    //3 or add in middle
    Node *curr = head->next, *prev = head;
    while(curr != NULL)
    {
        if(curr->data > data)
        {
            Node *temp = new Node(data);
            
            temp->next = curr;
            prev->next = temp;
            
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    
    prev->next = new Node(data);
    return head;
}

Node* take_input(){
    Node*head=NULL;
    int n;
    cin>>n;
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        insertinhead(head,data);
    }
    return head;
}
void printll(Node* head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<'\n';
}
Node* creatll(){
    int n;
    cin>>n;
    Node* head=NULL,*tail=NULL;
    while (n--)
    {
        /* code */
        int x;
        cin>>x;
        if(head==NULL){
            Node* curr=new Node(x);
            head=curr;
            tail=curr;
        }
        else{
            Node*curr=new Node(x);
            tail->next=curr;
            tail=curr;  
        }
    }
    return head;
}
Node* rotate(Node* head,int k){
    if(k==0)return head;
    Node* curr=head,*prev=NULL;
    while(k--){
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    Node* curr1=curr;
    while(curr1->next!=NULL){
        curr1=curr1->next;
    }
    curr1->next=head;
    return curr;
}
Node*  point(Node*head){
    if(head==NULL and head->next!=NULL){
        return head;
    }
    Node*slow=head;
    Node*fast=head->next;
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node* kthnodeend(Node* head,int k){
    if(head==NULL and head->next!=NULL){
        return head;
    }
    Node*slow=head;
    Node*fast=head;
    while(k--){
        fast=fast->next;
    }
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}
Node* reversell(Node* head){
    Node*curr=head;//Current node
    Node*prev=NULL;//Prev node
    Node*n;//next node
    while(curr!=NULL){//loop till the NULL
        n=curr->next;//Store the address of next node
        curr->next=prev;//change the pointer to prev
        prev=curr;//mark the curr node as prev
        curr=n;// and curr as next
    }
    return prev;//return prev which is now new head 
}
Node* reverse_recc(Node* head){
    if(head!=NULL and head->next!=NULL){
        return head;
    }
    Node* rest_head=reverse_recc(head->next);
    Node* rest_tail=head->next;
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;
}
Node* reverseingroup(Node* head,int k){
    Node*current=head;
    Node*prev=NULL;
    Node*nxt;
    int c(0);
    while(current!=NULL and c<k){
        nxt=current->next;
        current->next=prev;
        prev=current;
        current=nxt;
        c++;
    }
    if(nxt!=NULL){
        head->next=reverseingroup(nxt,k);
    }
    return prev;
}
bool isPalindrome1(Node*head){
    stack<int>st;
    Node*slow=head;
    while(slow!=NULL){
        st.push(slow->data);
        slow=slow->next;
    }
    auto curr=head;
    while(curr!=NULL){
        int i=st.top();
        st.pop();
        if(curr->data!=i){
            return false;
        }
    }
    return true;
}
bool isPalindrome2(Node* head){
    //1. Find the mid-point
    Node *fast=head;
    Node *slow=head;
    while(fast and fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    if(fast){
        slow=slow->next;
    }
    //2. Reverse the second half
    Node *dummy=slow;
    Node *last=NULL;
    Node *nxt=NULL;
    while(dummy){
        nxt=dummy->next;
        dummy->next=last;
        last=dummy;
        dummy=nxt;
    }
    //3. Compare each half
    dummy=last;
    while(dummy){
        if(dummy->data==head->data){
            dummy=dummy->next;
            head=head->next;
        }else{
            return false;
        }
    }
    return true;
}
Node* reversebetween(Node*head,int m,int n){
    Node*dummy=new Node(0);
    Node *pre=dummy,*curr;
    dummy->next=head;
    for(int i=0;i<m-1;i++){
        pre=pre->next;
    }
    curr=pre->next;
    for(int i=0;i<n-m;i++){
        Node *temp=pre->next;//a
        pre->next=curr->next;//b
        curr->next=curr->next->next;//c
        pre->next->next=temp;//d
    }
    return dummy->next;
}
int main(){
    OJ;
    FIO;
    // Node*head=take_input();
    // insertintail(head,6);
    // insertinmiddle(head,8,2);
    Node* head=creatll();
    //head=sortedInsert(head,3);
    //head=reversebetween(head,2,5);
    // if(isPalindrome2(head)){
    //     cout<<"YES";
    // }
    // else{
    //     cout<<"NO";
    // }
    //head=reversell(head);
    //head=reverse_recc(head);
    //head=reverseingroup(head,5);
    printll(head);
    //head=reversell(head);
    //head=rotate(head,2);
    // head=midpoint(head);
    // cout<<head->data<<" ";
    // head=kthnodeend(head,3);
    // cout<<head->data<<" ";
    //printll(head);
    //cout<<length(head);
}