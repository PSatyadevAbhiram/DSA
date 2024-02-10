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
    }
    treeNode* createTree(){
        int n;
        cout<<"Enter the number of elements in your tree: ";
        cin>>n;
        cout<<endl;
        vector<int> vec;
        for(int i=0; i<n;i++){
            int x;
            cout<<"Enter elemenet: ";
            cin>>x;
            vec.push_back(x);
        }
        for(int i=0;i<n;i++){

        }
    }
};