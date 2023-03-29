# cub3D
My first RayCaster with miniLibX

- [ ] miniLibX를 사용하라. 
운영체제에서 사용할 수 있는 버전 또는 해당 소스에서 사용할 수 있다. 소스로 작업하기로 선택한 경우 Common Instructions 부분을 libft에도 적용해야 한다.
- [ ] 창의 관리가 수월하게 이루어져야 한다. 
다른 창으로 바꾸기, 최소화 등.
- [ ] 벽이 향하는 방향에 따라 텍스쳐를 다르게 표시해야 한다.
- [ ] 바닥과 천장이 다른 색으로 설정되어야 한다.
- [ ] 프로그램이 창에 표시되는 이미지는 아래의 규칙을 따라야 한다.
    - [ ] 키보드의 왼쪽과 오른쪽 키가 미로의 왼쪽과 오른쪽을 볼 수 있도록 해야 한다.
    - [ ] WASD 키로 미로를 보는 시점을 움직일 수 있어야 한다.
    - [ ] ESC를 누르면 창을 닫고 프로그램이 종료될 수 있도록 해야한다.
    - [ ] x 버튼을 누르면 창이 닫히고 프로그램이 종료되어야 한다.
    - [ ] minilibX의 이미지를 사용하는 것을 매우 권장한다.
- [ ] 프로그램의 첫 번째 인자는 미로를 묘사하는 .cub 확장자를 사용하는  파일이다.
    - 맵은 6개의 문자로 이루어져 있다.
        - 0: 빈 공간
        - 1: 벽
        - N, S, E, W: 플레이어가 소환될 때 바라보고 있는 방향
        
        ```
        111111
        100101
        101001
        1100N1
        111111
        ```
        
    - [ ] 맵은 벽으로 둘러쌓여 있어야 한다. 그렇지 않은 경우 error를 반환해야 한다.
    - [ ] 맵을 제외한 각 요소의 타입은 하나 이상의 빈 줄로 구분될 수 있다.
    - [ ] 맵은 맨 마지막에 위치해야 하며 각 요소의 타입은 파일의 어느 위치에 올 수 있다.
    - [ ] 맵을 제외하고 각 요소의 정보들은 1개 이상의 space가 올 수 있다.
    - [ ] 파일에서 보이는 대로 파싱이 되어야 한다. 맵의 공백은 유효한 부분이다. 규칙을 준수하는 모든 종류의 맵을 파싱할 수 있어야 한다.
- [ ] 각  요소의 첫 번째 정보는 타입의 설명자이다. `[type identifiler]: specific informations`
    
    North texture:
    
    `NO` `./path_to_the_north_texture`
    
    South texture:
    
    `SO` `./path_to_the_south_texture`
    
    West texture:
    
    `WE` `./path_to_the_west_texture`
    
    East texture:
    
    `EA` `./path_to_the_east_texture`
    
    Floor color:
    
    `F` `220,100,0` → R,G,B colors in range [0,255]: 0, 255, 255
    
    Ceiling color:
    `C` `225,30,0`
    
- 유효한 맵
    
   <img width="1000" alt="image" src="https://user-images.githubusercontent.com/99523863/228504677-603ca193-29c0-420b-b3b0-11d96d862e6d.png">
    
    유효하지 않은 맵은 `Error\n` 을 출력하고, 종료. 에러메시지를 추가해도 된다.
