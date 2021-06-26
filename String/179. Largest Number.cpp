class Solution {
public:
    bool static cmp(int n1, int n2){
        
        string s1 = to_string(n1);
        string s2 = to_string(n2);
        
        if(s1 + s2 > s2 + s1){
            return true;
        }
        return false;
    }
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(),cmp);
        
        string res;
        
        for(int i = 0; i < nums.size(); i++){
            res += to_string(nums[i]);
        }
        
        int i = 0;
        
        while(i < res.size() - 1){
            if(res[i] == '0'){
                i++;
            }
            else{
                break;
            }
        }
        return res.substr(i);
    }
};
