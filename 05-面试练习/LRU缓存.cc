// 方法一：双哈希表（通过记录次数来判断最近最少使用）效率较低
class LRUCache {
public:
    LRUCache(int capacity) :_capacity(capacity) {}
    
    int get(int key) {
        if(_hash.count(key)) {
            _cache[key] = --level;
            return _hash[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(_cache.size() == _capacity) {
            if(!_hash.count(key)) {
                //找到count最大的数据并删除
                int maxCnt = INT_MIN, maxKey = INT_MIN;
                for(auto& [k, cnt]: _cache) {
                    if(cnt > maxCnt) {
                        maxCnt = cnt;
                        maxKey = k;
                    }
                }
                _cache.erase(maxKey);
                _hash.erase(maxKey);
            }
        }

        _cache[key] = --level;
        _hash[key] = value;
    }
private:
    std::unordered_map<int, int> _cache; //<key,count>
    std::unordered_map<int, int> _hash; //<key,value>
    int _capacity;
    int level = INT_MAX;
};

// 方法二：双向链表（STL）+ 哈希表（每次访问后将节点移至头部）
class LRUCache {
public:
    using ListIt = std::list<pair<int,int>>::iterator;
public:
    LRUCache(int capacity) :_capacity(capacity) {}
    
    int get(int key) {
        if(!_hash.count(key)) return -1;
        //将节点移至begin之前，成为新的头部
        auto it = _hash[key];
        _cache.splice(_cache.begin(), _cache, it);
        return it->second;
    }
    
    void put(int key, int value) {
        if(_hash.count(key)) { //存在则移至头部，并更新值
            auto it = _hash[key];
            _cache.splice(_cache.begin(), _cache, it);
            it->second = value;
        } else { //不存在则头插
            _cache.emplace_front(key, value);
            _hash[key] = _cache.begin();

            //超过容量则尾删
            if(_cache.size() > _capacity) {
                int delKey = _cache.back().first;
                _hash.erase(delKey);
                _cache.pop_back();
            }
        }
    }
private:
    std::list<pair<int, int>> _cache; //<key,value>
    std::unordered_map<int, ListIt> _hash; //<key, ListIt>
    int _capacity;
};

// 方法三：双向链表（手动实现）+ 哈希表
struct Node {
    Node(int key = -1, int val = -1) 
        :_key(key), _val(val) {}
    struct Node* _prev = nullptr;
    struct Node* _next = nullptr;
    int _key, _val;
};

class LRUCache {
public:
    LRUCache(int capacity) :_capacity(capacity) {
        _cache = new Node;
        _cache->_prev = _cache;
        _cache->_next = _cache;
    }
    
    int get(int key) {
        if(!_hash.count(key)) return -1;
        //将节点剥离出来
        auto node = remove(key);
        //将节点移至头部之前，成为新的头部
        push_front(node);
        return node->_val;
    }
    
    void put(int key, int value) {
        if(_hash.count(key)) { //存在则移至头部，并更新值
            //将节点剥离出来
            auto node = remove(key);
            //将节点移至头部之前，成为新的头部
            push_front(node);
            node->_val = value;
        } else { //不存在则头插
            auto node = new Node(key, value);
            push_front(node);
            _hash[key] = node;
            ++_size;

            //超过容量则尾删
            if(_size > _capacity) {
                int tailKey = _cache->_prev->_key;
                delete remove(tailKey);
                _hash.erase(tailKey);
                --_size;
            }
        }
    }
private:
    void push_front(Node* node) {
        auto head = _cache->_next;
        _cache->_next = node;
        node->_prev = _cache;
        node->_next = head;
        head->_prev = node;
    }

    Node* remove(int key) {
        auto node = _hash[key];
        auto prev = node->_prev;
        auto next = node->_next;
        prev->_next = next;
        next->_prev = prev;
        return node;
    }
private:
    struct Node* _cache;
    std::unordered_map<int, Node*> _hash; //<key, Node*>
    int _capacity;
    int _size = 0;
};
