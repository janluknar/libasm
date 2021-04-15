/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 12:46:05 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/14 09:36:06 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	ft_strlen(char *str);
char *ft_strcpy(char *dest, char *src);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_write(int fd, char *str, int len);
int	ft_read(int fd, char *buff, int size);
char *ft_strdup(char *str);

int	main(int argc, char **argv)
{
	char *path = "Makefile";
	if (argc == 1)
		(void)argv;
	else if (argc == 2)
		path = argv[1];
	printf("____________________________________");
	char *s = "";
	printf("\nFT_STRLEN -> string:  \"%s\"\n", s);
	printf("ft_strlen: %d\n", ft_strlen(s));
	printf("   strlen: %lu\n", strlen(s));

	s = "El lugar donde los espejos te llaman gorda.";
	printf("\nFT_STRLEN -> string:  \"%s\"\n", s);
	printf("ft_strlen: %d\n", ft_strlen(s));
	printf("   strlen: %lu\n", strlen(s));
	printf("____________________________________");
	char *s1 = "holi";
	char *s2 = "holi";
	printf("\nFT_STRCMP\nS1: \"%s\" S2 \"%s\"\n", s1, s2);
	printf("ft_strcmp: %d\n", ft_strcmp(s1, s2));
	printf("   strcmp: %d\n", strcmp(s1, s2));

	char *s3 = "____________________________________________________________________________________________________________________________________________________________________________________";
	char *s4 = "string largastring largastring largastring largastring largastring largastring largastring largastring largastring largastring largastring larga";
	printf("\nFT_STRCMP\nS1: \"%s\"\nS2 \"%s\"\n", s3, s4);
	printf("ft_strcmp: %d\n", ft_strcmp(s3, s4));
	printf("   strcmp: %d\n", strcmp(s3, s4));
	printf("____________________________________\n");

	char *src = strdup("");
	char *dst = malloc(strlen(src) * sizeof(char) + 1);

	printf("FT_STRCPY\nANTES   -> SRC: \"%s\" DST: \"%s\"\n", src, dst);
	char * ret = ft_strcpy(dst, src);
	printf("DESPUÉS -> SRC: \"%s\" DST: \"%s\"\n", src, dst);
	printf("RETURN: \"%s\"\n", ret);
	free(src); 
	free(dst);

	src = strdup("Esta no es una frase.");
	dst = malloc(strlen(src) * sizeof(char) + 1);
	
	printf("ANTES   -> SRC: \"%s\" DST: \"%s\"\n", src, dst);
	ret = ft_strcpy(dst, src);
	printf("DESPUÉS -> SRC: \"%s\" DST: \"%s\"\n", src, dst);
	printf("RETURN: \"%s\"\n", ret);
	free(src); 
	free(dst);

	printf("____________________________________\nFT_WRITE\n");
	char *towrite = "....................\n";
	ft_write(1, towrite, ft_strlen(towrite));
	towrite = "";
	ft_write(1, towrite, ft_strlen(towrite));
	towrite = "\n";
	ft_write(1, towrite, ft_strlen(towrite));

	printf("____________________________________\nFT_READ\n");
	int fd = open(path, O_RDONLY);
	char text[10] = "\0\0\0\0\0\0\0\0";
	int retu = ft_read(fd, text, 9);
	printf("FT_READ: \"%s\"\nRETURN VAL: %d\n", text, retu);
	char text2[10] = "\0\0\0\0\0\0\0\0";
	retu = ft_read(45, text2, 9);
	perror("error");
	printf("FT_READ: \"%s\"\nRETURN VAL: %d\n", text2, retu);

	fd = open(path, O_RDONLY);
	char text4[10] = "\0\0\0\0\0\0\0\0";
	retu = read(fd, text4, 9);
	printf("   READ: \"%s\"\nRETURN VAL: %d\n", text4, retu);
	char text3[10] = "\0\0\0\0\0\0\0\0";
	retu = read(45, text2, 9);
	perror("error");
	printf("   READ: \"%s\"\nRETURN VAL: %d\n", text3, retu);
	

	printf("\n____________________________________\nFT_STRDUP\n");
	
	char *new;
	char *old = "copiar esta string";
	new = ft_strdup(old);
	printf("NEW: \"%s\"\n", new);
	free(new);
	printf("freed string: OK\n");
	new = ft_strdup("");
	printf("NEW: \"%s\"\n", new);
	free(new);
	printf("freed string: OK\n");
	close(fd);
}
