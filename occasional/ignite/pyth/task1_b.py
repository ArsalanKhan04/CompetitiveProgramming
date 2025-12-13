# Python3 program for the K-centers problem
def maxindex(dist, n):
    mi = 0
    for i in range(n):
        if (dist[i] > dist[mi]):
            mi = i
    return mi

def selectKcities(n, weights, num_centers):
    dist = [0] * n
    centers = []
    
    # Initialize distances to infinity
    for i in range(n):
        dist[i] = 10**9
        
    # Index of city having the maximum distance to its closest center
    max_idx = 0
    
    for i in range(num_centers):
        centers.append(max_idx)
        
        # Update the distance of all cities to their closest centers
        for j in range(n):
            dist[j] = min(dist[j], weights[max_idx][j])
        
        # Find the city with maximum distance to its closest center
        max_idx = maxindex(dist, n)
    
    # The answer is the maximum distance of any city to its closest center
    return dist[max_idx]

# Driver Code
if __name__ == '__main__':
    n, m, k = map(int, input().split())
    
    # Initialize adjacency matrix with infinities, 0 on diagonal
    InF = float('inf')
    weights = [[InF] * n for _ in range(n)]
    for i in range(n):
        weights[i][i] = 0
    
    # Read edges
    for _ in range(m):
        u, v, w = map(int, input().split())
        # Assuming 0-based indexing in input
        weights[u][v] = min(weights[u][v], w)
        weights[v][u] = min(weights[v][u], w)
    
    # Floyd-Warshall algorithm to find all-pairs shortest paths
    for intermediate in range(n):  # Changed variable name to avoid conflict
        for i in range(n):
            for j in range(n):
                if weights[i][j] > weights[i][intermediate] + weights[intermediate][j]:
                    weights[i][j] = weights[i][intermediate] + weights[intermediate][j]
    
    # Function Call
    result = selectKcities(n, weights, k)
    print(result)
