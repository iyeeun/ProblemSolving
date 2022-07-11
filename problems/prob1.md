## [알고리즘 기초 1](https://code.plus/course/41)

1. 자료구조1

    (1) 스택 ([10828번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/10828.cpp))
    - 시간 : 약 20분 정도 ..?
    - C++에 대한 어려움
    - 임의로 주어지는 입력값에 대한 초기화를 어떻게 할 것인가..!
    - STL 이용 많이 많이 하자요

    <br>

    (2) 단어 뒤집기 ([9093번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/9093.cpp))
    - 시간 : 27분
    - [C++ 문장 읽기](https://jhnyang.tistory.com/107)
        - cin : 공백과 개행을 입력받지 못함, 버퍼에 개행이 남아있어 cin.ignore() 해주어야 함
        - getline(cin, str) : 개행 전까지 
        - cin.getline() : istream, 파일, cin
    
    - [x] 스택으로 구현해보기 .. ?? ```#include <stack>``` 
        - [9093_2번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/9093_2.cpp)


    <br>

    (3) 괄호 ([9012번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/9012.cpp))
    - 시간 : 16분
    - 스택 쓸 때 예외 처리 신경쓰기

    <br>

    (4) 스택 수열 ([1874번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/1874_3.cpp))
    - **풀지 못함**
    - 스택을 어떻게 사용하면 될지 잘 모르겠음. 그냥 규칙 찾아서 해봤는데 [시간초과](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/1874.cpp)..
    => c++ string 연산이 O(N)이라 그런듯 호호 ^^...
        - cin, cout, endl, string 연산 등이 아주 느리다고 한다.
    - 파이썬으로 한번 해보았따. 그래도 [시간초과..](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/1874_2.py) 로직이 너무 느린가보당..헤헤헤ㅔ헤헤
    - 결국 [답을 참고](https://guiyum.tistory.com/3)해보았다. 틀은 비슷한테 스택을 쓰는거 + 예외 처리가 차이 나는듯. 사실 잘 이해안됨 중복이 없어야해서 top과 같아야 하는듯...?
    - 처음 짠 코드의 flag가 stack에 넣는거랑 비슷한 처리인데 변환이 잘 안되는 것 같다.

    <br>

    (5) 에디터 ([1406번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/1406_3.cpp))
    - 시간 : 26분 / 15분 / 7분
    - 시간초과... 부들부들.. : [1406_1](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/1406.cpp), [1406_2](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/1406_2.cpp)
    - FILO의 성질을 보일 때는 스택을 사용하자

    <br>

    (6) 큐 ([10845번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/10845.cpp))
    - 시간 : 12분
    - 그냥 벡터 이용해서 구현했는데 STL queue로도 해보면 좋을 것 같다. 
        - 그냥 ```push, pop, size, empty, front, back``` 다 있는듯

    <br>

    (7) 요세푸스 문제 ([1158번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/1158.cpp))
    - 시간 : 20분
    - 정답을 담기 위한 큐만 사용했는데, circular queue로 풀었어도 될듯..!
        - 큐 두 개 사용한 [풀이](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/1158_2.cpp)
        - 진짜 훨씬 훨씬 훨씬 빠르다... STL 열심히 써야겠다 !!
    - 금방 풀었다고 생각했는데, 인덱스 때문에 살짝 헤맨것 같다

    <br>

    (8) 덱 ([10866번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/10866.cpp))
    - 시간 : 20분
    - 벡터 버전 : 테스트 케이스 실패 -> 인덱스 문제 ㅎㅎ... 꼼꼼하게 신경쓰자!
    - STL에 deque도 있다 .. !!  [STL 버전](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/10866_2.cpp)


