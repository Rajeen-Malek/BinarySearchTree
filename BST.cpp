#include<bits/stdc++.h>
using namespace std;

struct Node                         // Creating the new node structure with data , left , right pointer !
{
    int data ;                      // ---------------------
    Node *left;                     // |left | data | right|
    Node *right;                    // ---------------------
};

Node *getnewnode(int data)
{
    Node *newnode = new Node() ;    // Dynamically created new node
    newnode->data = data;           // Inserted the data into data feild
    newnode->left = newnode->right = NULL ;  
    return newnode;
}

Node *Insert(Node *rootptr , int data)
{
    if(rootptr == NULL) 
    {
        rootptr = getnewnode(data) ;
    }
    else if(data <= rootptr->data)
    {
        rootptr->left = Insert(rootptr->left , data);
    }
    else
    {
        rootptr->right = Insert(rootptr->right , data);
    }
    return rootptr ;
}

bool Search(Node *rootptr , int data)
{
    if(rootptr == NULL)
    {
        return false;
    }
    else if(rootptr->data == data)
    {
        return true;
    }
    else if(data <= rootptr->data)
    {
        return Search(rootptr->left , data);
    }
    else
    {
        return Search(rootptr->right,data);
    }
}

void Shownodes(Node *rootptr)      // Inorder traversal !
{
    if(rootptr == NULL) return ;
    else
    {
        Shownodes(rootptr->left);
        cout<<rootptr->data<<" ";
        Shownodes(rootptr->right);
    }
}

void bfs(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    queue <Node *> q;
    q.push(root);
    //cout<<root->data;
    while(!q.empty())
    {
        Node *temp = q.front();
        cout<<temp->data<<" ";    //showing the data of root node
        q.pop();
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL) 
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = NULL ;

    root = Insert(root,15);        //                           15
    root = Insert(root,10);        //                  10                20
    root = Insert(root,20);        //            8                17               25
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,17);

    cout<<"Inoder Traversal : ";
    Shownodes(root);              // Showing all the nodes present  8 10 15 17 20 25
    cout<<endl;

    cout<<"Level Order Traversal : ";
    bfs(root);                    // Showing all the nodes present  15 10 20 8 17 25
    cout<<endl;
    int num;
    cout<<"Enter the number to be searched : ";
    cin>>num;

    if(Search(root,num)==true)
    {
        cout<<"Found ! "<<endl ;
    }
    else{
        cout<<"Not Found !" <<endl;
    }
}