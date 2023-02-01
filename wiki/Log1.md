## [알고리즘 기초 1](https://code.plus/course/41)

### 자료구조

1. 자료구조1

    (1) [스택 (10828번)](https://www.acmicpc.net/problem/10828)
    - [시간 : 17분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/1_10828.cpp)
    - STL의 stack을 이용해서 풀었다. STL 막는데도 있다고 했던거 같은데 찾아보니 삼성도 이제 사용가능하다고 해서 그냥 잘 쓰는 것에 집중하는게 나을 것 같다.

    <br>

    (2) [단어 뒤집기 (9093번)](https://www.acmicpc.net/problem/9093) 
    - 시간 : 21분에 포기 => [서칭 후 14분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/2_9093.cpp)
    - 스택 이용 생각도 못함 ,,, + 문자열 사용,,,,,
    - 스택 <-> **입력과 반대인 출력**이 필요할 때

    <br>

    (3) [괄호 (9012번)](https://www.acmicpc.net/problem/9012)
    - 시간 : [12분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/3_9012.cpp)
    - stack empty이면 top이 segmentation fault

    <br>

    (4) [스택 수열 (1874번)](https://www.acmicpc.net/problem/1874)
    - 시간 : 23분에서 시간 초과, 총 [32분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/4_1874.cpp)
    - endl은 느림
    - 어려운 문제는 toy example로 규칙 찾기

    <br>

    (5) [에디터 (1406번)](https://www.acmicpc.net/problem/1406)
    - 시간 : [11분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/5_1406.cpp)

    <br>

    (6) [큐 (10845번)](https://www.acmicpc.net/problem/10845)
    - 시간 : [8분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/6_10845.cpp)

    <br>

    (7) [요세푸스 문제 (1158번)](https://www.acmicpc.net/problem/1158)
    - 시간 : [21분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/7_1158.cpp)
    - 큐 문제인건 알았는데 잘 생각이 안나서 벡터로 풀었음. 시간이 많이 걸리는 방법인듯
    - 벡터이든 큐이든 2개 말고 하나만 쓰도록 최적화할 수 있음

    <br>

    (8) [덱 (10866번)](https://www.acmicpc.net/problem/10866)
    - 시간 : [32분에 포기 (런타임 에러)](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/8_10866.cpp)
    - 덱을 잘 쓸 줄 몰라 STL 덱 말고 한번 벡터로 구현해보자 했는데..! 백준에서 채점하면 런타임 에러가 난다.. ㅜㅜ VSCode에서 나는 건 고쳤는데도 백준에서 통과가 안되어서 포기.. 대신 덱 쓰는 법을 공부하기로..!
    - 근데 예외처리 더 꼼꼼하게 바꾸니까 됐음.....!! ㅎㅎㅎ 시간이나 메모리도 STL 덱 쓸 때랑 비슷한듯

    <br>

2. 자료구조1 (연습)

    (1) [단어 뒤집기 2 (17413번)](https://www.acmicpc.net/problem/17413)
    - 시간 : [11분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/9_17413.cpp)

    <br>

    (2) [쇠막대기 (10799번)](https://www.acmicpc.net/problem/10799)
    - 시간 : [18분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/10_10799.cpp)
    - 좀 어려워보여서 겁먹었는데, 생각보다 그렇게 어렵지는 않은 문제였다. 자료구조를 쓰지 않고 로직으로 풀었는데 스택을 이용한 풀이가 있는 것 같다. 스택을 이용할 때에는 마지막 조각에서 +1 해줘야 하는데 이런 사소한 테크닉 때문에 스택을 쓰는걸 주저한 것 같다. 무엇인가 계속 지속되고 있고 그 위에서 생성과 소멸이 반복된다면 스택!

    <br>

    (3) [오큰수 (17298번)](https://www.acmicpc.net/problem/17298)
    - 시간 : [40분 이후에 서치](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/11_17298.cpp)
    - O(N)으로 풀어야 했음.. 스택을 사용하는 아이디어는 그래도 빨리 찾았는데 최적화하기가 너무 어려움. => 찾아보니 좀 다른 아이디어가 필요했음 한번에 훑어서 결과를 낼 수 있으려면 어떻게 해야할지 잘 생각해야 함.
    - 결국 서치로 해결했음.. 핵심은 내가 오른쪽에 있는 애들보다 크다면 내가 오큰수가 된다는 것,,, 그래서 한 번만 훑어봐도 가능했던 것,,, 스택을 쓸 아이디어를 캐치하는 게 어려웠는데 여기서의 개념은 필요한 정보를 저장하는 느낌쓰 사실 잘 모르겠다... ㅜㅜ 이런 유형이 있다는걸 잘 익혀두자!

    <br>

    (4) [오등큰수 (17299번)](https://www.acmicpc.net/problem/17299)
    - 시간 : [30분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/12_17299.cpp)
    - 오큰수랑 비슷하니까 금방 하겠지? 라고 생각했는데 오산.. map을 사용하니 시간초과가 떴다. 그래서 vector로 하니 맞았음. 스택을 이용해서 한번 훑기 잘 기억하자 !!
    

    <br>

3. 자료구조1 (참고)

    (1) 
    - 시간 : 

    <br>

<br>
<br>