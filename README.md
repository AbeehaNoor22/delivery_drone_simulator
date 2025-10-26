# delivery_drone_simulator
A C++ program for delivery drone software managing flights different locations daily based on weather, battery, and obstacles, with end-of-day mission summary reporting.
## Team Information

**Project Title:** Delivery Drone Simulator  

**Team Members:**
- **Aliza Batool** – Programmer 1; designed base code and also made some modifications. Wrote a part of readme. Modified lms deliverable.
- **Abeeha Noor** –  Programmer 2; made modifications in the code eg added functions, exit conditions etc. Wrote a part of readme. Logic designer 2; made flow chart.Modified lms deliverable.
- **Fatima Zahra Mustapha** – Documenter; made basic lms deliverable doc. Logic designer 1; made flow chart.
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
1. The program starts with **`startDay()`**, displays a welcome message and asks whether to start the function or not. 
2. For each delivery, the user enters **load** it is valid then the program further asks for the **location** after chcking its validity it proceeds.  
3. The program checks for invalid data type input and then continues.
4. The following checks occur:
   - Weather (using `getWeather()`)  
   - Obstacle detection (using `checkObstacle()`)  
   - Battery level  
   All these checks are wraped inside the function of delivery package.
5. Based on these conditions:
   - If **rainy**, the flight is delayed.  
   - If **windy** and **battery < 40%**, the drone returns to recharge.  
   - If **obstacle detected**, extra battery is consumed.  
   - Otherwise, delivery is successful.  
6. After each round, the battery updates and results are displayed.  
7. When the user exits, **`displaySummary()`** shows the final delivery report of all the deliveries of the day.
### Description of how random environmental factors are simulated
The rand() and srand() functions are used from the <cstdlib> header for generating random weather and obstacle. 

## Execution Instructions
### Assumptions:
-Battery drain per trip = 15%.  
-Rerouting due to obstacle = +5% drain.  
-Recharge adds +10% battery.  
-Maximum load capacity=50 kg. 
### sample outputs
Some sample outputs are included in this readme.

## Team Collaboration Summary
Two people ***Zahra and Abeeha*** worked on the development of the basic code flow in simple terms. Then one person ***Aliza*** made the basic code and commited it on git. ***Abeeha and Aliza*** then made further modicfications by adding functions, making exit conditions, placing checks for invalid inputs, testing different tests cases and finally compiling evidence test cases from the final code some of which are also in this readme. 
For the documentation ***Abeeha and Aliza*** made the readme and all three worked on the word doc.
## AI tool reflection
### AI Tools Used:
ChatGPT
### Tasks Assisted:
-Provided error-handling ideas for invalid input (cin.fail() concept).  
-Suggested better documentation format.
### Reflection:
-Learned about input validation and error handling.
## Future improvements
The program can be further improved by adding more realistic time delays, more weather conditions, detecting the type of object and not just its presence, the program should also be improved in such a way as to restart just the particular module from the point where the user gives an invalid input and not just break out of the program or start from the very begininning.