#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int findPos(vector<int> inorder, int element, int n){
    for(int i = 0; i < n; i++){
        if(inorder[i] == element){
            return i;
        }
    }
    return -1;
}

Node* solve(vector<int> inorder, vector<int> preorder, int &index, int inorderStart, int inorderEnd, int n){
    if(index > n || inorderStart > inorderEnd){
        return NULL;
    }

    int element = preorder[index++];
    Node* root = new Node(element);
    int position = findPos(inorder, element, n);

    root->left = solve(inorder, preorder, index, inorderStart, position-1, n);
    root->right = solve(inorder, preorder, index, position+1, inorderEnd, n);

    return root;

}

Node* Build_Tree(vector<int> &inorder, vector<int> &preorder){
    int preOrderIndex = 0;
    int n = inorder.size();
    Node* ans = solve(inorder, preorder, preOrderIndex, 0, n-1, n);
    return ans;
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    vector<int> preorder = {1, 6, 7, 8};
    vector<int> inorder = {1, 6, 8, 7};

    postorder(Build_Tree(inorder, preorder));

    return 0;
}