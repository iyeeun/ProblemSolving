## Notes

### 0. C++
#### String
- **한 줄 입력 : `getline(cin, str);`**
- 버퍼 비우기 : `cin.ignore();` => cin + getline 같이 쓸 때 써줘야함!
- 문자열 길이 : `str.length()`
- 인덱스로 char 접근 가능
- endl은 느리기 때문에 시간 초과가 발생할 수 있음 => '\n'으로 대체

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