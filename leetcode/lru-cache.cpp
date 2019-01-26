
struct List {
    List* nxt, *prev;
    int key;
    int val;
    List() {};
    List(List* _nxt, List* _prev, int _key, int _val) : nxt(_nxt), prev(_prev), key(_key), val(_val) {};
};
class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->curCap = 0;
        this->fst = NULL;
        this->lst = NULL;
    }
    
    int get(int key) {
        List* node = loc[key];
        if(!node) return -1;
        if(node->prev)
            node->prev->nxt = node->nxt;
        else fst = node->nxt;
        if(node->nxt)
            node->nxt->prev = node->prev;
        else lst = node->prev;
        if(lst)
            lst->nxt = node;
        node->prev = lst;
        node->nxt = NULL;
        if(!fst)
            fst = node;
        lst = node;
        return node->val;
    }
    
    void put(int key, int value) {
        if(this->get(key) != -1) {
            lst->val = value;
            return;
        }
        auto node = new List(NULL, lst, key, value);
        loc[key] = node;
        if(lst) {
            lst -> nxt = node;
        }
        if(!fst)
            fst = node;
        lst = node;
        if(curCap == capacity) {
            loc.erase(fst->key);
            List* tmp = fst;
            fst = fst->nxt;
            fst->prev = NULL;
            delete tmp;
        } else curCap++;
    }
private:
    int capacity, curCap;
    unordered_map<int, List*> loc;
    List* fst, *lst;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

