#include <iostream>
#include <queue>
using namespace std;
int map[100][100][100];
int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};

int main(){
    int w,l,h;
    cin>>w>>l>>h;
    cin.clear();
    queue<pair<int,pair<int,int>>> q;
    for(int k = 0; k < h; k++){
        for(int j = 0;j < l;j++){
            for(int i = 0;i < w;i++){
                cin >> map[k][j][i];
                if(map[k][j][i]==1){
                    q.push(make_pair(i,make_pair(j,k)));
                }
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second.first;
        int z = q.front().second.second;
        q.pop();
        for(int i=0;i<6;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            int nz = z+dz[i];
            if(nx >= 0 & nx < w & ny >= 0 & ny < l & nz >= 0 & nz < h){
                if(map[nz][ny][nx] == 0){
                    map[nz][ny][nx] = map[z][y][x] + 1;
                    q.push(make_pair(nx,make_pair(ny,nz)));
                }
            }
        }
    }
    int m = 0;
    for(int k = 0; k < h; k++){
        for(int j = 0;j < l;j++){
            for(int i = 0;i < w;i++){
                if(map[k][j][i]==0){
                    cout <<-1;
                    return 0;
                }
                m = max(m,map[k][j][i]-1);
            }
        }
    }
    cout<<m;
    return 0;
}
