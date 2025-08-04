#include <bits/stdc++.h>
using namespace std;

struct Position {
    int x, y;
};

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {1, -1, 0, 0};

void markPath(vector<vector<char>> &maze, vector<vector<Position>> &parent, Position start, Position end) {
    Position curr = end;
    while (!(curr.x == start.x && curr.y == start.y)) {
        if (maze[curr.x][curr.y] != 'D')
            maze[curr.x][curr.y] = 'X';
        curr = parent[curr.x][curr.y];
    }
    maze[start.x][start.y] = 'R';
}

void solveMaze(vector<vector<char>> &maze, int rows, int cols) {
    Position start, exit;
    queue<Position> q;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<Position>> parent(rows, vector<Position>(cols, {-1, -1}));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (maze[i][j] == 'R') {
                start = {i, j};
                q.push(start);
                visited[i][j] = true;
            } else if (maze[i][j] == 'D') {
                exit = {i, j};
            }
        }
    }

    bool found = false;
    while (!q.empty() && !found) {
        Position curr = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny] && (maze[nx][ny] == '.' || maze[nx][ny] == 'D')) {
                visited[nx][ny] = true;
                parent[nx][ny] = curr;
                q.push({nx, ny});
                
                if (maze[nx][ny] == 'D') {
                    found = true;
                    markPath(maze, parent, start, {nx, ny});
                    break;
                }
            }
        }
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<char>> maze(rows, vector<char>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> maze[i][j];
        }
    }
    
    solveMaze(maze, rows, cols);
    
    for (const auto &row : maze) {
        for (char cell : row) {
            cout << cell;
        }
        cout << endl;
    }
    
    return 0;
}
