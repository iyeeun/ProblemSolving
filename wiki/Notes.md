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
s.count();
s.lower_bound(3); // 3 <= iterator
s.upper_bound(3);
// Index Access Impossible => iterator
for(set<int>::iterator iter = s.begin(); iter != s.end(); iter ++) {*iter;} 
```

---
### 2. Algorithm
#### 정렬 (sort)
```:cpp
sort(arr, arr+n);
sort(v.begin(), v.end()); // iterator
sort(v.begin(), v.end(), compare); //사용자 정의 함수 compare 사용
sort(v.begin(), v.end(), greater<type>()); //내림차순
sort(v.begin(), v.end(), less<type>()); //오름차순
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

---
### 2. etc
#### 10진수 -> 2진수 변환
- 2로 계속 나누기
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