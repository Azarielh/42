#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    if (!lst) // Si la liste est vide, retourne NULL
        return (NULL);

    while (lst->next) // Parcourt la liste jusqu'à ce que lst->next soit NULL
        lst = lst->next;

    return (lst); // Retourne le dernier élément
}
