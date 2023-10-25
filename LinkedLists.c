#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ContactNode_struct {
   /* Define ContactNode struct here. */
   char contactName[999];
   char contactPhoneNumber[999];
   struct ContactNode_struct* nextNodePtr;
   
} ContactNode;



void InitializeContactNode(ContactNode *user) {

   printf("Enter contact name: ");
   fgets(user->contactName, 999, stdin);
   user->contactName[strcspn(user->contactName, "\n")] = '\0'; // Remove newline

   printf("Enter contact phone number: ");
   fgets(user->contactPhoneNumber, 999, stdin);
   user->contactPhoneNumber[strcspn(user->contactPhoneNumber, "\n")] = '\0'; // Remove newline

   user->nextNodePtr = NULL;

}

void PrintContactNode(ContactNode user, int personNumber) {
   

   printf("Person %d: %s, %s\n", personNumber, user.contactName, user.contactPhoneNumber);
  
   
   }
   



int main(void) {
   

   
   
   ContactNode user1;
   ContactNode user2;
   ContactNode user3;
   ContactNode* currentNode;

   // get 3 contact nodes initialized with values
   InitializeContactNode(&user1);
   InitializeContactNode(&user2);
   InitializeContactNode(&user3);


   // LINK THE LISTS
   user1.nextNodePtr = &user2;
   user2.nextNodePtr = &user3;
      // user3.nextNodePtr already set to null above
   
   
   
      // Start from the beginning of the linked list
   currentNode = &user1;
   int personNumber = 1; // Initialize person number

   while(currentNode != NULL) {
      PrintContactNode(*currentNode, personNumber);
      currentNode = currentNode->nextNodePtr; // Move to the next node
      personNumber = personNumber + 1;
   }



// SIMPLE
// quit the program after everything is done
   printf("\n\nPress any character and Enter to quit: ");
   getchar(); // Wait for any character input

   


   return 0;
}
