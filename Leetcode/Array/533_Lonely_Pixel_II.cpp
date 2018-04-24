class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.empty() || picture[0].empty()) return 0;
        int m = picture.size(), n = picture[0].size(), res = 0, k = 0;
        vector<int> rowCnt(m, 0), colCnt(n, 0);
        vector<string> rows(m, "");
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rows[i].push_back(picture[i][j]);
                if (picture[i][j] == 'B') {
                    ++rowCnt[i];
                    ++colCnt[j];
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rowCnt[i] == N && colCnt[j] == N) {
                    for (k = 0; k < m; ++k) {
                        if (picture[k][j] == 'B') {
                            if (rows[i] != rows[k]) break;
                        }
                    }
                    if (k == m) {
                        res += colCnt[j];
                        colCnt[j] = 0;
                    }
                }
            }
        }
        return res;
    }
};