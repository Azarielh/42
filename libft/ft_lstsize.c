#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int count = 0;

    while (lst) // Parcourt la liste tant que lst n'est pas NULL
    {
        count++;         // Incrémente le compteur à chaque élément
        lst = lst->next; // Passe à l'élément suivant
    }
    return (count);
}
