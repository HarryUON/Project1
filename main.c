//*****************************************************************************/
// c3255600 - ENGG1003
// Menu driven cipher/decipher program by Harry Elliott
//*****************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
    
//*******************************************************************
//Ceasar cipher encription function prototype ↓↓↓
    
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

//*******************************************************************
//Ceasar cipher decription function prototype ↓↓↓

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
       //Making the output upper case ↓↓↓
    i2=0;
    for(i2=0;i2<strlen(string);i2++)                          //second for loop
    {
        if (string[i2]>=97 && string[i2]<=122)
        {
            string[i2]=string[i2]-32;             // makes output upper-case                   
        }}     
       }    
       
    
    
    for(i3=0; string[i3] !='\0'; i3++)         //third for loop
        {
        printf("%c", string[i3]);             //prints every character of the encoded string
        }
        return string;
}

//*******************************************************************
//Function prototype to find the index of the character ↓↓↓

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

//*******************************************************************
//Substitution cipher encryptor function prototype ↓↓↓

char*encrypt2(char*message,char code[])
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
        //Making the output upper case ↓↓↓
        if (encrypted_message[i]>=97 && encrypted_message[i]<=122)
        {
            encrypted_message[i]=encrypted_message[i]-32; 
        }  
    }
    return encrypted_message;
}


//*******************************************************************
//Substitution cipher decryptor function prototype ↓↓↓

char*decrypt2(char*message,char code[]){
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
//Making the output upper case ↓↓↓
    i2=0;
    for(i2=0;i2<strlen(decrypted_message);i2++)                          //second for loop
    {
        if (decrypted_message[i2]>=97 && decrypted_message[i2]<=122)
        {
            decrypted_message[i2]=decrypted_message[i2]-32;             // makes output upper-case                   
        }}
    return decrypted_message;  
    }  
    
//*******************************************************************
// Program main menu & switch statement ↓↓↓

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
//Program 1:
//Encryption of a message using a custom ceasar cipher
//Example encrypted cipher:
//******************************************************************************
case 1:
    printf("★★★ Encrypting a Custom Cesar Cipher ★★★\n\n");
    puts("Enter String (in lower case): ");
    while (getchar() != '\n');
    {
        fgets(string, 80, stdin);
    }
    printf("%s", string);
    printf("\nEnter the shift-key (between 1/25): ");
    scanf("%d", &rotatorN);//storing the users shift-key inupt
    printf("%d\n\n",rotatorN);
    printf("Encrypted string: ");
    encrypt(string,rotatorN);
    break;
 
//******************************************************************************
//Program 2:
//Decryption of an encrypted ceasar cipher message
//Example encrypted cipher:
//******************************************************************************    
case 2:
    printf("★★★ Decrypting a Custom Cesar Cipher ★★★\n\n");
    puts("Enter String (in lower case): \n");
    while (getchar() != '\n');
    {
        fgets(string, 80, stdin);
    }
    printf("%s", string);
    printf("Enter the shift-key (between 1/25): ");
    scanf("%d", &rotatorN);//storing the users shift-key inupt
    printf("%d\n\n",rotatorN);
    printf("Decrypted string: ");
    decrypt(string,rotatorN);
    break;
    
//******************************************************************************
//Program 3:
//Encryption of a message using a custom Substitution cypher
//Possible combinations: 26! ≈ 4 × 1026
//↓↓ My custom character code ↓↓
//  qzmdjftkvehycxopbrsguiwnla 
//******************************************************************************    
case 3:
    printf("★★★ Encrypting a Custom Substitution Cipher ★★★\n\n");
    puts("Enter String (in lower case): ");
    while (getchar() != '\n');
    {
        fgets(message, 80, stdin);
    }
    printf("%s\n",message);
    printf("Enter the char code: ");
    scanf("%s",code);
    printf("%s\n",code);
    char*encrypted_message = encrypt2(message,code);
    printf("\nEncrypted Message: ");
    printf("%s",encrypted_message);    
    break;

//******************************************************************************
//Program 4:    
//Decryption of a custom substitution cypher (with key)
//Enter the key as the substituted alphabet (no spaces)
//Example encrypted msg: kqrrl jyyvogg
//Character code: qzmdjftkvehycxopbrsguiwnla 
//******************************************************************************
case 4: 
    printf("★★★ Decrypting a Custom Substitution Cipher ★★★\n\n");
    printf("Enter an encrypted string (in lower-case): \n\n");
    while (getchar() != '\n');
    {
        fgets(message, 80, stdin);
    }
    printf("Enter the char code: ");
    scanf("%s",code);
    printf("%s\n",code);
    printf("Original message: %s\n",message);
    char*decrypted_message = decrypt2(message,code);
    printf("Decrypted message: %s",decrypted_message);    
    
    }
return 0;
}
