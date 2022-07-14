from itertools import combinations

def getCombination(a, b):
    answer = 1; 
    
    if b == 0:
        return answer
    for i in range(b):
        answer *= (a-i)

    for i in range(1, b+1):
        answer //= i

    return answer

n = int(input())

A = 0
B = n

cnt = 0

while True:
    cnt += getCombination(A+B, min(A, B))
    
    A += 1
    B -= 2

    if B < 0:
        break

print(int(cnt % 10007))
