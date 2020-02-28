
//最大边长递推公式： dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
int min(int a, int b, int c){
    int min;
    if(a<b) min = a;
    else min = b;
    if(min < c) return min;
    else return c;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize == 0) return 0;
    int dp[matrixSize+1][matrixColSize[0]+1];
    memset(dp, 0, sizeof(dp));
    int res = 0;
    for(int i=1; i<matrixSize+1; i++){
        for(int j=1; j<matrixColSize[0]+1; j++){
            if(matrix[i-1][j-1] == '1'){
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
            }
            res = res > dp[i][j] ? res : dp[i][j];
        }
    }
    return res * res;
}