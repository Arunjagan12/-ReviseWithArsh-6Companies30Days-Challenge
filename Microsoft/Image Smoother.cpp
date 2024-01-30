class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
     int m=img.size();
     int n=img[0].size();
      vector<vector<int>> result(m, vector<int>(n));
     vector<int> dir={-1,0,1};
     for(int i=0;i<m;i++){
         for(int j=0;j<n;j++){
             int sum=0,cnt=0;
             for(int dx:dir){
                 for(int dy:dir){
                     int x=i+dx;
                     int y=j+dy;

                     if(x>=0 && x<m && y>=0 && y<n){
                         sum+=img[x][y];
                         cnt++;
                     }
                 }
             }
             result[i][j]=sum/cnt;
         }
     }
return result;
    }
};