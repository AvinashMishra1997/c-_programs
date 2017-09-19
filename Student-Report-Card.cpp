//============================================================================
// Name        : Student-Report-Card.cpp
// Author      : Avinash
// Version     :
// Copyright   : Your copyright notice
// Description : Student Report Card in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Student{
public:
	int roll,marks;
	float percent,phym,chemm,matm,engm,csm;
	char name[50];
	string grade;

	Student()						//CONSTRUCTOR To INITIALIZE Values
	{
		roll=0;
		marks=100;
		phym=0;
		chemm=0;
		matm=0;
		engm=0;
		csm=0;
		percent=100;
	}

	void Get_data()					//To Input Data Of Student
	{
		cout<<"Enter The ROLL NO. Of Student : ";
		cin>>roll;
		cout<<"Enter The NAME of ROLL NO. "<<roll<<" : ";
		cin>>name;
		cout<<"Enter The TOTAL MARKS That A Particular TEST Was Held For : ";
		cin>>marks;
		cout<<"Enter The Marks Obtained By ROLL NO. "<<roll<<" in PHYSICS Out Of "<<marks<<" : ";
		cin>>phym;
		cout<<"Enter The Marks Obtained By ROLL NO. "<<roll<<" in CHEMISTRY Out Of "<<marks<<" : ";
		cin>>chemm;
		cout<<"Enter The Marks Obtained By ROLL NO. "<<roll<<" in MATHS Out Of "<<marks<<" : ";
		cin>>matm;
		cout<<"Enter The Marks Obtained By ROLL NO. "<<roll<<" in ENGLISH Out Of "<<marks<<" : ";
		cin>>engm;
		cout<<"Enter The Marks Obtained By ROLL NO. "<<roll<<" in COMPUTER SCIENCE Out Of "<<marks<<" : ";
		cin>>csm;
	}

	float Percent()			//To Calculate PERCENTAGE And GRADE
	{
		percent=(phym + chemm + matm + engm + csm)/(marks*5)*100;
		return percent;
	}

	void Grade(float percent){
		if(percent>90 && percent<=100){
			grade="O";
		}
		else if(percent>80 && percent<=90){
			grade="A+";
		}
		else if(percent>70 && percent<=80){
			grade="A";
		}
		else if(percent>60 && percent<=70){
			grade="B+";
		}
		else if(percent>55 && percent<=60){
			grade="B";
		}
		else if(percent>50 && percent<=55){
			grade="c";
		}
		else if(percent>40 && percent<=50){
			grade="p";
		}
		else if(percent<=40 && percent>=0){
			grade ="F";
		}
		else{
			cout<<"\nERROR WHILE INPUT\n";
		}

	}

	void Display()			//To DISPLAY Information About The STUDENT
	{
		cout<<endl<<roll<<"\t"<<name<<"\t"<<phym<<"\t"<<chemm<<"\t"<<matm<<"\t"<<engm<<"\t"<<csm<<"\t"<<percent<<"\t"<<grade<<endl;
	}

};

int main(){
	Student s[100];
	int choice,sec_choice,c=0,i,r,flag=0,n;
	float a;
	do{
		cout<<"\n===================================MAIN  MENU==================================\n";
		cout<<"1.RESULT MENU\t\t2.ENTRY/EDIT MENU\t\t3.EXIT\n";
		cout<<"Enter Your Choice <1-3> : ";
		cin>>choice;
		system("clear");
		if(choice>0 && choice<3){
			switch(choice){
				case 1: do{
							cout<<"\n==================================RESULT  MENU=================================\n";
							cout<<"1.CLASS RESULT\t\t2.STUDENT REPORT CARD\t\t3.EXIT TO MAIN MENU\n";
							cout<<"Enter Your Choice <1-3> : ";
							cin>>sec_choice;
							system("clear");
							switch(sec_choice){
								if(sec_choice>0 && sec_choice<3){
									case 1: cout<<"\n===============================================================================\n";
											cout<<"ROLLNO\tNAME\tP\tC\tM\tE\tCS\tpercent\tG"<<endl;
											cout<<"===============================================================================";
											for(i=0;i<c;i++){
												a=s[i].Percent();
												s[i].Grade(a);
												s[i].Display();
											}
											cout<<"\n==============================================================================\n\n";
											break;
									case 2: cout<<"Enter The ROLL NO. That You Want To SEARCH For : ";
											cin>>r;
											for(i=0;i<c;i++){
												if(s[i].roll==r){
													cout<<"DATA FOUND : \n";
													s[i].Display();
													flag=1;
												}
											}
											if(flag==0){
												cout<<"RECORD NOT FOUND : \n";
											}
											break;
								}
								else if(sec_choice<=0 || sec_choice>3){
									cout<<"\nINVALID INPUT : Input Error\n";
								}
							}
						}while(sec_choice!=3);
						break;
			case 2: do{
						cout<<"\n================================ENTRY/EDIT  MENU===============================\n";
						cout<<"1.CREATE STUDENT RECORD\t\t2.DISPLAY ALL STUDENT RECORD\n3.SEARCH STUDENT RECORD\t\t4.MODIFY STUDENT RECORD\n5.DELETE STUDENT RECORD\t\t6.EXIT TO MAIN MENU\n";
						cout<<"Enter Your Choice <1-6> : ";
						cin>>sec_choice;
						system("clear");
						if(sec_choice > 0 && sec_choice <6){
							switch(sec_choice){
								case 1: s[c].Get_data();
										c++;
										break;
								case 2: cout<<"\n===============================================================================\n";
										cout<<"ROLLNO\tNAME\tP\tC\tM\tE\tCS\tpercent\tG"<<endl;
										cout<<"===============================================================================";
										for(i=0;i<c;i++){
											a=s[i].Percent();
											s[i].Grade(a);
											s[i].Display();
										}
										cout<<"\n==============================================================================\n\n";
										break;
								case 3: cout<<"Enter The ROLL NO. That You Want To SEARCH For : ";
										cin>>r;
										for(i=0;i<c;i++){
											if(s[i].roll==r){
												cout<<"DATA FOUND : \n";
												s[i].Display();
												flag=1;
											}
										}
										if(flag==0){
											cout<<"RECORD NOT FOUND : \n";
										}
										break;
								case 4: cout<<"Enter The ROLL NO. That You Want To MODIFY : ";
										cin>>r;
										for(i=0;i<c;i++){
											if(s[i].roll==r){
												cout<<"INPUT NEW RECORD : \n";
												s[i].Get_data();
												flag=1;
											}
											}
										if(flag==0){
											cout<<"RECORD NOT FOUND : \n";
										}
										break;
								case 5: cout<<"Enter The ROLL NO. That You Want To DELETE The RECORD For : ";
										cin>>r;
										for(i=0;i<c;i++){
											if(s[i].roll==r){
												for(n=i;n<c;n++){
													s[n]=s[n+1];
												}
												flag=1;
												c--;
											}
										}
										if(flag==1){
											cout<<"RECORD FOUND AND DELETED\n";
										}
										else{
											cout<<"RECORD NOT FOUND\n";
										}
										break;
								default : cout<<"INVALID OPERATION\n";
							}
						}
						else if(sec_choice >6 || sec_choice<=0){
							cout<<"\nINPUT ERROR : choose a valid input\n";
						}
					}while(sec_choice!=6);
			}
		}
		else if(choice==3){
			cout<<"\nEXITING THE PROGRAM\n";
		}
		else{
			cout<<"\nINPUT ERROR : choose a valid input\n";
		}
	}while(choice!=3);

	return 0;
}
