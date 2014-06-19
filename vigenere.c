/**********************************************
 * vigenere.c
 * 
 * Megumi Jinushi
 * megumij@hawaii.edu
 * 
 * Encipher the texts using Vigenere's cipher
 **********************************************/
# include <string.h>
# include <stdio.h> 
# include <stdlib.h> 
# include <cs50.h>
# include <ctype.h>

// declaration of functions
int CodeP(int pass);
int CodeT(char alphabet);
char Add(char alphabet);

// take a secret keyword in the command-line
int main (int argc, string argv[])
{
    // check if the # of arguments is exactly 2.
    if (argc != 2)
    {
        printf("Did you type the password?\n");
        return 1;
    }
                
    string password = argv[1]; // Call the command argument, argv[1], "password" 
    
    // Check if password is only alphabetical letters
    for (int i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            printf("Password only contains alphabet\n");
            return 1;
        }    
    }
          
    string text = GetString(); // Get user's input
    
    // Iterate as long as strlen (text)
    for (int j = 0, k = 0; j < strlen(text); j++)
    {
        if (isalpha(text[j])) // if alphabet, allow iterate through password
        {
            // keep track of password
            k = k % strlen(password); // wrap around the password in case password < text                                           

            char pass_letter = password[k]; // letter represents the kth char of password                   
            int shift_p = CodeP(pass_letter); // culculate how many keys password needs to shift
            
            // identify pass_letter is xth letter of alphabet 
            char letter = text[j];
            int shift_t = CodeT(letter);
            
            // culculate how many keys total it needs to shit           
            char shift = shift_t + shift_p;
            
            // wrap around in case it exceed 26
            if (shift > 26)
            {
                shift = shift % 26;             
            }
            
            // add 'a' or 'A' to the # of key to shift to encipher
            char cipher = shift + Add(text[j]); 
            printf("%c", cipher);    
            k += 1; // increment j to the next letter of password 
        }
        
        else // if not alphabet, print the user input
        {
            printf("%c", text[j]);
        }  
    }            
    printf("\n");
}

// Functions

// culculates how many keys each letter of password needs to shift
int CodeP(int pass)
{
    int shift_p = 0;
    //check texti
    if (islower(pass))
    {
        shift_p = pass - 97;    
    }
    
    else if (isupper(pass))
    {
        shift_p = pass - 65;
    }
    
    return shift_p;
}

// culculates how many keys each text letter needs to shift
int CodeT(char alphabet)
{
    int shift_t = 0;

    if (islower(alphabet))
    {
        shift_t = alphabet - 97;    
    }
    
    else if (isupper(alphabet))
    {
        shift_t = alphabet - 65;
    } 
    
    return shift_t;
}

// identify the case of text[i], then accordingly returns 'a' or 'A'
char Add(char alphabet)
{
    int base = 0;
    if (islower(alphabet))
    {
        base = 97;     
    }
    
    else if (isupper(alphabet))
    {
        base = 65;
    }
    return base;
}
