class Solution {
public:
    int calcsec(int t1, int t2, int t3, int t4){
        
        int t = 0;
        
        int temp1 = 10*t1 + t2;
        int temp2 = 10*t3 + t4;
        return 60*temp1 + temp2;
    }
    int minCostSetTime(int start, int move, int push, int target) {
        
        int minCost = INT_MAX;
        
        for(int i = 0; i <= 9; i++){
            for(int j = 0; j <= 9; j++){
                for(int k = 0; k <= 9; k++){
                    for(int l = 0; l <= 9; l++){
                        int temp = calcsec(i, j, k, l);
                        int t1 = i, t2 = j, t3 = k, t4 = l;
                        
                        if(temp == target){
                            cout << t1 << t2 << ":" << t3 << t4 << endl;
                            int cost = 0, curr = start;
                            
                            if(t1 != 0){
                                if(t1 == curr) cost += push;
                                else{
                                    cost += push + move;
                                    curr = t1;
                                }
                                if(t2 == curr) cost += push;
                                else{
                                    curr = t2;
                                    cost += push + move;
                                }  
                                if(t3 == curr) cost += push;
                                else{
                                    cost += push + move;
                                    curr = t3;
                                }
                                if(t4 == curr) cost += push;
                                else{
                                    curr = t4;
                                    cost += push + move;
                                }
                            } 
                            else{
                                if(t2 != 0){
                                    if(t2 == curr) cost += push;
                                    else{
                                        curr = t2;
                                        cost += push + move;
                                    }
                                    if(t3 == curr) cost += push;
                                    else{
                                        cost += push + move;
                                        curr = t3;
                                    }
                                    if(t4 == curr) cost += push;
                                    else{
                                        curr = t4;
                                        cost += push + move;
                                    }
                                }
                                else{
                                    if(t3 != 0){
                                        if(t3 == curr) cost += push;
                                        else{
                                            cost += push + move;
                                            curr = t3;
                                        }

                                        if(t4 == curr) cost += push;
                                        else{
                                            curr = t4;
                                            cost += push + move;
                                        }
                                    }
                                    else{
                                        if(t4 != 0){
                                            if(t4 == curr) cost += push;
                                            else{
                                                curr = t4;
                                                cost += push + move;
                                            }
                                        }
                                    }
                                }
                            }
                            cout << cost << endl;
                            minCost = min(minCost, cost);
                        }
                    }
                }
            }
        }
        return minCost;
    }
};
