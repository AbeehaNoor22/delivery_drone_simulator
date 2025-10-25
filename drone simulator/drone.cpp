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
int location_time(char);
//bool deliverPackage(string location, int& battery, int& success,int& failed,int& delayed);
//void displaySummary(int success, int failed, int delayed, int battery);

int main() {
	//initializing variables
	int batteryLevel = 100;
	//int success = 0, int failed = 0, int delayed = 0;
	char loc;
	if (startDay(batteryLevel) == true) {
		cout << "Starting Deliveries\n";
	}
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Analyzing Weather..\n";
	this_thread::sleep_for(chrono::seconds(3));
	cout << "The Weather Right Now is";
	cout << getWeather() << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Analyzing Obstacles in the Path..\n";
	this_thread::sleep_for(chrono::seconds(2));
	cout << checkObstacle();
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Enter the Location A,B or C\n";
	cin >> loc;
	cout << "Analyzing The Time..\n";
	this_thread::sleep_for(chrono::seconds(3));
	cout << "The Estimated Time to Deliver the Package to Your Destination is " << location_time(loc) << " MIN\n";


	system("pause");
	return 0;
}
//function definitions
//starting-the-day function that displays initial conditions and confirms the start of the day.
bool startDay(int battery) {
	char start;

	cout << "Welcome To Delivery Drone Simulator!\n";
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Initial Battery Level: " << battery << "%" << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Start the Day?(Y/N):\n";
	cin >> start;
	if (start == 'Y') {
		cout << "Preparing For Delivery. Please Wait...\n";
		this_thread::sleep_for(chrono::seconds(2));
		return true;
	}
	else {
		cout << "NO DELIVERIES FOR TODAY.SHUTING DOWN SYSTEM." << endl << "GOODBYE!" << endl;
		return false;
	}
}
int getWeather() {
	srand(time(0));
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
	srand(time(0));
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
int location_time(char location) {
	if (location == 'A') {
		return 30;
	}
	else if (location == 'B') {
		return 45;
	}
	else if (location == 'C') {
		return 60;
	}
	else { return -1; }
}