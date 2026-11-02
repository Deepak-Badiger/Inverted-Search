#include "inverted.h"

int update_database(hash_t HT[], F_node **head)
{
    char file_name[30];

    printf("Enter the backup file name : ");
    scanf("%s", file_name);

    // Check extension of backup file
    if (strstr(file_name, ".txt") == NULL)
    {
        printf("INFO : %s  => This file is not a .txt file\n\n",file_name);
        return FAILURE;
    }

    FILE *fp = fopen(file_name, "r");

    if (fp == NULL)
    {
        printf("ERROR : Unable to open %s\n", file_name);
        return FAILURE;
    }

    // Validate first and last character 
    char first = fgetc(fp);

    fseek(fp, -2, SEEK_END);
    char last = fgetc(fp);
    // printf("First = %c\n", first);
    // printf("First = %c\n", last);

    if (first != '#' || last != '#')
    {
        printf("INFO : %s => This file doesn't have the database\n",file_name);
        fclose(fp);
        return FAILURE;
    }

    rewind(fp); 

    int index;
    int file_count;
    int word_count;

    char word[30];
    char fname[30];

    //Logic for store the data from file to hash table
    while (fscanf(fp, "#%d;%[^;];%d;", &index, word, &file_count) == 3)
    {
        /* Create Main Node */
        M_node *m_new = malloc(sizeof(M_node));

        if (m_new == NULL)
        {
            fclose(fp);
            return FAILURE;
        }

        strcpy(m_new->word, word);
        m_new->file_count = file_count;
        m_new->sub_link = NULL;
        m_new->main_link = NULL;

        S_node *last_sub = NULL;

        for (int i = 0; i < file_count; i++)
        {
            fscanf(fp, "%[^;];%d;", fname, &word_count);

            
            S_node *s_new = malloc(sizeof(S_node));

            if (s_new == NULL)
            {
                fclose(fp);
                return FAILURE;
            }

            strcpy(s_new->filename, fname);
            s_new->word_count = word_count;
            s_new->sub_link = NULL;

            // Add filename to file list if not already present 
            if (check_duplicates(*head, fname) == FAILURE)
            {
                
                insert_last(head, fname);
            }
            
            delete_file(head,fname);

            //link subnode
            if (m_new->sub_link == NULL)
            {
                m_new->sub_link = s_new;
            }
            else
            {
                last_sub->sub_link = s_new;
            }

            last_sub = s_new;
        }

        fscanf(fp, "#\n");

        // Insert Main Node into Hash Table 

        if (HT[index].main_link == NULL)
        {
            HT[index].main_link = m_new;
        }
        else
        {
            M_node *temp = HT[index].main_link;

            while (temp->main_link != NULL)
            {
                temp = temp->main_link;
            }

            temp->main_link = m_new;
        }
    }

    fclose(fp); //close the file

    printf("Database updated successfully.\n");
    print_filelist(*head);


    return SUCCESS;
}