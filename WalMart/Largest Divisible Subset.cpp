class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) {
        return {};
    }

    int n = nums.size();
    
    // Sort the array in ascending order
    sort(nums.begin(), nums.end());

    // dp[i] represents the size of the largest divisible subset ending with nums[i]
    vector<int> dp(n, 1);

    // Parent array to keep track of the previous index in the largest divisible subset
    vector<int> parent(n, -1);

    // Find the largest divisible subset size and its ending index
    int maxSize = 1, endIndex = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
                if (dp[i] > maxSize) {
                    maxSize = dp[i];
                    endIndex = i;
                }
            }
        }
    }

    // Reconstruct the largest divisible subset
    vector<int> result;
    while (endIndex != -1) {
        result.push_back(nums[endIndex]);
        endIndex = parent[endIndex];
    }

    return result;
    }
};