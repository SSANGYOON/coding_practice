#include <iostream>
#include <queue>
using namespace std;
int ans[12];

int main(){
    ans[0]= 1;
    int t;
    cin>>t;
    for(int i=1;i<11;i++){
        ans[i]=ans[i-1];
        if(i>=2){
            ans[i]+=ans[i-2];
        }
        if(i>=3){
            ans[i]+=ans[i-3];
        }
    }
    for(int i=0;i<t;i++){
        int c;
        cin>>c;
        cout<<ans[c]<<endl;
    }
}
