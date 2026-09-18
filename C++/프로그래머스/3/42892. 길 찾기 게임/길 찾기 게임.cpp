#include <bits/stdc++.h>

using namespace std;

struct Node {
    int id;
    int x, y;
    Node* left_node;
    Node* right_node;
    
    Node(int id, int y, int x): id(id), y(y), x(x), left_node(nullptr), right_node(nullptr){}
    
    bool operator<(Node& other){
        if (this->y == other.y)
            return this->x < other.x;
        return this->y > other.y;
    }
};

void insertNode(Node* parent, Node* child){
    
    if (child->x < parent->x){
        if (parent->left_node == nullptr)
            parent->left_node = child;
        else
            insertNode(parent->left_node, child);
    }
    else if (child->x > parent->x){
        if (parent->right_node == nullptr)
            parent->right_node = child;
        else
            insertNode(parent->right_node, child);
    }
}

void preorder(Node* root, vector<int>& result){
    if (root == nullptr) return;
    
    result.push_back(root->id);
    preorder(root->left_node, result);
    preorder(root->right_node, result);
}

void postorder(Node* root, vector<int>& result){
    if (root == nullptr) return;
    
    
    postorder(root->left_node, result);
    postorder(root->right_node, result);
    result.push_back(root->id);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> ans;
    vector<Node> Nodes;
    
    for (int i=0; i < nodeinfo.size(); i++){
        Nodes.push_back(Node(i+1, nodeinfo[i][1], nodeinfo[i][0]));
    }
    
    sort(Nodes.begin(), Nodes.end());
    
    // for (Node n: Nodes){
    //     cout << n.id << " " << n.y << " " << n.x << "\n";
    // }
    
    Node* root = &Nodes[0];
    for (int i=1; i < Nodes.size(); i++){
        insertNode(root, &Nodes[i]);
    }
    
    vector<int> pre_vec;
    vector<int> post_vec;
    
    preorder(root, pre_vec);
    postorder(root, post_vec);
    
    ans.push_back(pre_vec);
    ans.push_back(post_vec);
    
    return ans;
}