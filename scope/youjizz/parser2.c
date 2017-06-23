#include        <stdlib.h>
#include        <stdio.h>
#include        <unistd.h>
#include        <string.h>
#include 		<fcntl.h>
#include 		<assert.h>
#include		"scope.h"
# define MEM_SIZE 4096

void my_putchar(char c)
{
  write(1,&c,1);
}

void my_putstr(char *str)
{
  while(*str!=0)
    {
      my_putchar(*str);
      str++;
    }
}

static int      my_strlen(char *str)
{
  int           i;

  i = 0;
  while (*str != 0)
    {
      i++;
      str++;
    }
  return (i);
}

 static int      words_number(char const *s, char c)
{
    int         i;
    int         result;

    i = 0;
    result = 0;
    while (s[i] != '\0')
    {
        while (s[i] == c && s[i] != '\0')
            i++;
        while (s[i] != c && s[i] != '\0')
            i++;
        result++;
        if (s[i - 1] == c)
            result -= 1;
    }
    return (result);
}

static int      words_size(char const *s, char c, int i)
{
    int     res;

    res = 0;
    while (s[i] != c && s[i] != '\0')
    {
        res++;
        i++;
    }
    return (res);
}
static char     **new_tab(char const *s, char c, int result)
{
    char        **str;
    int         i;
    int         j;
    int         word_size;

    i = 0;
    j = 0;
    if (!(str = (char**)malloc(sizeof(char*) * result + 1)))
        return (NULL);
    while (i < result)
    {
        word_size = 0;
        while (s[j] == c && s[j] != '\0')
            j++;
        word_size = words_size(s, c, j);
        while (s[j] != c && s[j] != '\0')
            j++;
        str[i] = (char*)malloc(sizeof(char) * (word_size + 1));
        if (!str[i])
            return (NULL);
        i++;
    }
    return (str);
}

char            **ft_strsplit(char const *s, char c)
{
    char        **str;
    int         j;
    int         k[2];

    k[0] = 0;
    k[1] = 0;
    if (!s)
        return (NULL);
    if (!(str = new_tab(s, c, words_number(s, c))))
        return (NULL);
    while (k[0] < words_number(s, c))
    {
        j = 0;
        while (s[k[1]] == c && s[k[1]] != '\0')
            k[1]++;
        while (s[k[1]] != c && s[k[1]] != '\0')
        {
            str[k[0]][j] = s[k[1]];
            j++;
            k[1]++;
        }
        str[k[0]++][j] = '\0';
    }
    str[k[0]] = NULL;
    return (str);
}




int     my_put_nbr(int n)
 {
   if (n < 0)
     {
       my_putchar('-');
       n = -n;
     }
   if (n >= 10)
     {
       my_put_nbr(n / 10);
       my_putchar(n % 10 + '0');
     }
   if (n < 10)
     {
       my_putchar(n % 10 + '0');
     }
   return (n);
}

static char     *my_strncpy(char *dest, char *src, int n)
{
  int           i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i++;
    }
  if (n < i)
    dest[i] = '\0';
  return (dest);
}

static char     *add_to_line(char *line, int treat, char *buff, int *start)
{
  char          *newlen;
  int           oldlen;

  if (line != 0)
    oldlen = my_strlen(line);
  else
    oldlen = 0;
  newlen = malloc((oldlen + treat + 1) * sizeof(*newlen));
  if (line != 0)
    my_strncpy(newlen, line, oldlen);
  else
    my_strncpy(newlen, "", oldlen);
  newlen[oldlen + treat] = 0;
  my_strncpy(newlen + oldlen, buff + *start, treat);
  if (line)
    free(line);
  *start = *start + (treat + 1);
  return (newlen);
}

char            *get_next_line(const int fd)
{
  static char   buff[MEM_SIZE];
  static int    nbinbuff = 0;
  static int    start;
  int           treat;
  char          *line;

  line = 0;
  treat = 0;
  while (1 == 1)
    {
      if (nbinbuff <= start)
        {
          start = 0;
          if (!(nbinbuff = read(fd, buff, MEM_SIZE)))
            return (line);
          if (nbinbuff == -1)
            return (NULL);
          treat = 0;
        }
      if (buff[start + treat] == '\n')
        return (line = add_to_line(line, treat, buff, &start));
      if (start + treat == nbinbuff - 1)
        line = add_to_line(line, treat + 1, buff, &start);
      treat = treat + 1;
    }
}

 void    ft_putchar(char c)
{
    write(1, &c, 1);
}


