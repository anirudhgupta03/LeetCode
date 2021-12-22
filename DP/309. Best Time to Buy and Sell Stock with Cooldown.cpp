//Ref: https://www.youtube.com/watch?v=GY0O57llkKQ&t=13s
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        
        int obsp = -arr[0];
        int ossp = 0;
        int ocsp = 0;
        
        for(int i = 1; i < arr.size(); i++){
            
            int nbsp = 0;
            int nssp = 0;
            int ncsp = 0;
            
            if(ocsp - arr[i] > obsp){
                nbsp = ocsp - arr[i];
            }
            else{
                nbsp = obsp;
            }
            
            if(obsp + arr[i] > ossp){
                nssp = obsp + arr[i];
            }
            else{
                nssp = ossp;
            }
            
            if(ossp > ocsp){
                ncsp = ossp;
            }
            else{
                ncsp = ocsp;
            }
            
            obsp = nbsp;
            ossp = nssp;
            ocsp = ncsp;
        }
        return ossp;
    }
};
