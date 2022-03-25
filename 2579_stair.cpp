#include <iostream>
#include <queue>
using namespace std;
int ans[301];

int main(){
    int n;
    cin>>n;
    int prev = 0;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        ans[i+1] = max(ans[i],t);
        if(i>0){
            ans[i+1] = max(ans[i],ans[i-2]+t);
        }
        else if(i>1){
            ans[i+1] = max(ans[i],ans[i-3]+t+prev);
        }
        prev = t;
    }
    cout<<ans[n]<<endl;
}
