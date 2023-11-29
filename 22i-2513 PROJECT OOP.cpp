#include<iostream>
#include<cstring>
#include<fstream>
#include<string.h>
#include<string>
#include <cctype>
using namespace std;
class NAFS {
private:
	//int passengerseat;
	int economyclass;
	int bussinessclass;
public:
	NAFS() {
		//passengerseat = 50;
		economyclass = 50;
		bussinessclass = 10;
	}
	NAFS(/*int passengerseat*/int economyclass,int bussinessclass) {
		//this->passengerseat = passengerseat;
		this->economyclass = economyclass;
		this->bussinessclass = bussinessclass;
	}
	/*int getpassengerseat() {
		return this->passengerseat;
	}*/
	void setbussinessclass(int bussinessclass) {
		this->bussinessclass = bussinessclass;
	}
	void seteconomyclass(int economyclass) {
		this->economyclass = economyclass;
	}
	int geteconomyclass() {
		return this->economyclass;
	}
	int getbussinessclass() {
		return this->bussinessclass;
	}
	void detailofseats(){             // this will show you the detail of seats available...
		//cout << "NUMBER OF SEAT IN FlIGHTS : " << getpassengerseat()<<endl;
		cout << "NUMBER OF SEAT IN ECONOMY CLASS : " << geteconomyclass()<<endl;
		cout << "NUMBER OF SEAT IN BUSSINESS CLASS : " <<getbussinessclass()<< endl;
	}
	
};
class airports {
private:
	string cities[5];
	string airport[10];
	string network[25];

public:
	airports() {
		cities[0] = "Islamabad"; cities[1] = "Lahore"; cities[2] = "Peshawar"; cities[3] = "Karachi"; cities[4] = "Quetta";
		airport[0] = "NorthIsl"; airport[1] = "southisl"; airport[2] = "northlah"; airport[3] = "southlah"; airport[4] = "northpes"; airport[5] = "southpes"; airport[6] = "northkar"; airport[7] = "southkar"; airport[8] = "northque"; airport[9] = "southque";
		network[0] = "India"; network[1] = "China"; network[2] = "UK"; network[3] = "America"; network[4] = "Iran"; network[5] = "Iraq"; network[6] = "Qatar"; network[7] = "Afghanistan"; network[8] = "Russia"; network[9] = "Germany"; network[10] = "Finland"; network[11] = "NewZealand"; network[12] = "Africa"; network[13] = "Austraila"; network[14] = "Bangladesh"; network[15] = "Nepal"; network[16] = "WestIndies"; network[17] = "Palestine"; network[18] = "Swizealand"; network[19] = "Thailand"; network[20] = "Maleshia"; network[21] = "Japan"; network[22] = "Korea"; network[23] = "Honkong"; network[24] = "Farance";
	}
	/*airports(string cities[5], string airport[10]) {
		this->cities[5] = cities[5];
		this->airport[10] = airport[10];
	}*/
	string getcities(int i) {
		return this->cities[i];
	}
	string getairport(int j) {
		return this->airport[j];
	}
	string getinterairport(int k) {
		return this->network[k];
	}
	void mustcitieslist() {             // this will show first time when you enter into console.........
		ofstream of("citylist.txt");
		cout << "LIST OF CITIES IN PAKISTAN WHERE YOU OPERANT :-" << endl;
		//of << "LIST OF CITIES IN PAKISTAN WHERE YOU OPERANT :-" << endl;
		for (int i = 0; i < 5; i++) {
			of << i + 1 << ". " << getcities(i) << endl;
			cout << i + 1 << ". " << getcities(i) << endl;
			
		}
		of.close();
	}
	void citieslist() {                      // this will show first time when you enter into console........
		string getcities1[5] = {"","","","",""};
		ifstream iff("citylist.txt");
		cout << "LIST OF CITIES IN PAKISTAN WHERE YOU OPERANT :-" << endl;
		//of << "LIST OF CITIES IN PAKISTAN WHERE YOU OPERANT :-" << endl;
		if (!iff) {
			cout << "Error opening file." << endl;
			return;
		}
		
		for (int i = 0; i < 5; i++) {
			
			getline(iff,getcities1[i]);
			cout  << getcities1[i] << endl;

		}
		iff.close();
	}

