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

<br>
<br>

1. 수학1

    (1) 나머지 ([10430번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/10430.cpp))
    - 시간 : 3분
    - 초 간 단

    <br>

    (2) 최대공약수와 최소공배수 ([2609번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/2609.cpp))
    - 시간 : 11분
    - [유클리드 호제법](https://sectumsempra.tistory.com/77)을 이용하는거란다 ... 그건 잘 모르겠고 그냥 몸에 남아있는 중등 수학의 기억으로 대충 품 ..
        - A*B/최대공약수 == 최소공배수
        - 최대공약수는 A % B == 0이 될 때까지 연산을 계속했을 때의 B (A = B, B = A % B 반복)

    <br>

    (3) 최소공배수 ([1934번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/1934.cpp))
    - 시간 : 6분
    - 유클리드 호제법 이용

    <br> 
    
    (4) 소수 찾기 ([1978번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/1978.cpp))
    - 시간 : 5분
    - 소수 정의 (나누어떨어지는 수가 2개만 있음) 이용해도 될듯
    - [빠른 방법들](https://nanyoungkim.tistory.com/32)
        - [에라토스테네스의 체](https://velog.io/@max9106/Algorithm-%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98-%EC%B2%B4)
        : 배열을 만들어서 소수의 배수를 거르는 늑낌

    <br>

    (5) 골드바흐의 추측 ([6588번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/6588.cpp))
    - 시간 : 16분 but 시간 초과
    - [에라토스테네스의 체](https://korean-otter.tistory.com/entry/6588-%EB%B0%B1%EC%A4%80-%EA%B3%A8%EB%93%9C%EB%B0%94%ED%9D%90%EC%9D%98-%EC%B6%94%EC%B8%A1-C)를 이용해야 한다고 합니다 .. ~~모르는데 어떻게 해요~!~~
    - 히히 인간승리다. 소수 구할때 sqrt(num)까지만 비교해도 된당 히히
        - 왜 ?
    - cin 빠르게 하는 거 -> 사실 없애도 시간 초과 안뜸 -> **반복문의 범위를 매우 매우 신경쓰자 ~~~!!!!**
        ``` 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL); 
        ```