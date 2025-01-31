/*
      Author: MinhBinhDo
      Created: 06:16 29.09.2023
*/
 
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
 
using namespace std;
 
#define maxn 10007
#define ll long long
#define pb push_back
#define fr first
#define sc second
 
const int oo = 1e9 + 7;
const ll lloo = 1e18 + 7;
 
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<pair<int, int>> pii;
 
int n, m;
vi g[maxn];
int low[maxn], num[maxn], timeDfs;
bool deleted[maxn];
int scc; 
stack<int> st;

void dfs(int u)
{
    num[u] = low[u] = ++timeDfs;
    st.push(u);
    for(int v : g[u])
    {
        if(deleted[v]) continue;
        if(!num[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }
    if(low[u] == num[u])
    {
        scc++;
        int v;
        do
        {
            v = st.top();
            st.pop();
            deleted[v] = true;
        } while (v != u);
        
    }
} 

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        g[u].pb(v);
    }
    for(int i = 1; i <= n; i++)
    {
        if(!num[i]) dfs(i);
    }
    cout << scc;
    return 0;
}
