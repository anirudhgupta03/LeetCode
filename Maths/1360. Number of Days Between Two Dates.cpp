class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        
        vector<int> month(13);
        
        month[1] = month[3] = month[5] = month[7] = month[8] = month[10] = month[12] = 31;
        month[4] = month[6] = month[9] = month[11] = 30;

        if(date1 > date2){
            swap(date1,date2);
        }
        
        int d1,m1,y1,d2,m2,y2;
        
        y1 = stoi(date1.substr(0,4));
        m1 = stoi(date1.substr(5,2));
        d1 = stoi(date1.substr(8,2));
        
        y2 = stoi(date2.substr(0,4));
        m2 = stoi(date2.substr(5,2));
        d2 = stoi(date2.substr(8,2));
        
        if((d1 == d2) && (m1 == m2) && (y1 == y2)){
            return 0;
        }
        
        int count = 0;
        bool flag = false;
      
        while(1){
            
            bool leap = false;
            if(y1 % 100 == 0 && y1 % 400 == 0 || y1 % 100 != 0 && y1 % 4 == 0){
                leap = true;
            }
            int last;
            if(leap && m1 == 2){
                last = 29;
            }
            else if(m1 == 2){
                last = 28;
            }
            else{
                last = month[m1];
            }
          
            for(int i = d1 + 1; i <= last; i++){
                count++;
                if(i == d2 && m1 == m2 && y1 == y2){
                    flag = true;
                    break;
                }
            }          
            m1++;
            d1 = 0;
            if(m1 == 13){
                m1 = 1;
                y1++;
            }
            if(flag){
                break;
            }
        }
        return count;
    }
};
