# 삼성 SW 역량테스트 준비

## [SWEA 모의 SW 역량테스트](https://swexpertacademy.com/main/code/problem/problemList.do)

(1) 보물상자 비밀번호 (5658번)
- [시간 : 45분](../problems/part4/5658.cpp)
- 구현 문제
    - 보물 상자의 뚜껑은 시계방향으로 돌릴 수 있고, 한 번 돌릴 때마다 숫자가 시계방향으로 한 칸씩 회전한다.
        - 회전 구현 : 앞 자리를 뒤로 더해주고 substr 하는 방식 사용
        - 숨겨진 조건 : 뚜껑은 사각형이라는 조건을 예시와 n은 4의 배수라는 조건을 통해 확인해야 함
    - 보물 상자에 적힌 16진수 숫자(0~F)로 만들 수 있는 모든 수 중, K번째로 큰 수를 10진수로 만든 수이다. 크기 순서를 셀 때 같은 수를 중복으로 세지 않도록 주의한다.
        - 16진수 수 : map을 이용해 string으로 처리하고, 최종 선택된 한 숫자에 대해 pow()를 이용해 계산함
        - 크기 + 중복 조건 : set을 이용해 둘 다 처리함. set은 기본적으로 less<> 정렬이기 때문에 첫 정의 때 두 번째 파라미터에 greater<>을 해줘야 내림차순이 됨
    - etc
        - set에서 n번째 수를 찾는 방법은 iterator와 변수 하나를 이용해서 찾는 방법 말고 없음 !!!


## [코드트리 삼성 SW 역량테스트 기출문제](https://www.codetree.ai/training-field/frequent-problems)

(1) 포탑 부수기 (삼성 SW 역량테스트 2023 상반기 오전 1번 문제)
- [시간 : 133분](../problems/part4/1.cpp)
- 구현 + BFS 문제
    - 애매했던 포인트
        - M x N 격자라는 표현이 좀 애매했음
        - 행과 열의 표현이 헷갈렸음
        - 벡터에서 삭제 : `v.erase(remove(v.begin(), v.end(), target), v.end());`
            - v.end()를 해주면 target과 같은 값을 가지는 모든 요소를 삭제할 수 있음
    - 공격자 / 공격대상자 선정
        - sort 함수를 이용해서 구현
    - 공격 방식 결정 : BFS
        - BFS 수행할 때 큐에 넣는 순서에 따라 경로의 우선순위를 구현할 수 있음
        - 경로를 기억해야 할 때는 각 노드의 부모 노드를 저장해둔 뒤 리스트를 따라가면 됨
    - 유의사항
        - 공격 시 공격 대상자는 포함하면 안 된다는 조건