	void mustairportlist() {                 // this will show first time when you enter into console........
		ofstream of1("airportlist.txt");

		//of1 << "LIST OF AIRPORTS IN PAKISTAN WHERE YOU OPERANT :-" << endl;

		cout << "LIST OF AIRPORTS IN PAKISTAN WHERE YOU OPERANT :-" << endl;
		for (int i = 0; i < 10; i++) {
			cout << i + 1 << ". " << getairport(i) << endl;
			of1 << i + 1 << ". " << getairport(i) << endl;
		}
		of1.close();
	}
	void airportlist() {     //this will handle file for airports.....
		ifstream iff1("airportlist.txt");
		if (!iff1) {
			cout << "Error opening file." << endl;
			return;
		}

		//of1 << "LIST OF AIRPORTS IN PAKISTAN WHERE YOU OPERANT :-" << endl;
		string getairport1[10] = {"","","","","","","","","",""};
		cout << "LIST OF AIRPORTS IN PAKISTAN WHERE YOU OPERANT :-" << endl;
		
		for (int i = 0; i < 10; i++) {
			
			getline(iff1,getairport1[i]);
			cout  << getairport1[i] << endl;
		}
		iff1.close();
	}
		void mustinternationalNetwork() {
			ofstream of2("internationalnetwork.txt");
			//of2 << "LIST OF AIRPORTS IN NETWORK INTERNATIONAALY WHERE YOU OPERANT :-" << endl;
			cout << "LIST OF AIRPORTS IN NETWORK INTERNATIONAALY WHERE YOU OPERANT :-" << endl;
			for(int i=0;i<25;i++){
				cout << i+1 << ". " << getinterairport(i)<<" : ";
				of2 << i + 1 << ". " << getinterairport(i) << " : ";
		}
			of2.close();
			cout << endl;
	}
		void internationalNetwork() {//this will handle file for internatonal airports.....
			string interairport1[25];
			ifstream iff2("internationalnetwork.txt");
			//of2 << "LIST OF AIRPORTS IN NETWORK INTERNATIONAALY WHERE YOU OPERANT :-" << endl;
			cout << "LIST OF AIRPORTS IN NETWORK INTERNATIONAALY WHERE YOU OPERANT :-" << endl;
			for (int i = 0; i < 25; i++) {
				
				getline(iff2,interairport1[i]);
				cout << i + 1 << ". " << interairport1[i] << " : ";
			}
			iff2.close();
			cout << endl;
		}
};
class localflights:public airports,public NAFS {
private:
	airports air;
	
public:
	localflights() {
		this->air = air;
		
	}
	localflights(airports& air) {
		this->air = air;
		
	}

	
	void mustlocalflighttiming() {   //  this will control the timimng of flights 
		cout << " TIMIMG OF LOCAL FLIGHTS :-" << endl<<endl;
		ofstream of3("localflighttiming.txt");
		for (int i = 0; i < 10; i++) {
			cout <<i+1<<". " << air.getairport(i) << " leaving time at " << 1 + (i * 2) << ":30 GMT" << endl;
			of3 << air.getairport(i) << " leaving time at " << 1 + (i * 2) << ":30 GMT" << endl;

		}
		of3.close();
	}

