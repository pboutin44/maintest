#include	"malloc.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
    size_t          i;
    const char      *src1;
    char            *dst1;

    i = 0;
    src1 = src;
    dst1 = dst;
    while (i < n)
    {
        dst1[i] = src1[i];
        i++;
    }
    return (dst1);
}

 t_list  *ft_lstnew(void const *content, size_t content_size)
{
    t_list *new;

//  if (!(new = (t_list *)malloc(sizeof(t_list))))
    if (!(new = (t_list *)mmap(0, sizeof(t_list), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1    , 0))) //normally PSIZE
        return (NULL);
    if (content == NULL)
    {
        new->content = NULL;
        new->content_size = 0;
    }
    else
    {
//      if (!(new->content = malloc(sizeof(new->content) * content_size)))
/*      if (!(new->content = mmap(0, sizeof(new->content) * content_size, PROT_READ | PROT_WRITE, MA    P_ANON | MAP_PRIVATE, -1, 0)))
            return (NULL);
        ft_memcpy(new->content, (void *)content, content_size);*/
        new->content = (char *)content;
        new->content_size = content_size;
    }
    new->next = NULL;
    return (new);
}


 t_list    *browse_lst(t_list *lst)
 {
     if (lst)
     {
         while (lst->next)
         {
             lst = lst->next;
         }
         return(lst);
     }
     return(NULL);
 }


t_list  *ft_lstiter(t_list *lst, int (f)(t_list *elem))
{
	t_list  *tmp;

	if(lst && f)
	{
		tmp = lst;
		while(tmp)
		{
			if(f(tmp) == 1)
			{
				return(tmp);
			}
			tmp = tmp->next;
		}
	}
	printf("COUCOU JE RETOURNE NULL\n");
	return(NULL);
}


