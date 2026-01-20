class Solution {
public:
    string findNthBin(string s1,int n){
        if(n==1){
            return s1;
        }
        string x="";
        for(char ch:s1){
            if(ch=='0') x+="1";
            else x+="0";
        }
        string y="";
        for(int i=x.size()-1;i>=0;i--){
            y+=x[i];
        }
        string s=s1+"1"+y;
        return findNthBin(s,n-1);
    }
    char findKthBit(int n, int k) {
        string s=findNthBin("0",n);

        return s[k-1];

    }
};