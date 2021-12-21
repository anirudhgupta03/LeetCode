//Brute Force
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        int k = 1;
        
        string temp = a;
        
        while(temp.size() < b.size()){
            k++;
            temp += a;
        }
        
        int p1 = 0, p2 = 0;
        cout << temp << endl;
        while(p1 <= temp.size() - b.size()){
            
            
            if(temp[p1] == b[p2]){
                //bool flag = true;
                int ind = p1;
                while(p1 < temp.size() && p2 < b.size()){
                    if(temp[p1] != b[p2]){
                        break;
                    }
                    p1++;
                    p2++;
                }
                if(p2 == b.size()){
                    return k;
                }
                else{
                    p1 = ind + 1;
                    p2 = 0;
                }
            }
            else{
                p1++;
            }
        }
        
        //cout << temp << endl;
        
        temp += a;
        k++;
        
        p1 = 0, p2 = 0;
        
        while(p1 <= temp.size() - b.size()){
            
            if(temp[p1] == b[p2]){
                //bool flag = true;
                int ind = p1;
                while(p1 < temp.size() && p2 < b.size()){
                    if(temp[p1] != b[p2]){
                        //flag = false;
                        break;
                    }
                    p1++;
                    p2++;
                }
                if(p2 == b.size()){
                    return k;
                }
                else{
                    p1 = ind + 1;
                    p2 = 0;
                }
            }
            else{
                p1++;
            }
        }
        return -1;
    }
};

//Using KMP Algorithm
//Ref: https://www.youtube.com/watch?v=V5-7GzOfADQ
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        string temp = a;
        
        int k = 1;
        
        while(temp.size() < b.size()){
            temp += a;
            k++;
        }
        
        int n = b.size();
        
        int lps[n];
        
        int j = 0, i = 1;
        
        lps[0] = 0;
        
        while(i < n){
            if(b[i] == b[j]){
                j++;
                lps[i] = j;
                i++;
            }
            else{
                if(j == 0){
                    lps[i] = 0;
                    i++;
                }
                else{
                    j = lps[j-1];
                }
            }
        }
        
        i = 0, j = 0;
        
        while(i < temp.size()){
            
            if(temp[i] == b[j]){
                i++;
                j++;
            }
            
            if(j == n){
                return k;
            }
            
            else if(i < temp.size() && temp[i] != b[j]){
                if(j == 0){
                    i++;
                }
                else{
                    j = lps[j-1];
                }
            }
        }
        
        temp += a;
        k++;
        
        i = 0;
        j = 0;
        
        while(i < temp.size()){
            
            if(temp[i] == b[j]){
                i++;
                j++;
            }
            
            if(j == n){
                return k;
            }
            
            else if(i < temp.size() && temp[i] != b[j]){
                if(j == 0){
                    i++;
                }
                else{
                    j = lps[j-1];
                }
            }
        }
        
        return -1;
    }
};
