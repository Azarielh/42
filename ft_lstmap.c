#include <stdlib.h>
#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_lst;
    t_list *new_elem;

    if (!lst || !f) // Vérifie si lst et f ne sont pas NULL
        return (NULL);

    new_lst = NULL; // Initialise la nouvelle liste à NULL

    while (lst) // Parcourt la liste tant que lst n'est pas NULL
    {
        new_elem = ft_lstnew(f(lst->content)); // Crée un nouvel élément avec le contenu modifié par 'f'
        if (!new_elem)                         // Vérifie si ft_lstnew a échoué
        {
            ft_lstclear(&new_lst, del); // Supprime la nouvelle liste
            return (NULL);
        }
        ft_lstadd_back(&new_lst, new_elem); // Ajoute l'élément à la fin de la nouvelle liste
        lst = lst->next;                    // Passe à l'élément suivant
    }

    return (new_lst); // Retourne la nouvelle liste
}