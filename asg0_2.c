#include <stdio.h>
#include <stdlib.h>

struct record {
    int id;
    char name[100];
    int age;

};

int isUniqueId(FILE *fileptr, int id){
    struct record user;
    rewind(fileptr);
    while(fscanf(fileptr,"%d %s %d\n",&user.id, user.name, &user.age)==3){
        if(user.id==id){
            printf("ID %d already exists.\n",id);
            return 0;
        }
    }
    return 1;

}

void createUserRecord(){
    struct record user;
    FILE* fileptr = fopen("users.txt","a+");
    if(!fileptr){
        printf("Some error in file opening! \n");
        return;
    } 
    printf("Enter ID:");
    scanf("%d", &user.id);
    while(!isUniqueId(fileptr,user.id)){
        printf("Please enter a valid unique ID.\n");
        printf("Enter ID:");
        scanf("%d", &user.id);     
    }
    
    printf("Enter Name:");
    scanf("%s", user.name);
    printf("Enter Age:");
    scanf("%d", &user.age);

    fprintf(fileptr, "%d %s %d\n", user.id, user.name, user.age);
    printf("User added successfully.\n");
    fclose(fileptr);

}


void updateUserRecord(int user_id) {
    struct record user;
    FILE* fileptr = fopen("users.txt","r");
    if(!fileptr){
        printf("Some error in file opening! \n");
        return;
    }
    FILE *tempFilePtr = fopen("temp.txt", "w+");
    if(!tempFilePtr){
        printf("Some error in file opening! \n");
        return;
    }
    int userFound = 0;
    while (fscanf(fileptr, "%d %s %d\n", &user.id, user.name, &user.age) != EOF) {
        if (user.id == user_id) {
            printf("Enter new Name and Age: ");
            scanf("%s %d", user.name, &user.age);
            userFound = 1;
        }
        fprintf(tempFilePtr, "%d %s %d\n", user.id, user.name, user.age);
    }
    fclose(fileptr);
    fclose(tempFilePtr);
    
    if (userFound) {
        remove("users.txt");
        rename("temp.txt", "users.txt");
        printf("User updated successfully.\n");
    } else {
        printf("User not found with the given id.\n");
    }

}

void readUserRecord(){
    struct record user;
    FILE* fileptr = fopen("users.txt","r");
    if(!fileptr){
        printf("Some error in file opening! \n");
        return;
    }
    printf("Displaying all records...\n"); 
    while(fscanf(fileptr,"%d %s %d\n",&user.id, user.name, &user.age)!=EOF){
        printf("ID: %d, Name: %s, Age: %d\n", user.id, user.name, user.age);
    }
    printf("Records read Successfully\n");
    fclose(fileptr);

}

void deleteUserRecord(int id){
    struct record user;
    FILE *tempFilePtr = fopen("temp.txt","w");
    if(!tempFilePtr){
        printf("Some error in file opening! \n");
        return;
    }
    FILE* fileptr = fopen("users.txt","a+");
    if(!fileptr){
        printf("Some error in file opening! \n");
        return;
    }

    int userFound=0;
    while(fscanf(fileptr,"%d %s %d\n",&user.id, user.name, &user.age)!=EOF){
        if(user.id != id){
            fprintf(tempFilePtr,"%d %s %d\n",user.id, user.name, user.age);
        } else {
            userFound=1;
        }
    }
    fclose(fileptr);
    fclose(tempFilePtr);

    if(userFound==1){
        remove("users.txt");
        rename("temp.txt","users.txt");
        printf("User deleted.\n");

    } else{
        printf("User not found.\n");
    }
    
}

int main(){
	int choice = 0, id;
    while (choice != 5)	{
		printf("\n1. Create user. \n2. Update user.\n3. Read user.\n4. Delete user.\n5. Exit");
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		if (choice == 1){
			createUserRecord();
		}
		else if (choice == 2){
			printf("Enter the ID of the user that you have to update: ");
			scanf("%d", &id);
			updateUserRecord(id);
		}
		else if (choice == 3){
			readUserRecord();
		}
		else if (choice == 4){
			printf("Enter the ID of the user that you have to remove: ");
			scanf("%d", &id);
			deleteUserRecord(id);
		}
		else if (choice == 5){
			printf("You have successfully exited!");
			break;
		}
		else{
			printf("Invalid choice!\n");
		}
	}

	return 0;
}
