#include "inverted.h"

void save_database(hash_t HT[])
{
    char word[30];
    printf("Enter the filename to save Database : ");
    scanf("%s",word);
    if(strstr(word,".txt") == NULL){
        printf("INFO : %s  => This file is not a .txt file\n\n",word);
        return;
    }
    FILE *fp = fopen(word,"w");
    
     int i;

    for (i = 0; i < 27; i++)
    {
        if (HT[i].main_link == NULL)
            continue;
        

        M_node *m_ptr = HT[i].main_link;

        while (m_ptr != NULL)
        {
            fprintf(fp,"#%d;%s;%d;",i, m_ptr->word,m_ptr->file_count);

            S_node *s_ptr = m_ptr->sub_link;

            while (s_ptr != NULL)
            {
                fprintf(fp,"%s;%d;",s_ptr->filename,s_ptr->word_count);

                s_ptr = s_ptr->sub_link;
            }

            fprintf(fp,"#\n");

            m_ptr = m_ptr->main_link;
        }
    }
    fclose(fp);
    printf("Database is saved\n\n");
}   
