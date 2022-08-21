// travelling salesman problem
#include<stdio.h>
#define INT_MAX 1000000000
int n; // number of nodes
int g[100][100]; // adjacency list [cost distance between every pair of nodes]
int distance[20][1 << 18]; // calculate & keep track of shortest cost distance
int all_visited;
int min(int a, int b)
{
	if (a < b) return a;
	return b;
}
int tsp(int city, int mask)
{
	if (mask == all_visited) // if every city is visited
		return g[city][0]; // return cost of coming back from the city to 0th city

	if (distance[city][mask] != -1)
		return distance[city][mask]; // if already calculated, return the cost

	int ans = INT_MAX;

	for (int i = 0; i < n; i++)
		{
			if ((mask & (1 << i)) == 0) // if not visited
				{
					int tmp_dist = g[city][i]; // cost of coming back from the city to 0th city
					ans = min(ans, tmp_dist + tsp(i, mask | (1 << i)));
				}
		}
	return distance[city][mask] = ans;
}
int main()
{
	printf("Enter no of cities: ");
	scanf("%d", &n);

	printf("Enter distance of every pair of cities:\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &g[i][j]); // cost distance for node i to j

	for (int i = 0; i < n; i++)
		for (int j = 0; j < (1 << n); j++)
			distance[i][j] = -1; // initializing dp array

	all_visited = (1 << n) - 1; // bitmask for every city visited

	int ans = tsp(0, 1); // tsp(start_city,mask), strats from 0th city
	printf("Shortest cost route to visit every city and come back to 0: %d\n", ans);
	return 0;
}
/*
Input:
4
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0

output: 80
*/
