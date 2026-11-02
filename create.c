#include "inverted.h"

void create_database(hash_t HT[], F_node *head)
{
    // Initialize required variables
    int flag = 0;
    F_node *fptr = head;

    // Traverse all files in the file list
    while (fptr != NULL)
    {
        // Open the current file
        FILE *fp = fopen(fptr->f_name, "r");

        // Check if the file opened successfully
        if (fp == NULL)
        {
            printf("ERROR: Unable to open %s\n", fptr->f_name);
            fptr = fptr->link;
            continue;
        }

        char word[100];

        // Read each word from the file
        while (fscanf(fp, "%99s", word) == 1)
        {
            // Get hash index for the word
            int index = get_index(word);

            // Validate the hash index
            if (index < 0 || index >= 27)
                continue;

            // Search for the word in the main node list
            M_node *temp = HT[index].main_link;

            while (temp != NULL)
            {
                if (strcmp(temp->word, word) == 0)
                    break;

                temp = temp->main_link;
            }

            // Word not found in the database
            if (temp == NULL)
            {
                // Create new main and sub nodes
                M_node *mnew = create_mNode();
                S_node *snew = create_snode();

                // Check memory allocation
                if (mnew == NULL || snew == NULL)
                {
                    printf("Memory allocation failed\n");
                    fclose(fp);
                    return;
                }

                // Initialize the main node
                strcpy(mnew->word, word);
                mnew->file_count = 1;
                mnew->sub_link = snew;
                mnew->main_link = NULL;

                // Initialize the sub node
                strcpy(snew->filename, fptr->f_name);
                snew->word_count = 1;
                snew->sub_link = NULL;

                // Insert the new main node into the hash table
                if (HT[index].main_link == NULL)
                {
                    HT[index].main_link = mnew;
                }
                else
                {
                    M_node *last = HT[index].main_link;

                    while (last->main_link != NULL)
                        last = last->main_link;

                    last->main_link = mnew;
                }
            }
            // Word already exists in the database
            else
            {
                S_node *sptr = temp->sub_link;
                S_node *prev = NULL;

                // Search for the current file in the sub list
                while (sptr != NULL)
                {
                    // Word found in the same file
                    if (strcmp(sptr->filename, fptr->f_name) == 0)
                    {
                        sptr->word_count++;
                        break;
                    }

                    prev = sptr;
                    sptr = sptr->sub_link;
                }

                // File not found in the sub list
                if (sptr == NULL)
                {
                    // Create a new sub node
                    S_node *snew = create_snode();

                    // Check memory allocation
                    if (snew == NULL)
                    {
                        printf("Memory allocation failed\n");
                        fclose(fp);
                        return;
                    }

                    // Initialize the new sub node
                    strcpy(snew->filename, fptr->f_name);
                    snew->word_count = 1;
                    snew->sub_link = NULL;

                    // Insert the new sub node
                    if (prev == NULL)
                        temp->sub_link = snew;
                    else
                        prev->sub_link = snew;

                    // Increment file count
                    temp->file_count++;
                }
            }
        }

        // Database creation completed for the current file
        printf("INFO : Successful : Creation of DATABASE for file: %s\n\n", fptr->f_name);

        // Close the opened file
        fclose(fp);

        // Move to the next file
        fptr = fptr->link;
        flag = 1;
    }

    // Check if any database was created
    if (!flag)
    {
        printf("INFO : Files are not there\nCreate database is not possible\n");
    }

    // Display the file list
    print_filelist(head);
}