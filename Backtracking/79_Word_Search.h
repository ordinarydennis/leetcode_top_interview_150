class Solution {

    void dfs(int x, int y, vector<vector<char>>& board, int index, string& w, vector<vector<bool>>& visit)
    {
        if (ret)
            return;

        if (w.size() <= index)
        {
            ret = true;
            return;
        }

        if (maxX <= x || x < 0 || 
            maxY <= y || y < 0)
            return;

        if (board[y][x] != w[index])
            return;

        if (visit[y][x])
            return;


        visit[y][x] = true;

        dfs(x + 1, y, board, index + 1, w, visit);
        dfs(x, y + 1, board, index + 1, w, visit);
        dfs(x - 1, y, board, index + 1, w, visit);
        dfs(x, y - 1, board, index + 1, w, visit);

        visit[y][x] = false;

    }

    int maxX = 0;
    int maxY = 0;

    bool ret = false;

public:
    bool exist(vector<vector<char>>& board, string word) {

        maxX = board[0].size();
        maxY = board.size();

        vector<vector<bool>> visit(maxY, vector<bool>(maxX));

        for (int y = 0; y < maxY; y++)
        {
            for (int x = 0; x < maxX; x++)
            {
                dfs(x, y, board, 0, word, visit);

                if (ret)
                {
                    return ret;
                }
            }
        }

        return false;
    }
};
