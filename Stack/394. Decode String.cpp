class Solution {
public:
    string decodeString(string s) {
        
        stack<int> num;
        stack<string> str;
        
        string res;
        int n = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] >= '0' && s[i] <= '9'){
                n = 10*n + s[i] - '0'; 
            }
            else if(s[i] == '['){
                str.push(res);
                res.clear();
                
                num.push(n);
                n = 0;
            }
            else if(s[i] == ']'){
                string temp = res;
                res = str.top();
                str.pop();
                
                int count = num.top();
                num.pop();
                
                while(count){
                    res += temp;
                    count--;
                }
            }
            else{
                res.push_back(s[i]);
            }
        }
        
        return res;
    }
};
