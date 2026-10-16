class LRUCache {
public:
    struct Node{
        Node* node;
        Node* next;
        Node* prev;
        int val;
        int key;
        Node(int _key, int _val){
            key = _key;
            val = _val;
            next = NULL;
            prev = NULL;
        }
    };

    unordered_map<int, Node*>m;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int size = 0;
    LRUCache(int capacity) {
        this->size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void removeNode(Node* temp){
      temp->next->prev = temp->prev;
      temp->prev->next = temp->next;
      return ;
    }
    void addNode(Node* node){
      Node* temp = head->next;
      head->next = node;
      node->prev = head;
      node->next = temp;
      temp->prev = node;
      return ;
    }

    int get(int key) {
        if(m.find(key)!=m.end()){
            removeNode(m[key]);
            addNode(m[key]);
            return m[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            m[key]->val = value;
            removeNode(m[key]);
            addNode(m[key]);
            return ;
        }
        if(m.size()>=size){
            m.erase(tail->prev->key);
            removeNode(tail->prev);
        }
        Node* newNode = new Node(key, value);
        m[key] = newNode;
        addNode(newNode);
        return ;
    }
};
