class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
         int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> heights(m, std::vector<int>(n, -1));
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] == 1) {
                    heights[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (const auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && heights[nx][ny] == -1) {
                    heights[nx][ny] = heights[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return heights;
    }
};
