class Solution {
public:
    int maxDepth(string s) {
       int n= s.length();
       int c1 = 0 , maxi =0;
       for(int i=0;i<n;i++){
         if(s[i]=='('){
            c1++;
            maxi=max(maxi,c1);
         }
         if(s[i]==')'){
            c1--;
             maxi=max(maxi,c1);
         }
       }
       return maxi;
    }
};