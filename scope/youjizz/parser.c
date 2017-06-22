#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>

static int	my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

static int  xwrite(int output, char *str, int len)
{
  int		i;
  char		*err;

  i = write(output, str, len);
  if (i < 0)
    {
      err = "Get Next Line Error : write error";
      xwrite(2, err, my_strlen(err));
      free(err);
      exit(-1);
    }
  return (i);
}

static void	*xmalloc(int size)
{
  void		*tmp;
  char		*err;

  tmp = malloc(size);
  if (tmp == NULL)
    {
      err = "Get Next Line Error : malloc error";
      xwrite(2, err, my_strlen(err));
      free(err);
      exit(-1);
    }
  return (tmp);
}

static int	xread(const int fd, char *buffer_read, int len)
{
  int		i;
  char		*err;

  i = read(fd, buffer_read, len);
  if (i < 0)
    {
      err = "Get Next Line Error : Read error";
      xwrite(2, err, my_strlen(err));
      free(err);
      exit(-1);
    }
  return (i);
}

char		*get_next_line(const int fd)
{
  static char	buffer_read[READ_BUFF];
  static int	i;
  static int	cursor;
  int		j;
  char		*buffer_return;

  j = 0;
  buffer_return = xmalloc(sizeof(*buffer_return) * (RETURN_BUFF + 1));
  cursor = (i == 0 ? xread(fd, buffer_read, READ_BUFF) : cursor);
  while (i <= cursor && j <= RETURN_BUFF)
    {
      if (j == RETURN_BUFF)
	return (buffer_return);
      if (buffer_read[i] == '\n')
	{
	  i++;
	  buffer_return[j] = '\0';
	  return (buffer_return);
	}
      cursor = (i >= cursor ? xread(fd, buffer_read, READ_BUFF) : cursor);
      i = (i >= cursor ? 0 : i);
      buffer_return[j++] = buffer_read[i++];
    }
  return (0);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}
char *concat_string(char *s1,char *s2)
{
 char *res = malloc(strlen(s1) + strlen(s2) + 1);
    if (res) {
        strcpy(res, s1);
        strcat(res, s2);
    }
    return res;
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

int main(int argc, char *argv[]){

int fd;
char *str;
char **str1;
char **str2;
char *str3;
float *str4;


puts("tachedebeurre");
fd = open(argv[1], O_RDONLY);
//printf("%s", get_next_line(fd));
int i = 0;
str = (char *)malloc(500 * sizeof(char));
str1 = (char **)malloc(500 * sizeof(char *));
str2 = (char **)malloc(2000 * sizeof(char *));
str3 = (char *)malloc(2000 * sizeof(char));
str4 = (float *)malloc(2000 * sizeof(float));
int	j = 0;
char c;
char v;
c = 'U';
v = '9';
write(1, &c, 1);
while(j < 500)
{
	str1[j] = (char *)malloc(600 * sizeof(char));
	j++;
}
j = 0;
while(j < 2000)
{
	str2[j] = (char *)malloc(3 * sizeof(char));
	j++;
}
j = 0;
/*while(j < 2000)
{
	str3[j] = (char *)malloc(60);
	j++;
}*/
write(1, &v, 1);
int y = 0;
puts("tachedebeurre2");
while(i != -1)
{
	my_put_nbr(i);
	str = (char *)malloc(1000 * sizeof(char));
	puts("tachefromage");
	str = get_next_line(fd);
	puts("tachedesinge");
	if(strstr(str, "off"))
	{
		str1[i] = "off";
		i = -2;
		puts("if");
	}
	else
	{
		puts("else");

		if(str[0] == 'v')
		{
			y = 0;
/*			while(str[y] != '\0')
			{
				str1[i][y] = str[y];
				y++;
			}
			str1[i][y] = '\0';*/
	
			str1[i] = str;
		}
	}
	i++;
}
puts("tachedebeurre2");
i = 0;
while(i != -1)
{
	str = get_next_line(fd);
//	puts(str);
	if(strstr(str, "off"))
	{
		str2[i] = "off";
		i = -2;
	}
	else
	{

		if(str[0] == 'v')
		{
			y = 0;
/*			while(str[y] != '\0')
			{
				str1[i][y] = str[y];
				y++;
			}
			str1[i][y] = '\0';*/
	
			str2[i] = str;
		}
	}
	i++;
}

i = 0;
int	h;
str3 = "";
while(i != -1)
{
//	puts(str2[i]);
	h = atoi(str2[i]);
//	puts(str1[h]);
//	my_put_nbr(3);	
	if(strstr(str2[i], "off"))
	{
//		puts (str3);
	//	str3 = concat_string(str3, '\0');
		//	strcpy(str3, '\0');
		//	str3 = s"off";
		my_put_nbr(i);
		i = -2;
	}
	else
	{
		str3 = 	concat_string(str3, str1[h - 1]);
//		str3 = 	concat_string(str3, "pouf");
//		str3 = str1[h - 1];
/*		while(str[y] != '\0')
		{
			str1[i][y] = str[y];
			y++;
		}
		str2[i] = str;*/
	}
	i++;
}

i = 0;
/*
while(str3[i] != '\0')
{
	my_putchar(str3[i]);
	i++;
}*/
//puts(str3);
/*while(i != -1)
{
//	puts(str3[i]);
	if(strstr(str3[i], "off"))
	{
	//	str3 = "off";
		my_put_nbr(i);
		i = -2;
	}
	else
	{
		str3 = concat_string(str3, "ef");
	}
	i++;
}*/
//my_put_nbr(i);

//puts(str3);
my_put_nbr(sizeof(str3));
int fd2;
fd2 = open("stock.txt", O_WRONLY);
puts(str3);
write(fd2, str3, 10000000);
int o = 0;
while(strcmp(str1[0], "off") != 0)
{
	puts(str1[o]);
	o++;
}


//printf("%s", str3[0]);
//printf("%s", str3[3]);
//str = get_next_line(fd);
return(1);
}


