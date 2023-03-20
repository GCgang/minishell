#include "../include/pars.h"

void	free_array(char **arr)
{
	int	idx;

	idx = -1;
	if (arr != 0)
	{
		while (arr[++idx] != 0)
			free(arr[idx]);
		free(arr);
	}
}
