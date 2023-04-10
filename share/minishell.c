/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehjoo <jaehjoo@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:57:22 by jaehjoo           #+#    #+#             */
/*   Updated: 2023/04/10 20:05:30 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

//static void	introduce_before(void)
//{
//printf("░░░¡''''  ~ ' ^  '                                                             '\n");
//printf("░░┐░»v»     .                                                                  '\n");
//printf("∩░┌:∩║        '''     ,>¬^^`   .` .                                            '\n");
//printf("░░!░∩▐ ⌐'    '     -         '⌐ò  -  -.                                        '\n");
//printf("░"▒░ΓL,∩'      ,'     ,.  S`lp/~+»¼~|\\√ƒ                                      .¡\n");
//printf("░░▒░Γ╓▒Ü░-∩.,*     ¿+τ¬▓▓Æp▒▓▓▓Γ".^─┘⌐╔U\\,                        ''  '       '│\n");
//printf("░░╠░¼▒░░░░y`      2▄▓╣▓▌█▓▓█▓▓▓▓▌,▄| \\^⌐  /n¬L                    " '  .'  ''.''\n");
//printf("░░╚░░░░░│^        L▓▓▓█▓▓█▓▓▓▓▓███▄`¬,"░g-|  ¡≈                    '''''' ' ''''\n");
//printf("≤w⌂░░▄╧`     .     └L└L╣▓█╫▓╣▓▓▓▓▀Σ⌐,/}7Γ ^(┐                                  '\n");
//printf("▓▓╩▀L    .>;(Γ    lön─L▌╝╚▓▓▓▓█▓╜    ⁿ | <W')J[                                ,\n");
//printf("' ;∩;J,,,░' ^║▐─╘ ┐⌐╓ ^,:`L╥╩▓▓▓          `|`\n");
//printf(".'╔ê░░é░▀▓▓▓Γ'fφù⌐╟▓▄▓▓▄▄,"╝▓▓█╬                                           '   .\n");
//printf(":Å⌂ÅÆ▒╓qL▄╫▓▓└hƒ┐┌⌐ v⌠▀▓▓▓╬▓▓▓▀▌⌐                                        .    ,Q\n");
//printf("ïû▌▓┴╢▓▓▌▓╣▓▌╞▓▌╣▓▒¡X╫▓▓▓▓▓▀▓╬▓▓▀~..                          .,,,,,░╓░dL   ¬⌐╗▓\n");
//printf("#Çwú│░╜╝▀╬▓▓╬▓▓▓▓▓▓▓▓▓▓▓▓▀    'L▓▓▒░░░░≥░░░»ⁿ≥∩░░≥≥»░░;░░░░░≥▒▒▒▒▒╩▒╣╬"     ^4▓▓\n");
//printf("░è▒9░ `╠╠;╝L╣╣▓▓▓▓▓▓╣▓▌`         ╜▓▓▒▒╢╬╠╠╠▒╠╠╠╬╬╠╬Å╬╠╠╠╠╬╬╬╬╬╬╬╣▀╬╩Γ    ▐▄▓▓▓▓▓\n");
//printf("░j▓▌▀▌▓▓▒▒▒#┤n∩╩╚▒╚▀L└     ⌐'     U└L╨╝╬╣╣╣╬╬╬╬╬╝└  L╬╬╣╬╬╬╬╬╬╩╜▒╜  ^,¬╠▓╣▓╝▀L^\n");
//printf("  ╚▓▓▓▓▓▓▓▒ΣΣ╢"╩▀└    .  ┐.\\w - .   ,» └L╬╣╬╬╢╠>φ▌▄╓▄╓,╠╢╨TLµ⌐`- ┌ ▄ç▄╝╨Γ;@▀Γ\n");
//printf("'   '└└.       ░░,  . ƒ.⌐ ~,  v ~▄¬  ░▐ç ▄,└L▀▀▀▀Φ▓▀╩╝╨╨LL,.µç\\╝▀LΓ. ╓▄╗╝L '..▄φ\n");
//printf("  ¡!░;.   ∩⌐   "¢"t  ' ".   ,░ ╟▌▒▀╒░ç└╚▓J▓▄L▓▄                 7▀▀▀▀▀╩.'▄▄▄▓▓▓╣\n");
//printf("┌.~ '.7▒Ç/",▓▒⌂┐ⁿ∩"┌.┐ .─┐1⌐┘ƒ¬ ▓▓▓▄L╫WNµLL▓▓▓╟▓▄ç.`x▄µ`~▄▒▀Φφ╬▓▓▓▓▀L ~.~;▄▄▄▓▓▓\n");
//printf("! ▄▓▓▒▓╣▓▓▓▓▓L┬Γ^J∩ï'¬`J⌂▐▄╔▄"µ .╫▓▓▓▒▒▒▒╩╫▒K╩╠▀╝▓▓▓╗▄╠▀▓▓╣╣▓╣▓▌╨└  '"▀▀▀▀L▄▄╣φ▓\n");
//printf(";▓▓▓▓╫▓▓▓▓▓▒▒▓▓╫▓▓▄'┴ Γ'  ▀▀▌▓y╗∩ L▀▓▓▓▓▒▒L░L╩▒⌂░│░░│││L╩▒╬▀╨└.,,,║▓▓▓▓▓▓▓╩╝╝▓▓▓\n");
//printf("¡██▓▓▓▓▓▓██▓▓▓█▓█▓█∩.╓╩▓b╓╣▒Θ╬▓▓█▄µ, L▀╝█▓▓▓▄▄▄▄▄▄▄m═²^`   ▀▀▓▓▓▓▀▀▀L,┐»...;≥≥-;\n");
//}

static void	introduce_before(void)
{
	printf("   \033[1;31m/\\                                                        /\\\n\033[0m");
	printf("  \033[1;33m|  |                                                      |  |\n");
	printf(" /----\\                by heyoan, jaehjoo");
	printf("                  /----\\\n");
	printf("[______]              ");
	printf("welcome minishell castle            [______]\n");
	printf(" |    |         _____            ");
	printf("            _____         |    |\n");
	printf(" |[]  |        [     ]                      ");
	printf("[     ]        |  []|\n");
	printf(" |    |       [_______][ ][ ][ ][][ ][ ][ ][_______]");
	printf("       |    |\n");
}

static void	introduce_after(void)
{
	printf(" |    [ ][ ][ ]|     |  ,----------------,  |");
	printf("     |[ ][ ][ ]    |\n");
	printf(" |             |     |/'    ____  ____    '\\|     |");
	printf("             |\n");
	printf("  \\  []        |     |    /'    ||    '\\    ");
	printf("|     |        []  /\n");
	printf("   |      []   |     |   |o     ||     o|   |     |  []       |\n");
	printf("   |           |  _  |   |     _||_     |   |  _  |           |\n");
	printf("   |   []      | (_) |   |    (_||_)    |   | (_) |       []  |\n");
	printf("   |           |     |   |     (||)     |   |     |           |\n");
	printf("   |           |     |   |      ||      |   |     |           |\n");
	printf(" /''           |     |   |o     ||     o|   |     |");
	printf("           ''\\\n");
	printf("[_____________[_______]--'------''------'--[_______]");
	printf("_____________]\n\033[0m");
}

static int	init_chk(int ac, char **envp, t_env **env_list)
{
	if (ac > 1)
		return (err_msg("Error : You don't need to insert argument", 1, 0));
	init_signal();
	if (init_env(envp, env_list) == 1)
		return (err_msg("Error : Malloc failed(init_env)", 1, 0));
	introduce_before();
	introduce_after();
	return (0);
}

int	main(int ac, char **av, char**envp)
{
	char	*line;
	t_env	*env_list;
	t_token	*tokens;

	(void)av;
	if (init_chk(ac, envp, &env_list) != 0)
		return (0);
	while (1)
	{
		line = readline("Minishell$ ");
		if (!line)
		{
			printf("exit\n");
			break ;
		}
		if (*line != 0)
			add_history(line);
		pars_line(line, &tokens, &env_list, envp);
	}
	clear_all(0, &env_list, 0);
	return (0);
}
