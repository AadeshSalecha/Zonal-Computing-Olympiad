    cin >> n >> m >> K;
    bool safe[n][m]; memset(safe, true, sizeof(safe));
    for(long long i = 0; i < K; i++)
    {
        cin >> row >> col >> start >> freq;
        row--; col--;
        for (int j = 0; j < n; j++) {
			// same row
            int cur = j+row;
            int norm = cur-abs(j-col);
            if(norm >= start and (norm-start) % freq == 0)
                safe[row][j] = false;
		}
 
		for (int j = 0; j < m; j++) {
			// same col
            int cur = j + col;
            int norm = cur-abs(j-row);
            if(norm >= start and (norm-start) % freq == 0)
                safe[j][col] = false;
		}
    }
    
    long long grid[n][m];
    for(long long i = n-1; i >= 0; i--)
        for(long long j = n-1; j >= 0; j--)
        {
            grid[i][j] = -1024;
            if(safe[i][j] and i == n-1 and j == n-1) grid[i][j] = 1; 
            else if(i == n-1 and safe[i][j] and grid[i][j+1] == 1) grid[i][j] = 1;
            else if(j == n-1 and safe[i][j] and grid[i+1][j] == 1) grid[i][j] = 1;
            else if(safe[i][j] and (grid[i+1][j] == 1 or grid[i][j+1] == 1)) grid[i][j] = 1;                    
        }
    if(grid[0][0] > 0)
        cout << "YES\n" << n-1+m-1 << endl;
    else
        cout << "NO\n";
} 