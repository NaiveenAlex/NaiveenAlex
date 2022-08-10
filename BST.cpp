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


class BSTIterator {
public:
    TreeNode* _next = nullptr;
    TreeNode* _root = nullptr;

    TreeNode* _successor_head = nullptr;
    
    bool inOrder(TreeNode* root, TreeNode* p)
    {
        if(root == nullptr) return false;
        
        if(root == p) return true;
        
        bool left = inOrder(root->left, p);
        if(left)
        {
            if(_successor_head == nullptr)
                _successor_head = root;
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
        _successor_head = nullptr;
        if( inOrder( root, p))
        {
            if(_successor_head)
                return _successor_head;
        }
        
        return nullptr;
        
    }
    
    
    BSTIterator(TreeNode* root) 
    {
        _root = root;
        
        while(root->left)
        {
            root = root->left;
        }
        _next = root;
        
        /*cout << "BSTI : " << _root->val << endl;
        if(_next)
        cout << _next->val << endl;*/
    }
    
    int next() 
    {
        if(hasNext())
        {
        int result = _next->val;
        
        _next = inorderSuccessor( _root, _next);
        
        return result;
        }
        return -1;
    }
    
    bool hasNext() 
    {
        return _next != nullptr;    
    }
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root == nullptr) return nullptr;
        if(root->val == key)
        {
            if(root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            
            if(root->left && root->right == nullptr)
            {
                TreeNode* node = root;
                root = root->left;
                delete node;
                return root;
            }

            //If key node has right child, replace the key node with the leftmost child of the right branch
            if(root->right)
            {
                TreeNode* node = root;
                TreeNode* suc  = root->right;
                TreeNode* prev = root;
                while(suc->left)
                {
                    prev = suc;
                    if(suc->left)
                        suc = suc->left;
                }
                if(suc != root->right)
                {
                    //Replace the predecessor's left node with successor's right node, as successor has no left child.
                    prev->left = suc->right;
                    suc->right = root->right;
                }
                suc->left = root->left;

                
                delete node;
                return suc;
            }
        }
        
        if(key > root->val)
            root->right = deleteNode(root->right, key);   
        else
            root->left = deleteNode(root->left, key);
        return root;
    }
};
