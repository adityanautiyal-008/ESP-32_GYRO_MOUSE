# Wireless BLE Gyroscopic Air Mouse (ESP32 + MPU-6050)

[![Platform: ESP32](https://img.shields.io/badge/Platform-ESP32-blue?logo=espressif&logoColor=white)](https://www.espressif.com/)
[![Sensor: MPU--6050](https://img.shields.io/badge/Sensor-MPU--6050-orange)](https://invensense.tdk.com/)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

A hardware-software solution that transforms an ESP32 microcontroller and an MPU-6050 6-axis IMU into a high-precision, wireless "Air Mouse." By leveraging Bluetooth Low Energy (BLE) Human Interface Device (HID) profiles, the system captures physical rotational velocity (pitch and yaw) and maps it seamlessly to native operating system cursor coordinates.

---

## 🚀 Key Features

* **Native BLE HID Integration:** Emulates a standard hardware mouse. No companion software or drivers are required on the host machine.
* **Dual-Axis Motion Mapping:** Dynamically tracks angular velocity around the X-axis (Pitch) for vertical tracking and the Z-axis (Yaw) for horizontal tracking.
* **Tremor & Drift Suppression:** Implements a deadzone filter to neutralize minor hand tremors and baseline sensor noise.
* **Low Latency Processing:** Optimized polling intervals ensure fluid, lag-free cursor tracking suitable for presentations, media navigation, or accessibility setups.

---

## 🛠️ Hardware Architecture & Wiring

### Components Required
* **Microcontroller:** ESP32 Development Board (e.g., ESP32-WROOM-32D)
* **Sensor:** InvenSense MPU-6050 (Accelerometer + Gyroscope)
* **Power Source:** 5V USB Bus Power (During testing/configuration)

### Wiring Topology (I2C Interface)

| MPU-6050 Pin | ESP32 Pin | Wire Function | Notes |
| :--- | :--- | :--- | :--- |
| **VCC** | 3.3V | Logic Power | Do not supply 5V to the MPU-6050 VCC pin. |
| **GND** | GND | Common Ground | Ensure a shared ground rail. |
| **SCL** | GPIO 22 | I2C Clock Line | Dedicated ESP32 hardware I2C pin. |
| **SDA** | GPIO 21 | I2C Data Line | Dedicated ESP32 hardware I2C pin. |

> ⚠️ **Electrical Safety Note:** When programming or debugging via the USB port, do not simultaneously apply external power to the ESP32 `VIN` pin to avoid hardware damage.

---

## 💻 Firmware Installation & Dependencies

### 1. IDE Configuration
Ensure your **Arduino IDE** is configured with the official ESP32 Arduino Core.
* Go to **Tools** > **Board** > **esp32** and select **ESP32 Dev Module**.
* Choose the appropriate active serial port under **Tools** > **Port**.

### 2. Library Requirements
Install the following libraries via the Arduino Library Manager (`Ctrl + Shift + I`):
* **Adafruit MPU6050** (Select *Install All* to automatically append `Adafruit_Sensor` and `Adafruit_BusIO`).

Due to compatibility considerations with modern ESP32 BLE stacks, this repository utilizes the updated **HijelHID_BLEMouse** library:
1. Download the library archive from [HijelHub/HijelHID_BLEMouse](https://github.com/HijelHub/HijelHID_BLEMouse/archive/refs/heads/main.zip).
2. Install via **Sketch** > **Include Library** > **Add .ZIP Library...**

---

## ⚙️ Configuration & Fine-Tuning

You can modify these variables directly within the firmware to adapt to your hardware orientation:

* **Sensitivity Adjustment:**
```cpp
  const int sensitivity = 18; // Increase for higher cursor speed; decrease for finer control.
