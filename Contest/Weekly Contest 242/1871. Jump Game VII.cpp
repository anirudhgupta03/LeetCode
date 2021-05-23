//Ref: https://www.youtube.com/watch?v=v1HpZUnQ4Yo&t=541s
class Solution {
public:
    
    bool canReach(string s, int minJump, int maxJump) {
        
        int n = s.size();
        
        if(s[n-1] == '1'){
            return false;
        }
        queue<int> q;
        q.push(0);
        
        int farthest = 0;
        
        while(!q.empty()){
            
            int curr = q.front();
            q.pop();
            
            if(s[curr] == '0'){
                
                int start = max(curr + minJump,farthest+1);   //To avoid the repeating indices we are taking maximum of the farthest index visited and new start
                int end = min(curr + maxJump,n-1);
              
                for(int j = start; j <= end; j++){
                        farthest = j;
                        q.push(j);
                }
            }
        }
        
        if(farthest == n - 1){
            return true;
        }
        return false;
    }
};
