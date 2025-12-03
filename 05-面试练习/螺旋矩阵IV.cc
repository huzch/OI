/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// 写法一：压缩边界
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ret(m, vector<int>(n));
        auto cur = head;
        int x = 0, y = 0;
        int up = 0, down = m - 1, left = 0, right = n - 1;
        while(left <= right) {
            while(x == up && y != right) {
                ret[x][y++] = cur ? cur->val : -1;
                if(cur) cur = cur->next;
            }
            if(++up > down) break;
            while(x != down && y == right) {
                ret[x++][y] = cur ? cur->val : -1;
                if(cur) cur = cur->next;
            }
            if(--right < left) break;
            while(x == down && y != left) {
                ret[x][y--] = cur ? cur->val : -1;
                if(cur) cur = cur->next;
            }
            if(--down < up) break;
            while(x != up && y == left) {
                ret[x--][y] = cur ? cur->val : -1;
                if(cur) cur = cur->next;
            }
            if(++left > right) break;
        }
        ret[x][y] = cur ? cur->val : -1;
        return ret;
    }
};

// 写法二：标记已访问+方向向量
class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ret(m, vector<int>(n, -1));

        auto cur = head;
        int i = 0, j = 0, p = 0;
        while(cur) {
            ret[i][j] = cur->val;
            cur = cur->next;
            int x = i + dx[p], y = j + dy[p];
            if(x < 0 || x >= m || y < 0 || y >= n || ret[x][y] != -1) {
                p = (p + 1) % 4;
            }
            i += dx[p], j += dy[p];
        }
        return ret;
    }
};
