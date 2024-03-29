# Notes

## 0. C++
#### String
- **한 줄 입력 : `getline(cin, str);`**
- 버퍼 비우기 : `cin.ignore();` => cin + getline 같이 쓸 때 써줘야함!
- 문자열 길이 : `str.length()`
- 인덱스로 char 접근 가능
- endl은 느리기 때문에 시간 초과가 발생할 수 있음 => '\n'으로 대체
- 문자열 찾기 : `str1.find(str2);` => 인덱스 or `string::npos` (-1) 리턴
- 문자열 대체 : `str.replace(start_idx, length, new_str)`
- 자릿수 고정 : `cout >> fixed;`, `cout.precision(n);`
- 문자열 여러개 읽기 : `while(getline(cin, str)) {}` -> `str.empty()`일 때 종료시키지 않아도 EOF가 true가 되면 알아서 멈춤
- 부분 문자열 : `str.substr(start_idx, length)`
- 다른 타입으로 변환 : `stoi(str)` / `to_string(num)`
- 다른 문자열과 비교 : `str1.compare(str2)` / `str1.compare (start_idx, len, str2)` / **`str1.compare (start_idx, len, str2, start_idx2, len2)`**

#### String Stream
```:cpp
#include <sstream>
stringstream ss(str);
for(string s : list) {
    string s1, s2;

    ss.str("");
    ss.clear();

    ss.str(s);
    ss >> s1 >> s2;
}
```

#### 시간 줄이기
```:cpp
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
```
---
## 1. STL

### 1. Container
#### Stack
```:cpp
#include <stack>
stack<int> stack;
stack.push(3); // void
stack.pop(); // void
stack.top() // if empty, segfault error
stack.empty() // bool
stack.size() // int
// iterator X
```

#### Vector
```:cpp
#include <vector>
vector<int> vec;
vector<int> vec(v.begin(), v.end()); // sub-vector
vec.push_back(3); // void
vec.pop_back();
vec.front();
vec.back();
vec.at(idx); // index check, == vec[idx]
vec.begin(); // iterator
vec.end(); // iterator
vec.size();
vec.insert(idx, value); // return iterator
vec.erase(iter);
vec.assign(iter, iter);
fill(vec.begin(), vec.end(), 1); // 원하는 값으로 전체 초기화
```

#### Queue
```:cpp
#include <queue>
queue<int> q;
q.push(3);
q.pop(); // void
q.front(); // type
q.back();
q.size(); // int
q.empty(); // bool
// iterator X
```

#### Deque
```:cpp
#include <deque>
deque<int> d;
d.push_front(3);
d.push_back(3);
d.pop_front(); // void
d.pop_back(); // void
d.front(); // type
d.back();
d.size(); // int
d.empty(); // bool
d.clear();
*max_element(d.begin(), d.end()) // #include <algorithm>, iterator 있음
```

#### Map
```:cpp
#include <map>
map<int, int> m;
m[key] = val;
m.insert(pair);
m.find(num); // iterator
m.begin();
m.end();
```

#### Set
```:cpp
#include <set>
set<int> s;
set<int> s(v.begin(), v.end());
s.insert(3); // pair<iterator, bool>
s.begin();
s.end();
s.find(); // iterator or end()
s.count(); // => faster than find()
s.lower_bound(3); // 3 <= iterator
s.upper_bound(3);
// Index Access Impossible => iterator
for(set<int>::iterator iter = s.begin(); iter != s.end(); iter ++) {*iter;} 
```

#### Heap (Priority queue)
```:cpp
#include <queue>
priority_queue<int> pq; // default : max heap
// min heap -> 각 원소에 - 곱해주고 사용 or
priority_queue<int, vector<int>, greater<int>> minheap;
pq.push(3);
pq.pop();
pq.top();
```

#### Tuple
```:cpp
#include <tuple>
tuple<int, int, int> t;
t = make_tuple(1, 2, 3);
tie(a, b, c) = t;
get<0>(t); // -> 1
auto t3 = tuple_cat(t1, t2); // concat
```

---
### 2. Algorithm
#### 정렬 (sort)
```:cpp
sort(arr, arr+n); // 기본 배열
sort(v.begin(), v.end()); // iterator
sort(v.begin(), v.end(), compare); //사용자 정의 함수 compare 사용
sort(v.begin(), v.end(), greater<type>()); //내림차순
sort(v.begin(), v.end(), less<type>()); //오름차순
stable_sort(v.begin(), v.end(), compare); // 값이 동일할 때 들어온 순서 유지
```

#### for-each
```:cpp
#include <algorithm>
for_each(begin_iter, end_iter, func);
// lambda function example
for_each(s.begin(), s.end(), [](int n) {cout << n << endl;});
```

#### min, max
```:cpp
min(a, b);
max(a, b);
```

#### vector unique
```:cpp
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
// or using set
#include <set>
set<type> s(v.begin(), v.end());
```

---
## 2. Others

### 1. 수학

#### 소수 (Prime number)
- 에라토스테네스의 체
    ```:cpp
    for(int i = 2; i <= sqrt(n); i ++) {
        if(arr[i] == 0) continue;
        for(int j = 2*i; j <= n; j += i) {
            arr[j] = 0;
        }
    }
    ```
    - 소수를 찾을 때 sqrt(n)까지만 확인해도 배수로 다 지워짐

