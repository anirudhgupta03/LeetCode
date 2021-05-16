class Solution {
public:
    vector<int> memLeak(int m1, int m2) {
        
        int time = 1;
        
        while(1){
            
            if(m1 >= m2){
                
                if(time <= m1){
                    m1 -= time;
                }
                else{
                    break;
                }
            }
            else{
                
                if(time <= m2){
                    m2 -= time;
                }
                else{
                    break;
                }
            }
            time++;
        }
        
        vector<int> res;
        
        res.push_back(time);
        res.push_back(m1);
        res.push_back(m2);
        return res;
    }
};
