#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct entry
{
    char name[50];
    char doorno[50];
    char aptmtn[50];
    char strt[50];
    char place[50];
    char city[50];
    char pincode[50];
    char contact[50];
    char email[50];
    struct entry *lptr;
    struct entry *rptr;
}*start=NULL,*end=NULL,*tmp;
void addentry();
void displayall();
void save();
void display();
void disp_file();
void modify();
void deletee();
void deleteall();
void main()
{
    int ch=0;
    char a[50];
    while(ch!=8)
    {
        system("cls");
        printf("\t\t\t\t\tPROJECT - ADDRESS BOOK\nMenu:\n\t(1) - Add a new entry\n\t(2) - Display all details\n\t(3) - Display details of a specific person\n\t(4) - Load Entries from the file\n\t(5) - Modify an Entry\n\t(6) - Delete an entry\n\t(7) - Delete all the saved data\n\t(8) - Exit\n\tEnter your choice - ");
        scanf("%d",&ch);
        if(ch==1)
        {
            addentry();
            getch();
        }
        else if(ch==2)
        {
            displayall();
            getch();
        }
        else if(ch==3)
        {
            display();
            getch();
        }
        else if(ch==4)
        {
            disp_file();
            getch();
        }
        else if(ch==5)
        {
            modify();
            getch();
        }
        else if(ch==6)
        {
            deletee();
            getch();
        }
        else if(ch==7)
        {
            deleteall();
            getch();
        }
        else if(ch==8)
            exit(1);
        else
        {
            printf("Enter a valid choice!!!");
            getch();
        }
    }
}
void addentry()
{
    struct entry *newe;
    int j;
    char k[5];
    newe = (struct entry*)malloc(sizeof(struct entry));
    printf("\nEnter the details:\n");
    gets(k);
    printf("Name: ");
    gets(newe->name);
    printf("Door no: ");
    gets(newe->doorno);
    printf("Apartment Name: ");
    gets(newe->aptmtn);
    printf("Street: ");
    gets(newe->strt);
    printf("Place: ");
    gets(newe->place);
    printf("City: ");
    gets(newe->city);
    printf("Pin-code: ");
    gets(newe->pincode);
    printf("Contact: ");
    gets(newe->contact);
    printf("Email: ");
    gets(newe->email);
    newe->lptr=NULL;
    newe->rptr=NULL;
    if(start==NULL)
    {
        start=newe;
        end=newe;
    }
    else
    {
        tmp=(struct entry*)malloc(sizeof(struct entry));
        tmp=start;
        if(tmp->rptr==NULL)
        {
            if(strcmpi(tmp->name,newe->name)<0 || strcmpi(tmp->name,newe->name)==0)
            {
                tmp->rptr=newe;
                newe->lptr=tmp;
                end=newe;
            }
            else if(strcmpi(tmp->name,newe->name)>0)
            {
                tmp->lptr=newe;
                newe->rptr=tmp;
                start=newe;
            }
        }
        else
        {
            while(tmp!=NULL)
            {
                if(strcmpi(tmp->name,newe->name)<0 && strcmpi((tmp->rptr)->name,newe->name)>0)
                {
                    newe->rptr=tmp->rptr;
                    (tmp->rptr)->lptr=newe;
                    tmp->rptr=newe;
                    newe->lptr=tmp;
                    break;
                }
                else if(strcmpi(tmp->name,newe->name)==0 && strcmpi((tmp->rptr)->name,newe->name)>0)
                {
                    newe->rptr=tmp->rptr;
                    (tmp->rptr)->lptr=newe;
                    tmp->rptr=newe;
                    newe->lptr=tmp;
                    break;
                }
                else if(strcmpi(tmp->name,newe->name)>0 && tmp->lptr==NULL)
                {
                    tmp->lptr=newe;
                    newe->rptr=tmp;
                    start=newe;
                    break;
                }
                else if(strcmpi(tmp->name,newe->name)<0 && tmp->rptr==NULL)
                {
                    tmp->rptr=newe;
                    newe->lptr=tmp;
                    end=newe;
                    break;
                }
                tmp=tmp->rptr;
            }
        }
    }
    save();
    printf("Entry is added");
}
void displayall()
{
    if(start==NULL)
        printf("No entries present");
    else
    {
        system("cls");
        tmp=(struct entry*)malloc(sizeof(struct entry));
        tmp=start;
        int i=0;
        while(tmp!=NULL)
        {
            printf("\nEntry %d:\nName: %s\nAddress: %s,%s,\n%s,\n%s,\n%s.\nPin-code: %s\nMobile: %s\nEmail-id: %s\n",++i,tmp->name,tmp->doorno,tmp->aptmtn,tmp->strt,tmp->place,tmp->city,tmp->pincode,tmp->contact,tmp->email);
            tmp=tmp->rptr;
        }
    }
}
void save()
{
    FILE *f;
    f=fopen("Address Book.txt","w");
    tmp=(struct entry*)malloc(sizeof(struct entry));
    tmp=start;
    while(tmp!=NULL)
    {
        fprintf(f,"\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",tmp->name,tmp->doorno,tmp->aptmtn,tmp->strt,tmp->place,tmp->city,tmp->pincode,tmp->contact,tmp->email);
        tmp=tmp->rptr;
    }
    fclose(f);
}
void display()
{
    char name[50],a[50];
    int f=0;
    if(start==NULL)
        printf("No entries present");
    else
    {
        system("cls");
        tmp=(struct entry*)malloc(sizeof(struct entry));
        tmp=start;
        printf("Enter the name of the person: ");
        gets(a);
        gets(name);
        while(tmp!=NULL)
        {
            if(strcmpi(tmp->name,name)==0)
            {
                printf("\nName: %s\nAddress: %s,%s,\n%s,\n%s,\n%s.\nPin-code: %s\nMobile: %s\nEmail-id: %s\n",tmp->name,tmp->doorno,tmp->aptmtn,tmp->strt,tmp->place,tmp->city,tmp->pincode,tmp->contact,tmp->email);
                f=1;
            }
            else if(strcmpi(tmp->name,name)>0 && f==0)
            {
                printf("Name not found!!!");
                break;
            }
            else if(strcmpi(tmp->name,name)>0)
                break;
            tmp=tmp->rptr;
        }
    }
}
void disp_file()
{
    int i=0;
    char a[50];
    tmp=(struct entry*)malloc(sizeof(struct entry));
    FILE *f;
    f=fopen("Address Book.txt","r");
    system("cls");
    if(f==NULL)
        printf("No entries present");
    else
    {
        while(fgets(a,50,f)!=NULL)
        {
            fgets(tmp->name,50,f);
            fgets(tmp->doorno,50,f);
            fgets(tmp->aptmtn,50,f);
            fgets(tmp->strt,50,f);
            fgets(tmp->place,50,f);
            fgets(tmp->city,50,f);
            fgets(tmp->pincode,50,f);
            fgets(tmp->contact,50,f);
            fgets(tmp->email,50,f);
            printf("\nEntry %d:\nName: %sAddress: %s%s%s%s%sPin-code: %sMobile: %sEmail-id: %s",++i,tmp->name,tmp->doorno,tmp->aptmtn,tmp->strt,tmp->place,tmp->city,tmp->pincode,tmp->contact,tmp->email);
        }
    }
}
void modify()
{
    char name[50],a[50],b[50],c[5];
    int f=0,i,x;
    if(start==NULL)
        printf("No entries present");
    else
    {
        tmp=(struct entry*)malloc(sizeof(struct entry));
        tmp=start;
        printf("Whose details do you want to change?\n");
        gets(a);
        gets(name);
        while(tmp!=NULL)
        {
            if(strcmpi(tmp->name,name)==0)
            {
                for(;;)
                {
                    system("cls");
                    printf("\nWhich one do you want to modify?\n\t(1) - Name\n\t(2) - Door number\n\t(3) - Apartment Name\n\t(4) - Street\n\t(5) - Place\n\t(6) - City\n\t(7) - Pin-Code\n\t(8) - Contact\n\t(9) - Email\n\tEnter your choice - ");
                    scanf("%d",&i);
                    gets(c);
                    if(i>=1 && i<=9)
                    {
                        if(i==1)
                        {
                            printf("New Name: ");
                            gets(b);
                            strcpy(tmp->name,b);
                        }
                        else if(i==2)
                        {
                            printf("New Door No: ");
                            gets(b);
                            strcpy(tmp->doorno,b);
                        }
                        else if(i==3)
                        {
                            printf("New Apartment Name: ");
                            gets(b);
                            strcpy(tmp->aptmtn,b);
                        }
                        else if(i==4)
                        {
                            printf("New Street: ");
                            gets(b);
                            strcpy(tmp->strt,b);
                        }
                        else if(i==5)
                        {
                            printf("New Place: ");
                            gets(b);
                            strcpy(tmp->place,b);
                        }
                        else if(i==6)
                        {
                            printf("New City: ");
                            gets(b);
                            strcpy(tmp->city,b);
                        }
                        else if(i==7)
                        {
                            printf("New Pin-Code: ");
                            gets(b);
                            strcpy(tmp->pincode,b);
                        }
                        else if(i==8)
                        {
                            printf("New Contact: ");
                            gets(b);
                            strcpy(tmp->contact,b);
                        }
                        else if(i==9)
                        {
                            printf("New Email: ");
                            gets(b);
                            strcpy(tmp->email,b);
                        }
                    }
                    else
                        printf("Enter valid choice!!!");
                    printf("\nDo you want to modify anything else in the entry?(1 for yes/0 for no) - ");
                    scanf("%d",&x);
                    if(x==1);
                    else if(x==0)
                        break;
                    else
                        printf("Enter a valid choice");
                }
                system("cls");
                printf("Entry after changes\n");
                printf("\nName: %s\nAddress: %s,%s,\n%s,\n%s,\n%s.\nPin-code: %s\nMobile: %s\nEmail-id: %s\n",tmp->name,tmp->doorno,tmp->aptmtn,tmp->strt,tmp->place,tmp->city,tmp->pincode,tmp->contact,tmp->email);
                f=1;
                printf("\nEntry saved!!!");
            }
            else if(strcmpi(tmp->name,name)>0 && f==0)
            {
                printf("Name not found!!!");
                break;
            }
            else if(strcmpi(tmp->name,name)>0)
                break;
            tmp=tmp->rptr;
        }
    }
    save();
}
void deletee()
{
    char name[50],a[50];
    if(start==NULL)
        printf("No entries present");
    else
    {
        system("cls");
        tmp=(struct entry*)malloc(sizeof(struct entry));
        tmp=start;
        gets(a);
        printf("Enter the name of the person: ");
        gets(name);
        while(tmp!=NULL)
        {
            if(strcmpi(tmp->name,name)==0)
            {
                if(tmp->lptr==NULL && tmp->rptr==NULL)
                {
                    start=NULL;
                    end=NULL;
                }
                else if(tmp->lptr==NULL && tmp->rptr!=NULL)
                    start=start->rptr;
                else if(tmp->lptr!=NULL && tmp->rptr==NULL)
                    end=end->lptr;
                else
                {
                    (tmp->lptr)->rptr=tmp->rptr;
                    (tmp->rptr)->lptr=tmp->lptr;
                }
                printf("\nDeleted the entry\n");
                printf("\nName: %s\nAddress: %s,%s,\n%s,\n%s,\n%s.\nPin-code: %s\nMobile: %s\nEmail-id: %s\n",tmp->name,tmp->doorno,tmp->aptmtn,tmp->strt,tmp->place,tmp->city,tmp->pincode,tmp->contact,tmp->email);
                break;
            }
            else if(strcmpi(tmp->name,name)>0)
            {
                printf("Name not found!!!");
                break;
            }
            tmp=tmp->rptr;
        }
    }
    save();
}
void deleteall()
{
    start=NULL;
    end=NULL;
    save();
    printf("\nDeleted all the files!!!");
}
