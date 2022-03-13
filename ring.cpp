#include <iostream>
using namespace std;
int map[100][100];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    for(int r=0;r<n;r++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(map[i][j]){
                    for(int k=0;k<n;k++){
                        if(map[i][k]||map[j][k]){
                            map[i][k] = 1;
                        }
                    }
                }
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<endl;
    }
}