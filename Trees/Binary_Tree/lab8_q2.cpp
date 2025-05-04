#include <iostream>
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
    
    
    void InorderTraversal(node*);
    node* searchBinaryTree(node* , int );
    void search(int);
    void preorderTraversal(node*);
    void postorderTraversal(node*);

};

int main(){
    TreeADT mytree;

    int inp = 0, value = 0, index = 0;

    while (1)
    {

        cout<<"------------------------------------------";
        cout << "\n\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search \n6.Exit\n\nEnter choice: ";
        cin >> inp;
        cout<<endl;

        switch (inp)
        {

        case 1 : 
            mytree.buildTree();
            break;
        case 2 : 
            cout<<"\nPreorder traversal of tree: "<<endl;
            mytree.preorderTraversal(mytree.getroot());
            break;
        case 3 : 
            cout<<"Inorder traversal of tree: "<<endl;
            mytree.InorderTraversal(mytree.getroot());
            break;
        case 4 : 
            cout<<"\nPost order traversal of tree: "<<endl;
            mytree.postorderTraversal(mytree.getroot());
            break;
        case 5 : 
            cout<<"Enter value to search : ";
            cin>>value;
            mytree.search(value);
            
            break;
        case 6 : 
            return 0;
            break;
        default : 
            cout<<"Invalid Input"<<endl;
            
        }
    }

}
// Returns root of the tree
TreeADT::node* TreeADT::getroot(){
    return root;
}
// Creates a newnode for the tree
TreeADT::node* TreeADT::createnode(int data){
    node* newnode = new node();
    newnode->data=data;
    newnode->left=nullptr;
    newnode->right=nullptr;
    return newnode;
}
// Helps building the tree
void TreeADT::buildTree(){
    root = buildTreeHelper();
}
// Builds the tree
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
// Inorder traversal of tree
void TreeADT::InorderTraversal(node* ptr){

    if (ptr == nullptr){
        return;
    }
    InorderTraversal(ptr->left);
    cout<<ptr->data<<" ";
    InorderTraversal(ptr->right);
    
}
// Preorder traversal of tree
void TreeADT::preorderTraversal(node* ptr){

    if (ptr == nullptr){
        return;
    }
    cout<<ptr->data<<" ";
    preorderTraversal(ptr->left);
    preorderTraversal(ptr->right);
    
}
// Postorder traversal of tree
void TreeADT::postorderTraversal(node* ptr){

    if (ptr == nullptr){
        return;
    }
    postorderTraversal(ptr->left);
    postorderTraversal(ptr->right);
    cout<<ptr->data<<" ";
    
}

// Search of element in the tree
TreeADT::node* TreeADT::searchBinaryTree(node* root, int key) {
    if (root == nullptr) 
        return nullptr;

    if (root->data == key) 
        return root;

    // Search in left and right subtrees
    node* leftSearch = searchBinaryTree(root->left, key);
    if (leftSearch) 
        return leftSearch;

    return searchBinaryTree(root->right, key);
}

void TreeADT::search(int val){
    node* result = searchBinaryTree(root, val);
    if ( result){
        cout<<"Found!"<<endl;
    }
    else{
        cout<<"Not Found!"<<endl;
    }
}