#include <iostream>

using namespace std;

class binaryTree{
    private: 
    struct node{
        int data;
        node* left;
        node* right;
    }*root;

    public:
    binaryTree(){
        root = nullptr;
    };
    node* createnode(int);
    node* buildTree();
};


int main(){
    binaryTree mytree;
    mytree.buildTree();


    return 0;
}

binaryTree::node* binaryTree::createnode(int data){
    node* newnode = new node();
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

binaryTree::node* binaryTree::buildTree(){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    // USER INPUT -1 FOR NULL
    if(data == -1){
        return nullptr;
    }

    node* newnode = createnode(data);
    cout<<"Inside left of "<<data<<" node"<<endl;
    newnode->left = buildTree();
    cout<<"Inside right of "<<data<<" node"<<endl;
    newnode->right = buildTree();

    return newnode;

}