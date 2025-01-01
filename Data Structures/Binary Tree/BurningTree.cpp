#include<iostream>
#include<queue>
#include<map>
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

Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent){
    Node* res = NULL;
    queue<Node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front->data == target){
            res = front;
        }

        if(front->left){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }

        if(front->right){
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

void burnTree(Node* root, map<Node*, Node*> &nodeToParent, int &ans){
    map<Node*, bool> visited;
    queue<Node*> q;

    q.push(root);
    visited[root] = true;

    while(!q.empty()){
        int flag = 0;
        int size = q.size();

        for(int i = 0; i < size; i++){
            Node* front = q.front();
            q.pop();

            if(front->left && !visited[front->left]){
                flag = 1;
                q.push(front->left);
                visited[front->left] = true;
            }

            if(front->right && !visited[front->right]){
                flag = 1;
                q.push(front->right);
                visited[front->right] = true;
            }

            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }

        if(flag == 1){
            ans++;
        }
    }
}

int BurningTree(Node* root, int target){
    int ans = 0;
    map<Node*, Node*> nodeToParent;
    Node* targetNode = createParentMapping(root, target, nodeToParent);
    burnTree(targetNode, nodeToParent, ans);
    return ans;
}

int main(){

    return 0;
}