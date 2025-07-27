# 🌞 Sun Tracking Solar Panel System

> Dual Axis Solar Tracker using Arduino and LDRs for enhanced solar energy capture.

---

##  Abstract

The growing demand for clean energy has driven the need for more efficient solar power systems. This project presents a dual-axis solar tracking system using Arduino Mega, Light Dependent Resistors (LDRs), and servo motors. The tracker ensures that the solar panel remains perpendicular to the sun’s rays throughout the day, maximizing energy generation.

> 📈 The designed system achieves an **annual energy gain of 48.98%** over static panels, and **36.5% over single-axis trackers**.

---

##  Tech Stack & Components

-  **Microcontroller:** Arduino Mega
-  **Sensors:** Light Dependent Resistors (LDR)
-  **Actuators:** 2 Servo Motors (Horizontal and Vertical Axes)
-  **Power Supply:** Solar Panel
-  **Other:** Breadboard, Jumper Wires, Mounting Frame

---

##  Project Images

###  Final Hardware Setup
![Model](final_model.jpg)

###  Circuit Diagram
![Circuit](Sun_Tracker/AnalogInOutSerialfinalprojectcode/circuit.jpg

---

##  Working Principle

- Four LDRs are placed in a cross formation to sense light intensity.
- Arduino reads these values and adjusts servo motors accordingly.
- The panel rotates **horizontally and vertically** to align with the sun.
- Tracker maintains **perpendicular alignment** for maximum power.

---

## 🔧 How to Run

1. Upload the Arduino sketch `Arduino_Code.ino` using Arduino IDE.
2. Connect servo motors and LDRs as per the circuit diagram.
3. Place the setup under sunlight and observe automatic alignment.

---

##  Key Outcomes

-  Achieved dual-axis tracking.
-  Improved energy harvesting efficiency.
-  Simple yet scalable design.

---

##  Learnings

- Embedded system programming using Arduino
- Sensor-based real-time control systems
- Physical hardware prototyping

---

##  Author
Nani
