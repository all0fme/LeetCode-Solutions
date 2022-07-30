class LRUCache {
public:
    class DLL{
        public:
        
        int key;
        int val;
        DLL* next;
        DLL* prev;
    };
    unordered_map<int,DLL*> mp;
    int cap;
    DLL* head ;
    DLL* back;
    
    void addFront(DLL * node){
        
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head; 
    }
    void delNode(DLL* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    int delBack(){
        int x = back->prev->key;
     back->prev->prev->next = back;
        back->prev = back->prev->prev;
        return x;
    }
    
    LRUCache(int capacity) {
        cap = capacity;
        head = new DLL();
        back = new DLL();
        
        head->next = back;
        back->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            delNode(mp[key]);
            addFront(mp[key]);
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            delNode(mp[key]);
            addFront(mp[key]);
            mp[key]->val = value;
        }
        else{
             if(cap==0){
            int temp = delBack();
            mp.erase(temp);
            
        }
        else{
            cap--;
        }
        DLL* newTemp = new DLL();
            newTemp->key = key;
            newTemp->val = value;
            mp[key] = newTemp;
            addFront(newTemp);
        
        }
       
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */