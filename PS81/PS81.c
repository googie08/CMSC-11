#include<stdio.h>

struct Name{
  char first[100];
  char last[100];
};

struct Address{
  char province[100];
  int zipCode;
};

struct PBEntry{
    struct Name name;
    struct Address address;
    int age;
    long int mobile;
};

void printMenu();
void addEntry(struct PBEntry pb[], int *SIZE);
void editEntry(struct PBEntry pb[], int SIZE);
void showAll(struct PBEntry [], int SIZE);

int main(void){

    struct PBEntry phonebook[10];
    int choice = 1, SIZE = 0;

    printf("Welcome to Phonebook Application\n");

    while(choice != 4 ){
        printMenu();
        printf("\nInput: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addEntry(phonebook, &SIZE);
                break;
            case 2:
                editEntry(phonebook, SIZE);
                break;
            case 3:
                showAll(phonebook, SIZE);
                break;
            case 4:
                return 0;
        }
    }
}

void printMenu(){
    printf("\nPhonebook Main Menu\n");
    printf("1. Add Entry\n");
    printf("2. Edit Entry\n");
    printf("3. Show All\n");
    printf("4. Exit\n");
}

void addEntry(struct PBEntry pb[], int *SIZE) {
    printf("\n\n-----------------------------------\n\n");
    if (*SIZE >= 10) {
        printf("Phonebook is full\n");
        return;
    }
    int i = *SIZE;

    printf("ADD NEW ENTRY\n");
    printf("First Name: ");
    scanf("%s", pb[i].name.first);
    printf("Last Name: ");
    scanf("%s", pb[i].name.last);
    printf("Province: ");
    scanf("%s", pb[i].address.province);
    printf("Zip Code: ");
    scanf("%d", &pb[i].address.zipCode);
    printf("Age: ");
    scanf("%d", &pb[i].age);
    printf("Mobile Number: ");
    scanf("%ld", &pb[i].mobile);

    (*SIZE)++;
    printf("\nEntry %d added successfully!", *SIZE);
    printf("\n\n-----------------------------------\n\n");
    return;
}

void editEntry(struct PBEntry pb[], int SIZE){
    printf("\n\n-----------------------------------\n\n");
    printf("EDIT ENTRY\n");
    if (SIZE == 0) {
        printf("No entries found\n");
        printf("\n-----------------------------------\n\n");
        return;
    }

    int i;
    printf("Enter Phonebook entry number to edit (1-%d): ", SIZE);
    scanf("%d", &i);
    i--;

    if (i < 0 || i >= SIZE) {
        printf("Invalid entry number\n");
        printf("\n-----------------------------------\n\n");
        return;
    }

    printf("Editing entry #%d: %s %s\n", i+1, pb[i].name.first, pb[i].name.last);
    printf("New First Name: ");
    scanf("%s", pb[i].name.first);
    printf("New Last Name: ");
    scanf("%s", pb[i].name.last);
    printf("New Province: ");
    scanf("%s", pb[i].address.province);
    printf("New Zip Code: ");
    scanf("%d", &pb[i].address.zipCode);
    printf("New Age: ");
    scanf("%d", &pb[i].age);
    printf("New Mobile Number: ");
    scanf("%ld", &pb[i].mobile);
    printf("Entry #%d updated successfully!", i+1);
    printf("\n-----------------------------------\n\n");
}

void showAll(struct PBEntry pb[], int SIZE){
    printf("\n\n-----------------------------------\n\n");
    printf("SHOW ALL ENTRIES");
    if (SIZE == 0) {
        printf("\nNo entries found\n");
        printf("\n-----------------------------------\n\n");
        return;
    }

    printf("\nPhonebook Entries:\n");
    for (int i=0; i<SIZE; i++) {
        printf("\nEntry %d: \n", i+1);
        printf("Name: %s %s\n", pb[i].name.first, pb[i].name.last);
        printf("Address: %s, %d\n", pb[i].address.province, pb[i].address.zipCode);
        printf("Age: %d\n", pb[i].age);
        printf("Mobile Number: %ld\n", pb[i].mobile);
    }

    printf("\n-----------------------------------\n\n");
}
