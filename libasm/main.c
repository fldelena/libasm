/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:31:53 by fldelena          #+#    #+#             */
/*   Updated: 2021/05/14 16:25:48 by fldelena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"


void	check_strlen(char *str)
{
	int a, b;
	a = strlen(str);
	b = ft_strlen(str);
	printf("orig: %d,\tmine: %d \t---> ", a, b);
	if (strlen(str) == ft_strlen(str))
		printf("good\n");
	else
		printf("fail\n");
}

void	check_strcpy(char *str)
{
	char	*mine;
	char	*orig;

	mine = malloc(ft_strlen(str));
	orig = malloc(ft_strlen(str));
	printf("orig: %s\n", strcpy(orig, str));
	printf("mine: %s\n", ft_strcpy(mine, str));
	if (strcmp(mine, orig) == 0)
		printf("good\n");
	else
		printf("fail\n");
	free(mine);
	free(orig);
}

void	check_strcmp(char *str)
{
	char	*str2;

	str2 = "luck";
	printf("orig: %d,\tmine: %d \t---> ", strcmp(str, str2),
		ft_strcmp(str, str2));
	if (ft_strcmp(str, str2) == strcmp(str, str2))
		printf("good\n");
	else
		printf("fail\n");
}

void	check_strdup(char *str)
{
	char	*orig;
	char	*mine;

	orig = strdup(str);
	mine = ft_strdup(str);
	printf("orig: %s\nmine: %s\n", orig, mine);
	if (strcmp(orig, mine) == 0)
		printf("good\n");
	else
		printf("fail\n");
}

void	check_read()
{
	int count;
	int fd;
	char *line;

	fd = open("for_read.txt", O_RDONLY);
	line = malloc(BUFFER_SIZE);
	count = ft_read(fd, line, BUFFER_SIZE);
	printf("the string:\n%shas %d characters\n", line, count);
}

void	check_write(char *str)
{
	int i;

	i = ft_write(1, str, strlen(str));
	printf("|%d|\n", i);
}

void	check_func(char *var, char *str, char *str_a, char *str_b, char *str_c)
{
	if (strstr(var, "ft_strlen"))
	{
		check_strlen(str);
		check_strlen(str_a);
		check_strlen(str_b);
		check_strlen(str_c);
	}
	else if (strstr(var, "ft_strcpy"))
	{
		check_strcpy(str);
		check_strcpy(str_a);
		check_strcpy(str_b);
		check_strcpy(str_c);
	}
	else if (strstr(var, "ft_strcmp"))
	{
		check_strcmp(str);
		check_strcmp(str_a);
		check_strcmp(str_b);
		check_strcmp(str_c);
	}
	else if (strstr(var, "ft_strdup"))
	{
		check_strdup(str);
		check_strdup(str_a);
		check_strdup(str_b);
		check_strdup(str_c);
	}
	else if (strstr(var, "ft_read"))
	{
		check_read();
	}
	else if (strstr(var, "ft_write"))
	{

		check_write(str);
		check_write(str_a);
		check_write(str_b);
		check_write(str_c);
	}
	printf("\n");
	printf("-----------------------\n");
	printf("to finish, write 'exit'\n");
}

int		main(int argc, char **argv)
{
	char	var[20] = "";
	char	*var1;
	char	*str	= "";
	char	*str_a	= "luck";
	char	*str_b	= "where's the money, lebowski?";
	char	*str_c	= "Remember when you were young You shone like the Sun Shine on, you crazy diamond! Now theres a look in your eyes Like black holes in the sky Shine on, you crazy diamond!";

	var1 = gets(var);
	while (strstr(var, "exit") == NULL)
	{
		check_func(var, str, str_a, str_b, str_c);
		printf("select a function: ");
		var1 = gets(var);
	}
}
