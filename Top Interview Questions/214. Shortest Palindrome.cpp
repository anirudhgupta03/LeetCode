//Time complexity: O(n)
//Space complexity: O(n)
//Ref1: https://www.youtube.com/watch?v=GTJr8OvyEVQ
//Ref2: https://www.youtube.com/watch?v=c4akpqTwE5g
//Ref3: https://leetcode.com/problems/shortest-palindrome/discuss/60113/Clean-KMP-solution-with-super-detailed-explanation
class Solution {
public:
    string shortestPalindrome(string str) {
    
        string rev = str;
        reverse(rev.begin(),rev.end());
        
        string s;
        s = str + "#" + rev;
        
        int n = s.size();

        int i = 0, j = 1;

        vector<int> lps(n);

        while(j < s.size()){

            if(s[i] != s[j] && i == 0){
                lps[j] = 0;
                j++;
            }
            else if(s[i] == s[j]){
                lps[j] = i + 1;
                i++;
                j++;
            }
            else if(s[i] != s[j] && i != 0){

                bool flag = false;
                while(i){
                   i = lps[i-1];
                   if(s[i] == s[j]){
                       lps[j] = i + 1;
                       i++;
                       j++;
                       flag = true;
                       break;
                   }
                }

                if(s[i] == s[j]){
                    flag = true;
                    lps[j] = i + 1;
                    i++;
                    j++;
                }

                if(!flag){
                    lps[j] = 0;
                    j++;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            cout << lps[i] << " ";
        }
        cout << endl;
        int mct = lps[n-1];

        return (rev.substr(0,rev.size()-mct) + str);
    }
};
