# Python3 program for the above approach
def maxindex(dist, n):
    mi = 0
    for i in range(n):
        if (dist[i] > dist[mi]):
            mi = i
    return mi

def selectKcities(n, weights, k):
    dist = [0]*n
    centers = []

    for i in range(n):
        dist[i] = 10**9
        
    # index of city having the
    # maximum distance to it's
    # closest center
    max = 0
    for i in range(k):
        centers.append(max)
        for j in range(n):

            # updating the distance
            # of the cities to their
            # closest centers
            dist[j] = min(dist[j], weights[max][j])

        # updating the index of the
        # city with the maximum
        # distance to it's closest center
        max = maxindex(dist, n)

    # Printing the maximum distance
    # of a city to a center
    # that is our answer
    # print()
    print(dist[max])

# Driver Code
if __name__ == '__main__':
    n,m,k = map(int, input().split())

    # Initialize adjacency matrix with infinities, 0 on diagonal
    InF = float('inf')
    weights = [[InF] * n for _ in range(n)]
    for i in range(n):
        weights[i][i] = 0

    for _ in range(m):
        u, v, w = map(int, input().split())
        u -= 1  # zero-indexing
        v -= 1
        weights[u][v] = min(weights[u][v], w)
        weights[v][u] = min(weights[v][u], w)

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if weights[i][j] > weights[i][k] + weights[k][j]:
                    weights[i][j] = weights[i][k] + weights[k][j]


    # Function Call
    selectKcities(n, weights, k)

# This code is contributed by mohit kumar 29.
