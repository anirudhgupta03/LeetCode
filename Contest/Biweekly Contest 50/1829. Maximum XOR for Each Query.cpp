class Solution {
public:
    int todecimal(string s){
        
        int n = s.size() -1;
        
        int ans = 0;
        
        for(int i = 0;  i < s.size(); i++){
            
            ans += pow(2,n)*(s[i]-48);
            n--;
        }
        return ans;
    }
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        int totalxor = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            totalxor = totalxor ^ nums[i];
        }
        int n = nums.size();
        int j = n - 1;
        
        string temp;
        for(int i = 0; i < maximumBit; i++){
            temp.push_back('0');
        }
        
        vector<int> res;
        for(int i = 1; i <= n; i++){
            
            string s = temp;
            int x = totalxor;
         
            int k = s.size() - 1;
            
            while(k >= 0){
                if(x & 1){
                    s[k] ='0';
                    x /= 2;
                    k--;
                }
                else{
                    s[k] = '1';
                    x /= 2;
                    k--;
                }
            }

            totalxor = totalxor ^ nums[j];
            j--;
            
            int ans = todecimal(s);
            res.push_back(ans);
        }
        return res;
    }
};
