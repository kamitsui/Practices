#include <unistd.h>
#include <string.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return ;
	int len;
	len = strlen(s);
	write(fd, s, len);
}

void	ft_putstr_fd2(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

#define BUFF_SIZE 1000000
int	main(void)
{
	char buff[BUFF_SIZE];
	memset(buff, 'a', BUFF_SIZE - 1);
	buff[BUFF_SIZE - 1] = '\0';
	ft_putstr_fd(buff, STDERR_FILENO);
	//ft_putstr_fd2(buff, STDERR_FILENO);
	return 0;
}
