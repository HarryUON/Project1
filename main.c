//*****************************************************************************/
// c3255600 - ENGG1003
// Menu driven cipher/decipher program by Harry Elliott
//*****************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdio.h>
	char string[80];//string to encrypt
	char origString[80];
    int  rotatorN;
    int n = 0;
    int choice;
    int shiftKey = 0; //the desired difference between the string and the encryption
    int i=0; //counter1
    int i2=0; //counter2
    int i3=0; //counter3
    char message[80];
    char code [100];
    int key;
    
    
    char*encrypt(char*string,int rotatorN)
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


    char*decrypt(char*string,int rotatorN)
    {
	for(i=0; string[i] != '\0'; i++) 
     {                                            //first for loop
          if(string[i] >='a' && string[i] <='z')  //for every letter within a/z
             {
                n = 'a' - string[i];
                if( rotatorN < n )
                 {
                    shiftKey = rotatorN - n + 1;
                    string[i] = 'z';             //making string loop back to 'z' when reaching 'a'
                    string[i] -= shiftKey;
                  }  
               else
                string[i] -= rotatorN;
               }
       }    
       
    
    
    for(i3=0; string[i3] !='\0'; i3++)         //third for loop
        {
        printf("%c", string[i3]);             //prints every character of the encoded string
        }
        return string;
}



    
int main ()
{
    printf("Chose from one of the options below: \n");
    printf("1. Encrypting a substitution cypher: \n");
    printf("2. Decrypting a substitution cypher: \n");
    printf("3. Encrypting a ceasar cypher: \n");
    printf("4. Decrypting a ceasar cypher: \n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    printf("%d\n",choice);
    printf("\n");
    switch (choice)
    {
        
//******************************************************************************
//Encryption of a message using a custom ceasar cipher
//Example encrypted cipher:
//******************************************************************************
case 1:
    printf("*Encrypting a cesar cipher*");
    printf("\nEnter the shift-key (between 1/25): ");
    scanf("%d", &rotatorN);//storing the users shift-key inupt
    printf("%d\n",rotatorN);
    puts("Enter String (in lower case): ");
    while (getchar() != '\n');
    {
        fgets(string, 80, stdin);
    }
    printf("%s", string);
    printf("Encrypted string: ");
    encrypt(string,rotatorN);
    break;
 
//******************************************************************************
//Decryption of an encrypted ceasar cipher message
//Example encrypted cipher:
//******************************************************************************  
case 2:
    printf("*Decrypting a cesar cipher*\n");
    puts("Enter String (in lower case): ");
    while (getchar() != '\n');
    {
        fgets(string, 80, stdin);
    }
    printf("%s", string);
    printf("Enter the shift-key (between 1/25): ");
    scanf("%d", &rotatorN);//storing the users shift-key inupt
    printf("%d\n",rotatorN);
    printf("Decrypted string: ");
    decrypt(string,rotatorN);
    break;
    
    
    
    
    }
return 0;}


