#include <bits/stdc++.h>
using namespace std;
int pref[1000007];
int n,t;
char s[1000007];
void kmp() {
    pref[0]=0;
    for(int i=1;i<n;i++) {
        pref[i]=pref[i-1];
        while(pref[i]>0 and s[i]!=s[pref[i]]) {
            pref[i]=pref[pref[i]-1];
        }
        if(s[i]==s[pref[i]]) pref[i]++;

    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin>>t;
    for(int d=0;d<t;d++) {
        cin>>n;
        string w,es;
        cin>>w>>es;
        for(int i=0;i<w.size();i++) {
            s[i]=w[i];
        }
        s[w.size()]='#';
        int id=w.size()+1;
        for(int i=0;i<es.size();i++) {
            s[id]=es[i];
            id++;
        }
        kmp();
        for(int i=w.size()+1;i<w.size()+1+es.size();i++) {
            if(pref[i]==n) {
                cout << i-w.size()+1 << endl;
            }
        }
    }
}