	void localflighttiming() {
		cout << " TIMIMG OF LOCAL FLIGHTS :-" << endl << endl;
		string airport2[10];
		ifstream iff3("localflighttiming.txt");
		for (int i = 0; i < 10; i++) {
		
			getline(iff3, airport2[i]);
			cout<<i<<". " << airport2[i] << endl;
		}
	
	}
	void yourflight() {
		cout << " you want bussiness class then press one other wise gothrough economy class :" << endl;
		int s = 0;
		cin >> s;
		if (s == 1) {
			int a = 0;
			cout << "SElECT OPTION WHERE YOU WANT TO GO :-" << endl;
		abc:
			try {
				cin >> a;
				if (a < 0 || a>10) {
					throw a;
				}

			}
			catch (int ex) {
				cout << " EXcetion : enter again .." << endl;
			}
			if (a < 1 || a>10) {
				cout << " ENTER AGAIN !!!!\n select between 1-10" << endl;
				goto abc;
			}
			else {
				ifstream iff4("interflighttiming.txt");
				int linenum = 1;
				string line;
				while (!iff4.eof()) {
					linenum++;
					getline(iff4, line);
					if (linenum == a) break;
				}
				cout << " your flight toward " << line << endl;
				iff4.close();
				int new1 = 0;
				int ee = 0;
				cout << " ENTER NUMBER OF SEATS YOU WANT RESERVE >>>>>" << endl;
				cin >> ee;
				new1 = (getbussinessclass() - (ee*2));
				setbussinessclass(new1);
			}
		}
		else {
			int a = 0;
			cout << "SElECT OPTION WHERE YOU WANT TO GO :-" << endl;
		abc1:
			cin >> a;
			if (a < 1 || a>10) {
				cout << " ENTER AGAIN !!!!\n select between 1-10" << endl;
				goto abc1;
			}
			else {
				ifstream iff5("localflighttiming.txt");
				int linenum1 = 1;
				string line1;
				while (!iff5.eof()) {
					linenum1++;
					getline(iff5, line1);
					if (linenum1 == a) break;
				}
				cout << " your flight toward " << line1 << endl;
				iff5.close();
				int new2 = 0;
				int ee1 = 0;
				cout << " ENTER NUMBER OF SEATS YOU WANT RESERVE >>>>>" << endl;
				cin >> ee1;
				new2 = (geteconomyclass() - (ee1*2));
				seteconomyclass(new2);
			}
		}
		
	}
};
class internationalflights {
public :
	internationalflights() {

	}
	void mustinterflighttiming() { //  this will control the timimng of flights 
		cout << "DETAIL OF ALL INTERNATIONAL FLIGHTS FROM PAKSITAN,S DIFFERENT AIRPORTS WITH TIMIMG:-" << endl;
		ifstream iff6("interflighttiming.txt");
		if (!iff6) {
			cout << "Error opening file." << endl;
			return;
		}
		string line2[50];
		for (int i = 0; i < 50; i++) {
			getline(iff6, line2[i]);
			cout << line2[i] << endl;
		}
		iff6.close();

	}
	void yourflightinter() {
		cout << " you want bussiness class then press one other wise gothrough economy class :" << endl;
		int s = 0;
		cin >> s;
		if (s == 1) {
			int a = 0;
			cout << "SElECT OPTION WHERE YOU WANT TO GO :-" << endl;
		abc:
			cin >> a;
			if (a < 1 || a>50) {
				cout << " ENTER AGAIN !!!!\n select between 1-10" << endl;
				goto abc;
			}
			else {
				ifstream iff7("interflighttiming.txt");
				int linenum = 1;
				string line;
				while (!iff7.eof()) {
					linenum++;
					getline(iff7, line);
					if (linenum == a) break;
				}
				cout << " your flight toward " << line << endl;
				iff7.close();
				
			}
		}
		else {
			int a = 0;
			cout << "SElECT OPTION WHERE YOU WANT TO GO :-" << endl;
		abc1:
			cin >> a;
			if (a < 1 || a>50) {
				cout << " ENTER AGAIN !!!!\n select between 1-10" << endl;
				goto abc1;
			}
			else {
				ifstream iff8("localflighttiming.txt");
				int linenum1 = 1;
				string line1;
				while (!iff8.eof()) {
					linenum1++;
					getline(iff8, line1);
					if (linenum1 == a) break;
				}
				cout << " your flight toward " << line1 << endl;
				iff8.close();
				
			}
		}

	}

};
class airplanes {
private:
	int plane;
public:
	airplanes() {
		plane = 0;
	}
	airplanes(int plane) {
		this->plane = plane;
	}
	void setplanes(int plane) {
		this->plane = plane;
	}
	int getplanes() {
		return this->plane;
	}
	void detailplanes() {
		cout << "Total amount of airplanes in each airports" << getplanes() << endl;
	}

};
class adminpanel:public localflights,public internationalflights {
private:
	string user;
	string password;
	localflights lof;
	internationalflights inf;

public:
	adminpanel() {
		user = "\0";
		password = "\0";
		//this->lof =lof;
		//this->inf =inf;
	}
	
