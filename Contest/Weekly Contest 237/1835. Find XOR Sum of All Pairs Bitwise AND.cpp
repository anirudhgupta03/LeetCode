/*
We can break down the final list into smaller lists for each pair that includes arr1[i]. 
So we'd have arr1.length lists which are of the form [arr1[i] & arr2[0], arr1[i] & arr2[1], ..., arr1[i] & arr2[arr2.length -1]] for each i, where 0 <= i < arr1.length.

Consider the xor sum of one of these arrays:
(arr1[i] & arr2[0]) ^ (arr1[i] & arr2[1]) ^ ... ^ (arr1[i] & arr2[arr2.length - 1])

For each bit in this xor sum there are two cases:
arr1[i] at that bit is 0 => in this case all &'s will result in 0 at that bit so the xor sum will be 0 at that bit.
arr1[i] at that bit is 1 => then the &'s will result in the bit at that location of the other value (eg. arr2[j]) 
so the bit will be set to arr2[0] ^ arr2[1] ^ ... ^ arr2[arr2.length - 1] at that bit.

Therefore, the xor sum of one of these arrays is just arr1[i] & (arr2[0] ^ arr2[1] ^ ... ^ arr2[arr2.length - 1]) and arr2[0] ^ arr2[1] ^ ... ^ arr2[arr2.length - 1] 
is just the xor sum of arr2. So the final xor sum is the xor sum of arr1[i] & xor_sum(arr2) for all i.
*/
class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        
        int t = arr2[0];
        
        for(int i = 1; i < arr2.size(); i++){
            t = t^arr2[i];
        }
        
        int ans = 0;
        for(int i = 0; i < arr1.size(); i++){
            ans = ans^(arr1[i]&(t));
        }
        
        return ans;
    }
};
