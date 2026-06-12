import random

# Define constraints
num_test_cases = 1000  # You can change this up to 10000
max_a = 10**5

print(num_test_cases)

for _ in range(num_test_cases):
    # Generate a random non-negative integer 'a'
    a = random.randint(0, max_a)

    # Generate two distinct random digits from 0 to 9
    digits = random.sample(range(10), 2)
    # Sort them so they are strictly increasing (d1 < d2)
    digits.sort()

    # Print the test case
    print(f"{a} 2")
    print(f"{digits[0]} {digits[1]}")
