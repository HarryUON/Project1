//*****************************************************************************/
// c3255600 - ENGG1003
// Menu driven cipher/decipher program by Harry Elliott
//*****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char code [100];
char message[80];
int choice;
char string[80];//string to encrypt
int rotatorN;
int n = 0;
int shiftKey = 0; //the desired difference between the string and the encryption
int i=0; //counter1
int i2=0; //counter2
int i3=0; //counter3


int find_index(char code[],char char_to_find)
{
    for(int i=0;i<26;i++)
    {
        if(code[i]==char_to_find)
        {
            return i;
        }
    }
    return-1;
}
//find the index of the character^^^


char*encrypt(char*message,char code[])
{
    int length=strlen(message);
    char*encrypted_message=(char*)malloc(sizeof(char)*length);
    for(int i=0;i<length;i++)
    {
        int encryption_index=tolower(message[i]-'a');
        if(encryption_index>=0&&encryption_index<26)
        {
            encrypted_message[i]=code[encryption_index];
        }
        else
        {
            encrypted_message[i]=message[i];
        }
        if (encrypted_message[i]>=97 && encrypted_message[i]<=122)
        {
            encrypted_message[i]=encrypted_message[i]-32; 
        }   //converting output to upper-case ^^^
    }
    return encrypted_message;
}


char*decrypt(char*message,char code[]){
    int length= strlen(message);
    char*decrypted_message = (char*)malloc(sizeof(char)*length);
    for(int i=0;i<length;i++){
        int decryption_index=tolower(message[i])-'a';
        if(decryption_index>=0&&decryption_index<26){
            int code_index=find_index(code,tolower(message[i]));
            decrypted_message[i]='a'+ code_index;
        }
        else{
            decrypted_message[i]=message[i];
        }}
    return decrypted_message;
    }
    
    
char*encrypt2(char*string,int rotatorN)
    {    
	for(i=0; string[i] != '\0'; i++) 
     {                                            //first for loop
          if(string[i] >='a' && string[i] <='z')  //for every letter within a/z
             {
                n = 'z' - string[i];
                if( rotatorN > n )
                 {
                    shiftKey = rotatorN - n - 1;
                    string[i] = 'a';             //making string loop back to 'a' when reaching 'z'
                    string[i] += shiftKey;
                  }  
               else
                string[i] += rotatorN;
               }
    for(i2=0;i2<n;i2++)                          //second for loop
    {
        if (string[i]>=97 && string[i]<=122)
            string[i]=string[i]-32;             // makes output upper-case                   
    }  
       }
    for(i3=0; string[i3] !='\0'; i3++)         //third for loop
        {
        printf("%c", string[i3]);             //prints every character of the encoded string
        }
        return string;
}

char*decrypt2(char*message,char code[]){
    int length= strlen(message);
    char*decrypted_message2 = (char*)malloc(sizeof(char)*length);
    for(int i=0;i<length;i++){
        int decryption_index=tolower(message[i])-'a';
        if(decryption_index>=0&&decryption_index<26){
            int code_index=find_index(code,tolower(message[i]));
            decrypted_message2[i]='a'+ code_index;
        }
        else{
            decrypted_message2[i]=message[i];
        }}
    return decrypted_message2;
    }

    
int main(){
        printf("Chose from one of the options below: \n");
        printf("1. Encrypting a substitution cypher: \n");
        printf("2. Decrypting a substitution cypher: \n");
        printf("3. Encrypting a ceasar cypher: \n");
        printf("4. Decrypting a ceasar cypher: \n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        printf("%d\n",choice);
        switch (choice)
        {
//******************************************************************************
//Encryption of a message using a custom Substitution cypher
//Possible combinations: 26! ≈ 4 × 1026
//Example character code:

//  qzmdjftkvehycxopbrsguiwnla 
//******************************************************************************
        case 1:
            printf("Enter String (in lower case): ");
            scanf("%s",message);
            printf("%s\n",message);
            printf("Enter the char code: ");
            scanf("%s",code);
            printf("%s\n",code);
            char*encrypted_message = encrypt(message,code);
            printf("Encrypted Message: ");
            printf("%s",encrypted_message);    
            break;

//******************************************************************************
// Decryption of a message encrypted with a unique substitution cipher
// Requieres an encoded string and a character key
//******************************************************************************
        case 2:
            printf("Enter an encrypted message: ");
            scanf("%s",message);
            printf("%s\n",message);
            printf("Enter the char code: ");
            scanf("%s",code);
            printf("%s\n",code);
            printf("Original message: %s\n",message);
            char*decrypted_message = decrypt(message,code);
            printf("Decrypted message: %s",decrypted_message);
            break;
                      
//******************************************************************************
//Encryption of a message using a custom ceasar cipher
//Example encrypted cipher:
//******************************************************************************
        case 3:
            printf("Enter String (in lower case): ");
            scanf("%s",string);//storing the users input string
            printf("%s",string);
            printf("Enter the shift-key (between 1/25): ");
            scanf("%d", &rotatorN);//storing the users shift-key inupt
            printf("%d\n",rotatorN);
            printf("Encrypted message: ");
            encrypt2(string,rotatorN);
            break;
        
//******************************************************************************
//Decryption of a message encrypted with a custom ceasar cipher
//Example encrypted cipher:

//Encrypted message: olssv dvysk
//Rotation amount: 7               (d(c) = (c − k)(%7))
//******************************************************************************
        case 4:
            printf("Enter the char code: ");
            scanf("%s",code);
            printf("%s\n",code);
            printf("Enter an encrypted message: ");
            scanf("%s",message);
            printf("%s\n",message);
            char*decrypted_message2 = decrypt2(message,code);
            printf("Decrypted message: %s",decrypted_message2);
            break;
       }
         
    return 0;
}
