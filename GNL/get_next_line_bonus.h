#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define FD 10240

size_t	len_if(char *s, int nl);
char	*ft_dup_free(char *src, char **to_free);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
int		build_line(char **line, char **buff, char **buff_s, char step);
int		get_next_line(int fd, char **line);

#endif
