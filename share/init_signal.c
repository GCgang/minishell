#include "init.h"

/*
	전체적으로 사용할 signal을 종합적으로 정리하는 곳
	1. init_signal : signal을 적용
		1-a. cut_echo : ^C, ^D 등 ctrl 키를 입력했을 시, 터미널에 echo가 발생하는 걸 막기 위함
		1-b. sigquit_handler : ctrl_C 동작 설정
		1-c. sigint_handler : ctrl_D 동작 설정
	2. heredoc_sigint_handler : 자식 프로세스 종료를 위함
*/
static void	cut_echo(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(0, 0, &term);
}

static void	sigquit_handler(int sig)
{
	(void)sig;
	rl_redisplay();
}

static void	sigint_handler(int sig)
{
	(void)sig;
	g_exit_status = 1;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	heredoc_sigint_handler(int sig)
{
	(void)sig;
	g_exit_status = 1;
	printf("\n");
	exit(1);
}

void	init_signal(void)
{
	cut_echo();
	signal(SIGQUIT, sigquit_handler);
	signal(SIGINT, sigint_handler);
}
