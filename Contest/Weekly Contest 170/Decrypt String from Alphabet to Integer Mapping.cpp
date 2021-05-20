class Solution {
public:
    string freqAlphabets(string s) {
        
        int l = 0;
        string ans;
        
        while(l < s.size()){
            
            char t1 = s[l];
            
            string t2;
            bool flag = false;
            if(l + 2 < s.size()){
                t2 = s.substr(l,3);
                flag = true;
            }
            
            if(flag == true && t2[2] == '#'){
                int g = 0;
                for(int k = 0; k < 2; k++){
                    g = 10*g + t2[k] - 48;
                }
                ans +=  g-1 + 'a';
                l = l + 3;
            }
            else{
                ans += t1 - 49 + 'a';
                l++;
            }
        }
        return ans;
    }
};
