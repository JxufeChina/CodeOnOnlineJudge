#include<iostream>
#include<vector>
using namespace std;
int calc(const string &s, const string &t){
    if(s.size()<0||t.size()<0)
        return 0;
    int len1 = s.size()+1;
    int len2 = t.size()+1;
    vector<vector<int> > A(len1, vector<int>(len2, 0));
    for(int i=1;i<len1;++i)
        for(int j=1;j<len2;++j){
            if(s[i-1]==t[j-1])
                A[i][j] = A[i-1][j-1]+1;
            else
                A[i][j] = A[i-1][j]>A[i][j-1] ? A[i-1][j] : A[i][j-1];
        }
    return A[len1-1][len2-1];
}
int main(){
   string s,t;
   while(cin>>s>>t){
       cout<<calc(s,t)<<endl;

    }
    return 0;
}
