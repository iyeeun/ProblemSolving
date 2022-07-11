#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack {
public:
    int size;
    vector<int> stack;

    Stack();
    void init(int n);
    void push(int x);
    int pop();
};

Stack::Stack() {
    size = 0;
    stack.clear();
}

void Stack::init(int n) {
    for(int i = 0; i < n; i ++) {
        stack.push_back(-1);
    }
}

void Stack::push(int x) {
    stack[size] = x;
    size ++;
}

int Stack::pop() {
    if(size == 0)
        return -1;
    size --;
    return stack[size];
}

int main() {

    int n;
    string comm;
    Stack s;

    cin >> n;

    s.init(n);

    for(int i = 0; i < n; i ++) {
        cin >> comm;
        if(comm == "push") {
            int num;
            cin >> num;
            s.push(num);
        } else if(comm == "pop") {
            int num = s.pop();
            cout << num << endl;
        } else if(comm == "size") {
            cout << s.size << endl;
        } else if(comm == "empty") {
            if(s.size == 0)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        } else if(comm == "top") {
            if (s.size == 0)
                cout << -1 << endl;
            else
                cout << s.stack[s.size-1] << endl;
        }
    }
    


    return 0;
}