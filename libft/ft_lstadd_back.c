#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *last;

    if (!lst || !new) // Vérifie si les pointeurs sont valides
        return;

    if (*lst == NULL) // Si la liste est vide, new devient le premier élément
    {
        *lst = new;
        return;
    }

    last = ft_lstlast(*lst); // Trouve le dernier élément de la liste
    last->next = new;        // Relie le dernier élément à new
}
