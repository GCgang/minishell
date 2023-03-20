# minishell

1. 구조체 설명

typedef struct s_token
{
	char			type;
	char			*val;
	char			*quote;
	struct s_token	*next;
}	t_token;

파싱한 내용물을 유형에 따라 별도로 담기 위한 구조체
1. type : 토큰의 유형을 나타냄
	1-a. 'r' : redirection
	1-b. 'p' : pipe
	1-c. 'w' : word
	1-d. 'h' : "<<" 다음에 위치한 word 토큰. heredoc.
		1-d-a. 'H' : 따옴표를 별도로 제거한 word 토큰. 
	1-e. 'v' : "<<"를 제외한 다른 redirection 뒤에 위치한 word 토큰. volume.
	1-f. 't' : 아직 분류되지 않은 메타문자. temp.
	1-g. 'b' : 쓸데없는 공백. 지울 예정. blank.
2. val : 각 토큰의 실제값
3. quote : val에서 인용부호와 환경변수의 위치를 가늠하기 위한 것. 각 idx에 위치한 값에서 1은 인용부호, 2는 환경변수를 의미.
4. 위 token은 parsing 부분에서만 사용한다

typedef struct	s_env
{
	char			*name;
	char			*val;
	char			mean;
	int				status;
	struct s_env	*next;
}	t_env;

envp로 받은 환경변수 내용물을 정리하기 위한 것
1. name : 각 환경변수에서 '=' 기준 좌변에 해당
2. val : 각 환경변수에서 '=' 기준 우변에 해당
3. mean : 각 환경변수가 무슨 의미인지 확인하기 위한 용도
	3-a. 'e' : 일반 환경변수
	3-b. 'c' : main 무한 반복문 탈출을 위한 조건 검사 용도
4. status : 환경변수의 상태를 나타내기 위한 용도
5. 위 env는 실행부로 넘겨주는 구조체 중 하나

typedef struct s_command
{
	int		order;
	char	**word;
	char	*path;
	int		path_err;
	char	*oper;
	char	*oper_val;
	char	val_type;
	char	builtin;
	int		std_in;
	int		std_out;
	int		std_err;
	int		std_in_dup1;
	int		std_out_dup1;
	int		pipe;
	int		pipe_in;
	int		pipe_out;
	int		pipe_in_dup1;
	int		pipe_out_dup1;
	struct s_command	*next;
}	t_command;

token과 env를 정리하여 파이프 또는 메타 문자 기준으로 내용물을 정리하기 위한 구조체
1. order : command 순서
2. word : 'w'에 해당하는 토큰만 순서대로 모아 놓는다
3. path : 경로값을 집어넣는다
4. path_error : 경로가 불분명하거나 어떠한 문제가 발생했을 경우 1로 값을 변경
5. oper : 파이프 기준으로 잘랐을 때, 가장 앞에 위치한 토큰
6. oper_val : oper 다음에 위치한 토큰값
7. val_type : oper_val의 유형
8. builtin : builtin 존재 여부. 존재할 시, builtin의 첫 자만 따온다
9. std_in : 표준입력값으로 0으로 초기화됨. 단, oper값이 '<'인 경우 그 다음에 위치한 토큰의 fd값을 저장
10. std_out : 표준출력값으로 1으로 초기화됨. 단, oper값이 >이거나 또는 >>이면 그 다음에 위치한 토큰의 fd 값을 저장
11. std_err : 표준에러값으로 2로 초기화
12. pipe : 파이프 유무 검사. 있으면 1.
13. pipe_in : 파이프 입구 fd값
14. pipe_out : 파이프 출구 fd값