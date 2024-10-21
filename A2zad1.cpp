#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <queue>

#define ll long long
#define MAXN 32000

struct Location {
    ll x, y;
    int idx;
};

bool compX(Location a, Location b) { 
    return a.x < b.x;
}
bool compY(Location a, Location b) { 
    return a.y < b.y; 
}

Location a[MAXN];
ll dist[MAXN];
bool done[MAXN];
std::vector<std::pair<int, ll>> adj[MAXN];

void dijkstra(int s) {
    for(int i = 0; i < MAXN; i++) dist[i] = std::numeric_limits<ll>::max();
    dist[s] = 0;
    std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<std::pair<ll, int>>> pq;
    pq.push({0, s});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(done[u]) continue;
        done[u] = true;
        for(auto e : adj[u]) {
            int v = e.first;
            ll w = e.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, s, t;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i].x >> a[i].y;
        a[i].idx = i;
    }

    std::cin >> s >> t;

    std::sort(a, a + n, compX);
    for(int i = 0; i < n - 1; i++) {
        adj[a[i].idx].push_back({a[i + 1].idx, a[i + 1].x - a[i].x});
        adj[a[i + 1].idx].push_back({a[i].idx, a[i + 1].x - a[i].x});
    }

    std::sort(a, a + n, compY);
    for(int i = 0; i < n - 1; i++) {
        adj[a[i].idx].push_back({a[i + 1].idx, a[i + 1].y - a[i].y});
        adj[a[i + 1].idx].push_back({a[i].idx, a[i + 1].y - a[i].y});
    }

    dijkstra(s);
    std::cout << dist[t];

    return 0;
}
