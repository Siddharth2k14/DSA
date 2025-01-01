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

//Inorder Traversal
void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//Postorder Traversal
void postorder(Node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    Node* root = NULL;
    root = BuildTree(root);

    cout << "The inorder traversal is" << endl;
    inorder(root);

    cout << endl;

    cout << "The postorder traversal is" << endl;
    postorder(root);
    return 0;
}