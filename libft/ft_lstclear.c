#include <stdlib.h>
#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *tmp;

    if (!lst || !del) // Vérifie si lst et del ne sont pas NULL
        return;

    while (*lst) // Parcourt la liste tant que lst n'est pas NULL
    {
        tmp = (*lst)->next;      // Stocke l'adresse de l'élément suivant
        ft_lstdelone(*lst, del); // Supprime l'élément actuel
        *lst = tmp;              // Passe à l'élément suivant
    }
}