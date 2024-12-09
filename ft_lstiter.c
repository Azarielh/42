#include <stdlib.h>
#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *)) // Prend une liste et une fonction en paramètre
{
    if (!lst || !f) // Vérifie si lst et f ne sont pas NULL
        return;

    while (lst) // Parcourt la liste tant que lst n'est pas NULL
    {
        f(lst->content); // Applique la fonction 'f' sur le contenu de l'élément actuel
        lst = lst->next; // Passe à l'élément suivant
    }
}