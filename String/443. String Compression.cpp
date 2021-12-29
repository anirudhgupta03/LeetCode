class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n = chars.size();
        
        if(chars.size() == 1){
            return 1;
        }
        int ptr = 0;
        
        int i = 1;
        
        int count = 1;
        char ch = chars[0];
        
        bool flag = false;
        while(i < chars.size()){
            
            count = 1;
            char ch = chars[i-1];

            while(i < chars.size() && chars[i] == chars[i-1]){
                i++;
                count++;
            }
            
            if(i == chars.size()){
                flag = true;
            }
            if(count == 1){
                chars[ptr] = ch;
                ptr++;
            }
            else if(count < 10){
                chars[ptr] = ch;
                ptr++;
                chars[ptr] = count + '0';
                ptr++;
            }
            else{
                chars[ptr] = ch;
                ptr++;
                int temp = count;
                int n1 = 0;
                while(temp){
                    temp /= 10;
                    n1++;
                }
                int temp1 = pow(10,n1 - 1);
                while(temp1){
                    chars[ptr] = count/temp1 + '0';
                    count %= temp1;
                    temp1 /= 10;
                    ptr++;
                }
            }
            i++;
        }
        if(!flag){
            chars[ptr] = chars[n-1];
            ptr++;
        }
        return ptr;
    }
};
