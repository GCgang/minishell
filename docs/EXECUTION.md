## Execution Flow

### 1. 리다이렉션 처리

- `>`, `>>`, `<`, `<<` 등의 리다이렉션을 처리.

### 2. 명령어 처리

- 부모 프로세스에서 명령어 처리
  - 만약 파이프가 없는 단일 명령어이고, 그 명령어가 `cd`, `echo`, `pwd`, `export`, `unset`, `env`, `exit`와 같은 내장 명령어인 경우 입출력 처리 후 명령어 실행
- 자식 프로세스에서 명령어 처리
  - 위의 경우가 아닌경우 입출력 처리 후 명령어 실행

### 3. 종료 및 대기

- 자식 프로세스에서는 명령어 실행 후 exit(g_exit_status)로 종료
- 부모 프로세스는 자식 프로세스의 종료를 대기한다.