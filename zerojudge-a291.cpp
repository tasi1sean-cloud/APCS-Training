#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<char> s(4,0);
    vector<char> s1(4,0);
    while (cin >> s[0]){
        for(int i=1;i<4;i++){
            cin >> s[i];
        }
        int n;
        cin >> n;
        while(n--){
            int a=0,b=0;
            vector<char> s2=s;
            for(int i=0;i<4;i++){
                cin >> s1[i];
            }
            for(int i=0;i<4;i++){
                if(s1[i]==s2[i]){
                    a++;
                    s2[i]=-1;
                }
            }
            for(int i=0;i<4;i++){
                if(s1[i]==s[i]){
                    continue;
                }
                if(find(s2.begin(),s2.end(),s1[i])!=s2.end()){
                    int index = find(s2.begin(),s2.end(),s1[i]) - s2.begin();
                    b++;
                    s2[index]=-1;
                }
            }
            cout << a << "A" << b << "B" << endl;
        }
    }
    return 0;
}