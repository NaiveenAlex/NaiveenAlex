class LRUCache {
public:
    
    struct DoublyListNode
    {
        int key;
        int val;
        DoublyListNode *next, *prev;
        DoublyListNode(int x, int y):key(x), val(y), next(NULL), prev(NULL){};
    };


    DoublyListNode *  removeFromHead() 
    {
        DoublyListNode * node = head->next;
        head->next = node->next;
        node->next->prev = head;
        return node;
    }

    void addAtTail(DoublyListNode * node) 
    {
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
    }


    unordered_map<int, DoublyListNode*> _map;
    DoublyListNode* head = nullptr, *tail = nullptr;
    int _capacity;

    LRUCache(int capacity) 
    {
        _capacity = capacity;
		head = new DoublyListNode( 0, 0);
		tail = new DoublyListNode( 0, 0);
		head->next = tail;
		tail->prev = head;
    }
	
	int get(int key)
	{
        if(_map.count(key) > 0)
        {
			DoublyListNode* node = _map[key];
			node->prev->next = node->next;
			node->next->prev = node->prev;
			int val = node->val;
			addAtTail(node);
			return val;
        }
		
		return -1;
	}

    void put(int key, int value) 
    {

        if(_map.count(key) > 0)
        {
			DoublyListNode* node = _map[key];
			node->prev->next = node->next;
			node->next->prev = node->prev;
			node->val = value;
			addAtTail(node);
			_map[key] = node;
        }
        else
        {
			int size = _map.size();
			if(size == _capacity)
			{
				DoublyListNode* node = removeFromHead();
				_map.erase(node->key);
				delete node;
			}
			DoublyListNode* node = new DoublyListNode( key, value);
			addAtTail(node);
			_map[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
