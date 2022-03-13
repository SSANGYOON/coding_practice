#include <iostream>
using namespace std;
bool arr[1000001];
int main(){
    for(int i=2;i<1000001;i++){
        arr[i] = 1;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                arr[i]=0;
                break;
            }
        }
    }
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    while(true){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        for(int i=2;i<n/2+1;i++){
            if(arr[n-i]&&arr[i]){
                cout<<n<<" = "<<i<<" + "<<n-i<<'\n';
                break;
            }
        }
    }
}