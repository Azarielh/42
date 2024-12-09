#include "libft.h"
#include <stdlib.h>

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (!lst || !del) // Vérifie si lst et del ne sont pas NULL
        return;

    del(lst->content); // Supprime le contenu avec la fonction 'del'
    free(lst);         // Libère la mémoire de l'élément
}
