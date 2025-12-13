s = input().strip().lower()
p = input().strip().lower()
n = len(s)
m = len(p)

ans = []

for i in range(n-m+1):
    match = True
    for j in range(m):
        if (p[j] == '?'):
            continue
        if p[j] != s[i+j]:
            match = False
            break
    if match:
        ans.append(i)
                
print(len(ans))
print(" ".join(map(str, ans)))

