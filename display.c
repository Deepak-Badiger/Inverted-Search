#include "inverted.h"

void display_database(hash_t HT[])
{
    printf("\n-------------------------------------------------------------------------------------------------\n");
    printf("%-8s %-20s %-12s %-25s %-10s\n","Index", "Word", "File Count", "File Name", "Word Count");
    printf("-------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < 27; i++)
    {
        if (HT[i].main_link == NULL)
            continue;

        M_node *m_ptr = HT[i].main_link;

        while (m_ptr != NULL)
        {
            S_node *s_ptr = m_ptr->sub_link;

            /* Print first sub node along with main node */
            if (s_ptr != NULL)
            {
                printf("%-8d %-20s %-12d %-25s %-10d\n", i,m_ptr->word,m_ptr->file_count,s_ptr->filename,s_ptr->word_count);

                s_ptr = s_ptr->sub_link;
            }
            else
            {
                printf("%-8d %-20s %-12d\n",i,m_ptr->word,m_ptr->file_count);
            }

            /* Print remaining sub nodes */
            while (s_ptr != NULL)
            {
                printf("%-8s %-20s %-12s %-25s %-10d\n","","","",s_ptr->filename, s_ptr->word_count);

                s_ptr = s_ptr->sub_link;
            }

            printf("-------------------------------------------------------------------------------------------------\n");

            m_ptr = m_ptr->main_link;
        }
    }
}