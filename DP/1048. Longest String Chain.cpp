class Solution {
public:
    bool isPredecessor(string &str1, string &str2){
        int p1 = 0, p2 = 0;
        bool flag = false;
        while(p1 < str1.length() && p2 < str2.length()){
            if(str1[p1] != str2[p2]){
                if(flag) return false;
                flag = true;
                p2++;
            }
            else{
                p1++;
                p2++;
            }
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        
        int n = words.size();

        vector<pair<int,string>> twords;
        for(int i = 0; i < n; i++){
            twords.push_back({words[i].length(), words[i]});
        }
        sort(twords.begin(), twords.end());

        vector<int> dp(n, 1);
        int ans = 1;

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(twords[i].first - twords[j].first == 1 && isPredecessor(twords[j].second, twords[i].second)){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
