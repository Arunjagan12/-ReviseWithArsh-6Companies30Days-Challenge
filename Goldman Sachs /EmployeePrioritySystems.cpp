class Solution {
public:
    int cal(string a,string b){
         if(a[0]==b[0]&&a[1]==b[1]){
           string s1 = a.substr(2, 2);
string s2 = b.substr(2, 2);

            int a1=stoi(s1);
            int b1=stoi(s2);
            return (abs(a1-b1));
        }
        else{
        string s1=a.substr(0,2);
        string s2=b.substr(0,2);
        string s3=a.substr(2,2); 
        string s4=b.substr(2,2);

        int a1=stoi(s1);
        int b1=stoi(s2);
        int a2=stoi(s3);
        int b2=stoi(s4);
         int time=0;
          if(abs(a1-b1)==1){
                if(a1<b1){time+=60-a2;time+=b2;}
                else {time+=60-b2;time+=a2;}
                return time;
            }
            else return INT_MAX;

        }

    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        int n=access_times.size();
       sort(access_times.begin(),access_times.end());
        unordered_map<string,vector<string>> mpp;

        //pushing the times in which employees are key

            for(int i=0;i<n;i++){

                mpp[access_times[i][0]].push_back(access_times[i][1]);
            }

            for(auto it=mpp.begin();it!=mpp.end();it++){
                string key=it->first;
                vector<string> vec=it->second;

                if(mpp[key].size()<3)
                continue;

                else{
                    for(int i=0;i<vec.size()-2;i++){
                        if(cal(mpp[key][i],mpp[key][i+2])<=59){
                            ans.push_back(key);
                            break;
                        }

                    }

                }
            }
            return ans;
    }
};
