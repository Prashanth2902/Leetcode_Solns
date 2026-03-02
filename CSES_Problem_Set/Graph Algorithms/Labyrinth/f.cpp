#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string directions = "";

bool f(vector<vector<char>>& grid, pair<int, int> startNode, pair<int, int> endNode) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<char>> path(rows, vector<char>(cols, '.'));

    vector<int> rowDir = {1, -1, 0, 0};
    vector<int> colDir = {0, 0, 1, -1};
    vector<char> steps = {'D', 'U', 'R', 'L'};
    path[startNode.first][startNode.second] = 'S';

    queue<pair<int, int>> q;
    q.push({startNode.first, startNode.second});

    while(!q.empty()) {
        auto [r,c] = q.front();
        q.pop();
        if(r == endNode.first && c == endNode.second) {
            int currR = endNode.first;
            int currC = endNode.second;
            while(grid[currR][currC] != 'A') {
                char d = path[currR][currC];
                directions += d;
                if(d == 'D') currR--;
                else if(d == 'U') currR++;
                else if(d == 'L') currC++;
                else if(d == 'R') currC--;
            }
            reverse(directions.begin(), directions.end());
            return true;
        }
        for(int i=0;i<4;i++) {
            int nr = r + rowDir[i];
            int nc = c + colDir[i];
            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] != '#' && path[nr][nc] == '.') {
                path[nr][nc] = steps[i];
                q.push({nr, nc});
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<char>> grid(rows, vector<char>(cols));
    pair<int, int> startNode, endNode;
    for(int r=0;r<rows;r++) {
        for(int c=0;c<cols;c++) {
            char x;
            cin >> x;
            if(x == 'A') {
                startNode = {r,c};
            } else if (x == 'B') {
                endNode = {r,c};
            }
            grid[r][c] = x;
        }
    }
    
    if(f(grid, startNode, endNode)) {
        cout << "YES" << endl;
        cout << directions.size() << endl;
        cout << directions << endl;
    } else {
        cout << "NO" << endl;
    }

}