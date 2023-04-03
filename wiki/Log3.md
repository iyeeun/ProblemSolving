# SQL 연습

## [프로그래머스 SQL 고득점 Kit](https://school.programmers.co.kr/learn/challenges?tab=sql_practice_kit)

### SELECT
1. [3월에 태어난 여성 회원 목록 출력하기](https://school.programmers.co.kr/learn/courses/30/lessons/131120)
    ```
    -- MySQL
    SELECT MEMBER_ID, MEMBER_NAME, GENDER, LEFT(DATE_OF_BIRTH, 10) AS DATE_OF_BIRTH FROM MEMBER_PROFILE WHERE GENDER = 'W' AND DATE_OF_BIRTH LIKE '%-03-%' AND TLNO IS NOT NULL ORDER BY MEMBER_ID;
    
    -- Oracle
    SELECT MEMBER_ID, MEMBER_NAME, GENDER, TO_CHAR(DATE_OF_BIRTH, 'YYYY-MM-DD') AS DATE_OF_BIRTH FROM MEMBER_PROFILE WHERE GENDER = 'W' AND TO_CHAR(DATE_OF_BIRTH, 'MM') = '03' AND TLNO IS NOT NULL ORDER BY MEMBER_ID;
    ```
- 형식이 정해져있기 때문에 그냥 ```LEFT(str, len)```를 써서 잘랐는데, Oracle에서는 지원을 안하기도 하고 형식에 맞게 출력해야 하기 때문에 ```date_format(datetime, '%Y-%m-%d')```을 쓰는 것이 좋을듯
- Oracle에서는 ```TO_CHAR(date, 'format')```