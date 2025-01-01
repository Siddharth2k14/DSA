#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node{
    private:
    int data;
    Node* left;
    Node* right;

    public:
    Node(int data){
        this->data = data;
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

vector<int> TopView(Node* root){
    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    map<int, int> topNode;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }

        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    for(auto i : topNode){
        ans.push_back(i.second);
    }

    return ans;
}

int main(){

    return 0;
}