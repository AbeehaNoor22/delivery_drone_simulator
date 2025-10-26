//delivery drone simulator
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>
#include<thread>
using namespace std;
//function prototypes
bool startDay(int battery);
int getWeather();
bool checkObstacle();
int delivery_time(char location);//*added this function
bool deliverPackage(char location, int& battery, int drain_per_trip, int& success, int& failed, int& delayed);
void displaySummary(int success, int failed, int delayed, int battery);
bool loadCheck(int);//added this function
int main() {
	//initializing variables
	int batteryLevel = 100;
	const int drain_per_trip = 15;
	int success = 0, failed = 0, delayed = 0;
	srand(time(0));

	if (startDay(batteryLevel) == true) {
		this_thread::sleep_for(chrono::seconds(1));
		cout << "Starting deliveries!\n" << endl;
		cout << "------------------------------------\n";
		while (true) //*changed the loop
		{
			char location;
			int load;
			cout << "Enter the delivery package load.\n";
			cin >> load;

			if (loadCheck(load) == true) {

				cout << "Enter location(A/B/C) or enter X to exit. ";
				cin >> location;
				cout << "------------------------------------\n";
				if (location == 'A' || location == 'a' || location == 'B' || location == 'b' || location == 'C' || location == 'c') {
					deliverPackage(location, batteryLevel, drain_per_trip, success, failed, delayed);
					cout << "------------------------------------\n\n";
					cout << "Time for this delivery will be " << delivery_time(location) << " minutes.\n";
					cout << "\n------------------------------------\n";
				}
				else if (location == 'x' || location == 'X') {
					cout << "End of Deliveries for today.\n";
					displaySummary(success, failed, delayed, batteryLevel);
					break;
				}
				else { cout << "Invalid Location entered. Please try again.\n"; }
			}
			else {
				cout << "Please reduce weight and try again.\n";
				cout << "------------------------------------\n";
			}


		}

	}

	return 0;
}
//function definitions
bool startDay(int battery) {
	char start;
	cout << "------------------------------------\n";
	cout << "WELCOME TO DELIVERY DRONE SIMULATOR!\n";
	this_thread::sleep_for(chrono::seconds(1));//added all times delays
	cout << "Initial battery level: " << battery << "%" << endl;
	cout << "------------------------------------\n\n";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "\nStart delivering?(Y/N):\n ";
	cin >> start;
	if (start == 'Y' || start == 'y')//*modified this
	{
		cout << "Preparing for delivery.Please wait.\n";
		this_thread::sleep_for(chrono::seconds(2));
		return true;
	}
	else {
		cout << "Delivery Day cancelled.Goodbye!\n";
		return false;
	}
}
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
bool loadCheck(int load) {
	if (load <= 50 && load > 0) {
		cout << "The weight is within the load capacity.\nProceeding forward...\n";
		this_thread::sleep_for(chrono::seconds(1));
		cout << "------------------------------------\n";
		return true;
	}
	else if (load > 50) {
		cout << "The weight is out of the load capacity\n";
		return false;
	}
	else { cout << "Invalid load entered"; return false; }

}
int delivery_time(char location) //added ths function
{
	cout << "Estimating the total delivery time...\n";
	this_thread::sleep_for(chrono::seconds(3));
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
bool deliverPackage(char location, int& battery, int drain_per_trip, int& success, int& failed, int& delayed) {

	cout << "Delivering to " << location << " \n";

	int weather = getWeather();
	//weather based decision making module
	if (weather == 3) {

		cout << "Flight delayed.\n";
		delayed++;
		success++;

	}
	else if (weather == 2 && battery < 40) {
		cout << "Weather is too Windy and low battery.\n";
		cout << "Returning to base to Recharge\n";
		battery += 10;
		if (battery > 100) {
			battery = 100;
		}
		delayed++;

	}
	else if (weather == 2 && battery >= 40) {
		cout << "Weather is windy but battery is sufficient.\nProceeding with caution.\n";
		success++;
	}
	//obstacle based decision making module
	bool obstacle = checkObstacle();
	if (obstacle == true) {
		cout << "Obstacle detected. Rerouting path...\n";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "Extra battery used during reroute.\n";
		battery -= (drain_per_trip + 5);
	}
	else {
		cout << "No obstacle detected.\n";
		battery -= drain_per_trip;
	}
	//battery based decision making module
	if (battery <= 0) {
		cout << "Battery exhausted! Delivery failed.\n";
		failed++;

	}
	cout << "Package successfully delivered to Location. " << location << endl;
	cout << "Remaining battery: " << battery << "%\n";
	success++;
	return true;

}
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