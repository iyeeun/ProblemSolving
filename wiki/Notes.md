## Notes

### 0. C++
#### String
- **한 줄 입력 : `getline(cin, str);`**
- 버퍼 비우기 : `cin.ignore();` => cin + getline 같이 쓸 때 써줘야함!
- 문자열 길이 : `str.length()`
- 인덱스로 char 접근 가능
- endl은 느리기 때문에 시간 초과가 발생할 수 있음 => '\n'으로 대체
- 문자열 찾기 : `str1.find(str2);` => 인덱스 or `string::npos` (-1) 리턴
- 문자열 대체 : `str.replace(start_idx, length, new_str)`

#### 시간 줄이기
```:cpp
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
```

### 1. STL
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