class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        
        int l = 0, r = plants.size() - 1;
        
        int count = 0;
        
        int temp1 = capacityA, temp2 = capacityB;
        
        while(l < r){
            
            //cout << "Alice " << plants[l] << " " << temp1 << endl;
            if(plants[l] <= temp1){
                temp1 -= plants[l];
                l++;
            }
            else if(plants[l] > temp1){
                temp1 = capacityA;
                temp1 -= plants[l];
                l++;
                count++;
            }
            //cout << "Bob " << plants[r] << " " << temp2 << endl;
            if(plants[r] <= temp2){
                temp2 -= plants[r];
                r--;
            }
            else if(plants[r] > temp2){
                temp2 = capacityB;
                temp2 -= plants[r];
                r--;
                count++;
            }
        }
        if(l == r){
            if(plants[l] > temp1 && plants[r] > temp2){
                count++;
            }
        }
        return count;
    }
};
