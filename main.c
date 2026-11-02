/*
Name : Deepak Balappa Badiger
Date : 23-07-2026
Description:Developed an Inverted Search Engine in C that indexes multiple text files for fast keyword searching.
 The project uses a hash table to store words alphabetically and linked lists to maintain file names and word frequencies. 
 It supports creating a searchable database from multiple files, searching for keywords, displaying the indexed database, updating the database with new files, and saving/restoring the database from a backup file. 
 The project extensively uses data structures, dynamic memory allocation, pointers, and file handling, making searches significantly faster than scanning every file each time.
*/ 
#include "inverted.h"

int main(int argc, char *argv[])
{
	F_node *head = NULL;
	hash_t HT[27];
	for (int i = 0; i < 27; i++)
	{
		HT[i].index = i;
		HT[i].main_link = NULL;
	}

	// Validate_files
	validate_files(argc, argv, &head);

	int option;
	int c_flag = 0, u_flag = 0; // flags for special test cases
	do
	{
		printf("Select your choice among following operations:\n1. Create Database\n2. Display Database\n3. Save Database\n4. Search\n5. Update Database\n6. Exit\n\nEnter your choice : ");

		scanf("%d", &option);

		switch (option)
		{
		case 1:
			if (c_flag != 0)
			{
				printf("INFO : Database is already created\n");
				break;
			}
			create_database(HT, head);
			c_flag = 1;
			break;

		case 2:
			display_database(HT);
			break;

		case 3:
			save_database(HT);
			break;

		case 4:
			search_database(HT);
			break;

		case 5:
			if (c_flag != 0 && u_flag != 0)
			{
				printf("Update database is not possible\n");
				break;
			}
			update_database(HT, &head);
			u_flag = 1;
			break;

		case 6:
			break;

		default:
			printf("INFO : Please enter the valid option\n");
		}
	} while (option != 6);

	return 0;
}
