class Node{
    public:
    int key,val;
    Node* next;
    Node* prev;
    Node(){
       next = prev = NULL;
       key = val = -1;
    } 
    Node(int key,int val){
        this->key = key;
        this->val = val;
        next = prev = NULL;
    }
};
class LRUCache {
public:
    int cap;
    map<int,Node*>mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
         cap = capacity;
         head = new Node();
         tail = new Node();
         head->next = tail;
         tail->prev = head;
    }

     void deleteNode(Node* node){
    Node* prevNode = node->prev;
    Node* nextNode = node->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    node->next = NULL;
    node->prev = NULL;

    return;
  }
  void insertNode(Node* node){
    Node* nextNode = head->next;
    head->next = node;
    node->prev = head;
    node->next = nextNode;
    nextNode->prev = node;
  }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
        return -1;
        Node* node = mp[key];
        deleteNode(node);
        insertNode(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            if(mp.size() == cap){
                 mp.erase(tail->prev->key);
            deleteNode(tail->prev);
           
            }
            Node* node = new Node(key,value);
            insertNode(node);
            mp[key] = node;
        } else {
            Node* node = mp[key];
            deleteNode(node);
            node->val = value;
            insertNode(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */