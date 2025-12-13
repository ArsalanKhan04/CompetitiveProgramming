import heapq
from collections import defaultdict

def dijkstra(graph, start, n):
    """
    Compute shortest distances from start node to all other nodes
    """
    dist = [float('inf')] * n
    dist[start] = 0
    pq = [(0, start)]
    
    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
            
        for v, w in graph[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))
    
    return dist

def can_cover_with_k_centers(all_distances, n, k, max_dist):
    """
    Check if we can place k centers such that all towns are within max_dist
    using a greedy set cover approach
    """
    uncovered = set(range(n))
    centers_used = 0
    
    while uncovered and centers_used < k:
        # Find the center that covers the most uncovered towns
        best_center = -1
        best_coverage = set()
        
        for center in range(n):
            coverage = set()
            for town in uncovered:
                if all_distances[center][town] <= max_dist:
                    coverage.add(town)
            
            if len(coverage) > len(best_coverage):
                best_center = center
                best_coverage = coverage
        
        if not best_coverage:
            return False
            
        # Place the center
        uncovered -= best_coverage
        centers_used += 1
    
    return len(uncovered) == 0

def solve_vaccination_centers():
    # Read input
    n, m, k = map(int, input().split())
    
    # Build graph
    graph = defaultdict(list)
    for _ in range(m):
        u, v, w = map(int, input().split())
        graph[u].append((v, w))
        graph[v].append((u, w))
    
    # Compute all-pairs shortest paths using Dijkstra from each node
    all_distances = []
    for i in range(n):
        all_distances.append(dijkstra(graph, i, n))
    
    # Get all possible distances for binary search
    all_possible_distances = set()
    for i in range(n):
        for j in range(n):
            if all_distances[i][j] != float('inf'):
                all_possible_distances.add(all_distances[i][j])
    
    all_possible_distances = sorted(list(all_possible_distances))
    
    # Binary search on the sorted list of possible distances
    left, right = 0, len(all_possible_distances) - 1
    result = all_possible_distances[-1] if all_possible_distances else 0
    
    while left <= right:
        mid_idx = (left + right) // 2
        mid_dist = all_possible_distances[mid_idx]
        
        if can_cover_with_k_centers(all_distances, n, k, mid_dist):
            result = mid_dist
            right = mid_idx - 1
        else:
            left = mid_idx + 1
    
    return result

if __name__ == "__main__":
    print(solve_vaccination_centers())
