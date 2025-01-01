#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* BuildTree(Node* root){
    cout << "Enter the data for the node" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter the data for the left subtree" << data << endl;
    root->left = BuildTree(root->left);

    cout << "Enter tge data for the right subtree" << data << endl;
    root->right = BuildTree(root->right);

    return root;
}

bool isIdentical(Node* r1, Node* r2){
    if(r1 == NULL && r2 == NULL)
        return true;
    if(r1 == NULL && r2 != NULL)
        return false;
    if(r1 != NULL && r2 == NULL)
        return false;

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    bool val = r1->data == r2->data;

    if(left && right && val){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Node* root = NULL;
    root = BuildTree(root);

    
    return 0;
}