int findMinimumCoins(int amount) 
{
    int prices[] = {1,2,5,10,20,50,100,500,1000};
    int n = 9;
    int cc = 0;
    for(int i=n-1;i>=0;i--){
        cc+=amount/prices[i];
        amount %= prices[i];
    }
    return cc;
}
