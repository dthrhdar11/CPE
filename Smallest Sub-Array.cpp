#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    // fast io
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T, N, M, K, cases = 0;
    vector<int> G;
    vector<int> check;
    cin >> T;
    while (T--)
    {
        cin >> N >> M >> K;
        // init
        G.assign(N + 1, 0);
        G[1] = 1, G[2] = 2, G[3] = 3;
        for (int i = 4; i <= N; ++i) G[i] = (G[i - 1] + G[i - 2] + G[i - 3]) % M + 1;
        check.assign(K + 1, 0);
        // find the smallest subsequence
        int result = N + 1;
        for (int i = 1, f = 1, cnt = 0; i <= N; ++i)
        {
            if (G[i] > K)//first element should always in [1,k] 
				continue;
            else if (++check[G[i]] == 1)
				++cnt;
            while (f <= i && cnt == K)//when cnt == k, count the result
            {
                if (G[f++] > K)//ignore element not in [1,k]
					continue;
                result = min(result, i - f + 2); //(i-f+1)+1 because f++ 
                if (--check[G[f - 1]] == 0) --cnt;//if previous one is in [1,k],--cnt
            }
        }
        cout << "Case " << ++cases << ": ";
        if (result == N + 1) cout << "sequence nai\n";
        else cout << result << "\n";
    }
    return 0;
}

