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
public:
    //int sum=0;
    int ss(TreeNode* root,int sum) {
        sum*=10;
        sum+=root->val;
        int value1=0,value2=0;
           if(root->left)
        {
               //sum+=value;
            value1=ss(root->left,sum);
              
        }
        if(root->right)
        {
           // sum+=value;
            value2=ss(root->right,sum);
            
        }
        return max(value1+value2,sum);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)return 0;
        int sum=root->val;
        int value1=0,value2=0;
        if(root->left)
        {
            value1=ss(root->left,sum);
        }
        if(root->right)
        {
             value2=ss(root->right,sum);
        }
        return max(value1+value2,sum);
    }
};