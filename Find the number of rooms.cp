#include <iostream>
#include <vector>

using namespace std;

// Function to check if a cell is within the map boundaries
bool isValid(int row, int col, int rows, int cols) {
  return (row >= 0) && (row < rows) && (col >= 0) && (col < cols);
}

// Depth-First Search (DFS) to explore a room
void dfs(vector<vector<char>>& map, int row, int col, int rows, int cols, vector<vector<bool>>& visited) {
  visited[row][col] = true;

  // Explore all four directions (up, down, left, right)
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};

  for (int i = 0; i < 4; ++i) {
    int newRow = row + dx[i];
    int newCol = col + dy[i];

    // Check if the new cell is valid, unvisited floor square
    if (isValid(newRow, newCol, rows, cols) && !visited[newRow][newCol] && map[newRow][newCol] == '.') {
      dfs(map, newRow, newCol, rows, cols, visited);
    }
  }
}

int countRooms(vector<vector<char>>& map) {
  int rows = map.size();
  int cols = map[0].size();

  // Keep track of visited squares to avoid revisiting the same room
  vector<vector<bool>> visited(rows, vector<bool>(cols, false));

  int roomCount = 0;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      // If the current cell is an unvisited floor square, start exploring a new room
      if (!visited[i][j] && map[i][j] == '.') {
        dfs(map, i, j, rows, cols, visited);
        roomCount++;
      }
    }
  }

  return roomCount;
}

int main() {
  int rows, cols;
  cin >> rows >> cols;

  vector<vector<char>> map(rows, vector<char>(cols));
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cin >> map[i][j];
    }
  }

  int roomCount = countRooms(map);
  cout << roomCount << endl;

  return 0;
}
