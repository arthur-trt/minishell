#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>

#define MAX_CMD_LINE 4096

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}


static char	*get_username(void)
{
	char	*username;

	username = getenv("USER");
	if (username == NULL)
		username = strdup("username");
	return (username);
}

static char *get_home(void)
{
	char	*home;

	home = getenv("HOME");
	return (home);
}

static void		ft_prompt(void)
{
	char	cwd_buffer[MAX_CMD_LINE];
	char	*cwd;

	bzero(cwd_buffer, MAX_CMD_LINE);
	cwd = getcwd(cwd_buffer, MAX_CMD_LINE);
	if (strcmp(cwd, get_home()) == 0)
	{
		free(cwd);
		cwd = strdup("~");
	}
	ft_putstr_fd("\e[1;32m", 1);
	ft_putstr_fd(get_username(), 1);
	ft_putstr_fd("@", 1);
	ft_putstr_fd(cwd, 1);
	ft_putstr_fd(" > \e[0m", 1);

}

int main()
{
	ft_prompt();
	return (0);
}
