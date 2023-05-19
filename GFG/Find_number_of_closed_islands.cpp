//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int Find(vector<int>& hashSet, int val)
    {
        int parent = val;
        while (parent != hashSet[parent]) {
            parent = hashSet[parent];
        }
        return parent;
    }

    void Union(vector<int>& hashSet, int first, int second)
    {
        int first_father = Find(hashSet, first);
        int second_father = Find(hashSet, second);

        if (first_father != second_father)
            hashSet[first_father] = second_father;
    }
     
    void change(vector<vector<int>>& matrix, int x, int y, int n, int m)
    {
        if (x < 0 || y < 0 || x > m - 1 || y > n - 1 || matrix[x][y] == 0)
            return;
        matrix[x][y] = 0;
        change(matrix, x + 1, y, n, m);
        change(matrix, x, y + 1, n, m);
        change(matrix, x - 1, y, n, m);
        change(matrix, x, y - 1, n, m);
    }

    void changeCorner(vector<vector<int> >& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i * j == 0 || i == m - 1 || j == n - 1) {
                    if (matrix[i][j] == 1) {
                        change(matrix, i, j, n, m);
                    }
                }
            }
        }
    }

    int closedIslands(vector<vector<int> >& matrix,int N,int M)
    {
        if (matrix.size() == 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        changeCorner(matrix);
        vector<pair<int, int> > edges;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    int id = i * n + j;
                    if (j + 1 < n) {
                        if (matrix[i][j + 1] == 1) {
                            int right = i * n + j + 1;
                            edges.push_back(make_pair(id, right));
                        }
                    }
                    if (i + 1 < m) {
                        if (matrix[i + 1][j] == 1) {
                            int down = (i + 1) * n + j;
                            edges.push_back(make_pair(id, down));
                        }
                    }
                }
            }
        }
        vector<int> hashSet(m * n, 0);
        for (int i = 0; i < m * n; i++) {
            hashSet[i] = i;
        }
        for (auto edge : edges) {
            Union(hashSet, edge.first, edge.second);
        }
        int numComponents = 0;
        for (int i = 0; i < m * n; i++) {
            if (matrix[i / n][i % n] == 1
                && hashSet[i] == i)
                numComponents++;
        }
        return numComponents;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends
