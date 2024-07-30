# Library Management System Using C

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Functionality](#functionality)


## Introduction

The Library Management System is a simple yet effective tool for managing a library's inventory of books. This console-based application allows users to add, view, search, edit, and delete book records. It also includes a password-protected login feature to ensure only authorized users can access the system.

<img width="881" alt="image" src="https://github.com/user-attachments/assets/ae06f705-9751-46a9-a4a6-1e5e2418712a">



## Features

- **Password Protection**: Ensures only authorized users can access the system.
- **Add Books**: Allows users to add new books to the library's inventory.
- **View Books**: Displays a list of all books available in the library.
- **Search Books**: Enables users to search for books by their ID.
- **Edit Books**: Allows users to update the details of existing books.
- **Delete Books**: Provides functionality to remove books from the library's inventory.
- **Help Section**: Offers guidance on how to use the system.

## Functionality

### Password Protection
- **Function**: `password()`
- **Description**: Prompts the user to enter a password to access the system. The default password is "murali". The user gets three attempts to enter the correct password.

  <img width="598" alt="image" src="https://github.com/user-attachments/assets/51a4a0c2-cc49-428b-8ec0-c2270342e1b2">


### Add Books
- **Function**: `addBook()`
- **Description**: Allows the user to add a new book to the library by entering the book's ID, Name, Author, Quantity, and Rack Number. It checks for duplicate IDs before adding the book.

### View Books
- **Function**: `viewBooks()`
- **Description**: Displays all books currently available in the library, including their ID, Name, Author, Quantity, and Rack Number. It also shows the total number of books.

### Search Books
- **Function**: `searchBook()`
- **Description**: Allows the user to search for a book by its ID. If the book is found, its details are displayed.
  <img width="523" alt="image" src="https://github.com/user-attachments/assets/5427060f-4fc5-4a2e-ad09-d1c380f8c9b7">


### Edit Books
- **Function**: `editBook()`
- **Description**: Enables the user to update the details of an existing book by entering the book's ID. The user can modify the Name, Author, Quantity, and Rack Number.

  <img width="324" alt="image" src="https://github.com/user-attachments/assets/4a7fd7ea-0241-46d5-bac6-570ef82237be">


### Delete Books
- **Function**: `deleteBook()`
- **Description**: Allows the user to remove a book from the library by entering the book's ID. The book is permanently deleted from the inventory.
  <img width="512" alt="image" src="https://github.com/user-attachments/assets/556a7950-6635-44d4-9152-58d61d142834">


### Help Section
- **Function**: `help()`
- **Description**: Provides information on how to use the system, including the default password and available functionalities.

### Exit Program
- **Function**: `exitprog()`
- **Description**: Exits the application after displaying a thank you message.

## Technologies Used

- **C**: Programming language used for implementing the application.
- **Standard Libraries**: Including `<stdio.h>`, `<stdlib.h>`, `<string.h>`, `<time.h>`, and `<windows.h>` for various functionalities.




<img width="904" alt="image" src="https://github.com/user-attachments/assets/a754aec5-389d-4f72-9fd4-5a82ad376177">


