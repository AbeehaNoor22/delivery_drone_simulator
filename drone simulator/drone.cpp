//delivery drone simulator
#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>
using namespace std;
//function prototypes
bool startDay(int battery);
int getWeather();
bool checkObstacle();
//bool deliverPackage(string location, int& battery, int& success,int& failed,int& delayed);
//void displaySummary(int success, int failed, int delayed, int battery);

int main() {
	//initializing variables
	int batteryLevel = 100;
	const int drain_per_trip = 15;
	int success = 0, int failed = 0, int delayed = 0;
	srand(time(0));

	if (startDay(batteryLevel) == true) {
		cout << "STARTING DELIVERIES";
	}


	getch();
	return 0;
}
//function definitions
bool startDay(int battery) {
	char start;

	cout << "WELCOME TO DELIVERY DRONE SIMULATOR!\n";
	cout << "INITIAL BATTERY LEVEL: " << battery << "%" << endl;
	cout << "Start the Day?(Y/N): ";
	cin >> start;
	if (start == 'Y') {
		cout << "PREPARING FOR DELIVERY.PLEASE WAIT.";
		return true;
	}
	else {
		cout << "DELIVERY DAY CANCELLED.GOODBYE! ";
		return false;
	}
}
int getWeather() {
	int weather = rand() % 3 + 1;
	switch (weather) {
	case 1:
		cout << "SUNNY\n";
		break;
	case 2:
		cout << "WINDY\n";
		break;
	case 3:
		cout << "RAINY\n";
		break;

	}
	return weather;
}
bool checkObstacle() {
	bool obstacle = rand() % 2 == 1;
	if (obstacle == 1) {
		cout << "OBSTACLE FOUND.\n";
	}
	else
	{
		cout << "NO OBSTACLE FOUND.ROUTE IS CLEAR.\n";
	}
	return obstacle;
}
