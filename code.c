#include <stdio.h>
#include<stdlib.h>

char stack[100]; int top=-1;
void push(char x)
{
    stack[++top]=x;
    top=top+1;
}
void encryption()
{
    char message[100],c;
    int i,key;
    printf("\nEnter the message to encrypt:");
    scanf("\n%[^\n]s",message);
    printf("\nEnter key:");
    scanf("%d",&key);
    for(i=0;message[i]!='\0';i++)
    {
        c=message[i];
        if(c>='a'&& c<='z')
        {
            c=(((message[i]+key-97)%26)+97);
            push(c);
        }
        else if(c>='A'&& c<='Z')
        {
            c=(((message[i]+key-65)%26)+65);
            push(c);
        }
        else if(c>=' ' && c<='@')
        {
            c=(((message[i]+key-32)%33)+32);
            push(c);
        }
        else if(c>='['&& c<='`')
        {
            c=(((message[i]+key-91)%6)+91);
            push(c);
        }
        else if(c>='{' && c<='~')
        {
            c=(((message[i]+key-123)%4)+123);
            push(c);
        }
    }
    printf("Encrypted message is\n");
    for(i=0;i<=top;i++)
    {
        printf("%c",stack[i]);
    }
    top=-1;
}
void decryption()
{
    char message[100], ch; int i, key, keyk;
    printf("\nEnter a message to decrypt: ");
    scanf("\n%[^\n]s",message);
    printf("\nEnter key: ");
    scanf("%d", &key);
    for(i=0;message[i]!='\0';i++)
    {
        ch = message[i];
        if(ch >= 'a' && ch <= 'z')
        {
            keyk=key%26;
            ch=message[i]-keyk;
            if(ch<'a')
            {
                ch=ch+26;
            }
            push(ch);
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            keyk=key%26;
            ch=message[i]-keyk;
            if(ch<'A')
            {
                ch=ch+26;
            }
            push(ch);
            }
        else if(ch>=' ' && ch<='@')
        {
            keyk=key%33;
            ch=message[i]-keyk;
            if(ch<' ')
            {
                ch=ch+33;
            }
            push(ch);
        }
        else if(ch>='[' && ch<='`')
        {
            keyk=key%6;
            ch=message[i]-keyk;
            if(ch<'[')
            {
                ch=ch+6;
            }
            push(ch);
        }
        else if(ch>='{'&&ch<='~')
        {
            keyk=key%4;
            ch=message[i]-keyk;
            if(ch<'{')
            {
                ch=ch+4;
            }
            push(ch);
        }
    }
    printf("Decrypted message:\n");
    for(i=0;i<=top;i++)
    {
        printf("%c",stack[i]);
    }
    top=-1;
}
int main()
{
    int start;
    while(1)
    {
        printf("\n 1. CIPHER");
        printf("\n 2. DECIPHER");
        printf("\n 3. EXIT");
        printf("\n Enter your choice:");
        scanf("%d",&start);
        switch(start)
        {
            case 1: encryption();
            break;
            case 2: decryption();
            break;
            case 3: exit(1);
            default: printf("Invalid Input\n");
        }
    }
}