void    ft_putstr(char const *s)
{
    while (*s)
        write(1, s++, 1);
}

 void    ft_putnbr(int n)
{
    if (n == -2147483648)
        ft_putstr("-2147483648");
    else
    {
        if (n < 0)
        {
            ft_putchar('-');
            n = -n;
        }
        if (n >= 10)
        {
            ft_putnbr(n / 10);
            ft_putnbr(n % 10);
        }
        else
        {
            ft_putchar(n + 48);
        }
    }
}

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

/*char    *ft_strcat(char *s1, const char *s2)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (s1[i] != '\0')
    {
        i++;
    }
    while (s2[j] != '\0')
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    return (s1);
}*/
size_t  ft_strlen(const char *s)
{
    int     i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}

/*char *ft_strcat(char *s1, const char *s2)
{
	size_t	len;
	int		i;

	len = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		s1[len + i] = s2[i];
		i++;
	}
	s1[len + i] = '\0';
	return (s1);
}*/

char	*ft_strcat(char *s1, const char *s2)
{
	char	*cur1;
	char	*cur2;

	cur1 = s1;
	cur2 = (char *)s2;
	while (*cur1 != '\0')
	{
		cur1++;
	}
	while (*cur2 != '\0')
	{
		*cur1 = *cur2;
		cur1++;
		cur2++;
	}
	*cur1 = '\0';
	return (s1);
}

