// 方法一：排序+哈希
// time: O(Lnlogn), space: O(Ln), L为字符串平均长度
class Solution {
    unordered_set<string> hash;
    string ret;
public:
    string longestWord(vector<string>& words) {
        ranges::sort(words, [](string&a, string& b) {
            if(a.size() != b.size()) return a.size() < b.size();
            else return a > b; //由于后续不停更新，故字典序小的放在后面
        });

        hash.insert(""); //必须从空串开始构造
        for(auto& s: words) {
            auto t = s.substr(0, s.size() - 1);
            if(hash.count(t)) {
                ret = s; hash.insert(s);
            }
        }
        return ret;
    }
};

// 方法二：Trie(字典树)
// time: O(Ln), space: O(Ln), L为字符串平均长度
class Solution {
    struct Node {
        Node* son[26] = {nullptr};
        bool end = false;
    };
    class Trie {
        Node* root = new Node;
    public:
        void insert(string& word) {
            auto cur = root;
            for(char ch: word) {
                int path = ch - 'a'; //全小写
                if(cur->son[path] == nullptr) {
                    cur->son[path] = new Node;
                }
                cur = cur->son[path];
            }
            cur->end = true;
        }

        bool find(string& word) {
            auto cur = root;
            for(char ch: word) {
                int path = ch - 'a';
                if(cur->son[path] == nullptr) return false;
                cur = cur->son[path];
                if(!cur->end) return false; //保证每个前缀都存在
            }
            return cur->end;
        }
    };
    Trie tr;
    string ret;
public:
    string longestWord(vector<string>& words) {
        for(auto& word: words) tr.insert(word);
        for(auto& word: words) {
            if(tr.find(word)) {
                if(word.size() > ret.size() || (word.size() == ret.size() && word < ret)) {
                    ret = word;
                }
            }
        }
        return ret;
    }
};
