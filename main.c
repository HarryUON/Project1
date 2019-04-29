//*****************************************************************************/
// c3255600 - ENGG1003
// Menu driven cipher/decipher program by Harry Elliott
// Program takes user input from stdin (upper AND lower case)
// Does not attempt to decipher substitution cipher w/o key.


// 	★★★ Rotation cipher 1 (without key) ★★★
// Encrypted cipher: "TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. DL HSZV RUVD AOHA AOL DLHWVU ZFZALTZ VM AOPZ KLHAO ZAHY HYL UVA FLA VWLYHAPVUHS. DPAO AOL PTWLYPHS MSLLA ZWYLHK AOYVBNOVBA AOL NHSHEF PU H CHPU LMMVYA AV LUNHNL BZ, PA PZ YLSHAPCLSF BUWYVALJALK. IBA TVZA PTWVYAHUA VM HSS, DL'CL SLHYULK AOHA AOL LTWLYVY OPTZLSM PZ WLYZVUHSSF VCLYZLLPUN AOL MPUHS ZAHNLZ VM AOL JVUZAYBJAPVU VM AOPZ KLHAO ZAHY. THUF IVAOHUZ KPLK AV IYPUN BZ AOPZ PUMVYTHAPVU". 
// Decrypted cipher: "MON MOTHMA: THE DATA BROUGHT TO US BY THE BOTHAN SPIES PINPOINTS THE EXACT LOCATION OF THE EMPEROR'S NEW BATTLE STATION. WE ALSO KNOW THAT THE WEAPON SYSTEMS OF THIS DEATH STAR ARE NOT YET OPERATIONAL. WITH THE IMPERIAL FLEET SPREAD THROUGHOUT THE GALAXY IN A VAIN EFFORT TO ENGAGE US, IT IS RELATIVELY UNPROTECTED. BUT MOST IMPORTANT OF ALL, WE'VE LEARNED THAT THE EMPEROR HIMSELF IS PERSONALLY OVERSEEING THE FINAL STAGES OF THE CONSTRUCTION OF THIS DEATH STAR. MANY BOTHANS DIED TO BRING US THIS INFORMATION."
// Key: 17


// 	★★★ Rotation cipher 2 (without key) ★★★
// Encrypted cipher: "SJSFMPCRM WG O USBWIG. PIH WT MCI XIRUS O TWGV PM WHG OPWZWHM HC QZWAP O HFSS, WH KWZZ ZWJS WHG KVCZS ZWTS PSZWSJWBU HVOH WH WG GHIDWR. - OZPSFH SWBGHSWB" 
// Decrypted cipher: "EVERYBODY IS A GENIUS. BUT IF YOU JUDGE A FISH BY ITS ABILITY TO CLIMB A TREE, IT WILL LIVE ITS WHOLE LIFE BELIEVING THAT IT IS STUPID. - ALBERT EINSTEIN
// Key: 14

//*****************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
	char string[1000];//string to encrypt
	char origString[80];
    int  rotatorN;
    char chara[50];
    int n = 0;
    int choice;
    int shiftKey = 0; //the desired difference between the string and the encryption
    int i=0; //counter1
    int i2=0; //counter2
    int i3=0; //counter3
    int i4 = 0;
    char message[1000];
    char code [26];
    int key;
    
