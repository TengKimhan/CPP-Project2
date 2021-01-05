#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<ctime>
#include<stdbool.h>
#include<iomanip>
#include<fstream>
#include<conio.h>



using namespace std;

class Exception;
class Customer;
class RoomCustomer;
class Employee;
class Dish;
class RestaurantCustomer;
class Restaurant;
class Hotel;
class Room;
class RoomService;


class Exception
{
	public:
		int errNo;
		string msg;

	public:
		Exception(int errNo,string msg)
		{
			this->errNo=errNo;
			this->msg=msg;
		}

		void what()
		{
			cout<<"\t\t"<< errNo<<" :: "<< msg<<endl;
		}
};


class Room
{
	public:
		string roomType;
		int noOfBeds;
		double rent;
		int roomNo;
		int status;

	public:
		Room(string roomType,int noOfBeds,double rent,int roomNo)
		{
			this->roomType=roomType;
			this->noOfBeds=noOfBeds;
			this->rent=rent;
			this->roomNo=roomNo;
			this->status=0;

		}
		void setRoom()
		{
			cout<<"Enter Room Type, No of beds, Rent, RoomNo\n";
			cin>>this->roomType;
			cin>>this->noOfBeds;
			cin>>this->rent;
			cin>>this->roomNo;
			status=0;

		}

		Room()
		{
		}




		bool isVacant(Room r)
		{
			if(r.status==1)
			return false;
			else
			return true;
		}

		void displayDetail()
		{

			cout<<"Room Type :: "<<this->roomType<<endl;
			cout<<"Number of Beds :: "<<this->noOfBeds<<endl;
			cout<<"Rent :: "<<this->rent<<endl;
			cout<<"Room Number ::"<<this->roomNo<<endl;
			if(status==1)
			cout<<" Occupied \n";
			else
			cout<<"Vacant \n";
		}

		void vacateRoom(int rno)
		{
			int i;
			for(i=0;i<6;i++)
			{
				if(this->roomNo==rno)
			this->status=0;
		}
		}

		void displayAvailable(Room r[6])
		{
			int i;
			for(i=0;i<6;i++)
			{
				if(r[i].status==0)
				r[i].displayDetail();
			}
		}

};

class Dish
{
	public:
		string dishName;
		double price;
		string dishType;

	public:
		Dish(string dishName,double price,string dishType)
		{
			this->dishName=dishName;
			this->price=price;
			this->dishType=dishType;
		}
		Dish()
		{

		}
};



class Customer
{
	public:
		string custName;
		string custAddress;
		string custID;
		long int custPhone;
		string custEmail;
		string checkInTime;
		int status;

	public:
		Customer()
		{
			time_t c=time(0);
	        string dt = ctime(&c);
			this->custName=" ";
			this->custAddress =" ";
			this->custID =" ";
			this->custPhone = 0L;
			this->custEmail =" ";
			this->checkInTime = dt;
			status=0;
		}

		void setData()
		{
			time_t now=time(0);
			string dt = ctime(&now);
			this->checkInTime = dt;
			ofstream customer;
			customer.open("Customer.txt",ios::ate);
			cout<<"Enter your Name : ";
			cin>>this->custName;
			customer << "Name ::"<< this->custName<<"\n\n";

			cout<<"\nEnter your Address : ";
			cin>>this->custAddress;
   			customer<< "Address ::"<< this->custAddress<<"\n\n";

			cout<<"\nEnter your Phone number : ";
			cin>>this->custPhone;
			customer << "Phone ::"<< this->custPhone<<"\n\n";

			cout<<"\nEnter your Email : ";
			cin>>this->custEmail;
			customer << "Email ::"<< this->custEmail<<"\n\n";
			customer.close();

		}

		int selectChoice()
		{
			int ch;
			cout<<" Hello!\n";
			cout<<"Enter \n1. Accomodation \n 2. Dine\n ";
			cin>>ch;
			return ch;
		}



		virtual void printCustomer()
		{
			cout<<"Name :: "<<this->custName<<endl;
			cout<<"Address :: "<< this->custAddress<<endl;
			cout<<"ID :: " <<custID<<endl;
			cout<<"Phone Number :: "<< custPhone<<endl;
			cout<<"Email :: "<<custEmail<<endl;
			cout<<"Check-In Time ::"<<this->checkInTime<<endl;

 		}
		virtual void viewTotalBill(){
		}
		virtual void allocateRoom(Room r1){
		}
		virtual void allocateDish(Dish d1){
		}
		virtual void checkout(){
		}
};

