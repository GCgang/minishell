#include <unistd.h>
#include <stdio.h>
int	main()
{
	char	*path;
	int		ret;

	path = getcwd(NULL, 1024);
	printf("%s\n", path);
	chdir("..");
	path = getcwd(NULL, 1024);
	printf("%s\n", path);
}