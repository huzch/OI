// 方法一：队列模拟
// time: O(n), space: O(n)
class Solution {
    queue<int> q;
    int cnt[2];
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        for(int x: students) {
            if(x == 0) ++cnt[0];
            q.push(x);
        }
        int n = students.size();
        cnt[1] = n - cnt[0];

        for(int x: sandwiches) {
            if(cnt[x] == 0) break;
            // 只要队列中还有喜欢这个三明治的学生，就一直循环
            while(cnt[x] > 0) {
                if(q.front() == x) {
                    q.pop(); --cnt[x]; break;
                } else {
                    q.push(q.front()); q.pop();
                }
            }
        }
        return cnt[0] + cnt[1];
    }
};

// 方法二：模拟简化
// time: O(n), space: O(1)
class Solution {
    int cnt[2];
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        for(int x: students) {
            if(x == 0) ++cnt[0];
        }
        int n = students.size();
        cnt[1] = n - cnt[0];

        for(int x: sandwiches) {
            if(cnt[x] == 0) break;
            if(cnt[x] > 0) --cnt[x];
        }
        return cnt[0] + cnt[1];
    }
};