	adminpanel(string user, string password, localflights& lof,internationalflights& inf) {
		this->user = user;
		this->password = password;
		this->lof = lof;
		this->inf = inf;
	}
	void setuser(string user) {
		this->user = user;
	}
	void setpassword(string password) {
		this->password = password;
	}
	string getuser() {
		return this->user;
	}
	string getpassword() {
		return this->password;
	}
	void changelocalflighttiming() {           //this function can change your timing of flights .....
		cout << " which flight time with route you want to change :" << endl;
		lof.localflighttiming();
		fstream of6("localflighttiming.txt");
		if (!of6) {
			cout << "Error opening file." << endl;
			return;
		}
		int a = 0;
	abc6:
		try {
			cin >> a;
			if (a < 1 || a>10) {
				cout << "enter b/w 1-10 try again!!" << endl;
			}
		}
		catch (int a) {
			cout << " EXCEPTION :" << endl;
			goto abc6;

		}
		/*if (a < 1 || a>10) {
			cout << "enter b/w 1-10 try again!!" << endl;
			goto abc6;
		}*/
		cout << " CHANGE IN THIS FORMATE>>>> -->   southisl to India : flight takeoff time : 1:00 Am fight arrival time :3:00 Am " << endl;
		string line;
		int lineNumber = 1;
		while (getline(of6, line)) {
			if (lineNumber == a) {
				of6.seekp(of6.tellg()); // Move the write pointer to the current read position
				cin.ignore();
				getline(cin,line);
				of6 << line << endl;
			
			}
			lineNumber++;
		}

		of6.close();

	}
	void changeinterflighttiming() {         //this can also change the flights timing... 
		cout << " which flight time with route you want to change :" << endl;
		inf.mustinterflighttiming();
		fstream of7("interflighttiming.txt");
		if (!of7) {
			cout << "Error opening file." << endl;
			return;
		}
		int a = 0;
	abc5:
		cout << " enter between 1-50,..." << endl;
		cin >> a;
		if (a < 1 || a>50) {
			cout << "enter b/w 1-50 try again!!" << endl;
			goto abc5;
		}
		string line;
		int lineNumber = 1;
		while (getline(of7, line)) {
			if (lineNumber == a) {
				of7.seekp(of7.tellg()); // Move the write pointer to the current read position
				cin.ignore();
				getline(cin, line);
				of7 << line << endl;
			}
			lineNumber++;
		}
		of7.close();

	}

};
class passengerpanel {
protected:
	string usernamepas;
	string passwordpas;
	string cnic;
	int age;
	
public:
	void setpass(string passwordpas) {
		this->passwordpas = passwordpas;
	}
	void setusernamepas(string usernamepas) {
		this->usernamepas = usernamepas;
	}
	void setcnic(string cnic) {
		this->cnic = cnic;
	}
	void setage(int age) {
		this->age = age;
	}
	string getpass() {
		return this->passwordpas;
	}
	string getusernamepas() {
		return this->usernamepas;
	}
	string getcnic() {
		return this->cnic;
	}
	int getage() {
		return age;
	}
	void enterpass() {
		string pass = "\0";
		cout << " ENTER PASSWORD :" << endl;
		//abc8:
		getline(cin,pass);
		
		setpass(pass);
		
	}
	void filepassword(passengerpanel p1) {
		cout << "running :" << endl;
		ofstream fil2;
		//string us;
		fil2.open("password.txt", ios::app);
		fil2 << p1.getpass() << endl;
		fil2.close();
	}
	bool hasUpperCase(passengerpanel p) {
		for (int i = 0; i < p.getpass().length(); i++) {
			if (isupper(p.getpass()[i])) {
				return true;
			}
		}
		return false;
	}

