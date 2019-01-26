//Data file handling.
/*
   1. Create a file.
   2. Display a file.
   3. Display the details of a given team number.
   4. Display the details of teams of a given sponsor.
   5. Display the details of teams in a given winning price range.
   6. To add a wild card entry in the tournament.
   7. Disqualify a team from the tournament.
   8. Modification of a team record.
   9. Sorting of teams.
   10.Insertion of a team.
   11.Number of teams and total file size.
   12.Insertion of a team without using temporary file.
   13.Log out.
*/
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<fstream.h>
#include<dos.h>
#include<graphics.h>
#include<ctype.h>
class tournament
{
 int tno;          // For team number.
 char tname[20];   // For team name.
 char sname[20];   // For sponsor name.
 long double price;// For winning price.
 int nop;          // For number of players.
 char dcode[10];   // For dress code.
 char result[10];  // For result of the tournament.
 float htotal;     // For highest total made by the team.
 public:
	// Default constructor.
	tournament()
	{
	 tno=0;
	 tname[0]='\0';
	 sname[0]='\0';
	 price=0;
	 nop=0;
	 dcode[0]='\0';
	 result[0]='\0';
	 htotal=0;
	}
	// Parameterised constructor.
	tournament(int a,char b[],char c[],float d,int e,char f[],char g[],long double h)
	{
	 tno=a;
	 strcpy(tname,b);
	 strcpy(sname,c);
	 price=d;
	 nop=e;
	 strcpy(dcode,f);
	 strcpy(result,g);
	 htotal=h;
	}
	// Copy constructor.
	tournament(tournament &T)
	{
	 tno=T.tno;
	 strcpy(tname,T.tname);
	 strcpy(sname,T.sname);
	 price=T.price;
	 nop=T.nop;
	 strcpy(dcode,T.dcode);
	 strcpy(result,T.result);
	 htotal=T.htotal;
	}
	// Destructor.
	~tournament()
	{
	}
	void input();
	void output()
	{
	 cout<<"\n\n";
	 cout<<"\t\tThe team number is               :\t";
	 cout<<tno<<'\n';
	 cout<<"\t\tThe team name is                 :\t";
	 cout<<tname<<'\n';
	 cout<<"\t\tThe sponsor name is              :\t";
	 cout<<sname<<'\n';
	 cout<<"\t\tThe winning price of the team is :\t";
	 cout<<price<<'\n';
	 cout<<"\t\tThe no of players are            :\t";
	 cout<<nop<<'\n';
	 cout<<"\t\tThe dress code is                :\t";
	 cout<<dcode<<'\n';
	 cout<<"\t\tThe result of the team is        :\t";
	 cout<<result<<'\n';
	 cout<<"\t\tThe highest total by the team is :\t";
	 cout<<htotal<<'\n';
	 delay(2500);
	 clrscr();
	}
	void output1()
	{
	 gotoxy(10,6);
	 cout<<"The team number is:";
	 gotoxy(55,6);
	 cout<<tno<<'\n';
	 gotoxy(10,8);
	 cout<<"The team name is:";
	 gotoxy(55,8);
	 cout<<tname<<'\n';
	 gotoxy(10,10);
	 cout<<"The sponsor name is:";
	 gotoxy(55,10);
	 cout<<sname<<'\n';
	 gotoxy(10,12);
	 cout<<"The winning price of the team is:";
	 gotoxy(55,12);
	 cout<<price<<'\n';
	 gotoxy(10,14);
	 cout<<"The no of players are:";
	 gotoxy(55,14);
	 cout<<nop<<'\n';
	 gotoxy(10,16);
	 cout<<"The dress code is:";
	 gotoxy(55,16);
	 cout<<dcode<<'\n';
	 gotoxy(10,18);
	 cout<<"The result of the team is:";
	 gotoxy(55,18);
	 cout<<result<<'\n';
	 gotoxy(10,20);
	 cout<<"The highest total by the team is:";
	 gotoxy(55,20);
	 cout<<htotal<<'\n';
	 gotoxy(10,22);
	}
	int rettno()
	{
	 return(tno);
	}
	char *retsname()
	{
	 return(sname);
	}
	long double retprice()
	{
	 return(price);
	}
};
void tournament::input()
{
 cout<<"\nEnter the team number\n";
 cin>>tno;
 while(!cin)
 {
  cout<<"That was not an integer. Please enter an integer\n";
  cin.clear();
  cin.ignore();
  cin>>tno;
 }
 cout<<"Enter the team name\n";
 gets(tname);
 for(int i=0;i<sizeof(tname-1);i++)
 {
  if(!(isalpha(tname[i]))||(isspace(tname[i])))
  {
   cout<<"Enter valid team name (characters only)\n";
   cin.get();
   cin.getline(tname,10);
   i=0;
  }
 }
 cout<<"Enter the no of players\n";
 cin>>nop;
 while(!cin)
 {
  cout<<"That was not an integer. Please enter an integer\n";
  cin.clear();
  cin.ignore();
  cin>>nop;
 }
 cout<<"Enter the sponsor name\n";
 gets(sname);
 for(int j=0;j<sizeof(sname-1);j++)
 {
  if(!(isalpha(sname[j]))||(isspace(sname[j])))
  {
   cout<<"Enter valid sponsor name (characters only)\n";
   cin.get();
   cin.getline(sname,10);
   j=0;
  }
 }
 cout<<"Enter the winning price of the team\n";
 cin>>price;
 while(!cin)
 {
  cout<<"That was not an integer. Please enter an integer\n";
  cin.clear();
  cin.ignore();
  cin>>price;
 }
 cout<<"Enter the dress code\n";
 gets(dcode);
 for(i=0;i<sizeof(dcode-1);i++)
 {
  if(!(isalpha(dcode[i]))||(isspace(dcode[i])))
  {
   cout<<"Enter valid dress code (characters only)\n";
   cin.get();
   cin.getline(dcode,10);
   i=0;
  }
 }
 cout<<"Enter the highest total by the team\n";
 cin>>htotal;
 while(!cin)
 {
  cout<<"That was not an integer. Please enter an integer\n";
  cin.clear();
  cin.ignore();
  cin>>htotal;
 }
 cout<<"The result of the team \n";
 gets(result);
 for(j=0;j<sizeof(result-1);j++)
 {
  if(!(isalpha(result[j]))||(isspace(result[j])))
  {
   cout<<"Enter valid result (characters only)\n";
   cin.get();
   cin.getline(result,10);
   j=0;
  }
 }
}
//To create a box.
void box()
{
 gotoxy(1,1);
 cout<<"*******************";
 gotoxy(1,25);
 cout<<"*******************";
 gotoxy(61,25);
 cout<<"*******************";
 gotoxy(61,1);
 cout<<"*******************";
 cout<<"\nPress any key to continue";
 getch();
 gotoxy(1,2);
 clreol();
}
//To create a binary file which contains the objects of class tournament.
void create()
{
 tournament t;
 char ch;
 ofstream f("sports.dat",ios::binary);
 if(f==NULL)
 {
  cout<<"Error in opening file\n";
  getch();
  return;
 }
 do
 {
  t.input();
  f.write((char *)&t,sizeof(t));
  cout<<"Do you want to enter more records\n";
  cin>>ch;
  if(ch=='Y' || ch=='y')
  {
   clrscr();
   cout<<"Press enter key to enter next record\n";
   delay(5000);
   clrscr();
  }
  getch();
 }while(ch=='Y'|| ch=='y');
 f.close();
}
//To display the contents of the above created file.
void display()
{
 ifstream f;
 tournament t;
 f.open("sports.dat",ios::binary);
 if(!(f))
 {
  cout<<"Error in opening file\n";
  getch();
  return;
 }
 f.read((char *)&t,sizeof(t));
 while(f)
 {
  t.output();
  f.read((char *)&t,sizeof(t));
 }
 f.close();
}
//To display the details of team whose number is passed as argument.
void display(int no)
{
 tournament t;
 int flag=-1;
 ifstream f;
 f.open("sports.dat",ios::binary);
 if(!(f))
 {
  cout<<"Error in opening file\n";
  getch();
  return;
 }
 f.read((char *)&t,sizeof(t));
 while(f)
 {
  if(t.rettno()==no)
  {
   flag=1;
   t.output1();
   break;
  }
  f.read((char *)&t,sizeof(t));
 }
 f.close();
 if(flag==-1)
  cout<<"Record not found\n";
}
// To display details of teams of a given sponsor.
void display(char sn[])
{
 tournament t;
 int flag=-1;
 ifstream f("sports.dat",ios::binary);
 if(f==NULL)
 {
  cout<<"Error in opening file\n";
  getch();
  return;
 }
 f.read((char *)&t,sizeof(t));
 while(f)
 {
  int x=strcmp(sn,t.retsname());
  if(x==0)
  {
   flag=1;
   t.output1();
  }
  f.read((char *)&t,sizeof(t));
 }
 f.close();
 if(flag==-1)
  cout<<"Record not found\n";
}
// To display the details of teams whose winning price lies in the given range.
void display(long double l,long double u)
{
 tournament t;
 int flag=-1;
 ifstream f("sports.dat",ios::binary);
 if(f==NULL)
 {
  cout<<"Error in opening file\n";
  getch();
  return;
 }
 f.read((char *)&t,sizeof(t));
 while(f)
 {
  if(t.retprice()>=l && t.retprice()<=u)
  {
   flag=1;
   t.output1();
  }
  f.read((char *)&t,sizeof(t));
 }
 f.close();
 if(flag==-1)
  cout<<"Record not found\n";
}
// To append a wild card entry in the tournament.
void append()
{
 tournament t;
 fstream f("sports.dat",ios::binary|ios::app);
 if(!(f))
 {
  cout<<"Error in finding file\n";
  getch();
  return;
 }
 cout<<"Enter the new team details\n";
 t.input();
 f.write((char *)&t,sizeof(t));
 f.close();
}
// Deletion of a team for not obeying the tournament rules.
void DELETE(int tn)
{
 int flag=-1;
 tournament t;
 char ch;
 ifstream f1("sports.dat",ios::binary);
 ofstream f2("temp.dat",ios::binary);
 if(f1==NULL || f2==NULL)
 {
  cout<<"Error in opening file\n";
  getch();
  return;
 }
 f1.read((char *)&t,sizeof(t));
 while(f1)
 {
  if(t.rettno()!=tn)
   f2.write((char *)&t,sizeof(t));
  else
  {
   flag=1;
   cout<<"Do you want the team to be permanently disqualified\n";
   cin>>ch;
   if(ch=='Y' || ch=='y')
   cout<<"Disqualified\n";
   else
    f2.write((char *)&t,sizeof(t));
  }
  f1.read((char *)&t,sizeof(t));
 }
 f1.close();
 f2.close();
 if(flag==-1)
  cout<<"Record not found\n";
 remove("sports.dat");
 rename("temp.dat","sports.dat");
}
//Modification in a team using sequential processing.
void modify(int tn)
{
 tournament t;
 int flag=0;
 ifstream f1;
 ofstream f2;
 f1.open("sports.dat",ios::binary);
 f2.open("temp.dat",ios::binary);
 if(f1==NULL || f2==NULL)
 {
  cout<<"Error in opening file\n";
  getch();
  return;
 }
 f1.read((char *)&t,sizeof(t));
 while(f1)
 {
  if(t.rettno()==tn)
  {
   flag=1;
   cout<<"Enter the new details\n";
   t.input();
  }
  f2.write((char *)&t,sizeof(t));
  f1.read((char *)&t,sizeof(t));
 }
 if(flag==0)
  cout<<"Record not found\n";
 f1.close();
 f2.close();
 remove("sports.dat");
 rename("temp.dat","sports.dat");
}
//Sorting of teams .
void sort()
{
 tournament t[100],temp;
 int n=0;
 ifstream f1("sports.dat",ios::binary);
 if(!(f1))
 {
  cout<<"Error in opening file\n";
  getch();
  return;
 }
 f1.read((char *)&t[n],sizeof(tournament));
 while(f1)
 {
  n++;
  f1.read((char *)&t[n],sizeof(tournament));
 }
 f1.close();
 for(int i=1;i<n;i++)
 {
  temp=t[i];
  int j=i-1;
  while((j>=0) && (temp.rettno()<t[j].rettno()))
  {
   t[j+1]=t[j];
   j--;
  }
  t[j+1]=temp;
 }
 ofstream f2("sports.dat",ios::binary);
 if(f2==NULL)
 {
  cout<<"Error in opening file\n";
  getch();
  return;
 }
 for(i=0;i<n;i++)
  f2.write((char *)&t[i],sizeof(tournament));
 f2.close();
}
//Insertion of a new team .
void insertion(tournament tk)
{
 tournament t;
 char found='N';
 ifstream f1("sports.dat",ios::binary);
 ofstream f2("temp.dat",ios::binary);
 if(f1==NULL || f2==NULL)
 {
  cout<<"Error in opening file\n";
  getch();
  return;
 }
 while(f1.read((char *)&t,sizeof(t)))
 {
  if(t.rettno()<tk.rettno())
   f2.write((char *)&t,sizeof(t));
  else
  {
   found='Y';
   f2.write((char *)&tk,sizeof(tk));
   break;
  }
 }
 if(found=='N')
  f2.write((char *)&tk,sizeof(tk));
 else
 {
  while(f1)
  {
   f2.write((char *)&t,sizeof(t));
   f1.read((char *)&t,sizeof(t));
  }
 }
 f1.close();
 f2.close();
 remove("sports.dat");
 rename("temp.dat","sports.dat");
}
//To display the total file size of sports.dat and also the total no of teams.
void nor()
{
 tournament t;
 int r;
 ifstream f;
 f.open("sports.dat",ios::binary);
 if(f==NULL)
 {
  cout<<"Error in openiig file\n";
  getch();
  return;
 }
 f.seekg(0,ios::end);
 long x=f.tellg();
 gotoxy(10,10);
 cout<<"The file size is:";
 gotoxy(45,10);
 cout<<x;
 r=x/sizeof(t);
 gotoxy(10,12);
 cout<<"The no of teams are:";
 gotoxy(45,12);
 cout<<r;
 f.close();
}
// Insertion of a team without using temporary file.
void updater()
{
 tournament t;
 int no;
 fstream f("sports.dat",ios::binary|ios::in|ios::app);
 if(f==NULL)
 {
  cout<<"Error in opening file\n";
  getch();
  return;
 }
 while(f.read((char *)&t,sizeof(t)))
 {
  f.seekg(f.tellg()-sizeof(t));
  t.input();
  f.write((char *)&t,sizeof(t));
  break;
 }
 f.close();
}
void main()
{
 int p=0,i;
 clrscr();
 char user[9],us[]={"hssjseva"},ps[]={"28122789"},pass[9];
 for(int j=0;j<3;j++)
 {
  p=0;
  clrscr();
  cout<<"\n\n\n\n\n\t\t\tEnter the username\n\t\t\t";
  gets(user);
  if(strcmpi(user,us)==0)
  {
   cout<<"\n\n\t\t\tEnter the password\n\t\t\t";
   for(i=0;i<=7;i++)
   {
    pass[i]=getch();
    cout<<"*";
   }
   if(strcmp(pass,ps)==0)
    p=8;
   if(p==8)
   {
    clrscr();
    cout<<"\n\n\n\n\n\n\t\t\t\t";
    cprintf("Logging in");
    delay(1500);
    clrscr();
    clrscr();
    cout<<"			* * * *                 " <<'\n';
    cout<<"			*     *                 " <<'\n';
    cout<<"			*     *                 " <<'\n';
    cout<<"			*     *                 " <<'\n';
    cout<<"			* * * *                 " <<'\n';
    cout<<"		       *       *                " <<'\n';
    cout<<"		      *	        *               " <<'\n';
    cout<<"		     * * * * * * *              " <<'\n';
    cout<<"		     *           *              " <<'\n';
    cout<<"		     *		 *              " <<'\n';
    cout<<"		     *	   M	 *              " <<'\n';
    cout<<"		     *	   R	 *              " <<'\n';
    cout<<"		     *	   F	 *              " <<'\n';
    cout<<"		     *		 *              " <<'\n';
    cout<<"		     *		 *              " <<'\n';
    cout<<"		     * * * * * * *              " <<'\n';
    cout<<"		     *           *     *  *  *  " <<'\n';
    cout<<"		     *           *   *         *" <<'\n';
    cout<<"		     *           *   *         *" <<'\n';
    cout<<"		     *           *   *         *" <<'\n';
    cout<<"		     *           *     *  *  *  " <<'\n';
    cout<<"                     *           *       " <<'\n';
    cout<<"                     * * * * * * *       " <<'\n';
    getch();
    clrscr();
    break;
   }
   else
   {
    clrscr();
    cout<<"\n\n\n\t\tWrong password";
    delay(500);
   }
  }
  else
   continue;
 }
 if(p==8)
 {
  int e,i,ch,tn,y=0;
  char sn[35],str[20],x[20];
  long double l,u;
  tournament tg;
  do
  {
   clrscr();
   box();
   textbackground(BLUE);
   textcolor(43);
   cout<<"\n\n";
   cout<<"\t\t1. Create a file\n";
   cout<<"\t\t2. Display a file\n";
   cout<<"\t\t3. Display the details of a given team number\n";
   cout<<"\t\t4. Display the details of teams of a given sponsor\n";
   cout<<"\t\t5. Display the details of teams in a given winning price range\n";
   cout<<"\t\t6. Add the details of a wild card entry\n";
   cout<<"\t\t7. Disqualify a team from the tournament\n";
   cout<<"\t\t8. Modification of a team record \n";
   cout<<"\t\t9. Sorting of teams\n";
   cout<<"\t\t10.Insertion of a team \n";
   cout<<"\t\t11.Total file size and number of teams\n";
   cout<<"\t\t12.Insertion of a team without using temporary file\n";
   cout<<"\t\t13.Log out\n";
   cout<<"\t\t\tEnter your choice\n";
   cin>>ch;
   switch(ch)
   {
    case 1:clrscr();
	   create();
	   break;
    case 2:clrscr();
	   display();
	   break;
    case 3:clrscr();
	   box();
	   cout<<"\nEnter the team number\n";
	   cin>>tn;
	   display(tn);
	   break;
    case 4:clrscr();
	   box();
	   cout<<"\nEnter the sponsor name\n";
	   gets(sn);
	   display(sn);
	   break;
    case 5:clrscr();
	   box();
	   cout<<"\nEnter the lower and upper limit\n";
	   cin>>l>>u;
	   display(l,u);
	   break;
    case 6:clrscr();
	   box();
	   append();
	   break;
    case 7:clrscr();
	   box();
	   cout<<"\nEnter the team number to be disqualified\n";
	   cin>>tn;
	   DELETE(tn);
	   break;
    case 8:clrscr();
	   box();
	   cout<<"\nEnter the team number to be modified\n";
	   cin>>tn;
	   modify(tn);
	   break;
    case 9:clrscr();
	   box();
	   sort();
	   display();
	   break;
    case 10:clrscr();
	    box();
	    cout<<"\n Enter the details";
	    tg.input();
	    insertion(tg);
	    break;
    case 11:clrscr();
	    box();
	    nor();
	    break;
    case 12:clrscr();
	    box();
	    updater();
	    display();
	    break;
    case 13:clrscr();
	    box();
	    y=1;
	    cout<<"\n\n\n\n\t\t\t\tLogged out\n";
	    cout<<"\t\t\tPress any key to continue\n";
	    break;
    default:cout<<"Wrong choice\n";
   }getch();
  }while(y==0);
 }
}
