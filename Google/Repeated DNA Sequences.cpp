class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
         unordered_map<string, int> sequenceCount; 
        vector<string> result;
        
        for (int i = 0; i + 10 <= s.length(); ++i) {
            string sub = s.substr(i, 10); 
            sequenceCount[sub]++;
        }
        
        
        for (auto it = sequenceCount.begin(); it != sequenceCount.end(); ++it) {
            if (it->second > 1) {
                result.push_back(it->first);
            }
        }
        
        return result;
    }
};