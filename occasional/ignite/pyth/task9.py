import sys

# It's good practice to increase the recursion limit for deep trees in competitive programming
sys.setrecursionlimit(200005)

def solve():
    """
    This function reads the tree structure, solves the problem, and prints the result.
    """
    n_str = sys.stdin.readline()
    n = int(n_str)

    if n <= 1:
        print(0)
        return

    # Adjacency list to represent the tree
    adj = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        u, v = map(int, sys.stdin.readline().split())
        adj[u].append(v)
        adj[v].append(u)

    # dp[u][0]: max matching in subtree of u, where u is NOT matched with a child.
    # dp[u][1]: max matching in subtree of u, where u IS matched with a child.
    dp = [[0, 0] for _ in range(n + 1)]

    def dfs(u, p):
        """
        Performs DFS to calculate DP values for the maximum matching.
        u: current node
        p: parent of current node
        """
        # Base cases (leaves) are implicitly handled as the loops over children won't run.
        # dp[u] will remain [0, 0] which is correct for a leaf.

        # sum_of_maxes will store sum_{v} max(dp[v][0], dp[v][1])
        sum_of_maxes = 0
        
        # Calculate sum_of_maxes by visiting all children first
        for v in adj[u]:
            if v == p:
                continue
            dfs(v, u)
            sum_of_maxes += max(dp[v][0], dp[v][1])
        
        # dp[u][0] is simply the sum of the best matchings from its children's subtrees
        dp[u][0] = sum_of_maxes

        # To calculate dp[u][1], we try to match u with each child v and take the max
        max_matching_u = 0
        for v in adj[u]:
            if v == p:
                continue
            
            # Score if u is matched with v:
            # 1 (for the u-v edge)
            # + dp[v][0] (v cannot be matched with its children)
            # + (sum_of_maxes - max(dp[v][0], dp[v][1])) (scores from other children)
            current_match_score = 1 + dp[v][0] + (sum_of_maxes - max(dp[v][0], dp[v][1]))
            if current_match_score > max_matching_u:
                max_matching_u = current_match_score
        
        dp[u][1] = max_matching_u

    # Start the DFS from an arbitrary root (e.g., node 1) with a virtual parent 0.
    dfs(1, 0)

    # The result for the whole tree is the best we can do at the root.
    result = max(dp[1][0], dp[1][1])
    print(result)

solve()
