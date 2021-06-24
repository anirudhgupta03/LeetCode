class Solution {
public:
    int numberOfRounds(string sT, string fT) {
        
        int sh;
        sh = stoi(sT.substr(0,2));
        int sm;
        sm = stoi(sT.substr(3,2));
        int eh;
        eh = stoi(fT.substr(0,2));
        int em;
        em = stoi(fT.substr(3,2));
        
        int count = 0;
        
        if(sh < eh){
            
            count += (60-sm)/15;
            sh++;
            
            while(sh != eh){
                count += 4;
                sh++;
            }
            
            count += (em)/15;
        }
        else if(sh == eh){
            
            if(sm < em){
                if(0 >= sm && 15 <= em){
                    count++;
                }
                if(15 >= sm && 30 <= em){
                    count++;
                }
                if(30 >= sm && 45 <= em){
                    count++;
                }
                if(45 >= sm && 60 <= em){
                    count++;
                }
            }
            else{
                
                count += (60-sm)/15;
                
                sh++;
                
                // if(sh == 24){
                //     sh = 1;
                // }
                count += (24 + eh - sh)*4;
                
                count += (em)/15;
            }
        }
        else{
            
            eh += 24;
            
            count += (60-sm)/15;
            
            sh++;
            
            while(sh != eh){
                count += 4;
                sh++;
            }
            
            count += (em)/15;
        }
        
        return count;
    }
};
