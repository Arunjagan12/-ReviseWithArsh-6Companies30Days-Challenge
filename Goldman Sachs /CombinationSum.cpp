class Solution {
    vector<vector<int>> res;
    int maxEl, limit = 45, target;

public:
    bool isPromising(int cur, int size) {
        if(limit < cur || maxEl == size) return false;
        return true;
    }

    void dfs(int level, int sum, vector<int>& comb) {
        if(sum == target && comb.size() == maxEl)
        {
            res.push_back(comb);
            return;
        }

        if(level == 9)
            return;


        if(isPromising(sum, comb.size()))
        {
            int nextLevel = level+1;
            comb.push_back(nextLevel);
            dfs(nextLevel, sum+nextLevel, comb);
            comb.pop_back();
            dfs(nextLevel, sum, comb);
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        maxEl = k; target = n;

        if(limit < n) return res;

        vector<int> temp;
        dfs(0, 0, temp);

        return res;
    }
};
