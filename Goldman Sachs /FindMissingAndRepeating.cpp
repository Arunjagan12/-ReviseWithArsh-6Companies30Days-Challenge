class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(arr[i]==arr[i+1]){
            ans.push_back(arr[i]);
    
            }
            
        }
        unordered_set<int> s;
        for(auto it:arr)
        s.insert(it);
        
        for(int i=1;i<=n;i++){
            if(!s.count(i)){
            ans.push_back(i);
            break;
        }
        }
        return ans;
    }
};
