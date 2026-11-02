# Inverted Search Using C

## Project Description

Developed an Inverted Search application using C programming to efficiently index and search words across multiple text files. The project implements the concept of an inverted index, a fundamental data structure used in search engines and information retrieval systems.

The application scans multiple input text files, extracts individual words, and creates an inverted index that maps each unique word to the list of files in which it appears, along with its occurrence count.

Implemented the indexing mechanism using linked lists to maintain unique words and their associated file details. Each word is stored in a main linked list, while a sub-linked list maintains the filenames and occurrence counts for that particular word.

Designed modular functions to support database creation, displaying the indexed data, searching for specific words, updating the existing database with new files, and saving the indexed information into a backup file for future use.

The application also includes file validation, duplicate word handling, and efficient database management using dynamic memory allocation and pointer manipulation.

## Key Features

- Creates an inverted index from multiple text files.
- Extracts and indexes unique words from input files.
- Maintains a list of filenames associated with each word.
- Tracks the occurrence count of each word in individual files.
- Supports searching for specific words across indexed files.
- Displays the complete inverted index database.
- Supports updating the database with additional files.
- Saves the indexed database into a backup file.
- Supports restoring the database from a saved backup.
- Handles duplicate words and file validation.
- Uses linked lists for dynamic data management.

## Technologies Used

- Programming Language: C
- Data Structures: Singly Linked Lists
- Concepts: File Handling, Dynamic Memory Allocation, Pointers, Structures, String Manipulation, Searching Algorithms, Modular Programming.

## C Programming Concepts Implemented

- File operations using `fopen()`, `fclose()`, `fscanf()`, and `fgets()`.
- Dynamic memory allocation using `malloc()` and `free()`.
- Singly linked list creation and traversal.
- Nested linked lists for word and file management.
- String comparison and manipulation.
- Pointer manipulation and structure-based data organization.
- Database creation, searching, updating, and backup operations.
- Modular programming using separate functions.

## Learning Outcomes

Gained practical experience in implementing an inverted indexing system using linked lists. Improved understanding of data structures, dynamic memory allocation, pointers, file handling, string processing, searching techniques, and database management. Developed problem-solving skills by building a word-indexing and retrieval system similar to the basic indexing mechanism used in search engines.
