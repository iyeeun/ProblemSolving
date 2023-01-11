## Notes

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