	// Function to verify if a given string contains at least one lowercase letter
	bool hasLowerCase(passengerpanel p) {
		for (int i = 0; i < p.getpass().length(); i++) {
			if (islower(p.getpass()[i])) {
				return true;
			}
		}
		return false;
	}

	// Function to verify if a given string contains at least one digit
	bool hasDigit(passengerpanel p) {
		for (int i = 0; i < p.getpass().length(); i++) {
			if (isdigit(p.getpass()[i])) {
				return true;
			}
		}
		return false;
	}

	// Function to verify if a given string contains at least one special character
	bool hasSpecialChar(passengerpanel p) {
		for (int i = 0; i <p.getpass().length(); i++) {
			if (!isalnum(p.getpass()[i])) {
				return true;
			}
		}
		return false;
	}

	// Function to hide password input with asterisks
	void hidePasswordInput(passengerpanel p) {
		int a= (p.getpass().length());
		for(int i=0;i<a;i++) {
			
			cout << '*';
		}
		cout << endl;
	}
	void enteruser() {
		cout << " ENTER USERNAME:" << endl;
		string use;
		getline(cin, use);
		setusernamepas(use);
	}
	void fileusername(passengerpanel p) {
		cout << "running :" << endl;
		ofstream fil1;
		//string us;
		fil1.open("username1.txt", ios::app);
		fil1 << p.getusernamepas() << endl;
		fil1.close();
	}
	bool checkpassanduser(string user12,string pass12) {
		cout << "running :" << endl;
		bool pas1=false;
		bool use1=false;
		string line;   // To read each line from code
		int count = 0;    // Variable to keep count of each line
		bool check = false;
		ifstream mFile;
		mFile.open("username1.txt");
		if (mFile.is_open())
		{
			while (mFile.peek() != EOF)
			{
				cout << " OK username founded.." << endl;
				getline(mFile, line);
				count++;
				if (line == user12) {
					use1 = true;
					goto as1;

				}
			}
			as1:
				mFile.close();
				//cout << "Number of lines in the file are: " << count << endl;
			}

		else
		{
			cout << "Couldn't open the file\n";
		}
		//cout << " runnunig 2" << endl;
		string line1;   // To read each line from code
		int count1 = 0;    // Variable to keep count of each line

		ifstream mFile1("password.txt");

		if (mFile1.is_open())
		{
			while (mFile1.peek() != EOF)
			{
				cout << " OK password founded.." << endl;
				getline(mFile1, line1);
				count1++;
				if (line1 == pass12) {
					pas1 = true;
					goto as;
				}
			}
			as:
			mFile.close();
			//cout << "Number of lines in the file are: " << count1 << endl;
		}
		else
			cout << "Couldn't open the file\n";

		if (pas1 == true && use1 == true && count == count1) {
			check = true;
			cout << "pass and username matched...!!" << endl;
		}
		else {
			check = false;
			cout << "pass and username not matched ...!!!" << endl;
		}
		return check;
		

	}
	void entercnic() {  //this is for enter cnic.. 
		cout << " ENTER CNIC NO :" << endl;
		string cni;
		abc9:
		getline(cin, cni);
		if (cni.length() == 13) {
			cout << "DONE! " << endl;
		}
		else {
			cout << " YOU ENTERED ABOUT 13 DIGIT OF CNIC :" << endl;
			goto abc9;
		}
		setcnic(cni);
	
	}
	void enterage() {    //this is for enter age
		int ag=0;
		ac1:
		cout << "ENTER AGE :" << endl;
		cin >> ag;
		if (ag < 18) {
			cout << "invalid!" << endl;
			goto ac1;
		}
		setage(ag);
	}
	void enteraccountno() {  // to enter account number..
		cout << " ENTER ACCOUNT NUMBER FOR TRANCTION AND PAYMENT BOOKING CHARGES :" << endl;
		string ac;
		getline(cin, ac);
		cout << ac;
	}
	void visacheck() {  // this is foe visa cchexcking
		cout << " YOU HAVE FORIGN VISA :" << endl;

	}

};
void balancelocal() {
	cout << "enter 1 to submit charges of flights " << endl;
	int u = 0;
	cin >> u;
	if (u == 1) {
		cout << " 10,000 Rs is paid through your account ..." << endl;
		cout << "YOUR FLIGHT IS BOOKED <<<<>>>>" << endl;
	}
	else {
		cout << " SO YOU DONT PAID YOUR CHARGES SO YOUR FLIGHT IS NOT REGISTERED..." << endl;
	}
}
void balanceinter() {
	cout << "enter 1 to submit charges of flights " << endl;
	int u = 0;
	cin >> u;
	if (u == 1) {
		cout << " 20,000 Rs is paid through your account ..." << endl;
		cout << "YOUR FLIGHT IS BOOKED <<<<>>>>" << endl;
	}
	else {
		cout << " SO YOU DONT PAID YOUR CHARGES SO YOUR FLIGHT IS NOT REGISTERED..." << endl;
	}
}