class RoomCustomer : public Customer
{
	public:
		double rbill;
		Room r;
		int bookStatus;
	public:

		void viewTotalbill()
		{
			cout<<"Bill ="<<rbill;
		}

		void allocateRoom(Room r1)
		{
			this->r=r1;
		}

		void printCustomer()
		{

				Customer :: printCustomer();
				if(r.status==1 && bookStatus==1)

				{
				cout<<"Check-In Time :: "<< checkInTime<<endl;
				cout<<"Room type :: "<<r.roomType<<endl;
				cout<<"Room Number :: "<<r.roomNo<<endl;

		}}
		void viewTotalBill()
		{
			this->rbill=r.rent;
			cout<<"Bill :: "<<this->rbill<<endl;
		}
		void checkOut()
		{
			cout<<"Your bill is "<<this->rbill<<"/-"<<endl;
			this->rbill=0;
			this->r.status=0;
			cout<<"Thank You! Visit Again.\n"<<endl;
		}


};


class RestaurantCustomer:public Customer
{
	public:
		double dbill;
		Dish d;
		int orderStatus;
	public:

		void viewTotalbill()
		{
			cout<<"Bill ="<<dbill;
		}

		 void allocateDish(Dish d1)
		 {
		 	this->d=d1;
		 }
		void printCustomer()
		{

				Customer :: printCustomer();
				if(orderStatus )
				{
				cout<<"Dish Name :: "<<d.dishName<<endl;
				cout<<"Dish Type :: "<<d.dishType<<endl;

				}}
		void viewTotalBill()
		{
			this->dbill=d.price;
			cout<<"Bill :: "<<this->dbill<<endl;
		}

};


class Employee
{

	public:


		virtual void performDuty()=0;
		virtual ~Employee(){
		}
};


class RoomService:public Employee
{
	public:
		void performDuty()
		{
		cout<<"Employee XYZ arriving at your doorstep...\n\n";
		}

		virtual ~RoomService(){
		}

};

class Waiter:public Employee
{
	public:
		void performDuty()
		{

			cout<<"\n\nEmployee ABC arriving at your table to take your Order\n\n";

		}
		virtual ~Waiter(){
		}
};

class SelectEmployee{
	//protected:
	Employee *e;

	public:
		SelectEmployee(Employee *e1)
		{
			e=e1;
		}

		void performDuty()
		{
			e->performDuty();
		}

};

class Restaurant
{
	public:
		Dish dish[8];

	public:
		void addDishes()
		{
			ofstream menu;
			menu.open("Menu.txt",ios::ate);
			int i;
			for(i=0;i<8;i++)
			{
				cout<<i+1<<"] Enter Dish Name Price and Type\n";
				cin>>dish[i].dishName>>dish[i].price>>dish[i].dishType;
				menu<< dish[i].dishName<<"\t"<<dish[i].price<<"\t"<<dish[i].dishType<<"\n";
			}
			menu.close();
		}


			Dish getDish(string dnam)
		{
			int i;
			for(i=0;i<8;i++)
			{

				if(dish[i].dishName==dnam)

				{
					return dish[i];
				}
		}
	}



			void displayDish(Dish d)
		{
			cout<<" Dish Name :: "<<d.dishName<<endl;
			cout<<" Price :: "<<d.price<<endl;
			cout<<" Dish Type :: "<<d.dishType;

		}

		void displayMenu()
		{
			int i;
			for(i=0;i<8;i++)
			{
				displayDish(dish[i]);
			}

		}

};



class Hotel
{
	private:
		static Hotel *instanceHotel;
		string hotelName;
		string hotelAddress;
	public:
		Employee *employee[5];
		Restaurant restuarant;

		Room room[6];
		Customer *customer[5];

	private:


		Hotel(string hname,string add)
		{
			this->hotelName=hname;
			this->hotelAddress=add;
		}
	public:
		static Hotel* getHotel()
		{
			if(!instanceHotel)
			instanceHotel=new Hotel("RENNAISSANCE","HUBLI");
			return instanceHotel;
		}

		void setHotel(Restaurant r,Room rs[6])
		{
			int i;

			for(i=0;i<6;i++)
			{
				this->room[i]=rs[i];
			}
			for( i=0;i<8;i++)
			this->restuarant.dish[i]=r.dish[i];

		}
		void generateID(Customer *c)
		{
			time_t t;
			static const char m[]="abcdefghijklmnopqrstuvwxyz";
			int i;

			for(i=0;i<6;i++)
			{
				c->custID=c->custID+ m[rand() % (sizeof(m)- 1)];
			}

		}

