#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;
int field[100][100];
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,-1,-1,-1,0,1,1,1};
int diry[] ={1,1,-1,-1};
int dirx[] ={1,-1,-1,1};
void seek(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<field[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>field[i][j];
        }
    }
    //cout <<endl;
    //seek(n);
    vector<pair<int,int>> cloud = {make_pair(0,n-1),make_pair(1,n-1),make_pair(0,n-2),make_pair(1,n-2)};
    set<pair<int,int>> inc;
    for(int i=0;i<m;i++){
        int d,a;
        cin>>d>>a;
        while(!cloud.empty()){
            auto c = cloud.back();
            cloud.pop_back();
            int x = ((c.first + dx[d-1]*a) % n + n) % n;
            int y = ((c.second + dy[d-1]*a) % n + n) % n;
            field[y][x] += 1;
            inc.insert(make_pair(x,y));
        }
        //seek(n);
        for(auto c:inc){
            int x = c.first;
            int y = c.second;
            for(int j=0;j<4;j++){
                int dx = x+dirx[j];
                int dy = y+diry[j];
                if(dx<n & dx >= 0 & dy<n & dy >= 0){
                    if(field[dy][dx]){
                        field[y][x] += 1;
                    }
                }
            }
        }
       //seek(n);
        set<pair<int,int>> new_cloud;
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                if(field[y][x] > 1){
                    if(inc.find(pair<int,int>(x,y))==inc.end()){
                        field[y][x] -=2;
                        cloud.push_back(make_pair(x,y));
                        //cout << x <<' '<<y<<endl;
                    }
                }
            }
        }
        //seek(n);
        inc.clear();
    }
    int s = 0;
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            s +=field[y][x];
        }
    }
    cout<<s;
}