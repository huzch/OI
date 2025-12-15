class Trie {
    struct Node {
        Node* son[26] = {nullptr};
        bool end = false;
    };
    Node* root = new Node;
public:
    void insert(string word) {
        auto cur = root;
        for(char ch: word) {
            int path = ch - 'a';
            if(cur->son[path] == nullptr) {
                cur->son[path] = new Node;
            }
            cur = cur->son[path];
        }
        cur->end = true;
    }

    bool search(string word) {
        auto cur = root;
        for(char ch: word) {
            int path = ch - 'a';
            if(cur->son[path] == nullptr) {
                return false;
            }
            cur = cur->son[path];
        }
        return cur->end;
    }

    bool startsWith(string prefix) {
        auto cur = root;
        for(char ch: prefix) {
            int path = ch - 'a';
            if(cur->son[path] == nullptr) {
                return false;
            }
            cur = cur->son[path];
        }
        return true;
    }
};
