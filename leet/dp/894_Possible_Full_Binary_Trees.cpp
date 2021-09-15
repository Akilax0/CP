/**
 *
 *	Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.
 *
 *
 *
 *
 * */



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<int,vector<TreeNode*>> cache;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if(cache[n].size() != 0) return cache[n];
        if(n==1){
            ans.push_back(new TreeNode(0));
        }else{
            vector<TreeNode*> left_trees;
            vector<TreeNode*> right_trees;

            for(int i=1;i<n;i+=2){

                for(TreeNode* left: allPossibleFBT(i)){
                    for(TreeNode* right : allPossibleFBT(n-i-1)){
                        TreeNode* root = new TreeNode(0);
                        root->left = left;
                        root->right = right;

                        ans.push_back(root);
                    }
                }
            }
        }
        cache[n]=ans;
        return ans;
    }
};
