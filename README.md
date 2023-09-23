# CG_project
### 2021-1 GE Project (2021년도 3학년 1학기 컴퓨터그래픽스 프로젝트)

# 게임 소개
### OpenGL을 이용해 제작한 공튀기기 게임입니다.

<img src="https://github.com/nunnunnana/CG_project/assets/99165741/5c86c58c-7487-40f7-b608-9903aa0ca437.png" width="600" height="400"/>

![CG_플레이영상](https://github.com/nunnunnana/CG_project/assets/99165741/98ff86df-d10f-4698-a2b6-795b8ab66c6f)

# 조작법
화살표 키보드 또는 마우스를 이용해 막대바를 움직일 수 있습니다.

---

## 제작과정

### Ball 오브젝트 생성
- Ball  클래스 생성 
  - Ball 클래스에는 x, y 좌표 x, y축 속도와 반지름 변수를 갖고 있음
https://github.com/nunnunnana/CG_project/blob/83384999202627e5ff8fad7917312b94847054c2/bouncing_ball/bouncing_ball/Ball.h#L4-L12

- createBall 함수 생성
  - Ball의 좌표와 속도, 반지름을 설정함
https://github.com/nunnunnana/CG_project/blob/83384999202627e5ff8fad7917312b94847054c2/bouncing_ball/bouncing_ball/Mesh.cpp#L16-L22

- 공 그리기
  - GL_TRIANGLE_FAN 사용 
  - 삼각함수를 사용해 Ball 생성
https://github.com/nunnunnana/CG_project/blob/83384999202627e5ff8fad7917312b94847054c2/bouncing_ball/bouncing_ball/Mesh.cpp#L70-L77


### 이동 및 충돌처리
- 윈도우 너비와 높이는 800, 600으로 설정
https://github.com/nunnunnana/CG_project/blob/83384999202627e5ff8fad7917312b94847054c2/bouncing_ball/bouncing_ball/main.cpp#L54

- 공이 벽에 닿았을 경우 충돌처리

<img src="https://github.com/nunnunnana/CG_project/assets/99165741/3ab52bbe-a6ad-4f24-b39b-65018fd0baf8.png" width="200" height="200"/>

  - 공의 x, y 좌표에 speed_x, y를 더해서 공을 이동시킴
  - 공이 벽에 충돌했을 때 진행 방향의 -1을 곱해서 반대로 방향을 전환함
https://github.com/nunnunnana/CG_project/blob/83384999202627e5ff8fad7917312b94847054c2/bouncing_ball/bouncing_ball/Mesh.cpp#L83-L90


### Bar 오브젝트 생성
- Bar 클래스 생성
  - Bar 클래스에는 x, y 좌표 너비 높이를 지정할 수 있는 변수 선언
https://github.com/nunnunnana/CG_project/blob/83384999202627e5ff8fad7917312b94847054c2/bouncing_ball/bouncing_ball/Bar.h#L4-L11

- createBar 함수 생성
  - Bar의 좌표와 가로, 세로 길이를 설정함
https://github.com/nunnunnana/CG_project/blob/83384999202627e5ff8fad7917312b94847054c2/bouncing_ball/bouncing_ball/Mesh.cpp#L24-L29

- drawBar 함수 생성
  - 색상을 정하고 4개의 정점을 통해 사각형을 그림
https://github.com/nunnunnana/CG_project/blob/83384999202627e5ff8fad7917312b94847054c2/bouncing_ball/bouncing_ball/Mesh.cpp#L139-L143

### Bar 오브젝트 충돌
- 공이 Bar에 충돌 했을 때
  - 첫 번째 조건문이 실행되려면 Bar 너비 길이에 공이 진입했을 때
    
    <img src="https://github.com/nunnunnana/CG_project/assets/99165741/d7232552-e537-4907-a05a-4d37050ad02d.png" width="200" height="200"/>

  - 두 번째 조건문은 공 y 좌표 – Bar y 좌표가 0과 -5 사이일 때
    
    <img src="https://github.com/nunnunnana/CG_project/assets/99165741/ce891f70-1da0-4a9d-bb15-584bc6127190.png" width="200" height="150"/>
    
https://github.com/nunnunnana/CG_project/blob/83384999202627e5ff8fad7917312b94847054c2/bouncing_ball/bouncing_ball/Mesh.cpp#L92-L98


### Bar 오브젝트 이동
- 키보드 이동
  - 방향키로 Bar를 20씩 이동
https://github.com/nunnunnana/CG_project/blob/83384999202627e5ff8fad7917312b94847054c2/bouncing_ball/bouncing_ball/Mesh.cpp#L154-L172

- 마우스 이동
  - 마우스의 x 좌표를 Bar의 x 좌표로 설정
https://github.com/nunnunnana/CG_project/blob/83384999202627e5ff8fad7917312b94847054c2/bouncing_ball/bouncing_ball/Mesh.cpp#L174-L179


### Block 오브젝트 생성
- Block 클래스 생성
  - Block 클래스에는 x, y 좌표 너비, 높이, 색상을 지정할 수 있는 변수 선언
https://github.com/nunnunnana/CG_project/blob/ccd2300536608527bd1cbcd78b9c6a2365eaf5f1/bouncing_ball/bouncing_ball/Block.h#L4-L14

- createBlock 함수 생성
  - Block은 여러 개 생성해야 하기 때문에 반복문을 사용해 좌표, 가로, 세로 길이를 설정
  - R, G, B 값을 설정해 한 줄 씩 색상을 다르게 출력
https://github.com/nunnunnana/CG_project/blob/ccd2300536608527bd1cbcd78b9c6a2365eaf5f1/bouncing_ball/bouncing_ball/Mesh.cpp#L31-L60

- drawBlock 함수 생성
  - 여러개 생성하기 위해서 iterator 정의
https://github.com/nunnunnana/CG_project/blob/ccd2300536608527bd1cbcd78b9c6a2365eaf5f1/bouncing_ball/bouncing_ball/Mesh.cpp#L145-L152


### Block 오브젝트 충돌
- 공이 Block의 측면에 충돌했을 때
  - 첫 번째 조건문이 실행되려면 Block 높이 길이에 공이 진입했을 때

    <img src="https://github.com/nunnunnana/CG_project/assets/99165741/6c0594d8-29c0-4ca3-a72c-9f004ae6e3d9.png" width="250" height="200"/>

  - 두 번째 조건문은 공 x 좌표 – Block x 좌표 – 블록의 길이가 0과 5 사이일 때, 공 x 좌표 – Block x 좌표가 0과 -5 사이일 때
    
    <img src="https://github.com/nunnunnana/CG_project/assets/99165741/6b1e3a86-d8f6-4915-b45b-4a16aacf1af9.png" width="250" height="150"/>
    <img src="https://github.com/nunnunnana/CG_project/assets/99165741/555160ba-7aee-4e8a-8390-d5d6df45aa5f.png" width="250" height="150"/>

https://github.com/nunnunnana/CG_project/blob/ccd2300536608527bd1cbcd78b9c6a2365eaf5f1/bouncing_ball/bouncing_ball/Mesh.cpp#L99-L117

- 공이 Block의 윗면 또는 아랫면에 충돌했을 때
  - 첫 번째 조건문이 실행되려면 Block 너비 길이에 공이 진입했을 때

    <img src="https://github.com/nunnunnana/CG_project/assets/99165741/3e4b257b-ce17-4565-9536-b3424a5492e1.png" width="250" height="200"/>

  - 두 번째 조건문은 공 y 좌표 – Block y 좌표 – Block 높이가 0과 5 사이일 때, 공 y 좌표 – Block y 좌표 – Block 높이가 0과 -5 사이일 때

    <img src="https://github.com/nunnunnana/CG_project/assets/99165741/a4b9a85e-ac97-45b0-a9c5-e65875c333bf.png" width="250" height="200"/>
    <img src="https://github.com/nunnunnana/CG_project/assets/99165741/cfbafa34-e25e-4087-a49b-7f35194b854e.png" width="250" height="200"/>

https://github.com/nunnunnana/CG_project/blob/ccd2300536608527bd1cbcd78b9c6a2365eaf5f1/bouncing_ball/bouncing_ball/Mesh.cpp#L119-L135