float	*point(char *objet)
{
	int		fd;
	char	*str;
	char	**str1;
	char	**str2;
	char	**str2bis;
	char	**str_tmp;	
	char	**str_tmp2;	
	float	*str3;
	int		i;
	int		j;
	int		k;
	int		l;
	int		v;
	int		flag;

	j = 0;
	flag = 0;
	fd = open(objet, O_RDONLY);
	str1 = (char **)malloc(500 * sizeof(char *));
	str2 = (char **)malloc(1000 * sizeof(char *));
	str2bis = (char **)malloc(1000 * sizeof(char *));
	str_tmp = (char **)malloc(1000 * sizeof(char *));
//	str_tmp2 = (char **)malloc(1000 * sizeof(char *));
	str3 = (float *)malloc(6000 * sizeof(float));
	while(j < 500)
	{
		str1[j] = (char *)malloc(600 * sizeof(char));
		j++;
	}
	j = 0;	
	while(j < 1000)
	{
		str2[j] = (char *)malloc(600 * sizeof(char));
		j++;
	}	
	j = 0;	
	while(j < 1000)
	{
		str2bis[j] = (char *)malloc(600 * sizeof(char));
		j++;
	}	
	j = 0;	
	while(j < 1000)
	{
		str_tmp[j] = (char *)malloc(600 * sizeof(char));
		j++;
	}	
/*	j = 0;	
	while(j < 1000)
	{
		str_tmp2[j] = (char *)malloc(600 * sizeof(char));
		j++;
	}	*/
	j = 0;
	i = 0;
	while(flag != 1)
	{
		str = get_next_line(fd);
	//	puts(str);
		if(str[0] == 's')
		{
			str1[i] = "off";
			flag = 1;
			i++;
		}
		else
		{
			if(str[0] == 'v')
			{
				str1[i] = str;
				i++;
			}
		}
		j++;
	}
	flag = 0;
	i = 0;
	while(flag != 1)
	{
		str = get_next_line(fd);
		if(!str || str[0] != 'f')
		{
			str2[i] = "off";
			flag = 1;
			i++;
		}
		else
		{
			if(str[0] == 'f')
			{
//				puts(str);
				str2[i] = str;
				i++;
			}
		}
		j++;
	}
	j = 0;
	i = 0;
	k = 0;
	l = 0;
	char	*tmp;
	char	*tmp1;
	char	*tmp2;
	tmp = (char *)malloc(100 * sizeof(char));
	tmp1 = (char *)malloc(100 * sizeof(char));
	while(strcmp(str2[j], "off") != 0)
	{
		i = 0;
		k = 0;
		while(str2[j][i] != '\0')
		{
			if(str2[j][i] == ' ')
				k++;
			i++;	
		}
		if(k == 3)
		{
			str2bis[l] = str2[j];
//			puts("if");
//			ft_putnbr(j);
//			puts(str2[j]);
		}
		else
		{
//			puts("else");
//			ft_putnbr(j);
//			puts(str2[j]);
			tmp = (char *)malloc(100 * sizeof(char));
			str_tmp = ft_strsplit(str2[j], ' ');
			strcpy(tmp, str_tmp[0]);
			tmp = strcat(tmp, " ");
			tmp = strcat(tmp, str_tmp[1]);
			tmp = strcat(tmp, " ");
			tmp = strcat(tmp, str_tmp[2]);
			tmp = strcat(tmp, " ");
			tmp = strcat(tmp, str_tmp[3]);

		//	str2bis[l] = tmp;
			strcpy(str2bis[l], tmp);
			l++;
			free(tmp);
			tmp2 = (char *)malloc(100 * sizeof(char));
			strcpy(tmp, str_tmp[0]);
			tmp2 = strcat(tmp2, " ");
			tmp2 = strcat(tmp2, str_tmp[1]);
			tmp2 = strcat(tmp2, " ");
			tmp2 = strcat(tmp2, str_tmp[3]);
			tmp2 = strcat(tmp2, " ");
			tmp2 = strcat(tmp2, str_tmp[4]);

		//	str2bis[l] = tmp2;
			strcpy(str2bis[l], tmp2);

		}

		j++;
		l++;
	}
	str2bis[l] = "off";
	i = 0;
/*	while(strcmp(str2bis[i], "off") != 0)
	{
		ft_putnbr(i);
		puts(str2bis[i]);
		i++;
	}
	i = 0;
	while(strcmp(str1[i], "off") != 0)
	{
		puts(str1[i]);
		ft_putnbr(i);
		i++;
	}
	i = 0;*/
	v = 0;
	free(str_tmp);
	while(strcmp(str2bis[i], "off") != 0)
	{
		tmp = (char *)malloc(100 * sizeof(char));
		str_tmp2 = ft_strsplit(str2bis[i], ' ');
	//	tmp = str_tmp2[1];
//		puts(str_tmp2[1]);
	//	ft_putnbr(atoi(str_tmp2[1]));
	//	puts(str2bis[i]);
//		puts(str1[atoi(str_tmp2[1]) - 1]);
	  	str_tmp = ft_strsplit(str1[atoi(str_tmp2[1]) - 1], ' ');
	//	puts(str_tmp[1]);
		str3[v] = atof(str_tmp[1]);
		v++;
		str3[v] = atof(str_tmp[2]);
		v++;
		str3[v] = atof(str_tmp[3]);
		v++;
		
		free(str_tmp);
/*		printf("toobib: %f\n", atof(str_tmp[1]));
		printf("toobib: %f\n", atof(str_tmp[2]));
		printf("toobib: %f\n", atof(str_tmp[3]));
	*/	
//		puts(str1[atoi(str_tmp2[2]) - 1]);
	  	str_tmp = ft_strsplit(str1[atoi(str_tmp2[2]) - 1], ' ');
	//	puts(str_tmp[1]);
/*		printf("toobib1: %f\n", atof(str_tmp[1]));
		printf("toobib1: %f\n", atof(str_tmp[2]));
		printf("toobib1: %f\n", atof(str_tmp[3]));*/
		str3[v] = atof(str_tmp[1]);
		v++;
		str3[v] = atof(str_tmp[2]);
		v++;
		str3[v] = atof(str_tmp[3]);
		v++;
		free(str_tmp);
		
//		puts(str1[atoi(str_tmp2[3]) - 1]);
	  	str_tmp = ft_strsplit(str1[atoi(str_tmp2[3]) - 1], ' ');
	//	puts(str_tmp[1]);
/*		printf("toobib2: %f\n", atof(str_tmp[1]));
		printf("toobib2: %f\n", atof(str_tmp[2]));
		printf("toobib2: %f\n", atof(str_tmp[3]));*/
		str3[v] = atof(str_tmp[1]);
		v++;
		str3[v] = atof(str_tmp[2]);
		v++;
		str3[v] = atof(str_tmp[3]);
		v++;
	/*	str_tmp = ft_strsplit(str2[j], ' ');
		puts(str2bis[i]);
		i++;*/
		i++;
	}
	str3[v] = 88888888;

	i = 0;
	while(str3[i] != 88888888)
	{
	//	printf("\nnumero%d : %f", i, str3[i]);
		i++;
	}

	return(str3);
}
