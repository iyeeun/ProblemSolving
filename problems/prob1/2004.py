n, m = map(int, input().split())

cnt_2 = 0
cnt_5 = 0

start = 0

# Count 5
for i in range(5):
    if (n-i)%5 == 0:
        start = n-i
        break

for i in range(start, n-m, -5):
    tmp = i
    while tmp%5 == 0:
        cnt_5 += 1
        tmp /= 5

for i in range(5, m-1, 5):
    tmp = i
    while tmp%5 == 0:
        cnt_5 -= 1
        tmp /= 5

# Count 2
if n%2 == 0:
    start = n
else:
    start = n-1

for i in range(start, n-m, -2):
    tmp = i
    while tmp%2 == 0:
        cnt_2 += 1
        tmp /= 2

for i in range(2, m+1, 2):
    tmp = i
    while tmp%2 == 0:
        cnt_2 -= 1
        tmp /= 2

print(min(cnt_2, cnt_5))