//*******************************************************************
//Ceasar cipher encription function prototype ↓↓↓
    
    char*encrypt(char*string,int rotatorN)
    {
	for(i=0; string[i] != '\0'; i++) 
     {                                            //first for loop
          if(string[i] >='a' && string[i] <='z' || string[i] >='A' && string[i] <='Z')  //for every letter within a/z (upper and lower case)
             {
                n = 'z' - string[i];
                if( rotatorN > n )
                 {
                    shiftKey = rotatorN - n - 1;
                    string[i] = 'a'-32;             //making string loop back to 'a' when reaching 'z'
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
//Ceasar cipher decryption function prototype ↓↓↓

char*decrypt(char*string,int rotatorN)
{
for(i=0; string[i] != '\0'; i++) 
{                                            //first for loop
    n = string[i]; 
    if(string[i] >='a' && string[i] <='z')  //for every letter within a/z (upper and lower case)
    {
        n = n - rotatorN;
        if( n<'a')
        {
            n=n+'z'-'a'+1;
        }            
        string[i]=n;
    }
    else if(n>='A' && n<='Z')
    {
        n=n-rotatorN;
        if (n<'A')
        {
            n=n+'Z'-'A'+1;
        }
        string[i]=n;
    }}
    i2=0;
    for(i2=0;i2<strlen(string);i2++)                          //second for loop
    {
        if (string[i2]>=97 && string[i2]<=122)
        {
            string[i2]=string[i2]-32;             // makes output upper-case                   
        }

    } 
    printf("%s",string);
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
    i4=0;
    for(i4=0;i4<27;i4++)
    {
        if (code[i4]>=65 && code[i4]<=90)
        {
            code[i4]+=32;
        }
    }
    for(int i=0;i<length;i++)
    {
        if (message[i] >='A' && message[i] <='Z')
        {
            message[i] = message[i] + 32;          //Allowing upper case input
        }
        
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
    i4=0;
    for(i4=0;i4<27;i4++)
    {
        if (code[i4]>=65 && code[i4]<=90)  // including upper case character codes
        {
            code[i4]+=32;
        }
    }

    for(int i=0;i<length;i++)
    {
        if (message[i] >='A' && message[i] <='Z')
        {
            message[i] = message[i] + 32;          //Allowing upper case input
        }
        int decryption_index=tolower(message[i])-'a';
        if(decryption_index>=0&&decryption_index<26){
            int code_index=find_index(code,tolower(message[i]));
            decrypted_message[i]='a'+ code_index;
        }
        else{
            decrypted_message[i]=message[i];
        }
    }
//Making the output upper case if entered lower case ↓↓↓
    i2=0;
    for(i2=0;i2<strlen(decrypted_message);i2++)                          //second for loop
    {
        if (decrypted_message[i2]>=97 && decrypted_message[i2]<=122)
        {
            decrypted_message[i2]=decrypted_message[i2]-32;             // makes output upper-case                   
        }
    }

    return decrypted_message;  
    }  
    
//*******************************************************************
// Program main menu & switch statement ↓↓↓

int main ()
{
    printf("↓↓ Chose from one of the options below ↓↓ \n\n");
    printf("1. Encrypting a custom rotation cypher: \n");
    printf("2. Decrypting a custom rotation cypher: \n");
    printf("3. Encrypting a custom substitution cypher: \n");
    printf("4. Decrypting a custom substitution cypher: \n");
    printf("5. Exit \n");
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
    printf("★★★ Decrypting a Custom Cesar Cipher ★★★\n\n\n");
    printf("Enter String (in lower case): \n");
    while (getchar() != '\n');
    {
        fgets(string,sizeof(string), stdin);
    }
    printf("%s\n\n", string);
    printf("Enter the shift-key (between 1/25): ");
    scanf("%d", &rotatorN);//storing the users shift-key inupt
    printf("%d\n\n\n",rotatorN);
    printf("Decrypted string: ");
    decrypt(string,rotatorN);
    break;
    
//******************************************************************************
//Program 3:
//Encryption of a message using a custom Substitution cypher
//Possible combinations: 26! ≈ 4 × 1026
//↓↓ My custom character code ↓↓
// qzmdjftkvehycxrpbosguiwnla  
//******************************************************************************    
case 3:
    printf("★★★ Encrypting a Custom Substitution Cipher ★★★\n\n");
    printf("Enter String (in lower case): \n");
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
// ↓↓ My custom character code ↓↓
//  qzmdjftkvehycxrpbosguiwnla 
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
    break;
    
    
case 5:
    printf("Bye!");
    exit(0);
    break;

default:
    printf("You have entered an invalid choice...\n\n");
    printf("Run again and chose from options 1 to 5.");
    break;
    }
return 0;
}
