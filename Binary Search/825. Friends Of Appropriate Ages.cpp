//Method - 1
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        
        sort(ages.begin(), ages.end(), greater<int>());
        
        int count = 0;
        
        for(int i = 0; i < ages.size(); i++){
            
            int lo = i + 1, hi = ages.size() - 1, ans = i;
            
            while(lo <= hi){
                
                int mid = (lo + hi)/2;
                
                if(0.5*ages[i] + 7 < ages[mid]){
                    ans = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            
            count += ans - i;
        }
        
        sort(ages.begin(), ages.end());
        
        for(int i = 0; i< ages.size(); i++){
            
            int lo = i + 1, hi = ages.size() - 1, ans = i;
            
            while(lo <= hi){
                
                int mid = (lo + hi)/2;
                
                if(ages[mid] > ages[i]){
                    hi = mid - 1;
                }
                else{
                    ans = mid;
                    lo = mid + 1;
                }
            }
            if(0.5*ages[i] + 7 < ages[ans]){
                count += ans - i;
            }
        }
        return count;
    }
};

//Method - 2
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        
        sort(ages.begin(), ages.end());
        
        int count = 0;
        
        for(int i = ages.size() - 1; i >= 1; i--){
            
            int lo = 0, hi = i - 1;
            int ans = i;
            
            while(lo <= hi){
                int mid = (lo + hi)/2;
                
                if(ages[mid] > ages[i]/2 + 7){
                    ans = mid;
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }
            count += i - ans;
        }
        
        for(int i = 0; i < ages.size() - 1; i++){
            
            int lo = i + 1, hi = ages.size() - 1;
            int ans = i;
            
            while(lo <= hi){
                int mid = (lo + hi)/2;
                
                if(ages[mid] == ages[i] && ages[mid] > ages[i]/2 + 7){
                    ans = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            count += ans - i;
        }
        
        return count;
    }
};
