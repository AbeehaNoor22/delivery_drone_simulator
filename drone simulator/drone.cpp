//delivery drone simulator
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
//function prototypes
bool startDay(int battery);
int getWeather();
bool checkObstacle();
bool deliverPackage(string location, int& battery,int drain_per_trip,int& success,int& failed,int& delayed);
void displaySummary(int success, int failed, int delayed, int battery);

int main() {
	//initializing variables
	int batteryLevel = 100;
	const int drain_per_trip = 15;
	int success = 0,failed = 0,delayed = 0;
	srand(time(0));

	if (startDay(batteryLevel) == true) {
		cout << "Starting deliveries!\n";
		for (int i = 1; i <= 3; i++) {
			string location;
			cout << "Enter location(A/B/C): ";
				cin >> location;
 deliverPackage(location,batteryLevel,drain_per_trip,success,failed,delayed);

		}
		displaySummary(success, failed,delayed,batteryLevel);
	}

	return 0;
}
//function definitions
bool startDay(int battery) {
	char start;

	cout << "WELCOME TO DELIVERY DRONE SIMULATOR!\n";
	cout << "Initial battery level: " << battery << "%" << endl;
	cout << "Start the Day?(Y/N): ";
	cin >> start;
	if (start == 'Y') {
		cout << "Preparing for delivery.Please wait.\n";
		return true;
	}
	else {
		cout << "Delivery Day cancelled.Goodbye!";
		return false;
	}
}
int getWeather() {
	int weather = rand() % 3 + 1;
	switch (weather) {
	case 1:
		cout << "Weather is Sunny\n";
		break;
	case 2:
		cout << "Weather is Windy\n";
		break;
	case 3:
		cout << "Weather is Rainy\n";
		break;

	}
	return weather;
}
bool checkObstacle() {
	bool obstacle = rand() % 2 == 1;
	if (obstacle == 1) {
		return true;
	}
	else
	{
		return false;
	}
	return obstacle;
}
bool deliverPackage(string location, int& battery, int drain_per_trip, int& success, int& failed, int& delayed) {
	cout << "Delivering to " << location << " \n";

	int weather = getWeather();
	bool obstacle = checkObstacle();
	if (weather == 3) {
		cout << "Weather is Rainy,Flight delayed.";
			delayed++;
			return false;
	}
	else if (weather == 2 && battery < 40) {
		cout << "Weather is too Windy and low battery.\n";
			cout << "Returning to base to Recharge";
			battery += 10;
			delayed++;
			return false;
	}
	 if (obstacle == true) {
		cout << "Obstacle detected. Rerouting path...\n";
		cout << "Extra battery used during reroute.\n";
		battery -= ( drain_per_trip + 5);
	}
	else {
		battery -= drain_per_trip;
	}
	 if (battery <= 0) {
		cout << "Battery exhausted! Delivery failed.\n";
		failed++;
		return false;
	}
	else {
		cout << "Package successfully delivered to Location " << location <<endl;
		cout << "Remaining battery: " << battery << "%\n";
		success++;              
		return true;              
	}

}
void displaySummary(int success, int failed, int delayed, int battery) {
	cout << "DAY SUMMARY"<<endl;
	cout << "Total Deliveries: " << (success + failed + delayed) << endl;
	cout << "Successful Deliveries: " << success << endl;
	cout << "Failed Deliveries: " << failed << endl;
	cout << "Delayed Deliveries: " << delayed << endl;
	cout << "Remaining Battery: " << battery << "%" << endl;
	cout << "End of the Delivery Day. Goodbye!\n";
}