		Room getRoom(int rno)
		{
			int i;
			for(i=0;i<6;i++)
			{
				if(room[i].roomNo==rno)
				return room[i];
			}
		}
	 void displayAvailble(){
	 	int i;
	 	cout<<"\n\n----------------------------------------------Room Details----------------------------------------------\n\n";
	 	cout<<setw(25)<<"Room Type"<<setw(25)<<"Number of Beds"<<setw(25)<<"Rent"<<setw(25)<<"Room Number\n";
			for(i=0;i<6;i++)
			{
				if(room[i].status==0)
				{
					cout<<setw(25)<<room[i].roomType;
					cout<<setw(25)<<room[i].noOfBeds;
					cout<<setw(25)<<room[i].rent;
					cout<<setw(25)<<room[i].roomNo<<"\n";
				}
			}
			cout<<"\n\n";
			cout<<"Press Enter to Continue.....";

			getch();
	 }

	 void displayMenu()
	 {
	 	cout<<"\n\n-----------------------------------------------Menu-------------------------------------------------\n\n ";
	 		int i;
	 		const int width=8;
	 		cout<<setw(25)<<" Dish Name"<<setw(25)<<"Price"<<setw(25)<<"Dish Type"<<endl;
			for(i=0;i<8;i++)
			{

			cout<<setw(25)<<restuarant.dish[i].dishName;
			cout<<setw(25)<<restuarant.dish[i].price;
			cout<<setw(25)<<restuarant.dish[i].dishType<<"\n";
			}
	 	cout<<"\n\n";
		getch();
	}

		void bookRoom(int r)
		{
			int i;
			for(i=0;i<6;i++)
			{
			if(room[i].roomNo==r)
		room[i].status=1;}
		}


		void askFeedback()
		{
			int f;
			string cname;
			ofstream feedback;
  			feedback.open ("feedback.txt",ios::app);
  			feedback <<"Customer Name\t : ";
			cout<<"Enter your Name\n";
			cin>>cname;
			feedback<<cname<<"\t\t\t";
			cout<<" Thanks for your time! \n How likely are you to recommend Hotel Rennaisance to a Friend or Colleague? \n Rate on a scale of 1-10\n";
			cin>>f;
			feedback<<"Feedback\t: ";
			feedback<<f<<"\n";
			feedback.close();
				cout<<" Thanks for your valuable feedback!"<<endl;
		}

		void getCustomerData(Customer *c)
		{
			cout<<" Name :: "<<c->custName<<endl;
			cout<<" Address :: "<<c->custAddress<<endl;
			cout<<" Phone :: "<<c->custPhone <<endl;
			cout<<" Email :: "<<c->custEmail <<endl;
			cout<<" Check-In Time:: "<<c->checkInTime <<endl;
		}

