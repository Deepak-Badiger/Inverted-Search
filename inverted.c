#include "inverted.h"

/* Function definitions */
void validate_files(int argc, char *argv[], F_node **head)
{
	for (int i = 1; i < argc; i++)
	{

		if (strstr(argv[i], ".") != NULL)
		{
			if (strstr(argv[i], ".txt") == NULL) // validation for .txt extension
			{
				printf("INFO : %s => This file not a .txt file\n", argv[i]);
				continue;
			}
		}
		else
		{
			printf("INFO : %s => This file has without extension\n",argv[i]);
			continue;
		}

		FILE *fp = fopen(argv[i], "r"); // open the file to read

		if (fp == NULL)
		{
			printf("%s can't be opened\n", argv[i]);
			continue;
		}

		fseek(fp, 0, SEEK_END); // file pointer points to last

		if (ftell(fp) == 0) // if file is empty
		{
			printf("INFO : %s => This file is empty\n\n", argv[i]);
			fclose(fp);
			continue;
		}

		rewind(fp); // make file pointer pionts to begining

		if (check_duplicates(*head, argv[i]) == FAILURE) // check duplicate
		{
			insert_last(head, argv[i]); // add the valid file
			printf("INFO : Successfull: inserting file name %s into file linked list\n\n",argv[i]);
		}
		else{
			printf("INFO : %s => This file is repeated, so it will not store into the sll\n\n",argv[i]);
		}

		fclose(fp); // close the file
	}
}

int insert_last(F_node **head, char *f_name)
{
	F_node *new = malloc(sizeof(F_node));

	if (new == NULL)
		return FAILURE;

	strcpy(new->f_name, f_name);
	new->link = NULL;

	if (*head == NULL)
	{
		*head = new;
		return SUCCESS;
	}

	F_node *temp = *head;

	while (temp->link != NULL)
	{
		temp = temp->link;
	}

	temp->link = new;

	return SUCCESS;
}

// logic for Check node
int check_duplicates(F_node *head, char *f_name)
{
	while (head)
	{
		if (strcmp(head->f_name, f_name) == 0)
			return SUCCESS;

		head = head->link;
	}

	return FAILURE;
}

// Logic for find index
int get_index(char *word)
{
	if (isupper((unsigned char)word[0]))
	{
		return word[0] - 'A';
	}
	else if (islower((unsigned char)word[0]))
	{
		return word[0] - 'a';
	}
	
	else
	{
		return 26;
	}
}

// logic to create
struct Main *create_mNode()
{
	M_node *new = malloc(sizeof(M_node));
	if (new == NULL)
	{
		printf("Main Node not created\n");
		return NULL;
	}
	return new;
}

struct Sub *create_snode()
{
	S_node *new = malloc(sizeof(S_node));
	if (new == NULL)
	{
		printf("Sub Node not created\n");
		return NULL;
	}
	return new;
}

void delete_file(F_node **head, char *fname)
{
    if (*head == NULL)
        return ;

    F_node *temp = *head;
    F_node *prev = NULL;

    while (temp != NULL)
    {
        if (strcmp(temp->f_name, fname) == 0)
        {
            if (prev == NULL)        // First node
                *head = temp->link;
            else
                prev->link = temp->link;

            free(temp);
            return ;
        }

        prev = temp;
        temp = temp->link;
    }
}

void print_filelist(F_node *head)
{
    if (head == NULL)
    {
        printf("-> NULL\n");
        return;
    }

    printf("\nHead");

    while (head != NULL)
    {
        printf(" -> %s", head->f_name);
        head = head->link;
    }

    printf(" -> NULL\n\n");
	return;
}