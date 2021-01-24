class Solution {
public:
    int minCharacters(string a, string b) {
        
        int count1[26]={0},count2[26]={0};
        int n = a.size(),m= b.size();
        
        for(int i =0 ; i < a.size(); i++){
            count1[a[i]-97]++;
        }
        
        for(int i = 0; i < b.size(); i++){
            count2[b[i]-97]++;
        }
        
        int ans = INT_MAX , op ;
        
        for(int i = 0; i < 25; i++){
            op = 0;
            for(int j = 0; j < a.size(); j++){
                if(a[j]>i+97){
                    op++;
                }
            }
            
            for(int j = 0; j<b.size();  j++){
                if(b[j]<=i+97){
                    op++;
                }
            }
            
            ans = min(ans,op);
        }
        cout << ans << endl;
        for(int i = 0; i < 25; i++){
            op = 0;
            for(int j = 0; j < a.size(); j++){
                if(a[j]<=i+97){
                    op++;
                }
            }
            
            for(int j = 0; j<b.size();  j++){
                if(b[j]>i+97){
                    op++;
                }
            }
            
            ans = min(ans,op);
        }
        cout << ans << endl;
        for(int i = 0; i < 26; i++){
            ans = min(ans,n-count1[i]+m-count2[i]);
        }
        
        return ans;
    }
};
