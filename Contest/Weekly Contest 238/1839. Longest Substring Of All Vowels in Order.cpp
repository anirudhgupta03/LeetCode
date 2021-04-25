class Solution {
public:
    int longestBeautifulSubstring(string word) {
        
        int count[5] = {0};
        
        int ans = INT_MIN;
        
        int p = 0;
        
        while(p < word.size()){
            
            bool flag = true;
            
            if(word[p] == 'a'){
                
                if(!(count[1] > 0|| count[2] > 0|| count[3] > 0 || count[4] > 0)){
                    p++;
                    count[0]++;
                }
                else flag = false;
            }
            else if(word[p] == 'e'){
                
                if(!(count[2] > 0|| count[3] > 0 || count[4] > 0)){
                    p++;
                    count[1]++;
                }
                else flag = false;
            }
            else if(word[p] == 'i'){
                
                if(!(count[3] > 0 || count[4] > 0)){
                    p++;
                    count[2]++;
                }
                else flag = false;
            }
            else if(word[p] == 'o'){
                
                if(!(count[4] > 0)){
                    p++;
                    count[3]++;
                }
                else flag = false;
            }
            else if(word[p] == 'u'){
                count[4]++;
                p++;
            }
            bool isValid = true;
            int len = 0;
            
            if(flag == false){
                //cout << p << endl;
                for(int i = 0; i < 5; i++){
                    if(count[i] == 0){
                        isValid = false;
                        //break;
                    }
                    len += count[i];
                    count[i] = 0;
                }
            }
            
            if(isValid) ans = max(ans, len);
        }
        int len = 0;
        bool isValid = true;
        for(int i = 0; i < 5; i++){
                    if(count[i] == 0){
                        isValid = false;
                        //break;
                    }
                    len += count[i];
                    count[i] = 0;
        }
        if(isValid) ans = max(ans, len);
        return ans;
    }
};
