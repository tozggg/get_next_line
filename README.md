# get_next_line
[subject](https://github.com/tozggg/get_next_line/blob/master/subject.pdf)  
fd(file descriptor)로 파일을 읽어서 개행까지 반환하는 프로그램 만들기  
읽은 위치는 static으로 저장되고 반복호출시 다음 개행까지 반환한다
<br>
<br>
## Details
### 전역변수와 *정적변수

- 전역은 global  //  정적은 static
- lifetime 은 동일 ( 프로그램이 죽을때까지 유지 )
- ! scope 가 다르다
    
    ⇒ a파일에서 선언된 static변수는 a파일에서만 접근가능
    

### static

- 전역변수는 함수외부에서 static 안붙이고 선언
- 정적변수는 static붙이고 함수 외부 // 내부

### read  함수

```c
#include <unistd.h>

ssize_t read(int fd, void *buf, size_t nbtyes);
```

- fd           읽을 파일의 파일 디스크럽터
- buf         데이터를 저장할 버퍼
- nbytes   읽어들일 데이터의 최대 길이 ( buf 의 길이보다 길어서는 안됨 )
- 반환값;    읽어들인 데이터의 길이 (중간에 끝난다면 nbytes보다 작을수 있음)

### lseek 함수

```c
#include <sys/types.h>
#include <unistd.h>

off_t lseek(int fd, off_t offset, int whence);
```

- fd            open 또는 creat를 통하여 얻은 file descriptor
- offset     whence로 부터 이동할 상대위치 ( + - )
- whence  기준위치
    - SEEK_SET  :  파일의 맨 처음
    - SEEK_CUR :  현재의 위치
    - SEEK_END :  파일의 맨 끝
- 반환값;    함수를 수행한 이후에 새로운 offset, 실패 시 -1
- ! lseek을 사용해 파일의 끝보다 뒤에서 쓰기작업시 hole생성 ( 0으로 채워짐 )

### 파일디스크럽터 (fd)

- 0 표준입력
- 1 표준출력
- 2 표준에러
- ~OPEN_MAX (환경에서 열수있는 최대파일수)

### gcc -D

```bash
# 외부에서 name에 해당하는 #define을 지정 
gcc -D [name]

# 외부에서 name정의하고 값을 def로 지정
gcc -D [name] = def
```

### EOF

- End Of File ( 더이상 데이터가 없음 )
    
    ⇒ 파일의 끝
    

### 댕글링 포인터

- 여전히 해제된 메모리 영역을 가리키고 있다면 댕글링 포인터

---

- stdlib.h ⇒ malloc , free
- unistd.h ⇒ read
- OPEN_MAX 는 원래 limits.h 헤더 추가하기  /  안되면 헤더에 직접 입력하자
- strjoin에서 free(s1)한거 기억하기
- read_ing ⇒ ( read 아직 안끝남 )  /  backup에 저장하는 함수
- read_end ⇒ ( read 끝났음 )  /  알아서 하는 함수

### 궁금한점

- read함수 offset이 저장되는거 확실

- \n 까지 line에 넣는것인가

- main에서 printf 왜 line 주소로 하냐

- strjoin 실패시 에외처리 해야하나

- 예외처리 line에 넣을자리가 없을때

- reading 함수에서 남은 backup 에 \n 뒤에 아무것도 없으면 따로 빼야하나

- free ( backup / buf ) 할때 free 한후 0 삽입해야 하나

- 1로 한번 더 넘겨도 되나?

- strdup("") 의 의미

### 추가사항

- backup (보너스)

- buf의 배열(정적)과 malloc(동적) 할당의 차이

- ft_free를 만든 이유

- if (*backup)의 의미