		 void vacateRoom(int rno)
		{
			int i,j=0;
			for(i=0;i<6;i++)
			{

				if(room[i].roomNo==rno)
			{
				j=1;
			room[i].status=0;
			cout<<"Thank You! Visit Again.\n"<<endl;}
			}
				if(j==0)
				throw Exception(8,"Sorry! Room Not Found, or occupied at the moment\n");

		}
		void takeOrder(string dnm)
		{
			int i,j=0;;
			for(i=0;i<8;i++)
			{
			if(	restuarant.dish[i].dishName== dnm)
			{
			j=1;
			cout<<"Order Successful\n"<<endl;
			}
			}
			if(j==0)
			throw Exception(9, "Sorry! Dish Not Found, Enter a valid entry");
		}

};
Hotel *Hotel :: instanceHotel=0;
int main()
{
	//level2:
	system("CLS");

	system("Color 06");

	cout << "\n\n\n\t\t\t\t\t\t--------Welcome To Project--------\n\n\n";
	cout << "\n\n\n\n\n\n\n\n*******************************************************************************************************************************\n\n";
	cout << "**********************************************     RENAISSANCE HOTEL RERSERVATION     *****************************************\n\n";
	cout << "*******************************************************************************************************************************\n\n\n\n";
	cout << "    Hotel  Renaissance  is  one of the newest hotels in Phnom Penh, Cambodia. The hotel is equipped with all  general   \n";
	cout << "    Amenities and facilities, set amidst beautiful landscaped gardens and fresh water lake it proves to be an ideal   \n";
	cout << "    Dream destination for a perceptive traveller.\n\n\n\n";
	cout << "*******************************************************************************************************************************\n\n";
	cout << "*******************************************************************************************************************************\n\n";

	cout<<"\n";
	cout << "\n\n\n\n\n\n\n\t\t\t\t\t>>>>>>>>>>>>>>Press Enter to Continue!<<<<<<<<<<<<<<\n\n";
	cout << "\n\n\t\t\t\t\t\t--------Thank You!--------\n\n\n";
	int ch,i,o,ch1,ch2,r,rno,rcount=0,dcount=0;
	Room r2;
	string dname;
	Dish d2;
	Hotel *Rennaisance=Rennaisance->getHotel();

	Dish d[8]={
		Dish("Chocolate_Fondue",140,"Desert"),
		Dish("Manchow_Soup",110,"Soup"),
		Dish("Shahi_Paneer",220,"Main Course"),
		Dish("Arizona_Tea",100,"Beverage"),
		Dish("Grilled_Romaine Salad",180,"Salad"),
		Dish("Mushroom_Manchurian",170,"Starter"),
		Dish("Pina_Colada",210,"Cocktail"),
		Dish("Raspberry_Ripple",120,"Ice Cream")
			};

	Customer *c[5];
	Restaurant res;
	for(i=0;i<8;i++)
	{
		res.dish[i]=d[i];
	}
	Rennaisance->restuarant=res;

	 Room rm[6] = {
		Room("Deluxe",2,3500,1),
 		Room("AC",1,5500,2),
 		Room("Non AC",2,2500,3),
		Room("AC",2,3500,4),
		Room("Deluxe",2,3500,5),
	 	Room("Deluxe",3,4500,6)
		 };
		 SelectEmployee *e;
	Rennaisance->setHotel(res,rm);
	while(1)
	{
		for(i=0;i<5;i++)
		{
			try
			{
				//level2:
				getch();
				level2:
				system("CLS");

				system("Color 07");
				cout << "*************************************************************************************************************************\n";
				cout << "**********************************************     RENAISSANCE HOTEL RERSERVATION     ***********************************\n";
				cout << "*************************************************************************************************************************\n\n";
				cout << "    Hotel  Renaissance  is  one of the newest hotels in Phnom Penh, Cambodia. The hotel is equipped with all  general   \n";
				cout << "    Amenities and facilities, set amidst beautiful landscaped gardens and fresh water lake it proves to be an ideal   \n";
				cout << "    Dream destination for a perceptive traveller.\n\n";
				cout << "*************************************************************************************************************************\n";
				cout << "*************************************************************************************************************************\n";

				cout << "\n\n";
				cout <<"\t\t\t\t\tWelcome to Main Menu of Our Hotel Reservation\n\n";
				cout <<"\t\t=============================================================================================\n";
				cout <<"\t\t=============================================================================================\n";
				cout <<"\n\t\t\t\t\t\t\t1. Accomadation\n\n";
				cout <<"\t\t\t\t\t\t\t2. Restaurant\n\n";
				cout <<"\t\t\t\t\t\t\t3. Exit\n\n";
				cout <<"\t\t=============================================================================================\n";
				cout <<"\t\t=============================================================================================\n";
				//cout <<"\t\t=============================================================================================\n";
				cout << "\n";
				cout << "Please Enter the Number:"; cin>>ch;

				if(ch==1)
				{
					system("CLS");

					cout << "*************************************************************************************************************************\n";
					cout << "**********************************************     RENAISSANCE HOTEL RERSERVATION     ***********************************\n";
					cout << "*************************************************************************************************************************\n\n";

					cout <<"\n\t\t\t\t\t\tWelcome to Accomadation Menu\n\n";
					cout <<"\t\t=============================================================================================\n";
					cout <<"\t\t=============================================================================================\n\n";
					Rennaisance->customer[i]=new RoomCustomer;
					Rennaisance->generateID(Rennaisance->customer[i]);

					cout<<"\t\t\t\t\t\tEnter Your details Information\n";
					Rennaisance->customer[i]->setData();

					level1:
					system("CLS");
					//level1:
					cout << "*************************************************************************************************************************\n";
					cout << "**********************************************     RENAISSANCE HOTEL RERSERVATION     ***********************************\n";
					cout << "*************************************************************************************************************************\n\n";

					cout <<"\n\t\t\t\t\t\tWelcome to Accomadation Menu\n\n";
					cout <<"\t\t=============================================================================================\n";
					cout <<"\t\t=============================================================================================\n\n";
					cout<<"\t\t\t\t\t\t   1. Display Rooms \n\n";
					cout<<"\t\t\t\t\t\t   2. Book a Room \n\n";
					cout<<"\t\t\t\t\t\t   3. Vacate Room \n\n";
					cout<<"\t\t\t\t\t\t   4. Get Invoice  \n\n";
					cout<<"\t\t\t\t\t\t   5. Not Satisfied? \n\n";
					cout<<"\t\t\t\t\t\t   6. Cancel Booking \n\n";
					cout<<"\t\t\t\t\t\t   7. Give Feedback \n\n";
					cout<<"\t\t\t\t\t\t   8. Back\n\n";
					cout <<"\t\t=============================================================================================\n";
					cout <<"\t\t=============================================================================================\n\n";

					//level1:
					cout<<"Please Enter Number:"; cin>>ch1;
					switch(ch1)
					{
						case 1:
							Rennaisance->displayAvailble();
							goto level1;

						case 2:
							if(Rennaisance->customer[i]->status)
							{
								cout<<"\n\n-----------------------------------------------------------------------------------------\n\n";
								throw Exception(1,"Sorry! You Cannot Book more than one room!\n");
								cout<<"\n\n-----------------------------------------------------------------------------------------\n\n";

								getch();
								goto level1;
							}


							else
							{
								Rennaisance->customer[i]->status=1;
								Rennaisance->displayAvailble();
								cout<<"\nEnter Room Number: "; cin>>rno;
								Rennaisance->bookRoom(rno);
								r2=Rennaisance->getRoom(rno);
								Rennaisance->customer[i]->allocateRoom(r2);
							}

							getch();
							goto level1;
						case 3:
							if(!Rennaisance->customer[i]->status)
							{
								cout<<"\n\n-----------------------------------------------------------------------------------------\n\n";
								throw Exception(3,"Cannot vacate a book unless booked\n");
								cout<<"\n\n-----------------------------------------------------------------------------------------\n\n";

								getch();
								goto level1;
							}

							else
							{
								Rennaisance->customer[i]->status=0;
								cout<<"Enter Room No\n";
								cin>>rno;
								Rennaisance->vacateRoom(rno);
								cout<<"Room vacated\n";

							}

							getch();
							goto level1;
						case 4:
							if(!Rennaisance->customer[i]->status)
							{
								cout<<"\n\n------------------------------------------------------------------------------------------\n\n";
								throw Exception(2,"Cannot get Invoice Details unless you book a Room\n");
								cout<<"\n\n------------------------------------------------------------------------------------------\n\n";

								getch();
								goto level1;
							}

							else
							{
								cout<<"\n\n-----------------------------------------------------------------\n\n";
								Rennaisance->customer[i]->printCustomer();
								Rennaisance->customer[i]->viewTotalBill();
								cout<<"\n\n-----------------------------------------------------------------\n\n";

								getch();
								goto level1;
							}
						case 5:
							if(!Rennaisance->customer[i]->status)
							{
								cout<<"\n\n--------------------------------------------------------------------------------------------\n\n";
								throw Exception(2,"Cannot call Room Service Unless you book a Room\n");
								cout<<"\n\n--------------------------------------------------------------------------------------------\n\n";

								getch();
								goto level1;
							}

							else
							{
								e=new SelectEmployee(new RoomService);
								e->performDuty();
							//Rennaisance->employee->performDuty()
							}

							getch();
							goto level1;
						case 6:
							if(!Rennaisance->customer[i]->status)
							{
								cout<<"\n\n-----------------------------------------------------------------------------------\n\n";
								throw Exception(2,"No Room Booked\n");

								getch();
								goto level1;
							}

							else
							{
								Rennaisance->customer[i]->status=0;
								cout<<"Enter Room No\n";
								cin>>rno;
								Rennaisance->vacateRoom(rno);
								cout<<"Cancellation Successful!\n";
							}

							getch();
							goto level1;
						case 7:
							if(!Rennaisance->customer[i]->status)
							{
								cout<<"\n\n-----------------------------------------------------------------------------------\n\n";
								throw Exception(2,"Cannot give feedback unless you order a Dish\n");

								getch();
								goto level1;
							}
							else	Rennaisance->askFeedback();

							getch();
							goto level1;
						case 8: goto level2;
					}

				}

				else if(ch==2)
				{
					system("CLS");
					cout << "*************************************************************************************************************************\n";
					cout << "**********************************************     RENAISSANCE HOTEL RERSERVATION     ***********************************\n";
					cout << "*************************************************************************************************************************\n\n";

					cout <<"\n\t\t\t\t\t\tWelcome to Restaurant Main Menu\n\n";
					cout <<"\t\t=============================================================================================\n";
					cout <<"\t\t=============================================================================================\n\n";

					Rennaisance->customer[i]=new RestaurantCustomer;
					Rennaisance->generateID(Rennaisance->customer[i]);

					cout<<"\t\t\t\t\t\tEnter Your details Information\n";
					Rennaisance->customer[i]->setData();


					level3:
					system("CLS");
					//level3:
					cout << "*************************************************************************************************************************\n";
					cout << "**********************************************     RENAISSANCE HOTEL RERSERVATION     ***********************************\n";
					cout << "*************************************************************************************************************************\n\n";

					cout <<"\n\t\t\t\t\t\tWelcome to Restaurant Main Menu\n\n";
					cout <<"\t\t=============================================================================================\n";
					cout <<"\t\t=============================================================================================\n\n";
					cout<<"\t\t\t\t\t\t   1. Display Menu \n\n";
					cout<<"\t\t\t\t\t\t   2. Order a Dish \n\n";
					cout<<"\t\t\t\t\t\t   3. Get Invoice \n\n";
					cout<<"\t\t\t\t\t\t   4. Cancel Order  \n\n";
					cout<<"\t\t\t\t\t\t   5. Give FeedBack \n\n";
					cout<<"\t\t\t\t\t\t   6. Go Back \n\n";
					cout <<"\t\t=============================================================================================\n";
					cout <<"\t\t=============================================================================================\n\n";


					cout<<"Please Enter Number:";cin>>ch2;

					switch(ch2)
					{
						case 1:
							Rennaisance->displayMenu();
							goto level3;
						case 2:
							if(Rennaisance->customer[i]->status)
							{
								cout<<"\n\n-----------------------------------------------------------------------------------\n\n";
								throw Exception(4,"You cannot order more than one dish\n");
								cout<<"\n\n-----------------------------------------------------------------------------------\n\n";
							}
							else
							{
								o=1;
								Rennaisance->customer[i]->status=1;
								Rennaisance->displayMenu();
								e=new SelectEmployee(new Waiter);
								e->performDuty();
								cout<<"Enter Dish Name you want to Order(Make sure you enter the exact same name.)\n";

								cin>>dname;
								Rennaisance->takeOrder(dname);

								d2=Rennaisance->restuarant.getDish(dname);

								Rennaisance->customer[i]->allocateDish(d2);

								if(o==0)
								{
									cout<<"\n\n-----------------------------------------------------------------------------------------\n\n";
									throw Exception(6,"No such Dish Found");
								}

							}
							getch();
							goto level3;
						case 3:
							if(!Rennaisance->customer[i]->status)
							{
								cout<<"\n\n-----------------------------------------------------------------------------------\n\n";
								throw Exception(2,"Cannot get Invoice Details unless you order a Dish\n");
							}

							else
							{
								cout<<"\n\n-----------------------------------------------------------------\n\n";
								Rennaisance->customer[i]->printCustomer();
								Rennaisance->customer[i]->viewTotalBill();
								cout<<"\n\n-----------------------------------------------------------------\n\n";
							}

							getch();
							goto level3;
						case 4:
							if(!Rennaisance->customer[i]->status)
							{
								cout<<"\n\n-----------------------------------------------------------------------------------\n\n";
								throw Exception(2,"No Dish Ordered\n");
							}
							else
							{
								Rennaisance->customer[i]->status=0;
								cout<<"Cancelation Successful!\n";

							}

							getch();
							goto level3;

						case 5:
							if(!Rennaisance->customer[i]->status)
							{
								cout<<"\n\n-----------------------------------------------------------------------------------\n\n";
								throw Exception(2,"Cannot give feedback unless you order a Dish\n");
							}
							else

							Rennaisance->askFeedback();

							getch();
							goto level1;
						case 6:
							goto level2;



					}
				}
				else if(ch==3)
				exit(0);
				else
				{
					cout<<"-----------------------------------------------------------------------------------\n\n";
					throw Exception(5,"INVALID INPUT\n");

				}
				goto level2;
			}

			catch(Exception eh)
			{
				eh.what();
				cout<<"-----------------------------------------------------------------------------------\n\n";
			}
		}
	}
	return 0;
}

