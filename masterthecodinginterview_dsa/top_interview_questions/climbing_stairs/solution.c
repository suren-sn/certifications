
int climbStairs(int n){
    int nMinus2 = 1;
    int nMinus1 = 2;
    int nSteps;
    if (n < 3)
        return n;
    
    for (int i=3; i<=n; i++){
        nSteps = nMinus1 + nMinus2;
        nMinus2 = nMinus1;
        nMinus1 = nSteps;
    }
    
    return nSteps;
}
