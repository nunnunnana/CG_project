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
    
    ![image](https://github.com/nunnunnana/CG_project/assets/99165741/d7232552-e537-4907-a05a-4d37050ad02d)

  - 두 번째 조건문은 공 y 좌표 – Bar y 좌표가 0과 -5 사이일 때
    
    ![image](https://github.com/nunnunnana/CG_project/assets/99165741/ce891f70-1da0-4a9d-bb15-584bc6127190)

https://github.com/nunnunnana/CG_project/blob/83384999202627e5ff8fad7917312b94847054c2/bouncing_ball/bouncing_ball/Mesh.cpp#L92-L98C4


### Bar 오브젝트 이동

### Block 오브젝트 생성

### Block 오브젝트 충돌
