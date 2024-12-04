#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (lst && new) // Vérifie si les pointeurs ne sont pas NULL
    {
        new->next = *lst; // Le nouvel élément pointe sur l'ancien premier élément
        *lst = new;       // Le pointeur du début de la liste pointe maintenant sur le nouvel élément
    }
}
