//Ref: https://www.youtube.com/watch?v=WTo5dh6pIis&t=151s
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        
        bool flag = false;
        
        if(x > y) flag = true;
        
        int ans = 0;
        
        vector<int> v1,v2; 
        
        for(int i = 0; i < s.size(); i++){
            if(v1.size()){
                if(flag){
                    if(v1.back() == 'a' && s[i] == 'b'){
                        ans += x;
                        v1.pop_back();
                    }
                    else{
                        v1.push_back(s[i]);
                    }
                }
                else{
                    if(v1.back() == 'b' && s[i] == 'a'){
                        ans += y;
                        v1.pop_back();
                    }
                    else{
                        v1.push_back(s[i]);
                    }
                }
            }
            else{
                v1.push_back(s[i]);
            }
        }
        
        
        for(int i = 0; i < v1.size(); i++){
            if(v2.size()){
                if(!flag){
                    if(v2.back() == 'a' && v1[i] == 'b'){
                        ans += x;
                        v2.pop_back();
                    }
                    else{
                        v2.push_back(v1[i]);
                    }
                }
                else{
                    if(v2.back() == 'b' && v1[i] == 'a'){
                        ans += y;
                        v2.pop_back();
                    }
                    else{
                        v2.push_back(v1[i]);
                    }
                }
            }
            else{
                v2.push_back(v1[i]);
            }
        }
        return ans;
    }
};
