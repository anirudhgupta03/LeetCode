class Solution {
public:
    int reinitializePermutation(int n) {
        
        int count = 0;
        
        vector<int> arr(n);
        
        vector<int> perm(n);
        
        for(int i = 0; i < n; i++){
            perm[i] = i;
            arr[i] = i;
        }
        while(1){
            
            vector<int> temp(n);
            
            for(int i = 0; i < n; i++){
                if(i % 2 == 0) temp[i] = perm[i/2];
                else temp[i] = perm[(n+i-1)/2];
            }
            count++;
                
            perm = temp;
            
            if(perm == arr){
                break;
            }
        }
        return count;
    }
};
