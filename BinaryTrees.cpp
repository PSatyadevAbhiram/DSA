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
        print2dVector(res);
    }

    void print2dVector(vector<vector<int>> res){
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res[i].size();j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void zigzag(treeNode* root){
        vector<vector<int>> res;
        if(!root){
            return;
        }
        bool left2right = true;
        queue<treeNode*> q;
        q.push(root);
        while(!q.empty()){
            int qs = q.size();
            vector<int> level(qs);
            for(int i=0;i<qs;i++){
                treeNode* temp = q.front();
                q.pop();
                
                int ind = left2right ? i : qs-i-1;

                level[ind] = temp->data;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            res.push_back(level);
            left2right = !left2right;
        }
        print2dVector(res);
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

    bool pathSum(treeNode* root, int target){
        if(!root){
            return false;
        }
        if(!root->left && !root->right){
            return root->data == target;
        }
        return pathSum(root->left, target-root->data)
            || pathSum(root->right, target-root->data);
    }  

    void invertBST(treeNode* root){
        if(!root) return;

        treeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertBST(root->left);
        invertBST(root->right); 
    }

    treeNode* lowestCommonAncestor(treeNode* root, treeNode* p, treeNode* q){
        if(!root){
            return nullptr;
        }
        while(root){
            if(root->data > p->data && root->data > q->data){
                root = root->left;
            }
            else if(root->data < p->data && root->data < q->data){
                root = root->right;
            }
            else{
                break;
            }
        }
        return root;
    }

    bool isBalanced(treeNode* root){
        if(!root){
            return true;
        }
        bool isLeftSubtreeBalanced = isBalanced(root->left);
        bool isRightSubtreeBalanced = isBalanced(root->right);
        int leftHeight = maxDepthBinaryTree(root->left);
        int rightHeight = maxDepthBinaryTree(root->right);
        return isLeftSubtreeBalanced && isRightSubtreeBalanced && abs(leftHeight-rightHeight)<=1;
    }

    int maxSum_helper(treeNode* root, int maxSum){
        if(!root){
            return 0;
        }

        //Recursively check left & right subtree
        int leftMaxSum = max(0, maxSum_helper(root->left, maxSum));
        int rightMaxSum = max(0, maxSum_helper(root->right, maxSum));

        //Update max path sum so far
        maxSum = max(maxSum, leftMaxSum + rightMaxSum + root->data);

        //Return max path sum from the CURRENT subtree
        return max(leftMaxSum,rightMaxSum) + root->data;
    }

    int maxPathSum(treeNode* root){
        int maxSum = INT_MIN;
        int res = maxSum_helper(root, maxSum);
        return res;
    }

    int countCompleteNodes(treeNode* root) {
        if (!root) {
            return 0;
        }
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (leftHeight == rightHeight) {
            // If left and right subtrees have the same height, the left subtree is a complete tree.
            // Count the nodes in the left subtree (2^leftHeight - 1) plus the root node.
            return (1 << leftHeight) + countCompleteNodes(root->right);
        } else {
            // If left and right subtrees have different heights, the right subtree is a complete tree,
            // and the left subtree is one level less than complete.
            // Count the nodes in the right subtree (2^rightHeight - 1) plus the root node.
            return (1 << rightHeight) + countCompleteNodes(root->left);
        }
    }

    int getHeight(treeNode* root) {
        int height = 0;
        while (root) {
            root = root->left;
            height++;
        }
        return height;
    }

};

int main(){
    treeAlgos obj;
    treeNode* root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->left = new treeNode(4);
    root->left->right = new treeNode(5);
    root->right->left = new treeNode(6);
    root->right->right = new treeNode(7);
    cout<<obj.countCompleteNodes(root)<<endl;
}