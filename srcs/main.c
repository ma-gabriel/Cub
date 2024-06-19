#include <stdbool.h>
#include <fcntl.h>
#include "libft.h"

bool check_arg(int argc, char *map)
{
	int	fd;

	if (argc == 1)
	{
		write(2, "Error\nWe need a map as an argument\n", 36);
		return (false);
	}
	if (argc > 2)
	{
		write(2, "Error\nWe only take one argument\n", 33);
		return (false);
	}
	if (ft_strlen(map) < 5 || ft_strncmp(map + ft_strlen(map) - 4, ".cub", 4))
	{
		write(2, "Error\nThge map doesn't have a valid name (extension must be .cub)\n", 67);
		return (false);
	}
	fd = open(map, 00200000);  //is O_DIRECTORY, but vscode doesn't find it
	if (fd != -1)
	{
		close(fd);
		write(2, "Error\nDid you really give a directory ???\n", 43);
		return (false);
	}
	return (true);
}

int main(int argc, char **argv)
{
	if (!check_arg(argc, argv[1]))
		return (1);
	return (0);
}