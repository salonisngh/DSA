class Solution {
public:
    
    void dfs(vector<vector<int>>& image, vector<vector<int>>& vis, int sr, int sc, int OldColor,int color){

        vis[sr][sc] = color;

        int delR[]={-1,0,1,0};
        int delC[]={0,1,0,-1};

        int n= image.size();
        int m= image[0].size();
        for(int i=0; i<4;i++){
            int r= sr + delR[i];
            int c= sc + delC[i];
            if(r >=0 && r <n && c>=0 && c<m && image[r][c]==OldColor && vis[r][c]!=color){
                dfs(image, vis, r, c, OldColor,color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n= image.size();
        int m= image[0].size();
        int OldColor= image[sr][sc];

        if(OldColor== color) return image;
        vector<vector<int>> vis=image;

        dfs(image,vis, sr, sc, OldColor, color);

        return vis;
    }
};