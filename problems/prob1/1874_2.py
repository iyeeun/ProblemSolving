
n = int(input())
curr = 0
isPossible = 1

# flag initialize
flag = []
for i in range(n+1):
    flag.append(0)
flag[0] = 2

result = []

for i in range(n):
    num = int(input())

    if curr < num:
        for j in range(curr, num+1):
            if flag[j] == 0:
                result.append(1)
                flag[j] = 1
        flag[num] = 2
        result.append(-1)
    elif curr > num:
        for j in range(curr, num-1, -1):
            if flag[j] == 1:
                result.append(-1)
                flag[j] = 2

    curr = num

    if all(f == 2 for f in flag) and i != n-1:
        isPossible = 0

if isPossible == 0:
    print("NO")
else:
    for i in range(len(result)):
        if result[i] == 1:
            print("+")
        else:
            print("-")