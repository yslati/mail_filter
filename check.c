#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "./GNL/get_next_line_bonus.c"
#include "./GNL/get_next_line_utils_bonus.c"
#include "./GNL/get_next_line_bonus.h"

typedef struct s_edu
{
	int edu_mail;
	int	maillist;
	int	valid;
}				t_edu;


int		check_txt(char *str)
{
	int		i;

	i = strlen(str);
	if (i < 4)
		return (-3);
	if (str[i - 1] != 't')
		return (-3);
	if (str[i - 2] != 'x')
		return (-3);
	if (str[i - 3] != 't')
		return (-3);
	if (str[i - 4] != '.')
		return (-3);
	return 0;
}

int		error_msg(int error)
{
	if (error == -1)
		printf("rak nssiti t3tini file !!\n");
	else if (error == -2)
		printf("tkayess 3tih gha file wa7d db\n");
	else if (error == -3)
		printf("dakahl file mzn & daruri ykon .txt\n");
	return(0);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*ptr1;
	size_t	l;

	l = strlen(s1);
	if ((ptr = (char *)malloc((l + 1) * sizeof(char))) == NULL)
		return (NULL);
	ptr1 = ptr;
	while (*s1 != '\0')
	{
		*ptr++ = *s1++;
	}
	*ptr = '\0';
	return (ptr1);
}

int 	main(int ac, char **av)
{
	t_edu edu;
	char *ret;
	char *right = "\n>>>>>>>>>>>>>>>>>>>> 5AFAYA <<<<<<<<<<<<<<<<<<<<\n\n";
	int read = 1;
	int fd;
	char *line;
	char *domain;
	FILE *fvalid;
	char *name = ft_strdup("");

	/* check error */
	if (ac < 2)
		return(error_msg(-1));
	if ((check_txt(av[1])) == -3) // check file.txt
		return (error_msg(-3));
	else if (ac > 3)
		return(error_msg(-2));
	/* ====================== */
	printf("dakhal domain name li baghi t9alb 3lih: ");
	scanf("%s", domain);

	strcpy(name, domain);
	strcat(name, ".txt");	
	/* ====== open files ========== */
	fd = open(av[1], O_RDONLY);
	fvalid = fopen(name, "w");

	fprintf(fvalid, "-------------------- %s --------------------\n\n", domain);
	while (read == 1)
	{
		read = get_next_line(fd, &line);
		ret = strstr(line, domain);
		if (ret)
		{
			fprintf(fvalid, line, strlen(line));
			fprintf(fvalid, right, strlen(right));
		}
		free(line);
	}
	close(fd);
	return 0;
}
