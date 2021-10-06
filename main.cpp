#include<bits/stdc++.h>

using namespace std;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector<vector <T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(vector<vector<T>> v) {cerr << "\n"; for (auto i : v) { for( auto t : i){cerr<<t; cerr << " ";} cerr<<"\n";}}

void DijkastraAlgo( vector<vector<int>> adj[] , int n){

	vector<bool> visited( n ,false);
	vector<int> dist( n , INT_MAX);

	priority_queue<pair<int,int>  , vector<pair<int,int>> , greater<pair<int,int>> > pq;

	dist[0] = 0;

	pq.push({ dist[0] , 0});

	while( !pq.empty()){

		auto i = pq.top();

		int minVertex = i.second;

		visited[minVertex]  = true;

		pq.pop();

		for( auto t : adj[minVertex]){

			if( !visited[t[0]] && dist[minVertex] + t[1] < dist[t[0]]){

				dist[t[0]] = dist[minVertex] + t[1];

				pq.push( { dist[t[0]] , t[0]});
			}
		}
	}

	cout<<endl;

	for( auto i : dist){
		cout<<i<<" ";
	}

}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
fastio();

int V,E;
cin>>V>>E;
vector<vector<int>> adj[V];
 
 for( int i =0 ; i < E; i++){

 	vector<int> t1,t2;
 	int f,s,w;
 	cin>>f>>s>>w;

 	t1.push_back(s);
 	t1.push_back(w);
 	adj[f].push_back(t1);

 	t2.push_back(f);
 	t2.push_back(w);
 	adj[s].push_back(t2);

 }

 DijkastraAlgo(adj,V);

return 0;

}
/*
input:
6 11
0 1 1
0 2 5
2 3 10
0 3 4
1 3 3
1 2 6
3 4 7
2 4 8 
4 5 2
2 5 9
3 5 6

output:

0 1 5 4 11 10 
*/
