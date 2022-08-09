/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    bool isValidHelper(TreeNode* root, TreeNode* min, TreeNode* max)
    {
        if (root == nullptr) return true;
        
        if(min && min->val >= root->val) return false;
        
        if(max && max->val <= root->val) return false;
        
        return isValidHelper(root->left, min, root) && isValidHelper(root->right, root, max);
        
        
    }    
    bool isValidBST(TreeNode* root) 
    {
        return isValidHelper(root, nullptr, nullptr);
    }
};

class Solution {
public:
    TreeNode* successor_head = nullptr;
    
    bool inOrder(TreeNode* root, TreeNode* p)
    {
        if(root == nullptr) return false;
        
        if(root == p) return true;
        
        bool left = inOrder(root->left, p);
        if(left)
        {
            if(successor_head == nullptr)
                successor_head = root;
            return true;
        }

        
        bool right = inOrder(root->right, p);
        return right;
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        if(p == nullptr || root == nullptr) return nullptr;
        
        TreeNode* suc = nullptr;
        
        if(p->right)
        {
            suc = p->right;
            while(suc->left)
            {
                suc = suc->left;
            }
        }
        if (suc)
            return suc;
        
        if( inOrder( root, p))
        {
            if(successor_head)
                return successor_head;
        }
        
        return nullptr;
        
    }
};
