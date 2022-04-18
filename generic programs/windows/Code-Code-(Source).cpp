
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iomanip>

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <direct.h>
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include <windows.h>
#define v 0.54
#define size 1024000


using namespace std;

string c,Name_;
int butter_lvl;



void initialize(){

string a="#Place_Files_Here",b="#Compiled_Output_Files",d="#Data",l="\\";


//if (system((std::string("mkdir ")+c+ std::string("\\")).c_str())==0){
    system((std::string("mkdir ")+c+ std::string("\\")+a).c_str());
    system((std::string("mkdir ")+c+ std::string("\\")+b).c_str());
    system((std::string("mkdir ")+c+ std::string("\\")+d).c_str());
  //  }


ofstream pre( (c+ std::string("\\")+ std::string("#Data")+ std::string("\\pre.txt")).c_str());
pre<<"echo\"";
pre.close();

ofstream save( (c+ std::string("\\")+ std::string("#Data")+ std::string("\\save.txt")).c_str());
save<<"butter_lvl==5";
save.close();

}

void spre(){

//----Save
//ofstream ppre("pre.txt", ios::app);
ofstream ppre( (c+ std::string("\\")+ std::string("#Data")+ std::string("\\")+ std::string("pre.txt")).c_str(), ios::app);
if(!ppre){initialize();
return;}
char name[10240];
cout<<"enter name : ";
cin.sync();
cin.getline(name,1280);
ppre<<endl<<name;//>>name*;
ppre.close();

}

int lpre(){
//----Load
//ifstream pre("pre.txt");
ifstream pre( (c+ std::string("\\")+ std::string("#Data")+ std::string("\\")+ std::string("pre.txt")).c_str());
if(!pre){initialize();
return 0;}
char r[size];
int y=1;
while(!pre.eof()){
pre.getline(r,size);
cout<<y<<") "<<r<<endl;
y++;}
pre.close();
return y;
}

string getpre(int sn){
//----Load--Get
//ifstream pre("pre.txt");
ifstream pre( (c+ std::string("\\")+ std::string("#Data")+ std::string("\\")+ std::string("pre.txt")).c_str());
if(!pre){initialize();
return 0;}
char r[size];
int y=1;
while(!pre.eof()){
pre.getline(r,size);
if(y==sn){return (r);}
y++;}}

void vpre(){
char t[size];
string kk="New_Code",kkk=".txt";
ifstream pprree( (c+ std::string("\\")+ std::string("#Compiled_Output_Files")+ std::string("\\")+kk+std::string("-")+Name_).c_str());
cout<<"\n\n-------------\nCompiled Code.txt\n\n";
while(!pprree.eof()){
pprree.getline(t,size);
puts(t);}
cout<<"\n\n-------------\n\nPress Any Key To Continue...";
_getch();
}

void dpre(){
int f=0,l,y=0,on;
char r[size];
system("cls");
l=lpre();
cout<<"\n\nWhich String To Delete : ";
cin>>on;

//ofstream temp("tmp.txt");
//ifstream pre("pre.txt");

ofstream temp( (c+ std::string("\\")+ std::string("#Data")+ std::string("\\")+ std::string("tmp.txt")).c_str());
ifstream pre( (c+ std::string("\\")+ std::string("#Data")+ std::string("\\")+ std::string("pre.txt")).c_str());

if(!pre){initialize();
return;}
int s=0;

while(!pre.eof()){
pre.getline(r,size);
temp<<r<<endl;
s++;
}
pre.close();
temp.close();

//ifstream tmp("tmp.txt");
//ofstream ppre("pre.txt");

ifstream tmp( (c+ std::string("\\")+ std::string("#Data")+ std::string("\\")+ std::string("tmp.txt")).c_str());
ofstream ppre( (c+ std::string("\\")+ std::string("#Data")+ std::string("\\")+ std::string("pre.txt")).c_str());

if(!ppre){
initialize();
return;}
char n[size];

for(int t=0;t<=s-1;t++){
tmp.getline(r,size);
if(t!=on-1){
ppre<<r;
if(t!=(on-1) && t<=(s-2)){
ppre<<endl;}}
}
ppre.close();
}

