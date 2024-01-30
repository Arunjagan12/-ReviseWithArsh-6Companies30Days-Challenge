class Solution {
public:

    string frequencySort(string s) {
        map<char,int> mpp;
        for(char c:s)
        mpp[c]++;
        vector<pair<char,int>> ans(mpp.begin(),mpp.end());
        string s1="";
        sort(ans.begin(),ans.end(),[](const pair<char, int> &a, const pair<char, int> &b) {
        return a.second > b.second;
    });

        for(const auto pair:ans){
            s1+=string(pair.second,pair.first);
        }
return s1;

    }
};