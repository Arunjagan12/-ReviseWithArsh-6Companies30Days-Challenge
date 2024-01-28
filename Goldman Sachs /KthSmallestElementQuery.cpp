class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
  
        int numOfNumbers = nums.size(); 
        vector<pair<string, int>> trimmedNumbers(numOfNumbers);  
        vector<int> ans; 

        
        for (auto& query : queries) {
            int k = query[0];  
            int trimLength = query[1]; 

           
            for (int i = 0; i < numOfNumbers; ++i) {
               
                trimmedNumbers[i] = {nums[i].substr(nums[i].size() - trimLength), i};
            }

      
            sort(trimmedNumbers.begin(), trimmedNumbers.end());

            
            ans.push_back(trimmedNumbers[k - 1].second);
        }

      
        return ans;
    }
};
