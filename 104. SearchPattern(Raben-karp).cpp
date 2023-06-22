#define MOD 1000000007

long long modPower(long long a, long long b)
{
    if (b == 0)
        return 1;

    long long p = modPower(a, b / 2);

    if (b % 2 == 1)
        return p * p % MOD * a % MOD;
    return p * p % MOD;
}

vector<int> stringMatch(string text, string pattern)
{
    int n = text.size();
	int m = pattern.size();

    vector<int> ans;

    long long maxPow = modPower(26, m - 1);

    long long hp = 0, ht = 0;

    for (int i = 0; i < m; i++){
        hp = hp * 26 + pattern[i] - 'a';
        hp %= MOD;
    }
    for (int i = 0; i < m - 1; i++)
    {
        ht = ht * 26 + text[i] - 'a';
        ht %= MOD;
    }

    for (int i = 0; i <= n - m; i++)
    {
        ht = ht * 26 + text[i + m - 1] - 'a';
        ht %= MOD;

        if (ht == hp)
        {
            bool match = true;

            for (int j = 0; j < m; j++){
                if (text[i + j] != pattern[j]){
                    match = false;
                    break;
                }
            }

            if (match)
            {
                ans.push_back(i + 1);
            }
        }

        ht = ht - maxPow * (text[i] - 'a');
        ht %= MOD;
        ht = (ht + MOD) % MOD;
    }

    return ans;
}
