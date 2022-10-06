class Solution {
   
    public:
     
    void connectHelper(queue<Node*>& _queue)
    {
        int size = _queue.size();
        
        if(size == 0) return;
        
        Node* prev = _queue.front();
     
        
        for(int i = 0; i < size; ++i)
        {
            if(prev->left)
                _queue.push(prev->left);
            if(prev->right)
                _queue.push(prev->right);

            _queue.pop();
            
            if(i == size - 1)
            {
                prev->next = nullptr;
                break;
            }
            else
                prev->next = _queue.front();
            
            prev = _queue.front();
        }
        
        connectHelper(_queue);
    }
    
    Node* connect(Node* root)
    {
        if(root == nullptr) return root;
        
        queue<Node*> _queue;
        _queue.push(root);
        
        connectHelper(_queue);
        
        return root;
    }
    
    
};
