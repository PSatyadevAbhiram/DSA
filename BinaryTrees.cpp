#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class treeNode{
    public:
        int data;
        treeNode* left;
        treeNode* right;
        treeNode(int data){
            this->data = data;
            left = nullptr;
            right = nullptr;
        }
        treeNode(){
            this->data = 0;
            left = nullptr;
            right = nullptr;
        }
};

class treeAlgos{
    public:
    treeNode* insertElement(treeNode* root, int val){
        if(root == nullptr){
            return new treeNode(val);
        }
        if(root->data > val){
            root->left = insertElement(root->left, val);
        }
        else{
            root->right = insertElement(root->right, val);
        }
        return root;
    }
    treeNode* createTree(){
        int n;
        cout<<"Enter the number of elements in your tree: ";
        cin>>n;
        cout<<endl;
        vector<int> vec;
        for(int i=0; i<n;i++){
            int x;
            cout<<"Enter element: ";
            cin>>x;
            vec.push_back(x);
        }
        sort(vec.begin(), vec.end());
        treeNode* root = new treeNode(vec[n/2]);
        for(int i=0;i<n/2;i++){
            root = insertElement(root, vec[i]);
        }
        for(int i=n/2+1;i<n;i++){
            root = insertElement(root, vec[i]);
        }
        return root;
    }
    void inorder(treeNode* root){
        if(root){
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }
    void preorder(treeNode* root){
        if(root){
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void postorder(treeNode* root){
        if(root){
            preorder(root->left);
            preorder(root->right);
            cout<<root->data<<" ";
        }
    }

    bool isValidBST_helper(treeNode* root, int min, int max){
        if(!root){
            return true;
        }
        if(root->data < min || root->data > max){
            return false;
        }
        return isValidBST_helper(root->left, min, root->data) && isValidBST_helper(root->right, root->data, max);
    }

    bool isValidBST(treeNode* root){
        return isValidBST_helper(root, INT_MIN, INT_MAX);
    }

    void levelOrderTraversal(treeNode* root){
        vector<vector<int>> res;
        if(!root){
            return;
        }

        queue<treeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int qs = q.size();
            for(int i=0;i<qs;i++){
                treeNode *temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                level.push_back(temp->data);    
            }
            res.push_back(level);
        }

        for(int i=0;i<res.size();i++){
            for(int j=0;j<res[i].size();j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    int maxDepthBinaryTree(treeNode* root){
        if(!root) return 0;
        return 1+max(maxDepthBinaryTree(root->left), maxDepthBinaryTree(root->right)); 
    }

    bool isBSTSymmetrical_helper(treeNode* left, treeNode* right){
        if(!left && !right){
            return true;
        }
        if(!left || !right){
            return false;
        }
        return (left->data == right->data) 
                && isBSTSymmetrical_helper(left->left, right->right)
                && isBSTSymmetrical_helper(left->right, right->left);
    }

    bool isBSTSymmetrical(treeNode* root){
        if(!root){
            return true;
        }
        return isBSTSymmetrical_helper(root->left, root->right);
    }

};

int main(){
    treeAlgos obj;
    treeNode* root = obj.createTree();
    cout<<obj.isBSTSymmetrical(root)<<endl;
}