int main() {
	NAFS flight;
	passengerpanel passenger;
	airplanes air(10);
	airports ap;
	localflights local(ap);
	internationalflights inter;
	adminpanel adpa("admin", "admin", local, inter);

	cout << " **************************************    NAFS (FLIGHT SYSTEM)           *********************************************" << endl << endl;
menuuu:
	cout << "                                    WELCOME TO OUR FAST AIRLINE " << endl << endl;
	cout << endl << endl << "                                     MENU             " << endl;
	cout << "1. Detail of flights  \n2. Admin Panal \n3. Passenger Panel\n4. exit  " << endl << endl;
	int s2 = 0;
	try {
		cin >> s2;
		if (s2 <= 0 || s2 > 4) {
			throw s2;
		}
	}
		catch (int ex1) {
			cout << " this is an exception:" << endl;
		}
	
	if (s2 == 1) {
		// this case is use for showing common user detail providing ........
		flight.detailofseats();
		cout << endl << endl << "---------------------X-----X-----X-----X-----X-----X----X---X--------------------- " << endl << endl;
		ap.mustairportlist();
		cout << endl << endl << "---------------------X-----X-----X-----X-----X-----X----X---X--------------------- " << endl << endl;
		ap.mustcitieslist();
		cout << endl << endl << "---------------------X-----X-----X-----X-----X-----X----X---X--------------------- " << endl << endl;
		//flight.detailofseats();
		ap.mustinternationalNetwork();
		cout << endl << endl << "---------------------X-----X-----X-----X-----X-----X----X---X--------------------- " << endl << endl;
		local.mustlocalflighttiming();
		cout << endl << endl << "---------------------X-----X-----X-----X-----X-----X----X---X--------------------- " << endl << endl;
		inter.mustinterflighttiming();
		cout << endl << endl << "---------------------X-----X-----X-----X-----X-----X----X---X--------------------- " << endl << endl;
	fg:
		cout << " enter 1 to go to menuu" << endl;
		int y = 0;
		cin >> y;
		if (y == 1) {
			goto menuuu;
		}
		else {
			goto fg;
		}
	}
	else if (s2 == 2) {        // this is for admin panal wherr they can manage flights and routes....
	abc4:
		cout << " enter user name(5-digit) :" << endl;
		string user1;
		getline(cin, user1);
		cout << " enter user password(5-digit) :" << endl;
		string password1;
		getline(cin, password1);


		if (user1 == adpa.getuser() && password1 == adpa.getpassword()) {
		abc12:
			cout << endl << " Enter 1 for changing timing and route of local flight and 2 for international flights and enter 3 to go into menu" << endl << endl;
			int f = 0;
			cin >> f;
			if (f == 1) {
				//local.mustlocalflighttiming();
				adpa.changelocalflighttiming();
			}
			else if (f == 2) {
				//inter.mustinterflighttiming();
				adpa.changeinterflighttiming();
			}
			else if (f == 3) {
				goto menuuu;
			}
			else {
				cout << " enter again !! " << endl;
				goto abc12;
			}
		}

		else
		{
			cout << "wrong password or username !!" << endl;
			goto abc4;
		}
	}

		else if (s2 == 4) {
			exit(0);
	}

	
	else if (s2 == 3) {  // this is for passenger where they can register and login and reserves there seates....
		int x = 0;
		cout << endl << endl << " ENTER 1 FOR REGISTRATION AND 2 FOR  LOGIN :" << endl << endl;
	abc11:
		cin >> x;
		if (x == 1) {
		   // for registration menu where you can register your self.......

		abc8:
			passenger.enterpass();
			if (((passenger.getpass().length()) != 8) || ((passenger.hasLowerCase(passenger)) == false) || ((passenger.hasSpecialChar(passenger)) == false) || ((passenger.hasUpperCase(passenger) == false))) {
				cout << "your password must be 8 digits including upercase,lowercase,digits..." << endl;
				goto abc8;
			}
			else {
				passenger.hidePasswordInput(passenger);
			}
			passenger.enteruser();
			passenger.enterage();
			passenger.entercnic();
			passenger.visacheck();
			cout << " YOU have been registered !!! WELCOME !!" << endl << endl;
			passenger.fileusername(passenger);
			passenger.filepassword(passenger);
			goto menuuu;
		}
		else if (x == 2) {            //for login menu where you can login into it .....
			cout << endl << endl << "                       WELCOME TO OUR LOGIN PAGE :" << endl << endl;
			string pass12;
			string username12;
		ax:
			cin.ignore();
			cout << " ENTER YOUR USER NAME :";
			getline(cin, username12);
			//cin.ignore();
			cout << endl << "ENTER YOUR PASSWORD :";
			getline(cin, pass12);
			cout << endl;
			//passenger.checkpassanduser(username12, pass12);
			if (passenger.checkpassanduser(username12, pass12) == true) {
				cout << endl << endl << " YOUR HAVE LOGED INTO YOUR ACCOUNT :" << endl << endl;
				ad:
				cout << endl << endl << " 1 for international flights and 2 of local flights that you gona set ..." << endl << endl;
				int xq = 0;
				cin >> xq;
				if (xq == 1) {
					inter.mustinterflighttiming();
					inter.yourflightinter();
					balanceinter();
				}
				else if (xq == 2) {
					local.localflighttiming();
					local.yourflight();
					balancelocal();
				}
				else {
					cout << " YOU ENTER WRONG OPTION .." << endl;
					goto ad;

				}
			}
			else
			{
				//cout << " WRONG PASSWORD OR USERNAME >>>>" << endl;
				cout << " ENTER 1 to go back on menu other wise reenter pass and username  ..." << endl;
				int t = 0;
				cin >> t;
				if (t == 1) {
					goto menuuu;
				}

				cout << " you enter wrong password ...ENTER AGAOIN !!!!!!!!!!!" << endl;
				goto ax;
				
			}
		}
		else{
			cout << " INVALID ENTRIE !!" << endl;
			goto abc11;
		}
	}
	
//	///////////////////////////////////
//	cout << "WELCOME FOR FLIGHT BOOKING :" << endl;
//	cout << " enter 1 for local and 2 for international flights " << endl;
//	int d = 0;
//ab12:
//	cin >> d;
//	
//	if (d == 1) {
//		
//	}
//	else if (d == 2) {
//		
//	}
//	else {
//		cout << " enter again !" << endl;
//		goto ab12;
//	}
//	cout << " now for changing detail of routes and timing  can b shown when you press 1" << endl;
//	int f1 = 0;
//	cin >> f1;
//	if (f1 == 1) {
//		ap.citieslist();
//		ap.airportlist();
//		ap.internationalNetwork();
//	}
//	else {
//		cout << " thank you !" << endl;
//	}
//	
	
}