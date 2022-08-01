class Solution {
public:

    Node* leftmost = nullptr;
    Node* rightmost = nullptr;
    
    void treeToDoublyListHelper(Node* root) 
    {
        if( root == nullptr ) return;
        
        
        treeToDoublyListHelper(root->left) ;

        if(rightmost)
        {
            rightmost->right = root;
            root->left = rightmost;
        }

        if( leftmost == nullptr) leftmost = root;

        rightmost = root;
    
        treeToDoublyListHelper(root->right);
        

    }
    
    Node* treeToDoublyList(Node* root) 
    {
        if(root == nullptr) return nullptr;
        
        treeToDoublyListHelper(root);
        
        if(leftmost && rightmost)
        {
            rightmost->right = leftmost;
            leftmost->left = rightmost;
            return leftmost;
        }
        
        return nullptr;
            
    }
};
