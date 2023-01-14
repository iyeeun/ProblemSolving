## Notes

### 0. C++
#### String
- 한 줄 입력 : `getline(cin, str);`
- 버퍼 비우기 : `cin.ignore();` => cin + getline 같이 쓸 때 써줘야함!
- 문자열 길이 : `str.length()`
- 인덱스로 char 접근 가능

### 1. STL
#### Stack
```:cpp
#include <stack>
stack<int> stack;
stack.push(3); # void
stack.pop(); # void
stack.top() # if empty, segfault error
stack.empty() # bool
stack.size() # int
```