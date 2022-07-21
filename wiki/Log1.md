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

2. 수학1

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

    <br>

    (6) 소수 구하기 ([1929번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/1929.cpp))
    - [소수 구하는 알고리즘 정리](https://maramarathon.tistory.com/39)
    - 시간 상관없이 에라토스테네스의 체를 익히는 연습 문제로 사용해보았다.
    - 방법
        - 배열 만들기
        - 범위의 제곱근보다 작은 소수들의 배수들을 지움 -> 작은 순서대로 소수를 찾으면 그 배수는 소수가 아님
        - 마지막에 남아있는 수는 소수

    <br>

    (7) 팩토리얼 ([10872번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/10872.cpp))
     - 시간 : 1분
     - recursive function과 for문 중 고민하다가 함수 만들기 귀찮아서 걍 반복문 돌렸다. DP도 .. 생각하면 좋을듯 !!

     <br>

     (8) 팩토리얼 0의 개수 ([1676번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/1676.cpp))
     - **풀지 못함**
     - [형변환 문제](https://blockdmask.tistory.com/334) : stoi, to_string
     - N의 범위가 500까지라 직접적으로 팩토리얼 결과를 구하면 오버플로우가 난다.. *파이썬은 되는거 확인함*
        - => unsigned long long 도 오버플로우가 나서 다른 방법을 사용해야 함
        - 0의 개수 == 10으로 나눠지는 개수 ..?? == 2는 무수히 많으므로 (적어도 N/2-1개) 5의 개수만 구하면 된다..!

    <br>

    (9) 조합 0의 개수 ([2004번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/2004.cpp))
    - **풀지 못함**
    - 진짜 시간 초과 계속 나온다. ..  화 가 난 다 ! ! ! ! ! ! !
    - 로직과 접근은 맞았지만, 개수를 카운트하는 데에 있어 while문을 사용하는 게 시간 초과의 원인 같음.
    - [개수 구하기](https://kyunstudio.tistory.com/202)
        ```
        int cnt = 0;
        for(unsigned long long i = a; i <= b; i *= a) {
            cnt += b / i;
        }
        return cnt;
        ```
        : b!에 포함되는 a의 개수


<br>
<br>

3. 다이나믹 프로그래밍1

    (1) 1로 만들기 ([1463번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/1463.cpp))
    - 표를 직접 그려보니 구조를 파악하기가 훨씬 쉬웠음 .. !!
    - DP라는 걸 알고 푸니까 structure를 파악하기 쉬웠지만, 아무 단서 없이 봤으면 어려웠을듯... 어케 알지 ?

    <br>

    (2) 2Xn 타일링 ([11726번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/11726.cpp))
    - 시간 : 1시간 이상
    - DP 구조가 잘 보이지 않아서 다른 패턴을 찾아봤는데, 조합으로 풀 수 있어서 풀었다. But 오버플로우.. [파이썬](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/11726.py)은 됐다.
    - DP는 중복되는 패턴을 걸러내는게 어려워서 ... -> 각 케이스에 대한 순서 고려 안하면 됨!
    - 구조 파악할 때 그 이전의 것과 어떻게 연관지을 수 있을지 논리적으로 생각할 것.

    <br>

    (3) 2Xn 타일링 2 ([11727번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/11727.cpp))
    - 시간 : 5분
    - Base Case가 늘어난 경우
    - (2)와 매우x2 유사해서 쉬웠당. 대충 DP 감이 온다..!

    <br>

    (4) 1, 2, 3 더하기 ([9095번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/9095.cpp))
    - 시간 : 12분
    - 얘도 Base Case가 늘어난 경우

    <br>

    (5) 카드 구매하기 ([11052번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/11052.cpp))
    - 시간 : 1시간
    - 처음엔 카드에 집중을 해 약간 헤맸지만 최댓값에 집중하니 optimal substructure를 금방 찾을 수 있었다 !!
    - 방법의 수를 구하는 기존 DP 문제와 다르게 최댓값을 찾는 문제
    - **" 지금의 문제를 해결할 때 하나를 고정시키면 그 이전의 문제와 같아진다 " => DP**

    <br>

    (6) 카드 구매하기 ([16194번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/16194.cpp))
    - 시간 : 7분
    - (5)랑 거의 똑같았는데, 방법을 바꿔서 for문을 이용해 풀어보았다. 굳 ~

    <br>

    (7) 1, 2, 3 더하기 5 ([15990번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/15990.cpp))
    - 시간 : 16분
    - 히히 DP를 잘 이해해가고 있는 것 같다. 무엇을 고정시켜야 하나 생각해보니 바로 풀 수 있었다 !!
    
    <br>

    (8) 쉬운 계단 수 ([10844번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/10844.cpp))
    - 시간 : 1시간 이상
    - 처음에는 완전 길을 잘못 들었는데.. '개수'에 집중하다보니 패턴이 보인듯. DP는 약간 개수 or 최대/최소 느낌인듯 다른건 나오기가 힘들거 같긴하다
    - 로직이 맞았을 때도 long long + mod 때문에 틀렸음. 오버플로우 체크!
    - 표를 그리는 것도 좋지만, 잘 보이지 않을 때는 tree 형태로 그려보는 것도 도움이 되는 듯하다.


    <br>

    (9) 이친수 ([2193번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/2193.cpp))
    - 시간 : 9분
    - 난 어레이 두개 만들었는데 다른 패턴도 충분히 찾을 수 있을듯.

    <br>

    (10) 가장 긴 증가하는 부분 수열 ([11053번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/11053.cpp))
    - 시간 : 1시간 이상
    - DP로 푼 걸까 .... ? 그것도 모르겠다.... ㅋㅋㅋㅋㅋㅋㅋ
    - O(N^3)으로 풀었는데 ... O(N^2)가 가능한디 .. .. . .
    - **[LIS (Longest Increasing Subsequence) 알고리즘](https://chanhuiseok.github.io/posts/algo-49/)**
        - 하나의 수열에서 끝 원소는 max라는 것을 이용 
        - 자리 찾기를 Binary Search로 수행하면 O(nlogn) 가능
    - [O(N^2) 버전](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/11053_2.cpp)

    <br>

    (11) 가장 긴 증가하는 부분 수열 4 ([14002번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/14002.cpp))
    - 시간 : 1시간 이상
    - 배열이 몇개가 필요한가, 이어서 계산할 수 있는가 등 여러 가지로 헷갈렸던 문제

    <br>

    (12) 연속합 ([1912번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/1912.cpp))
    - 시간 : 23분
    - 1차원 벡터를 이용한 간단한 DP 문제

    <br>

    (13) 제곱수의 합 ([1699번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/1699.cpp))
    - 시간 : 1시간 이상
    - memoization에 대한 고민,,, 잘 모르게씀 ...

    <br>

    (14) 합분해 ([2225번](https://github.com/22000546/ProblemSolving/blob/main/problems/prob1/2225.cpp))
    - 시간 : ?
    - 규칙을 코드로 나타내는 과정에서 어려움을 느꼈다. 

    <br>