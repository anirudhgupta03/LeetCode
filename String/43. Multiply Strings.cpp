class Solution {
public:
    string multiply(string num1, string num2) {
        
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        int n1 = num1.size(), n2 = num2.size();
        
        vector<int> arr(n1+n2,0);
        
        for(int i = n1 - 1; i >= 0; i--){
            for(int j = n2 - 1; j >= 0; j--){
                
                int t = (num1[i] - '0')*(num2[j] - '0') + arr[i+j+1];
                
                arr[i+j+1] = t%10;
                arr[i+j] += t/10;
            }
        }
        
        int i = 0;
        while(arr[i] == 0){
            i++;
        }
        string res;
        while(i < n1 + n2){
            res.push_back(arr[i]+'0');
            i++;
        }
        return res;
    }
};
