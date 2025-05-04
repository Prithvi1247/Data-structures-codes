#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class TreeADT{
    private:
    struct node{
        int data;
        node* left;
        node* right;
    }*root;

    public : 
    TreeADT(){root = nullptr;}

    node* getroot();
    void buildTree();
    node* buildTreeHelper();
    node* createnode(int);
    void levelOrderTraversal();
    // node* InOrderTraversalHelper(node*);
    void InorderTraversal(node*);
    void InorderTraversalIterative();
    void preorderTraversal(node*);
    void postorderTraversal(node*);

};
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

int main(){

    TreeADT mytree;
    //creating a tree
    mytree.buildTree();

    // level order traversal of tree - breadth first search
    cout<<"level order traversal of tree: "<<endl;
    mytree.levelOrderTraversal();

    // inorder traversal
    cout<<"In order traversal of tree: "<<endl;
    mytree.InorderTraversal(mytree.getroot());
    // inorder traversal iterative
    cout<<"In order traversal of tree: "<<endl;
    mytree.InorderTraversalIterative();
    // preorder traversal
    cout<<"\nPre order traversal of tree: "<<endl;
    mytree.preorderTraversal(mytree.getroot());
    // post order traversal
    cout<<"\nPost order traversal of tree: "<<endl;
    mytree.postorderTraversal(mytree.getroot());

    return 0;
}

void TreeADT::InorderTraversalIterative(){

    
}

TreeADT::node* TreeADT::getroot(){
    return root;
}

TreeADT::node* TreeADT::createnode(int data){
    node* newnode = new node();
    newnode->data=data;
    newnode->left=nullptr;
    newnode->right=nullptr;
    return newnode;
}
void TreeADT::buildTree(){
    root = buildTreeHelper();
}
TreeADT::node* TreeADT::buildTreeHelper(){
    cout<<"Enter data :"<<endl;
    int data;
    cin>>data;
    if (data == -1){
        return nullptr;
    }

    node* newnode = createnode(data);
    cout<<"inside left of "<<data<<" node"<<endl;
    newnode->left=buildTreeHelper();
    cout<<"\n\ninside right of "<<data<<" node"<<endl;
    newnode->right=buildTreeHelper();
    return newnode;
}

// void TreeADT::levelOrderTraversal(){
//     queue <node*> myqueue;
//     cout<<"Tree :"<<endl;
//     myqueue.push(root);

//     while (!myqueue.empty())
//     {
//         node* tempnode = myqueue.front();
//         myqueue.pop();
//         cout<<tempnode->data<<" ";
//         if (tempnode->left){
//             myqueue.push(tempnode->left);
//         }
//         if (tempnode->right){
//             myqueue.push(tempnode->right);
//         }
//     }
    
// }

void TreeADT::levelOrderTraversal(){
    // with seperator

    queue <node*> myqueue;
    cout<<"Tree :"<<endl;

    myqueue.push(root);
    myqueue.push(nullptr);

    while (!myqueue.empty())
    {
        node* tempnode = myqueue.front();
        myqueue.pop();

        if (tempnode == nullptr)
        {
            cout<<endl;
            // myqueue.pop();
            if(!myqueue.empty()){
                myqueue.push(nullptr);
            }
        }
        else{   
            cout<<tempnode->data<<" ";
            if (tempnode->left){
                myqueue.push(tempnode->left);
            }
            if (tempnode->right){
                myqueue.push(tempnode->right);
            }
        }
    }
    
}

void TreeADT::InorderTraversal(node* ptr){

    if (ptr == nullptr){
        return;
    }
    InorderTraversal(ptr->left);
    cout<<ptr->data<<" ";
    InorderTraversal(ptr->right);
    
}

void TreeADT::preorderTraversal(node* ptr){

    if (ptr == nullptr){
        return;
    }
    cout<<ptr->data<<" ";
    preorderTraversal(ptr->left);
    preorderTraversal(ptr->right);
    
}

void TreeADT::postorderTraversal(node* ptr){

    if (ptr == nullptr){
        return;
    }
    postorderTraversal(ptr->left);
    postorderTraversal(ptr->right);
    cout<<ptr->data<<" ";
    
}


