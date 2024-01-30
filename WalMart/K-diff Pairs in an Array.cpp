class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
         if (k < 0) return 0;
        unordered_set<int> s, m;
        for (auto n: nums) {
         
            if (m.count(n - k)) s.insert(n-k);
            
            if (m.count(n + k)) s.insert(n);
            m.insert(n);
        }
        return s.size();
    }
};