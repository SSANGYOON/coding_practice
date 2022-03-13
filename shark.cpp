#include <iostream>

using namespace std;
int prefs[400][4];
int map[20][20];
int sur[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n*n;i++){
        int s;
        cin>>s;
        cin>>prefs[s][0]>>prefs[s][1]>>prefs[s][2]>>prefs[s][3];
        int maxp = -1;
        int mb = -1;
        int maxy = -1;
        int maxx = -1;
        for(int y =0; y<n; y++){
            for(int x=0; x<n; x++){
                if(map[y][x] > 0){
                    continue;
                }
                int blank = 0;
                int pref = 0;
                for(int j=0;j<4;j++){
                    int nx = x + sur[j][0];
                    int ny = y + sur[j][1];
                    if(nx <0 |nx >= n| ny < 0 |ny >=n){
                        continue;
                    }
                    if(map[ny][nx] == 0){
                        blank +=1;
                    }
                    else if(map[ny][nx] == prefs[s][0] | map[ny][nx] == prefs[s][1] | map[ny][nx] == prefs[s][2] | map[ny][nx] == prefs[s][3]){
                        pref +=1;
                    }
                }
                if(pref>maxp | pref == maxp & blank > mb){
                    maxp = pref;
                    mb = blank;
                    maxy = y;
                    maxx = x;
                }
            }   
        }
        map[maxy][maxx] = s;
    }
    int sum = 0;
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            int s = map[y][x];
            int score = 0;
            for(int j=0;j<4;j++){
                int nx = x + sur[j][0];
                int ny = y + sur[j][1];
                if(nx <0 |nx >= n| ny < 0 |ny >=n){
                    continue;
                }
                else if(map[ny][nx] == prefs[s][0] | map[ny][nx] == prefs[s][1] | map[ny][nx] == prefs[s][2] | map[ny][nx] == prefs[s][3]){
                    if(score == 0){
                        score +=1;
                    }
                    else{
                        score *= 10;
                    }
                }
            }
            sum += score;
        }
    }
    cout<<sum<<endl;
}