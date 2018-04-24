class Solution {
public:
  int slidingPuzzle(vector<vector<int>>& board) {    
    const string goal = "123450";
    string start;
    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board[0].size(); ++j)
        start += (board[i][j] + '0');
    
    if (start == goal) return 0;
    
    const vector<vector<int>> idx{{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
    
    set<string> visited{start};
    int steps = 0;
    queue<pair<string, int>> q;
    q.emplace(start, start.find('0'));
    while (!q.empty()) {
      ++steps;
      int size = q.size();
      while (size-- > 0) {
        const auto& p = q.front();
        q.pop();
        for (int index : idx[p.second]) { 
          string t(p.first);
          swap(t[p.second], t[index]);
          if (visited.count(t)) continue;            
          if (t == goal) return steps;
          visited.insert(t);
          q.emplace(t, index);
        }
      }      
    }
    return -1;
  }
};