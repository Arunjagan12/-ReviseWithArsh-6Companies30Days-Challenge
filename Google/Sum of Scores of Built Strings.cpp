class Solution {
public:
    long long sumScores(string s) {
         const int n = s.length();
    vector<int> z(n);
    
    int l = 0;
    int r = 0;

    for (int i = 1; i < n; ++i) {
      if (i < r)
        z[i] = min(r - i, z[i - l]);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        ++z[i];
      if (i + z[i] > r) {
        l = i;
        r = i + z[i];
      }
    }

    return accumulate(z.begin(), z.end(), 0LL) + n;
    }
};