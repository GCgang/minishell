# minishell

1. pars 흐름
	가. 단어와 단어를 구분해주는 metacharacter 및 기본 구분자(space, newline, tab)를 spe 집합에 넣는다.
	나. 따옴표(' 또는 ")가 닫혀있는지 여부 확인. 
		나-1. 닫혀있으면 다 항으로 진행
		나-2. 닫혀있지 않으면 printf : syntax_err, exit_status = 2, main loop로 복귀
	다. make token : 따옴표(', ") 기준으로 token을 분리하고 따옴표가 없으면 한 자 씩 분류. special 문자에 속하면 't', 문자가 '$'면 'e', 그 외는 'w'로 분류
	라. mix token : phase를 0과 1로 분리. 0일 시에는 e + w, t + t 조합만 토큰 내용물을 합친다. 1은 w + w 조합도 추가
		라-1. e + w는 w가 따옴표로 구성된 경우 합치지 않으며 추후 환경변수 변환 후에 토큰의 종류가 'w'로 변환했을 시, phase 1에서 w + w 조합 시에 합친다. 
		라-2. t + t는 < + < 또는 > + > 인 경우에만 합친다.
		라-3. w + w는 phase 1에서만 수행하며 별도 조건 없이 바로 합친다.
	마. rotate env token : mix token이 phase 1로 넘어가기 전에 실행. 토큰을 순회하며 heredoc 용 토큰과 env 토큰, 큰 따옴표 토큰을 별도 분류한다.
		마-1. heredoc 뒤에 오는 토큰은 유형이 't'가 아닐 시에 'w'로 취급한다.
		마-2. 토큰 유형이 'e'거나 큰 따옴표 토큰인 경우, 내부에 변환할 환경변수가 있는 지 검색하고, 해당 토큰들 유형을 일괄 'w'로 변환
	바. env search : 토큰의 value 값을 확인하여 환경변수 존재 시, 환경변수 값을 변환하여 돌려준다.
		바-1. loca : loca[0]은 $가 시작되는 지점, loca[1]은 loca[0]에서 시작하여 구분자를 만나는 지점, loca[2]는 $가 변환 시, 삽입할 내용물의 길이.
		바-2. is env : env search에서 token->val 순회 시, $를 발견한 경우, 변환값을 만들고 그 값을 집어 넣는다.
			바-2-가. 최초는 $ expansion 값이 있는 지 검사. 없으면 구분자를 만날 때까지 loca[1] 값을 늘려준다
			바-2-나. 환경변수의 이름을 잘라서 별도의 문자열 포인터를 만들고 기존 환경변수 목록에서 동일한 값이 있는 지 확인한다
			바-2-다. 있으면 환경변수의 내용물을 복사하고, 없으면 확인하기 위해 별도의 파싱을 시도한다.
				바-2-다-1. 값이 subject에서 명시한 $?인 경우, exit_status 값을 복사한다.
				바-2-다-2. 단순 리터럴인 경우, "$"로 복사.
				바-2-다-3. 어느 쪽도 소속되지 않은 경우, 제거하기 위해 빈 문자열로 만들어준다.
		바-3. trans env token : 변환된 환경변수 값을 token에 적용
			바-3-가. non quote $ 리터럴 다음에 \", \'가 오는 경우 $는 제거한다
			바-3-나. 환경변수 길이를 측정하여 loca[2]에 넣는다.
			바-3-다. 환경변수를 token->val에 합쳐서 반영
		바-4. trim env token : non quote이고 token->val 내부 값이 존재하면 IFS 적용
			바-4-가. setting_ifs : IFS 디폴트 값을 설정
			바-4-나. env_list를 순회하며 IFS가 있을 시 해당 값으로 IFS를 변경
			바-4-다. search_token : 환경변수 길이 내에서 IFS를 만난 경우 token을 분할
				바-4-다-1. IFS 기준으로 token을 분할하여 token->val (IFS 만나기 전까지), token->next->val (IFS), token->next->next->val (IFS 만난 후 나머지) 세 부분으로 연결한다
				바-4-다-2. 만약 IFS가 default인 경우, 별도의 빈 문자열 출력 없이 제거해야 하기 때문에 전부 type을 t로 변경
				바-4-다-3. trim token은 마지막 빈 문자열 토큰이 'w'로 나오면 삭제해 줄 수 있게 't'로 바꿔준다.
	사. trim token : "", space, tab, newline 등. word와 word를 구분하던 seperator 토큰을 제거한다
		사-1. 최초에 잘라야 하는 토큰이 연속으로 나오는 경우 계속 제거해준다
		사-2. 현재 토큰 기준 다음 토큰이 제거 대상이면 제거하고 제거 대상이 아닐 경우에만 다음 토큰으로 넘어간다.
	아. chk oper token : 기존에 분리한 metacharacter에서 subject에서 언급한 redirection, pipe를 찾고 별도 분류한 뒤, 나머지 meta token은 syntax err로 처리
		아-1. 만약, token의 첫 시작이 빈 문자열인 경우 탈출한다
	자. removing quote : 각 토큰에서 닫힌 quote들을 찾아 제거해준다
		아-1. 토큰 내용물을 순회하면서 작은 또는 큰 따옴표를 만나는 경우, 닫힌 따옴표가 있는지 확인
			아-1-가. 닫힌 따옴표가 없으면 해당 따옴표는 단순한 리터럴로 취급
			아-1-나. 닫힌 따옴표가 있으면 세트로 '1'로 표기하여 추후 제거할 때 표식으로 사용
		아-2. remove quote : redirection이 아닌 경우, quote를 순회하며 quote에서 1이 있는 위치를 기준으로 strjoin으로 quote를 제거한 내용물을 합쳐준다
	차. make com : 토큰의 내용물을 pipe 기준으로 만든 command 구조체에 옮겨 담는다
		자-1. init_command : command 구조체 초기화
		자-2. word_cnt : token->type == 'w'인 토큰만 별도 분류하여 word에 넣는다
			자-2-가. 왜 word에 따로 담는가? bash 해석 기준이 heredoc(<<. >>), redireciton(<, >), word 순이기 때문이다.
		자-3. pars_com : token->type == 'r'는 com->redir, token->type == 'h'는 com->redir_val에 순서대로 넣어준다.
		자-4. chk_pipe : pipe를 만나면 pipe가 있다고 command 구조체에 flag를 올려주고 새로운 커맨드 구조체를 만들어 연결한다
		자-5. record builtin : com->word[0]가 builtin인지 확인하고 builtin인 경우, export와 env를 제외한 나머지 builtin만 소문자로 일괄 변경해준다
		자-6. record path : env list에서 PATH가 있으면 내용물을 : 기준으로 split하여 보기 좋게 각 com의 path에 담아준다

2. signal 흐름
	가. init_signal : 최초로 적용하는 시그널
		가-1. SIGQUIT : 해당 신호는 bash에서 기본적으로 무시하므로 SIG_IGN 처리
		가-2 .SIGINT : 해당 신호를 받으면 현재 활동이 종료되고 다음 입력을 받아야 한다
				그렇기에 printf("\n")으로 다음 줄로 이동한 뒤, rl_on_new_line을 통해 현재 라인에서 프롬프트를 출력할 거라는 신호를 주고 rl_replace_line으로 기존에 입력한 readline_buf를 빈 문자열로 바꿔주고 buf 포함하여 다시 readline을 출력하고 입력을 받는다
	나. exec_signal : 실행 파트에서 적용하는 시그널
		나-1. parent
			나-1-가. 자식이 종료될 경우 다음 입력을 받아야 하기에 부모에서 신호가 열려있으면 자식이 끝나도 부모에서 계속 신호를 기다린다. 그렇기에 부모 쪽은 일괄적으로 SIGINT, SIGQUIT 신호를 무시한다
			나-1-나. 본 minishell에서 heredoc은 부모에서 실행하기에 자식처럼 종료되는 경우, minishell 프로그램 자체가 종료될 위험이 있다. 그래서 SIGINT는 close를 통해 표준 입력을 막아서 EOF로 heredoc만 종료시키고 바로 표준 입력 부분을 다시 열어서 입력을 받게 한다.
			나-1-다. SIGQUIT 신호는 받으면 안되므로 heredoc에서는 무시한다.
		나-2. child
			나-2-가. 자식은 sigint는 개행과 함께 종료되고 sigquit는 Quit: 3를 출력하고 종료