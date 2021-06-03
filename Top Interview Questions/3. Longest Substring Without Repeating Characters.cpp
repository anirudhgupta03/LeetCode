//Method - 1
//Time Complexity - O(N)
//Space Complexity - O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> myumap;
        
        int l = 0, r = 0;
        
        int ans = 0;
        
        while(r < s.size()){
            
            if(myumap.find(s[r]) == myumap.end()){
                myumap[s[r]] = r;
            }
            else if(myumap[s[r]] >= l){
                ans = max(ans,r-l);
                l = myumap[s[r]] + 1;
                myumap[s[r]] = r;
            }
            else if(myumap[s[r]] < l){
                myumap[s[r]] = r;
            }
            r++;
        }
        ans = max(ans,r-l);
        return ans;
    }
};

//Method - 2
//Time Complexity: O(N)
//Space Complexity: O(min of a,b) for the unordered set. a, is the upper bound of the space complexity.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> myuset;
        
        int l = 0, r = 0;
        
        int ans = 0;
        
        while(r < s.size()){
            
            if(myuset.find(s[r]) == myuset.end()){
                myuset.insert(s[r]);
                r++;
            }
            else{
                ans = max(ans,r-l);
                myuset.erase(s[l]);
                l++;
            }
        }
        ans = max(ans,r-l);
        return ans;
    }
};