void build(){
    again:
    string Namme_,pre_="",post_="",strq,strw;
    string pre,post;
    char k[size];
    int l,g,flag;


    cout<<"\t\t\tCode To Code (v"<<v<<")\n"<<endl;
    cout<<"\nEnter The Name Of The Build File (Along With Full Extension) : ";
    cin>>Name_;
    cout<<"\n\n";
string kk="New_Code",kkk=".txt";

ofstream New_( (c+ std::string("\\")+ std::string("#Compiled_Output_Files")+ std::string("\\")+kk+std::string("-")+Name_).c_str());

    if(0){
    once:
    system("cls");}

    if(pre==""){strq='-';}
    else{strq=pre;}
    if(post==""){strw='-';}
    else{strw=post;}

    cout<<"Select The Pre Fix & Post Fix : \n\n----------------\n";
    cout<<"Pre : "<<strq;
    cout<<"\nPost : "<<strw;
    cout<<"\n\nPreview : "<<strq<<"xyz"<<strw;
    cout<<"\n----------------\n\n";
    g=lpre();
    cout<<"\n----------------\n"<<g<<") *Add String\n";
    cout<<g+1<<") *Delete String\n";
    cout<<g+2<<") *Retrun\n";
    cout<<g+3<<") *Start Compiling\n";
if(flag==1){
    cout<<g+4<<") *View Output Code\n";
    cout<<g+5<<") *Exit\n----------------\n";}
else{cout<<g+5<<") *Exit\n----------------\n";}

    cin>>l;

    if(l==g){
    system("cls");
    spre();
    goto once;}

    else if(l==g+1){
    system("cls");
    dpre();
    goto once;}

    else if(l==g+2){
    system("cls");
    goto again;}

    else if(l<=g && l>=1){
    Namme_=getpre(l);
    cout<<endl<<Namme_<<" as prefix(1) or postfix(2) : ";

    int opt;
    cin>>opt;

    switch (opt){
    case 1:{pre=Namme_.c_str();pre_=pre;goto once;break;}
    case 2:{post=(Namme_).c_str();post_=post;goto once;break;}
    default:{cout<<"wrong option";_getch();goto again;}}}

    else if(l==g+3){
    cout<<"*Compiling..\n----------------\n\n";
    goto compile;}

else if(flag==1 || l==g+4 || l==g+5){
    if(l==g+4){vpre();goto once;}
    if(l==g+5){system("cls");    cout<<"\n\n\n\t\tCode To Code (v"<<v<<")\n"<<endl;cout<<"\n\t\tBy Jesvi";Sleep(1000);exit(1);}}

else if(flag==0 || l==g+4){system("cls");cout<<"\n\n\n\t\tCode To Code (v"<<v<<")\n"<<endl;cout<<"\n\t\tBy Jesvi";Sleep(1000);exit(1);}

    else{cout<<"wrong option, try again..'";
    _getch();
    system("cls");
    goto again;}

    compile:
    ifstream Old_((c+ std::string("\\")+ std::string("#Place_Files_Here")+ std::string("\\")+Name_).c_str());

    int s;
    string x;
    ifstream save( (c+ std::string("\\")+ std::string("#Data")+ std::string("\\save.txt")).c_str());
    if(!save){initialize();}
    save>>x;
    save>>x;
    if(x=="0"){butter_lvl=0;}
    else if(x=="1"){butter_lvl=1;}
    else if(x=="2"){butter_lvl=2;}
    else if(x=="3"){butter_lvl=3;}
    else if(x=="4"){butter_lvl=4;}
    else if(x=="4"){butter_lvl=5;}
    else{butter_lvl=6;}
cout<<x<<endl<<butter_lvl<<endl;
    save.close();


    while(!Old_.eof()){
    Old_.getline(k,size);
    New_<<((pre_+ std::string("")+k+post_).c_str())<<endl;

    s=rand();

    if(butter_lvl==4 || butter_lvl==5 || butter_lvl==6 || butter_lvl==7){
    if(s%7==0){    Sleep(80);}
    if(s%13==0){    Sleep(40);}
    if(s%4==0){    Sleep(60);}
    if(butter_lvl==5 || butter_lvl==6 || butter_lvl==7){
    if(s&17==0){    Sleep(10);}}
    if(butter_lvl==7){
    if(s&5==0){    Sleep(200);}}
    if(butter_lvl==6){
    if(s&2==0){    Sleep(20);}}}

    else if(butter_lvl==2){
    Sleep(30);}

    else if(butter_lvl==3){
    Sleep(60);}

    else if(butter_lvl==1){
    Sleep(10);}

    else{}
    cout<<k;
    cout<<endl;}
    cout<<"\n\nPress Any Key To Continue...";

    _getch();
    flag=1;
    goto once;
    }

void getloc(){
 char cCurrentPath[FILENAME_MAX];
 if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))){return ;}
cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */
//printf ("The current working directory is %s", cCurrentPath);
c=cCurrentPath;
}

int main()
{
getloc();
build();
return 0;
}
