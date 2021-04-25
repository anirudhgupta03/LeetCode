class Solution {
public:
    string truncateSentence(string s, int k) {
        
        string ans;
        int count  = 0;
        
        stringstream X(s);
        
        string temp;
        
        while(X >> temp){
            count++;
            if(count == k) break;
            ans += temp;
            ans+= " ";    
        }
        ans += temp;
        
        return ans;
    }
};
