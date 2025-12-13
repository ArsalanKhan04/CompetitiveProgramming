def f(t: str, p: str):
    t = t.lower()
    p = p.lower()
    n, m = len(t), len(p)

    if m == 0 or n < m:
        print(0)
        print()
        return

    def pm(x, y): return x == '?' or y == '?' or x == y
    def cm(x, y): return y == '?' or x == y

    pi = [0] * m
    for i in range(1, m):
        j = pi[i - 1]
        while j and not pm(p[i], p[j]):
            j = pi[j - 1]
        if pm(p[i], p[j]):
            j += 1
        pi[i] = j

    out, j = [], 0
    for i in range(n):
        while j and not cm(t[i], p[j]):
            j = pi[j - 1]
        if cm(t[i], p[j]):
            j += 1
        if j == m:
            out.append(i - m + 1)
            j = pi[j - 1]

    print(len(out))
    print(" ".join(map(str, out)))


if __name__ == "__main__":
    a = input().strip()
    b = input().strip()
    f(a, b)


