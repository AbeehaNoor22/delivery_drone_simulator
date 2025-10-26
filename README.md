# delivery_drone_simulator
A C++ program for delivery drone software managing flights different locations daily based on weather, battery, and obstacles, with end-of-day mission summary reporting.
## Team Information

**Project Title:** Delivery Drone Simulator  

**Team Members:**
- **Aliza Batool** –  
- **Fatima Zahra Mustapha** – 
- **Abeeha Noor** –
## Problem Description

The **Delivery Drone Simulator** is a C++ program that simulates how a delivery drone operates under varying **weather**, **battery**, **load**, and **obstacle** conditions.  

It allows the user to input **package load** and **delivery location**, and the program then decides based on random environmental factors whether the drone:
- Successfully delivers the package  
- Delays the delivery due to weather or load  
- Returns to base to recharge
### Why This Problem is Interesting

In real life, drones are increasingly used for **logistics and delivery services**.  
However, they must constantly adapt to unpredictable **weather**, **obstacles**, and **battery constraints**.  

This simulator models that real-world decision-making in a **simplified, interactive form**, making it both **educational** and **practically relevant**.

## Program Design / Logic

### Functions Implemented
1. **`startDay()`** – Starts the program and asks if the user wants to begin deliveries.  
2. **`getWeather()`** – Randomly generates weather conditions.  
3. **`checkObstacle()`** – Randomly decides if an obstacle is detected.  
4. **`loadCheck(int load)`** – Ensures package weight is within the drone’s capacity.  
5. **`delivery_time(char location)`** – Returns estimated delivery time for each location (A, B, or C).  
6. **`deliverPackage(...)`** – Core decision logic for success, delay, or failure.  
7. **`displaySummary(...)`** – Prints the final summary of the day.  
### Logic Flow
1. The program starts with **`startDay()`**, displaying a welcome message.  
2. For each delivery, the user enters **load** and **location**.  
3. The following checks occur:
   - Weather (using `getWeather()`)  
   - Obstacle detection (using `checkObstacle()`)  
   - Battery level  
4. Based on these conditions:
   - If **rainy**, the flight is delayed.  
   - If **windy** and **battery < 40%**, the drone returns to recharge.  
   - If **obstacle detected**, extra battery is consumed.  
   - Otherwise, delivery is successful.  
5. After each round, the battery updates and results are displayed.  
6. When the user exits, **`displaySummary()`** shows the final delivery report.

