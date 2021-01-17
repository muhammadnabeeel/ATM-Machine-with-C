#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <sstream>

using namespace std;

int i,np=0;
string name,password,temp,temp2;
string arr[2],log[100],lasttran[8]="";
string password_arr[2],ppp="";
char choice, value;
char option;
double withdraw, deposit, remainingbalance, newbalance;
double balance=100000;
fstream login_f("login.txt");

main()
{
	ifstream login_f("login.txt");
	if(!login_f)
		{
			cerr<<"Can't open file Login file!\nload data";
			return 0;
		}
	else
		while(login_f>>log[np])
		{
			//cout<<log[np]<<" ";
			if(log[np]==" ")
			{
				break;
			}
			//cout<<"before "<<np;
			++np;
			//cout<<"after"<<np;
			//continue;
		}
	
	cout<<log[np]<<" "<<log[np+1];
	do{
	cout<<"\t\t\t\t ************************************************* " <<"\n";
	cout<<"\t\t\t\t   ********************************************* " <<"\n";
	cout<<"\t\t\t\t   *         \"Automated Teller Machine\"         *" <<"\n";
	cout<<"\t\t\t\t   ********************************************* " <<"\n";
	cout<<"\t\t\t\t ************************************************* " <<"\n\n\n";
	
	cout<<"1 - Create Account\n";
	cout<<"2 - Login\n";
	cout<<"3 - Exit\n";
	cout<<"Enter Choice: ";
	cin>>choice;
	
	system("cls");
	
	switch(choice)
	{
		case '1':
			{
				cout<<"   [[[% CREATE ACCOUNT %]]]   \n";
					//saving to files
					ofstream login_f("login.txt",ios::app);
					if(!login_f)
					{
						cerr<<"Can't open file Login file!";
						return 0;
					}
					
						cout<<"\nEnter Name: "; 
						cin>>temp;
						//cout<<"else working in saving";
						log[np]=temp;
						login_f<<temp<<" ";
						cout<<"\nEnter Password: ";
						cin>>temp2;
						log[np+1]=temp2;
						login_f<<temp2<<" ";
					
					//saving end
					cout<<"\n********** Account Successfully Created **********\n";
				continue;
			}
		case '2':
			{
				cout<<"   [[[% Login %]]]   \n";
				cout<<"\nEnter Name: "; cin>>name;
				cout<<"Enter Password: "; cin>>password;
				do{
				for(i=0; i<10; i=i+2)
				{
					if(name!=log[i] || password!=log[i+1])
					{
						ppp="\nPlease retry again\n";				
						option='7';
					}
			
					else if(name==log[i] && password==log[i+1])
					{do{
						//
						lasttran[6]="Current Balance:";
						stringstream ss;
						ss << balance;
						string str = ss.str();
						lasttran[7]=str;
						system("cls");
						cout<<"\n********** Login Successful **********\n";
				
						cout<<"\n\t\t\t\t\tSelect a transaction\n";
						cout<<"\n\t\t\t[1] Inquiry Balance";
						cout<<"\t\t\t[2] Withdraw \n";
						cout<<"\n\t\t\t[3] Deposit";
						cout<<"\t\t\t\t[4] Previous Transaction Details \n";
						cout<<"\n\t\t\t[5] Mini Statement";
						cout<<"\t\t\t[6] Change PIN \n";
						cout<<"\n\t\t\t\t\t\t[7] Quit\n";
						
						cout<<"\nOption: ";
						cin>>option;
						
						//saving transition detail
						lasttran[0]="Account Holder Name:";
						lasttran[1]=name;
						
						system("cls");
						
						switch(option)
						{
							case'1':
								{
									cout<<"\n[[[% BALANCE INQUIRY %]]]\n";
									cout<<"\n Your current balance is RS "<<balance<<endl;
									system ("pause");
									continue;
									
								}
							case '2':
								{
									cout<<"\n[[[% WITHDRAW %]]]\n";
									cout<<"Enter amount in Rupees: ";
									cin>>withdraw;
									
									lasttran[2]="Withdraw:";
									stringstream ss;
									ss << withdraw;
									string str = ss.str();
									lasttran[3]=str;
					
									if(withdraw>=500 && withdraw<=100000)
									{
										cout<<"\n[[[% WITHDRAW %]]]\n";
										remainingbalance=balance-withdraw;
					
										cout<<"Your withdraw amount is RS: "<<withdraw<<endl;
										cout<<"Your remaining balance is RS: "<<remainingbalance<<endl;
										balance=remainingbalance;
									}
									
									else if(withdraw<500 || withdraw>100000)
									{
										system("cls");
										cout<<"\nInvalid transaction, please retry again"<<endl;
									}
									getch();
									continue;
								}
							case '3':
								{
									cout<<"\n[[[% DEPOSIT %]]]\n";
									cout<<"Enter amount in RS: ";
									cin>>deposit;
									
									lasttran[4]="Deposit";
									stringstream ss;
									ss << deposit;
									string str = ss.str();
									lasttran[5]=str;
					
									if(deposit>=500)
									{
										cout<<"\n[[[% DEPOSIT %]]]\n";
										newbalance=remainingbalance+deposit;

										cout<<"You deposited RS: "<<deposit<<endl;
										cout<<"Your new balance is RS: "<<newbalance<<endl;
										balance=newbalance;
									}
				
									else if(deposit<500)
									{
										system("cls");
										cout<<"\nInvalid transaction, please retry again"<<endl;
									}
									getch();
									continue;
								}
							case '4':
								{
									cout<<"\n[[[% PREVIOUS TRANSACTION DETAILS %]]]\n";
				
									string fname ="details.txt";
									ifstream detailFile("details.txt");
									
									if(!detailFile)
									{
										cerr<<"Can't open file "<<fname;
										return 0;
									}
				
									string p;
									while(detailFile>>p)
									{
										cout<<p<<"\n";
									}
									getch();
									continue;
								}
							case '5':
								{
									cout<<"\n[[[% MINI STATEMENT %]]]\n";
				
									string fname ="mini_statement.txt";
									ifstream ist("mini_statement.txt");
									
									if(!ist)
									{
										cerr<<"Can't open file "<<fname;
										return 0;
									}
				
									string s;

									while(ist>>s)
									{
										cout<<s<<" ";
									}
									getch();
									continue;
								}
							case '6':
								{
									cout<<"\n***[[[% CHANGE PIN %]]]***\n";
									cout<<"\nEnter Name: "; cin>>name;
									cout<<"Enter current password: "; cin>>password;
										for(i=0; i<120; i=i+2)
										{

			
											if(name==log[i] && password==log[i+1])
											{
												system("cls");
												cout<<"Enter new password: ";
												string newp;
												cin>>newp;
												log[i+1] = newp;
												//saving
												ofstream login_f("login.txt");
												int loop=0;
												while(loop<=np)
												{
													//cout<<log[np]<<" ";
													login_f<<log[loop]<<" ";
													//cout<<"before "<<np;
													if(loop==np)
													{
														i=120;
													}
													++loop;
													//cout<<"after"<<np;
													//continue;
												}
											//cout<<"got here 0";
											//continue;
											}
										//break;
										}
											if(name!=log[i] && password==log[i+1])
											{
												cout<<"\nERROR in CHANGE PIN";
												cout<<"\nPlease retry again\n";
												getch();
												//break;
											}
										//continue;
											getch();
									continue;
								
								}
							case '7':
								{
									string fname ="details.txt";
									ofstream detailFile("details.txt");
									if(!detailFile)
									{
										cerr<<"Can't open file "<<fname;
										return 0;
									}
									for(int t=0;t<=7;t++)
									{
										detailFile<<lasttran[t]<<" ";
									}
									//system("cls");
									continue;
								}
							default:
								system("cls");
								cout<<"\nInvalid option, please retry again\n";
								break;
						}
						//saving details	

					}while (option!='7');
				}
				}
				}while (option!='7');
			}
		case '3':
			{
				//cout<<"\n***[[[% EXIT MODE %]]]***\n";
				system("cls");
			}
	}
	
	if(name!=log[i] && password!=log[i+1])
	{
		cout<<ppp;
		ppp="";
	}
	
	cout<<"\nDo you want to login again (y/n): ";
	cin>>value;
	system("cls");
}
while(value!='n');

}
