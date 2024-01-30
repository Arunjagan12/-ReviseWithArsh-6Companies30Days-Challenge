class Solution {
public:
    string numberToWords(int num) {
         if(num == 0) return "Zero";
        vector<string> words = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",       "Eight","Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        return process(words, num);
    }
    private:
    string process(vector<string> words, int num){
        string ans = "";
        if (num >= 1000000000) { //1,000,000,000 
            ans += process(words, num / 1000000000) + " " + "Billion" + " " + process(words,num%1000000000);
        }
        else if (num >= 1000000) { //1,000,000
            ans += process(words, num / 1000000) + " " + "Million" + " " +  process(words,num%1000000);
        }
        else if (num >= 1000) { //1,000
            ans += process(words, num / 1000) + " " + "Thousand" + " " + process(words,num%1000);
        }
        else if (num >= 100) { //100
            ans += process(words, num / 100) + " " + "Hundred" + " " + process(words,num%100);
        }
        else if (num >= 20){
            ans += words[(num - 20)/ 10 + 20] + " " + process(words, num %10);
        }
        else {
            ans += words[num];
        }

            return trim(ans);
    }

    string trim(string str){ 
        int startpos = 0, endpos = str.size() -1;
        while(startpos < str.size()){
            if(str[startpos] == ' ' ) { startpos ++;}
            else break;
        }

       while(endpos > 0){
            if(str[endpos] == ' ') endpos --;
            else break;
        } 
        if(endpos >= startpos){
            str = str.substr(startpos, endpos - startpos + 1);
        }
        return str;

    }
};