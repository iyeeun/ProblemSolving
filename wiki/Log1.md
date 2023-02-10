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

    (1) [후위 표기식2 (1935번)](https://www.acmicpc.net/problem/1935)
    - 시간 : [35분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/13_1935.cpp)
    - 데구 때 했던 postfix 문제랑 다른건데 거기에 집착하느라 초반에 잘못 생각함.. 20억까지의 수라 float 쓰면 틀림 double 써야 했음! 차근차근 생각하기

    <br>

    (2) [후위 표기식 (1918번)](https://www.acmicpc.net/problem/1918)
    - 시간 : [30분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/14_1918.cpp)
    - 지겹도록 공부했던 infix -> postfix 바꾸는 프로그램.. 왜 어려워하니.. '('의 우선순위가 0이라는 사실을 잘 기억해야겠다. + '('은 push만 하기! 나머지는 잘 기억했움 괄호를 처리하는게 어렵군요,,, 

    <br>

    (3) [알파벳 개수 (10808번)](https://www.acmicpc.net/problem/10808)
    - 시간 : [3분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/15_10808.cpp)
    - 왜 풀라고 했지.. 의미를 알 수 없는 문제

    <br>

    (4) [알파벳 찾기 (10809번)](https://www.acmicpc.net/problem/10809)
    - 시간 : [2분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/16_10809.cpp)
    - string의 find를 어제 공부해서 아주 쉽게 풀 수 있었다!

    <br>

    (5) [문자열 분석 (10820번)](https://www.acmicpc.net/problem/10820)
    - 시간 : [13분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/17_10820.cpp)
    - 문자열 여러줄 읽는 연습, EOF에 대한 이해

    <br>

    (6) [ROT13 (11655번)](https://www.acmicpc.net/problem/11655)
    - 시간 : [27분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/18_11655.cpp)
    - 킹받 ,, 로직은 똑같은데 대문자만 되고 소문자는 안돼서 왜그러지 싶었는데 소문자는 13 더하면 127을 넘어가서 그랬다 ㅜㅜ... 아스키 코드는 127번까지 있으니 그 이상을 다루고 싶을 때는 char 대신 int로!

    <br>

    (7) [네 수 (10824번)](https://www.acmicpc.net/problem/10824)
    - 시간 : [16분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/19_10824.cpp)
    - 쉬운데 배울게 많았음. 역시나 범위, 타입 조심하구 거기까지 눈치채긴 했는데 설마 그게 문제일줄은 몰랐다... math 라이브러리는 cmath

    <br>

    (8) [접미사 배열 (11656번)](https://www.acmicpc.net/problem/11656)
    - 시간 : [4분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/20_11656.cpp)
    - algorithm의 sort를 이용하여 금방 해결했다. 풀이를 보다보니 set을 사용하여 해결한 사람이 있었는데, set은 insert할 때 sorting해서 들어가기 때문이었다.

    <br>

### 수학

1. 수학 1

    (1) [나머지 (10430번)](https://www.acmicpc.net/problem/10430)
    - [시간 : 2분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/21_10430.cpp)

    <br>

    (2) [최대공약수와 최소공배수 (2609번)](https://www.acmicpc.net/problem/2609)
    - [시간 : 35분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/22_2609.cpp)
    - 유클리드 호제법 공부하면서 풀었다. . . 잘 이해 안됨 사실 그냥 받아들였다.. 잘 기억하기!

    <br>

    (3) [최소공배수 (1934번)](https://www.acmicpc.net/problem/1934)
    - [시간 : 3분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/23_1934.cpp)

    <br>

    (4) [소수 찾기 (1978번)](https://www.acmicpc.net/problem/1978)
    - [시간 : 6분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/24_1978.cpp)

    <br>

    (5) [소수 구하기 (1929번)](https://www.acmicpc.net/problem/1929)
    - [시간 : 9분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/25_1929.cpp)

    <br>

    (6) [골드바흐의 추측 (6588번)](https://www.acmicpc.net/problem/6588)
    - [시간 : 17분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/26_6588.cpp)
    - 완전 너무한 문제.. ㅜㅜㅜ

    <br>

    (7) [팩토리얼 (10872번)](https://www.acmicpc.net/problem/10872)
    - [시간 : 3분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/27_10872.cpp)

    <br>

    (8) [팩토리얼 0의 개수 (1676번)](https://www.acmicpc.net/problem/1676)
    - [시간 : 13분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/28_1676.cpp)
    - 0 개수 => 5로 나누어지는 개수 이용

    <br>

    (9) [조합 0의 개수 (2004번)](https://www.acmicpc.net/problem/2004)
    - [시간 : 3시간](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/29_2004.cpp)
    - 못풀었다... ㅜㅜ 시간초과.... 틀리기도 계속 틀리고 ㅜㅜ 다 바꿨다고 생각했는데 시간초과 나와서 이젠 모르겠다... 하하하하
    - 하나하나 세면서 5/2로 얼만큼 나눠지는지 보는 것은 시간 초과 뜨는 듯. 
    - k!의 i 개수를 알려면 k/i^n을 구하면 된다.

    <br>

2. 수학 1 (연습)

    (1) [GCD 합 (9613번)](https://www.acmicpc.net/problem/9613)
    - 시간 : [15분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/30_9613.cpp)
    - 유클리드 호제법 암기하기..! + 범위에 따라 알맞은 자료형 사용

    <br>

    (2) [숨바꼭질 6 (17087번)](https://www.acmicpc.net/problem/17087)
    - 시간 : [19분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/31_17087.cpp)
    - 모든 경우에 대해 살펴보는게 시간 초과가 나서 바로 다음만 보니까 맞음
    - 3가지의 숫자에 대한 최대공약수는 gcd(gdc(a, b), c)로 구하면 됨

    <br>

    (3) [2진수 8진수 (1373번)](https://www.acmicpc.net/problem/1373)
    - 시간 : [22분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/32_1373.cpp)

    <br>

    (4) [8진수 2진수 (1212번)](https://www.acmicpc.net/problem/1212)
    - 시간 : [13분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/33_1212.cpp)

    <br>

    (5) [-2진수 (2089번)](https://www.acmicpc.net/problem/2089)
    - 시간 : [23분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/33_1212.cpp)
    - 좀 생각하다가 모르겠어서 바로 구글링 했다. [참고한 문서는 여기](https://jun-coding.tistory.com/195)! 음수 % 연산에서 n-1하고 연산하는 팁을 기억해야겠다.

    <br>

    (6) [골드바흐 파티션 (17103번)](https://www.acmicpc.net/problem/17103)
    - 시간 : [25분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/33_1212.cpp)
    - 에라토스테네스의 체 이용해서 미리 저장해놓고, 합 계산하는 방식을 이용함.

    <br>

3. 수학 1 (참고)

    (1) [진법 변환 2 (11005번)](https://www.acmicpc.net/problem/11005)
    - 시간 : [8분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/36_11005.cpp)

    <br>

    (2) [진법 변환 (2745번)](https://www.acmicpc.net/problem/2745)
    - 시간 : [8분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/37_2745.cpp)

    <br>

    (3) [Base Conversion (11576번)](https://www.acmicpc.net/problem/11576)
    - 시간 : [46분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/33_1212.cpp)
    - 알맞은 자료형 사용하기

    <br>

    (4) [소인수분해 (11653번)](https://www.acmicpc.net/problem/11653)
    - 시간 : [16분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/39_11653.cpp)
    - 소인수분해라 소수인지도 판별해야한다고 생각했는데 그냥 나누어떨어지면 되나보다...!

    <br>

### 다이나믹 프로그래밍

1. 다이나믹 프로그래밍 1

    (1) [1로 만들기 (1463번)](https://www.acmicpc.net/problem/1463)
    - 시간 : [12분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/40_1463.cpp)
    - 조건 꼼꼼히!

    <br>

    (2) [2xn 타일링 (11726번)](https://www.acmicpc.net/problem/11726)
    - 시간 : [31분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/41_11726.cpp)
    - base case 잘 선택하기

    <br>

    (3) [2xn 타일링 2 (11727번)](https://www.acmicpc.net/problem/11727)
    - 시간 : [8분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/42_11727.cpp)

    <br>

    (4) [1, 2, 3 더하기 (9095번)](https://www.acmicpc.net/problem/9095)
    - 시간 : [4분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/43_9095.cpp)

    <br>

    (5) [카드 구매하기 (11052번)](https://www.acmicpc.net/problem/11052)
    - 시간 : [17분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/44_11052.cpp)
    - 문제 간소화하기

    <br>

    (6) [카드 구매하기 2 (16194번)](https://www.acmicpc.net/problem/16194)
    - 시간 : [1분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/45_16194.cpp)
    - 문제가 너무 똑같아서 그냥 복붙하고 부호 하나 바꿈..

    <br>

    (7) [1, 2, 3 더하기 5 (15990번)](https://www.acmicpc.net/problem/15990)
    - 시간 : [34분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/46_15990.cpp)
    - 결과에 % 해야하는 건 구할 때도 계속 % 해야 오버플로우를 막을 수 있음

    <br>

    (8) [쉬운 계단 수 (10844번)](https://www.acmicpc.net/problem/10844)
    - 시간 : [17분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/47_10844.cpp)

    <br>

    (9) [이친수 (2193번)](https://www.acmicpc.net/problem/2193)
    - 시간 : [13분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/48_2193.cpp)

    <br>

    (10) [가장 긴 증가하는 부분 수열 (11053번)](https://www.acmicpc.net/problem/11053)
    - 시간 : [7분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/49_11053.cpp)

    <br>

    (11) [가장 긴 증가하는 부분 수열 4 (14002번)](https://www.acmicpc.net/problem/14002)
    - 시간 : [28분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/50_14002.cpp)
    - 전에 진짜 못풀었던 기억이 있는데 비교적 쉽게 해결했다. 히히

    <br>

    (12) [연속합 (1912번)](https://www.acmicpc.net/problem/1912)
    - 시간 : [9분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/51_1912.cpp)

    <br>

    (13) [제곱수의 합 (1699번)](https://www.acmicpc.net/problem/1699)
    - 시간 : [9분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/52_1699.cpp)

    <br>

    (14) [합분해 (2225번)](https://www.acmicpc.net/problem/2225)
    - 시간 : [31분](https://github.com/22000546/ProblemSolving/blob/main/problems/part1/41_11726.cpp)

    <br>


<br>
<br>