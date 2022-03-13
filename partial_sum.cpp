#include <iostream>
using namespace std;


int ps[1025][1025];

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int n,m,num;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>num;
            ps[i+1][j+1] = ps[i][j+1] +ps[i+1][j] + num-ps[i][j];
        }
    }
    for(int i=0;i<m;i++){
        int x1,y1,x2,y2;
        cin>>y1>>x1>>y2>>x2;
        cin.clear();
        cout <<ps[y2][x2]-ps[y1-1][x2]-ps[y2][x1-1]+ps[y1-1][x1-1]<<'\n';
    }
}