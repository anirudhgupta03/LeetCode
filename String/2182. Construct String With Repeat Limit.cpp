class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
        vector<int> alpha(26);
        
        for(int i = 0; i < s.size(); i++){
            alpha[s[i] - 'a']++;
        }
        
        string res;
        char pre = '#';
        int precount = 0;
        
        while(1){
            bool flag = false;
            for(int i = 25; i >= 0; i--){
                if(alpha[i]){
                    if(pre != (i + 'a')){
                        res.push_back(i + 'a');
                        alpha[i]--;
                        precount = 1;
                        flag = true;
                        pre = i + 'a';
                        break;
                    }
                    else if(pre == (i + 'a')){
                        if(precount < repeatLimit){
                            res.push_back(i + 'a');
                            alpha[i]--;
                            precount++;
                            flag = true;
                            pre = i + 'a';
                            break;
                        }
                    }
                }
            }
            if(!flag){
                break;
            }
        }
        return res;
    }
};
