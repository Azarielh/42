#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *new_elem;

    // Allocation de mémoire pour le nouvel élément
    new_elem = (t_list *)malloc(sizeof(t_list));
    if (!new_elem) // Vérification si malloc a échoué
        return (NULL);

    // Initialisation des membres de la structure
    new_elem->content = content;
    new_elem->next = NULL;

    return (new_elem);
}
