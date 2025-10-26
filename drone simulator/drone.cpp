//DELIVERY DRONE SIMULATOR
#include<iostream>
#include<cstdlib>
#include<ctime>   //for srand and rand
#include<chrono>  //for adding delays
#include<thread>
#include <limits>
using namespace std;
//FUNCTION PROTOTYPES
bool startDay(int battery);
int getWeather();  //randomly generates weather
bool checkObstacle();  //randomly generates obstacles
int delivery_time(char location);  //gives the delivery time
bool deliverPackage(char location, int& battery, int drain_per_trip, int& success, int& failed, int& delayed); //delivery procedure for each delivery
void displaySummary(int success, int failed, int delayed, int battery);//displaying summary
bool loadCheck(int);  //verifies if the load is within limit

//MAIN FUNCTION
int main() {
	//initializing and declaring variables
	int batteryLevel = 100;
	const int drain_per_trip = 15;
	int success = 0, failed = 0, delayed = 0;  //delivery counters
	char location;
	int load;
	srand(time(0));

	if (startDay(batteryLevel) == true) {
		this_thread::sleep_for(chrono::seconds(1));
		cout << "Starting deliveries!\n" << endl;
		cout << "------------------------------------\n";
		while (true)
		{
			//taking load input
			cout << "Enter -1 to exit or\nEnter the delivery package load under 50kg: ";
			cin >> load;
			//exit condition
			if (load == -1) {
				cout << "\n\nEnd of Deliveries for today.\n";
				displaySummary(success, failed, delayed, batteryLevel);
				cout << "Exiting program...\nGoodbye!"; break;
			}
			//input validation
			while (cin.fail()) {
				cout << "Invalid input! Please enter a numeric value: ";
				cin.clear(); // clear error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
				cin >> load; // ask again
			}//*Chatgpt was used in this cin.fail part due to error of infinte loop in case of wrong input type*

			if (loadCheck(load) == true) {

				cout << "Enter location(A/B/C) or enter X to exit. ";//location input
				cin >> location;
				cout << "------------------------------------\n";

				//delivery location validation
				if (location == 'A' || location == 'a' || location == 'B' || location == 'b' || location == 'C' || location == 'c') {
					deliverPackage(location, batteryLevel, drain_per_trip, success, failed, delayed);
					cout << "The estimated time for this delivery under normal circumstances will be " << delivery_time(location) << " minutes.\n";
					cout << "\n------------------------------------\n";
				}
				//exit condition
				else if (location == 'x' || location == 'X') {
					cout << "\n\nEnd of Deliveries for today.\n";
					displaySummary(success, failed, delayed, batteryLevel);
					break;
				}
				else { cout << "Invalid Location entered. Please try again.\n"; }
			}
			else {
				//heavy load warning
				cout << "Please try again.\n";
				cout << "------------------------------------\n";
			}
		}

	}

	return 0;
}
//FUNCTION DEFINITIONS
bool startDay(int battery) {
	char start;
	cout << "------------------------------------\n";
	cout << "WELCOME TO DELIVERY DRONE SIMULATOR!\n";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Initial battery level: " << battery << "%" << endl;
	cout << "------------------------------------\n\n";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "\nStart delivering?(Y/N):";
	cin >> start;
	if (start == 'Y' || start == 'y')
	{
		cout << "Preparing for delivery.Please wait.\n";
		this_thread::sleep_for(chrono::seconds(1));
		return true;
	}
	else if (start == 'N' || start == 'n') {
		cout << "Delivery Day cancelled. Goodbye!\n";
		return false;
	}
	else { cout << "Invalid input.\nExitting program.\n"; return false; }
}
//random weather generation
int getWeather() {
	cout << "Analyzing weather...\n";
	this_thread::sleep_for(chrono::seconds(2));
	int weather = rand() % 3 + 1;
	switch (weather) {
	case 1:
		cout << "Weather is Sunny.\n";
		break;
	case 2:
		cout << "Weather is Windy.\n";
		break;
	case 3:
		cout << "Weather is Rainy.\n";
		break;

	}
	return weather;
}
//random obstacle generation
bool checkObstacle() {
	cout << "Analyzing objects in the path...\n";
	this_thread::sleep_for(chrono::seconds(2));
	bool obstacle = rand() % 2 == 1;
	if (obstacle == 1) {
		return true;
	}
	else
	{
		return false;
	}
}
//load check
bool loadCheck(int load) {
	if (load <= 50 && load > 0) {
		cout << "The weight is within the load capacity.\nProceeding forward...\n";
		this_thread::sleep_for(chrono::seconds(1));
		cout << "------------------------------------\n";
		return true;
	}
	else if (load > 50) {
		cout << "The weight is out of the load capacity.\n";
		return false;
	}
	else { cout << "Oops! Cannot take this input."; }

}
//time calculation
int delivery_time(char location)
{
	cout << "\nEstimating the total delivery time...\n";
	this_thread::sleep_for(chrono::seconds(2));
	if (location == 'A' || location == 'a') {
		return 30;
	}
	else if (location == 'B' || location == 'b') {
		return 45;
	}
	else if (location == 'C' || location == 'c') {
		return 60;
	}
	else { cout << "Could not estimate time\n"; }
}
//delivery decision
bool deliverPackage(char location, int& battery, int drain_per_trip, int& success, int& failed, int& delayed) {

	cout << "Delivering to " << location << " \n";
	//function calls
	int weather = getWeather();
	bool obstacle = checkObstacle();
	//decision logic

	//obstacle check
	if (obstacle == true) {
		cout << "Obstacle detected. Rerouting path...\n";
		this_thread::sleep_for(chrono::seconds(1));
		if (weather != 3) {
			cout << "Extra battery used during reroute.\n";
			battery -= (drain_per_trip + 5);
		}

	}
	else {
		cout << "No obstacle detected\n";

		if (weather != 3) {
			battery -= drain_per_trip;
		}
	}

	if (weather == 3) {//rainy

		cout << "Flight delayed due to Rain.\n";
		delayed++;
		cout << "Remaining battery: " << battery << "%\n";
		return false;
	}
	else if (weather == 2 && battery < 40) {//windy but low battery
		cout << "Weather is too Windy and low battery.\n";
		cout << "Returning to base to Recharge\n";
		battery += 10;
		if (battery > 100) {
			battery = 100;
		}
		delayed++;
		cout << "Remaining battery: " << battery << "%\n";
		return false;
	}
	else if (weather == 2 && battery >= 40)//windy but enough battery
	{
		cout << "Weather is Windy but battery is sufficient. Proceeding with caution.\n";
		success++;
	}
	//battery check
	if (battery <= 0) {
		cout << "Battery exhausted! Delivery failed.\n";
		failed++;
		cout << "Remaining battery: " << battery << "%\n";
		return false;
	}
	//successful delivery
	cout << "Package successfully delivered to Location " << location << endl;
	cout << "Remaining battery: " << battery << "%\n";
	success++;
	return true;

}
//final summary
void displaySummary(int success, int failed, int delayed, int battery) {
	cout << "------------------------------------\n";
	cout << "         DAY SUMMARY" << endl;
	cout << "------------------------------------\n";
	cout << "Summarizing all the deliveries today..\n";
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Total Deliveries: " << (success + failed + delayed) << endl;
	cout << "Successful Deliveries: " << success << endl;
	cout << "Failed Deliveries: " << failed << endl;
	cout << "Delayed Deliveries: " << delayed << endl;
	cout << "Remaining Battery: " << battery << "%" << endl;
	cout << "------------------------------------\n";
	cout << "End of the Delivery Day. Goodbye!\n";
}