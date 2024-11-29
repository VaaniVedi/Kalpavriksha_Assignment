#include <stdio.h>
#include <stdlib.h>

struct record {
    int id;
    char name[100];
    int age;
};

int isvalid(FILE *ptr,int id){
    struct record user;
    rewind(ptr);
    while(fscanf(ptr,"%d %s %d\n",&user.id, user.name, &user.age)==3){
        if(user.id==id){
            printf("ID %d already exists.\n",id);
            return 0;
        }
    }
    return 1;
}
void create_op(FILE *ptr){
    struct record user;
    printf("Enter ID:");
    scanf("%d", &user.id);
    while(!isvalid(ptr,user.id)){
        printf("Please enter a valid unique ID.\n");
        printf("Enter ID:");
        scanf("%d", &user.id);     
    }
    
    printf("Enter Name:");
    scanf("%s", user.name);
    printf("Enter Age:");
    scanf("%d", &user.age);

    fprintf(ptr, "%d %s %d\n", user.id, user.name, user.age);
    printf("User added successfully.\n");
}


void update_op(FILE *ptr, int user_id) {
    struct record user;
    FILE *temp = fopen("temp.txt", "w");
    rewind(ptr);
    int found = 0;
    while (fscanf(ptr, "%d %s %d\n", &user.id, user.name, &user.age) != EOF) {
        if (user.id == user_id) {
            printf("Enter new Name and Age: ");
            scanf("%s %d", user.name, &user.age);
            found = 1;
        }
        fprintf(temp, "%d %s %d\n", user.id, user.name, user.age);
    }
    fclose(ptr);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt", "users.txt");
    if (found) {
        printf("User updated successfully.\n");
    } else {
        printf("User not found.\n");
    }
    fopen("users.txt","a+");
}

void read_op(FILE *ptr){
    struct record user;
    rewind(ptr);
    printf("Displaying all records...\n"); 
    while(fscanf(ptr,"%d %s %d\n",&user.id, user.name, &user.age)!=EOF){
        printf("ID: %d, Name: %s, Age: %d\n", user.id, user.name, user.age);
    }
    fclose(ptr);
    ptr=fopen("users.txt","a+");
}

void delete_op(FILE *ptr, int id){
    struct record user;
    FILE *temp;
    temp = fopen("temp.txt","w");
    if(temp==NULL){
    printf("Some error in file opening! \n");
    return;
   }
    rewind(ptr);
    int flag=0;
    while(fscanf(ptr,"%d %s %d\n",&user.id, user.name, &user.age)!=EOF){
        if(user.id != id){
            fprintf(temp,"%d %s %d\n",user.id, user.name, user.age);
        } else {
            flag=1;
        }
    }
    fclose(ptr);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt","users.txt");

    if(flag==1){
        printf("User deleted.\n");
    } else{
        printf("User not found.\n");
    }
    ptr=fopen("users.txt","a+");
}

int main(){
   FILE* ptr;
   ptr=fopen("users.txt","a+");
   if(!ptr){
    printf("Some error in file opening! \n");
    return 1;
   }
   int choice=0, id;
   while(choice!=5){
    printf("\n1. Create user. \n2. Update user.\n3. Read user.\n4. Delete user.\n5. Exit");
    printf("\nEnter choice: ");
    scanf("%d",&choice);
    if(choice==1){
        create_op(ptr);
    }
    else if(choice==2){
        printf("Enter the ID of the user that you have to update: ");
        scanf("%d",&id);
        update_op(ptr,id);
    }
    else if(choice==3){
        read_op(ptr);        
    }
    else if(choice==4){
        printf("Enter the ID of the user that you have to remove: ");
        scanf("%d",&id);
        delete_op(ptr,id);  
    }
    else if(choice==5){
        break;
    }
    else{
        printf("Invalid choice!\n");
    }
   }
    fclose(ptr);  // Close file
    return 0;
}