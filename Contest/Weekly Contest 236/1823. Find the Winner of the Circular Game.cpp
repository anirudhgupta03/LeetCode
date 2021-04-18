//Josephus Problem
class Solution {
public:
    int findTheWinner(int n, int k) {
        
        vector<int> vis(n,1);
        
        int start = 0, i, total = n;
        
        while(total != 1){
            
            int count = 0;
            i = start;
            
            while(1){
                
                if(vis[i % n] == 1){
                    count++;
                    if(count == k){
                        vis[i % n] = 0;
                        total--;
                        break;
                    }
                    i = (i + 1)%n;
                }
                else{
                    i = (i + 1)%n;
                }
            }
            start = (i + 1)%n;
            while(vis[start] != 1){
                start = (start+1)%n;
            }
        }
        int ind;
        for(int i = 0; i < n; i++){
            if(vis[i] == 1){
                ind = i + 1;
                break;
            }
        }
        return ind;
    }
};
