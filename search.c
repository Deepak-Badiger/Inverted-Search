#include "inverted.h"
 //Logic for search database
void search_database(hash_t HT[])
{
    int i;
    char word[30];
    printf("Enter the word : "); //Read the word to search
    scanf("%s", word);

    for (i = 0; i < 27; i++)
    {
        if (HT[i].main_link == NULL) //Main node link is NULL skip 
            continue;

        M_node *m_ptr = HT[i].main_link;

        while (m_ptr != NULL)
        {
            if (strstr(word, m_ptr->word) != NULL)
            {
                printf("Word %s is present in %d files\n", m_ptr->word, m_ptr->file_count);

                S_node *s_ptr = m_ptr->sub_link;

                while (s_ptr != NULL)
                {
                    printf("In file %s, %d times\n\n", s_ptr->filename, s_ptr->word_count);

                    s_ptr = s_ptr->sub_link;
                }
                return;
            }

            m_ptr = m_ptr->main_link;
        }
    }
    printf("INFO : Word is not found in the database\n");
}
