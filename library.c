#include <stdio.h>
#include <string.h>

// Define a structure for a book
struct Book {
    char title[100];
    char author[100];
    int year;
};

// Function to add a book to the library
void addBook(struct Book library[], int *numBooks) {
    printf("Enter book title: ");
    scanf("%s", library[*numBooks].title);

    printf("Enter author: ");
    scanf("%s", library[*numBooks].author);

    printf("Enter publication year: ");
    scanf("%d", &library[*numBooks].year);

    (*numBooks)++;
    printf("Book added successfully!\n");
}

// Function to display all books in the library
void displayBooks(struct Book library[], int numBooks) {
    printf("Library Books:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Year: %d\n\n", library[i].year);
    }
}

// Function to search for a book by title
void searchBook(struct Book library[], int numBooks) {
    char searchTitle[100];
    printf("Enter the title to search: ");
    scanf("%s", searchTitle);

    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Book found!\n");
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Year: %d\n", library[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

int main() {
    struct Book library[100]; // Assuming a maximum of 100 books in the library
    int numBooks = 0;
    int choice;

    do {
        // Display menu
        printf("\nLibrary System Menu:\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &numBooks);
                break;
            case 2:
                displayBooks(library, numBooks);
                break;
            case 3:
                searchBook(library, numBooks);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option...\n");
        }
    } while (choice != 4);

    return 0;
}
