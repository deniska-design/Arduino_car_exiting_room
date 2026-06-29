Autonomous Obstacle-Avoiding Smart Car

An autonomous 4-wheeled robotic smart car built on the Arduino platform. The project utilizes an ultrasonic distance sensor mounted on a micro servo motor to actively scan its surroundings, compare spatial data, and navigate toward the path with the largest clearance. Thanks to this logic, if placed in an enclosed space or square room with an open exit, the car will dynamically chart a path and find its way out.

---

Features:

* **Custom-Built Hardware Drivers:** Built entirely without external, high-level third-party libraries for the core components. 
  * `HC-SR04.h`: A custom-written driver handling low-level pulse triggers and timing conversions (`pulseIn`) to calculate distances in centimeters.
  * `Car_motors.h`: A bespoke abstraction layer for independent 4-motor differential steering controls (forward, backward, left/right turns, and precise rotational spinning).
* **Spatial Scanning Algorithm:** The car stops and utilizes a micro servo to point the ultrasonic sensor in 3 directions (**Left, Center, Right**), saving distance measurements into a local tracking array.
* **Smart Decision Making:** Evaluates the scanned data at every iteration, calculates the maximum distance vector, and executes the optimal directional maneuver to avoid walls.

---

Hardware Configuration & Pinout:

Based on the default configuration in the source files, the components are wired as follows:

| Component | Pin / Channel | Description |
| :--- | :--- | :--- |
| **Servo Motor** | `A3` | Rotates the ultrasonic sensor array |
| **HC-SR04 Trig** | `12` | Triggers the ultrasonic pulse |
| **HC-SR04 Echo** | `13` | Reads the returning sound bounce |
| **Motor Drivers** | `5, 2, 4, 6` | H-Bridge logic interface pins for 4 DC motors |
| **IR Receiver** *(Optional)* | `3` | Remote control signal mapping |

---

Installation & Setup:

### 1. Clone the Repository
Open your terminal or command prompt and run:

```
git clone https://github.com/deniska-design/car_controlling.git
```
```
cd car_controlling
```
2. Open and Configure the Project
Launch the Arduino IDE.

Open the main sketch file: sketch_may19a.ino.

(Optional) If your specific hardware variant uses the manual remote mode, make sure you have installed the required library for your IR remote (e.g., IRremote.h) via the IDE Library Manager (Tools -> Manage Libraries).

3. Upload the Code
Connect your Arduino Uno board to your PC using a USB cable.

In the top IDE menu, select your board target:

Tools -> Board -> Arduino AVR Boards -> Arduino Uno

Select the active COM port assigned to your board under:

Tools -> Port

Click the Upload arrow button in the top left corner.

---

Execution:

https://github.com/user-attachments/assets/504c1d3b-490d-422a-885a-d0fb4b86b254

---

License: This project is open-source. Anyone is completely free to download, modify, use, and distribute this software for personal, hobbyist, or educational purposes.
