// 方法：贪心
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        strs.reserve(nums.size());
        for (int num : nums) {
            strs.emplace_back(to_string(num));
        }

        ranges::sort(strs, [](string& x, string& y) { 
            return x + y > y + x;
        });
        if(strs[0] == "0") return "0"; //防止全部都是0拼接在一起

        string ret;
        for(auto& str: strs) ret += str;
        return ret;
    }
};