#### 최대공약수와 최소공배수
- 유클리드 호제법
    ```:cpp
    // gcd
    int g = max(a,b);
    int l = min(a,b);
    while(l > 0) {
        int tmp = g % l;
        g = l;
        l = tmp;
    }
    
    // lcm
    int lcm = a*b/g;
    ```

#### 소인수분해
```:cpp
for (int i = 2; i <= n;) {
    if (n % i == 0) {
        cout << i << '\n';
        n /= i;
    } else {
        i++;
    }
}
```

#### 약수 구하기
```:cpp
for(int i = 1; i*i <= n; i ++) {
    if(n % i == 0) {
        answer += i;
        if(n/i != i) answer += n/i;
    }
}
```

#### 조합 (Combination)
- 팩토리얼 이용
- 파스칼의 삼각형 이용 -> DP

#### [순열과 조합 DFS로 구하기](https://charles098.tistory.com/9)
- 조합 : n개 중에서 cnt가 남아 있으면 선택
    ```:cpp
    void dfs(int n, int cur, int cnt, vector<bool> &visit) {
        if(cnt == 0) return;

        for(int i = cur; i < n; i ++) {
            if(visit[cur]) continue;
            visit[cur] = true;
            dfs(n, i, cnt-1, visit);
            visit[cur] = false;
        }

    }
    ```
- 중복조합 : 또 가도 되지만 돌아오는 건 안됨
    ```:cpp
    void dfs(int n, int cnt, int idx, vector<int> &res) {
        if(cnt == 0) return;
        
        for(int i = idx; i < n; i ++) {
            res.push_back(i);
            dfs(n, cnt-1, i, res);
            res.pop_back();
        }
    }
    ```
- 순열
    ```:cpp
    void dfs(int n, int cnt, vector<bool> &visit, vector<int> &res) {
        if(cnt == 0) return;

        for(int i = 0; i < n; i ++) {
            if(visit[i]) continue;
            visit[i] = true;
            res.push_back(i);
            dfs(n, cnt-1, visit, res);
            res.pop_back();
            visit[i] = false;
        }

    }
    ```
- 중복순열
    ```:cpp
    void dfs(int n, int cnt, vector<int> &res) {
        if(cnt == 0) return;
        
        for(int i = 0; i < n; i ++) {
            res.push_back(i);
            dfs(n, cnt-1, res);
            res.pop_back();
        }
    }
    ```

---
### 2. etc
#### 10진수 -> 2진수 변환
- 2로 계속 나누기
    ```:cpp
    while(num > 0) {
        int tmp = num % 2;
        num /= 2;
        str = to_string[tmp] + str;
    }
    ```
- shift 연산 이용
    ```:cpp
    for (int i = n; i >= 0; i--) {
        int temp = (x >> i) & 1;
        cout << temp;
    }
    ```
- bitset 이용
    ```:cpp
    #include <bitset>
    bitset<n> x;
    ```

#### 10진수 -> n진수 변환
- n으로 계속 나누는 방법 사용 (문자열 or 숫자 거꾸로 돌려야함)
    ```:cpp
    while(num > 0) {
        int tmp = num % n;
        num /= n;
        str = arr[tmp] + str;
    }
    ```

#### 배열 초기화
```:cpp
fill_n(arr, len, value);
```

#### 누적합 알고리즘
- O(N)으로 누적된 합을 `sum[i] = sum[i-1] + arr[i]`으로 구하는 문제
- 겹치는 구간을 확인하는 방법
    1. 시작 위치에 1을, 끝 위치에 -1을 함
    2. 누적합을 구함

---
### 3. 그래프 관련
#### Union-Find 알고리즘
: 두 노드를 선택해서 같은 그래프에 속하는지 확인 -> 사이클을 확인할 때 활용 가능
- Union : 두 노드를 하나의 부모로 합침
- Find : 두 노드가 부모가 같은지 확인
    ```:cpp
        int getParent(vector<int> parent, int n) {
            if(parent[n] == n) return n;
            else return getParent(parent, parent[n]);
        }

        vector<int> parent(n);
        for(int i = 0; i < n; i ++) parent[i] = i;
        for(int idx = 0; idx < costs.size(); idx ++) {
            int p1 = getParent(parent, costs[idx][0]);
            int p2 = getParent(parent, costs[idx][1]);
            
            if(p1 != p2) {
                parent[p2] = p1;
                answer += costs[idx][2];
            }
        }
    ```
    1. `parent[i] = i`로 초기화
    2. 각 노드에 대해 parent를 재귀적으로 찾음
    3. 해당 parent가 같다면 -> 싸이클, 같지 않다면 `parent[p2] = p1`으로 merge (더 작은 값을 이용해서 merge)

#### Minimum Spanning Tree

- Kruskal Algorithm
    : cost를 오름차순으로 sorting하고, 사이클이 생기지 않는 n-1개의 edge를 선택 (Union-Find 이용)

- Prim Algorithm
    : 특정 vertex에서 시작하여 현재까지 방문한 노드와 인접한 edge 중 cost가 가장 작은 것을 선택