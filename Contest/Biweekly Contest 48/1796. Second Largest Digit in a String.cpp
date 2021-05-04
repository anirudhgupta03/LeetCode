class Solution {
public:
    int secondHighest(string s) {
        
        int digit = -1, count = 0;
        
        map<int,int> m;
        
        for(int i = 0; i < s.size(); i++){
            
            if(isdigit(s[i])){
                m[s[i]-'0']++;
            }
        }
        
        if(m.size() <= 1){
            return -1;
        }
        map<int,int> :: iterator it;
        
        int ans;
        int n = m.size();
        for(it = m.begin(); it != m.end(); it++){
            
            count++;
            if(count ==  n - 1){
                ans  = it->first;
                break;
            }
        }
        return ans;
    }
};
