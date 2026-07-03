# HYDROWATCH: IoT Water Quality Monitoring System using ESP32

An open-source Societal Internship Project designed to provide an automated, smart, and cost-effective solution for real-time water purity monitoring and environmental tracking[cite: 2]. This repository contains firmware and simulation configurations to interface analog sensors with an ESP32 edge node to collect Total Dissolved Solids (TDS) and Electrical Conductivity (EC) data, streaming live metrics to a remote mobile application dashboard[cite: 2].

---

## 🎯 Project Objectives
* **Core Aim:** To develop a smart and automated water quality monitoring system for enhancing public health and safety[cite: 2].
* To reduce tracking and alert response times during contamination events by implementing remote dashboards[cite: 2].
* To design a cost-effective and reliable environment logging node using IoT technology[cite: 2].
* To utilize engineering knowledge to solve real-life social problems related to clean water scarcity[cite: 2].
* To promote the use of technology for public safety and social welfare[cite: 2].

---

## 🌍 Specific Socio-Economic Outcomes Aimed to Achieve
* To minimize the outbreak of waterborne conditions by ensuring timely purity tracking[cite: 2].
* To provide immediate water metric data to community users and regional water utility operations[cite: 2].
* To reduce the delay in contamination awareness, especially in remote agricultural or rural areas[cite: 2].
* To create awareness about the importance of intelligent environmental safety frameworks[cite: 2].
* To contribute towards building safer community consumption setups and improving overall well-being[cite: 2].
* To encourage the widespread adoption of affordable smart environmental safety arrays[cite: 2].

---

## 📋 Roles, Responsibilities & Duties
* **Societal Problem Study:** Investigated risk vectors associated with delayed tracking and manual verification of contaminated water lines[cite: 2].
* **Circuit Architecture:** Designed hardware circuits utilizing ESP32 microcontrollers, TDS sensor units, and EC probes[cite: 2].
* **System Integration:** Integrated sensor breakout modules with local wireless communication infrastructure lanes[cite: 2].
* **Firmware Development:** Developed and optimized low-latency embedded software routines within the Arduino IDE[cite: 2].
* **System Testing:** Performed environment simulation testing and analyzed the processing performance of the prototype[cite: 2].

---

## 🗓️ 15-Day Project Methodology Timeline

* **Days 1–2:** Identification of the target societal problem and literature survey[cite: 2]. Selection of suitable analog sensors and edge processing modules (ESP32 DevKit, TDS Module, EC Module)[cite: 2].
* **Day 3:** Hardware design, terminal pin configuration mapping, and circuit schematic development[cite: 2].
* **Days 4–5:** Configured the Blynk Cloud Template workspace and established Virtual Datastream endpoints (`V0` and `V1`)[cite: 2].
* **Day 6:** Interfaced analog sensor channels with the ESP32 and implemented 12-bit ADC mathematical code equations to map raw voltages to parts per million (ppm)[cite: 2].
* **Days 7–8:** Interfaced the internal ESP32 Wi-Fi network stack to establish a live connection with the Blynk Cloud layer[cite: 2].
* **Day 9:** Performed behavioral hardware simulation inside Wokwi using potentiometer arrays to safely mimic sudden fluid pollution jumps[cite: 2].
* **Days 10–11:** Generated a structural layout footprint of all components in EasyEDA software and designed clean PCB trace paths[cite: 2].
* **Days 12–15:** Completed final PCB etching, component soldering, validation, and field housing development[cite: 2].

---

## 🛠️ Interventions & Hardware Mapping

The developed edge system continuously monitors chemical water parameters through the integrated sensor array[cite: 2]. When total dissolved solids exceed safe, pre-programmed thresholds, a contamination hazard is flagged[cite: 2]. The ESP32 instantly initializes data packet transmissions via Wi-Fi to push live data directly to the user's mobile dashboard widgets[cite: 2].

| Sensor Output Signal | ESP32 Pin Assignment | Input Pin Mode | Operating Voltage |
| :--- | :--- | :--- | :--- |
| **TDS Analog Out (AOUT)** | **GPIO 34 (ADC1_CH6)** | Analog Input | 0V - 3.3V |
| **EC Analog Out (AOUT)** | **GPIO 35 (ADC1_CH7)** | Analog Input | 0V - 3.3V |
| **Sensor Power VCC** | **3V3 Rail** | Power Output Line| 3.3V |
| **Sensor Common Ground** | **GND** | System Ground Bus| 0V |

---

## ⚠️ Challenges Faced & Solutions Implemented

* **Over-Voltage Hazards:** 5V analog sensor output rails pose a degradation risk to 3.3V maximum rated ESP32 GPIO inputs[cite: 2].
  * *Solution:* Implemented a balanced 4.7kΩ / 10kΩ resistor hardware voltage divider network to step down signals safely[cite: 2].
* **Dropped Wireless Handshakes:** Standard blocking `delay()` functions inside code routines caused frequent Wi-Fi drops and disconnects from the Blynk cloud[cite: 2].
  * *Solution:* Reworked the firmware to leverage an asynchronous, non-blocking `BlynkTimer` polling loop[cite: 2].
* **Probe Preservation During Testing:** Physical calibration in fluid solutions risked premature wear on sensor probes during early troubleshooting phases[cite: 2].
  * *Solution:* Conducted comprehensive validation within the Wokwi sandbox simulator environment using potentiometers before deployment[cite: 2].

---

## 💡 Skills Learned & Professional Experience

* **Technical Competencies:** Embedded C++ programming, ESP32 architecture optimization, multi-sensor ADC calibration, IoT cloud integration via virtual pins, and EasyEDA PCB trace layout design[cite: 2].
* **Professional Competencies:** Systematic problem-solving, project management, technical writing, and structural documentation design[cite: 2].
* **Personal Growth:** Cultivated deep awareness regarding public health safety issues and recognized the impact of engineering in local social welfare developments[cite: 2].

---

## 🚀 Future Scope
* Integration with standalone GSM/LTE cellular shields or long-range LoRaWAN hardware to support off-grid water reservoirs[cite: 2].
* Development of automated physical solenoid valve shut-off mechanisms when dangerous contamination is detected[cite: 2].
* Direct automated alert logging links connected straight to municipal water management boards[cite: 2].

---

## 📜 Conclusion
The Smart Water Quality Monitoring and IoT Telemetry System was successfully designed, simulated, and implemented[cite: 2]. The system automatically tracks water purity deviations, handles cloud data transmission over active network gateways, and showcases real-time analytics on a custom smartphone interface to minimize detection delays and enhance public safety[cite: 2].