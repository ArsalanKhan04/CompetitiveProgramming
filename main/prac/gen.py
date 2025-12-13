import random

def generate_test_case(n, m, max_weight=10**8):
    """Generates a test case with n trees and m directed paths."""
    print(n, m)

    edges = set()
    for _ in range(m):
        x = random.randint(1, n)
        y = random.randint(1, n)
        w = random.randint(0, max_weight)
        print(x, y, w)
    
    s = random.randint(1, n)
    print(s)

# Smallest case
#print("## Minimum Case")
#generate_test_case(1, 0)

# Sparse Graph
#print("\n## Sparse Graph")
#generate_test_case(10**6, 10)  # Large forest, very few paths

# Dense Graph
#print("\n## Dense Graph")
#generate_test_case(1000, 50000)  # Many paths in a small forest

# Self-loops and multiple edges
#print("\n## Self-Loops and Multiple Edges")
#n, m = 10, 30
#print(n, m)
#for _ in range(m):
    #x = random.randint(1, n)
    #y = random.randint(1, n)
    #w = random.randint(0, 10**8)
    #print(x, y, w)

#s = random.randint(1, n)
#print(s)

# Extreme Case
#print("\n## Extreme Case")
generate_test_case(10**6, 10**6)

