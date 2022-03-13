#include <iostream>
#include <queue>
using namespace std;

bool vi[200][200];
int path[200][200];
int dx[] = {-1,1,-2,2,-1,1};
int dy[] = {-2,-2,0,0,2,2};

int main(){
    int n;
    cin >>n;
    int r1, c1, r2, c2;
    cin>>r1>>c1>>r2>>c2;
    vi[r1][c1]= true;
    queue<pair<int,int>> q;
    q.push(make_pair(r1,c1));
    int dis = -1;
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if(r==r2 && c == c2){
            dis = path[r][c];
            break;
        } 
        for(int i =0;i<6;i++){
            int rp = r+dy[i];
            int cp = c+dx[i];
            if(rp >= 0 && rp <n && cp >= 0 && cp <n && !vi[rp][cp]){
                vi[rp][cp]=true;
                q.push(make_pair(rp,cp));
                path[rp][cp]=path[r][c]+1;
            }
        }
    }
    cout<<dis<<endl;
}