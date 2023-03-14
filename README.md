# Attitude Determination and Control Subsystem (ADCS)

This is a simple project to demonstrate satellite ADCS. This is a 1DOF (one degree of freedom) prototype.

![Satellite](./Images/satellite_image.png)

It takes input from Ground Station (Android App) which is the required angle, then using both IMU and reaction wheel to drive system to the desired angle. Ground station also offers other features.

![Android App](./Images/ground_station_screenshots.png)


# Tools 

For satellite hardware, It uses Arduino Mega, with MPU6050 (Inertial Measurement Unit), HC-05 (Bluetooth module), an LED and Motor Driver powered by Lithium Ion batteries.

For Ground Station, an Android app is created by MIT App Inventor to display satelllite status and sends commands to satellite.

For further info:

1. [Components](Docsuments/system_components.md)
2. [How it works](Docsuments/how_it_works.md)
3. [Ground station](Docsuments/ground_station.md)