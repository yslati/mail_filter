#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	static	char	*buff_s[FD];
	char			*buff;
	int				b;

	if (fd < 0 || fd >= FD || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0 ||
		!line || !(*line = (char *)malloc(1 * sizeof(char))))
		return (-1);
	**line = '\0';
	b = 1;
	if (!(buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (b)
	{
		if (!buff_s[fd] && (b = read(fd, buff, BUFFER_SIZE)) == -1)
			return (-1);
		buff[b] = '\0';
		if (!buff_s[fd] && build_line(line, &buff, &(buff_s[fd]), 1))
			return (1);
		else if (buff_s[fd] && build_line(line, &buff, &(buff_s[fd]), 0))
			return (1);
	}
	(buff_s[fd] != NULL) ? free(buff_s[fd]) : 0;
	(buff != NULL) ? free(buff) : 0;
	return (0);
}
