class Solution {
public:
    typedef pair<int,int> p;
    const int mod=1000000007;

    p dp[101][101];
    int toInt(char ch) {
        return ch - '0';
    }
    p solve(int i, int j,vector<string>&board,int &size) {

        if (i==size-1 && j==size-1)
            return dp[i][j]={0,1};

        if (dp[i][j].second != -1)
            return dp[i][j];

        p down = {INT_MIN, 0};
        p right = {INT_MIN, 0};
        p diag = {INT_MIN, 0};

        if (i + 1 < size && board[i + 1][j] != 'X')
            down = solve(i + 1, j, board, size);

        if (j + 1 < size && board[i][j + 1] != 'X')
            right = solve(i, j + 1, board, size);

        if (i + 1 < size && j + 1 < size && board[i + 1][j + 1] != 'X')
            diag = solve(i + 1, j + 1, board, size);

        int maxi = max({down.first, right.first, diag.first});

        if (maxi == INT_MIN)
            return dp[i][j] = {INT_MIN, 0};

        int totalPath = 0;

        if (down.first == maxi)
            totalPath = (totalPath + down.second) % mod;
        if (right.first == maxi)
            totalPath = (totalPath + right.second) % mod;
        if (diag.first == maxi)
            totalPath = (totalPath + diag.second) % mod;

        return dp[i][j] = {maxi + toInt(board[i][j]), totalPath};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int size = board.size();

        board[0][0] = '0';
        board[size - 1][size - 1] = '0';

        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101; j++)
                dp[i][j] = {INT_MIN, -1};

        auto [maxi, path] = solve(0, 0, board, size);

        if (path <= 0)
            return {0, 0};

        return {maxi, path};
    }
};