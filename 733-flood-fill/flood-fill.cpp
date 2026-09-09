class Solution {
public:
   
         void df(vector<vector<int>>& image, int r, int c,
            int old, int color) {

        int m = image.size();
        int n = image[0].size();

        image[r][c] = color;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                image[nr][nc] == old) {

                df(image, nr, nc, old, color);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int old = image[sr][sc];

        if (old == color)
            return image;

        df(image, sr, sc, old, color);

        return image;
    }
};