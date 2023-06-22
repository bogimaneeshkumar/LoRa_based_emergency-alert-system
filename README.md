# Emergency Alert System using ESP32 and LoRa

## Project Overview

The Emergency Alert System using ESP32 and LoRa is designed to address the critical need for rescuing individuals in emergency situations where they may not have access to a mobile phone or a reliable network connection. This project utilizes IoT and LoRa technology to create a reliable and efficient communication system for emergency alerts.

During emergencies, such as accidents or health crises or when girl or any person in danger, the affected person can press the emergency alert button on their ESP32-based remote. This remote is assigned a unique ID, allowing the system to identify the person in need. As there might be limited or no cellular network coverage, the system leverages LoRa communication to transmit the emergency alert and location data to the nearest tower.

The tower, equipped with an ESP32 and LoRa transceiver, acts as a relay station. It receives the emergency alert data from the user remote. If the tower is the first tower to receive the user ID, it combines the user ID with its own unique ID, representing its location. This combined ID is then forwarded to the next nearest tower or the central ESP32 in the city center.

If the tower receives an already combined ID with the tower ID, it means that the tower is a duplicate tower near the user's location. In this case, the tower does not add its own ID and forwards the received combined ID to the next nearest tower or the central ESP32.

The central ESP32, connected to the internet via Wi-Fi, receives the combined data from the tower through LoRa communication. It extracts the user remote ID and tower ID from the data packet. The central ESP32 sends this information as a JSON packet to the website's API endpoint.

The website, which serves as a central monitoring and rescue platform, receives the JSON packets containing the emergency alert and location data. It decodes the information and displays it on a map interface, highlighting the precise location of the person in distress. The website also triggers alerts to nearby individuals, notifying them of the emergency and enabling them to provide assistance.

## Necessity of the Project

The Emergency Alert System serves a crucial purpose in scenarios where individuals find themselves in emergency situations without access to mobile phones or a reliable network. This can occur in remote areas with limited network coverage, during natural disasters when networks are disrupted, or when the person is physically unable to use a phone or when during emergencies, such as accidents or health crises or when girl or any person in danger.

By providing a dedicated remote with an emergency alert button, individuals can quickly summon help and share their precise location. The system utilizes the website's map interface to display the emergency location and trigger alerts to nearby individuals and emergency rescuing units such as the police station , hospitals , fire stations, enabling them to provide timely assistance.

## Working Methodology

1. User Remote:
   - The user carries an ESP32-based remote with an emergency alert button.
   - On pressing the button, the remote sends its unique ID via LoRa communication to the nearest tower.

2. Tower:
   - The tower, equipped with an ESP32 and LoRa transceiver, receives the emergency alert data from the user remote.
   - If it is the first tower to receive the user ID, it combines the user ID with its own unique ID and forwards it to the next nearest tower or the central ESP32.
   - If it receives an already combined ID with the tower ID, it forwards the received combined ID to the next nearest tower or the central ESP32.

3. Central ESP32 in the City:
   - The central ESP32, connected to the internet via Wi-Fi, receives the combined data from the tower through LoRa communication.
   - It extracts the user remote ID and tower ID from the data packet.
   - The central ESP32 sends this information as a JSON packet to the website's API endpoint.

4. Website:
   - The website acts as a central monitoring and rescue platform.
   - It receives the JSON packets containing the emergency alert and location data from the central ESP32.
   - The website decodes the information, extracts the user's location, and displays it on a map interface.
   - The website triggers alerts to nearby individuals, notifying them of the emergency and enabling them to provide assistance.

## Technology Stack

- ESP32 Development Boards: Used for the user remote, towers, and central ESP32.
- LoRa Transceiver Modules: Facilitate long-range wireless communication between the user remote, towers, and central ESP32.
- Wi-Fi: Enables the central ESP32 to connect to the internet and send data to the website.
- Website: Utilizes HTML, CSS, and JavaScript to provide a user-friendly interface for monitoring emergencies and displaying the map with alerts.
- Website API: Receives JSON packets from the central ESP32, decodes the data, and updates the map interface accordingly.

## Technology Gap and Project Extension

The initial implementation of the project focused on transmitting the user remote ID and tower ID through LoRa communication to the central ESP32. However, in scenarios where the person is located far from the city center, additional towers are required to relay the data.

To address this, an extension was made to the tower code to handle the following scenarios:

1. If the tower is the first to receive the user ID, it combines the ID with its own unique ID and forwards it to the next nearest tower or the central ESP32.
2. If the tower receives an already combined ID with the tower ID, it forwards the received combined ID without adding its own ID.

This modification ensures that the emergency alert data reaches the central ESP32 even if the person is located far from the city center. The central ESP32 can then send the information to the website, triggering alerts and displaying the emergency location on the map.

## Conclusion

The Emergency Alert System using ESP32 and LoRa provides a reliable and efficient solution for rescuing individuals in emergency situations where mobile phones or network connectivity may not be available. By leveraging IoT and LoRa technology, the system enables users to send emergency alerts with their precise location to the nearest tower. The central ESP32, connected to the internet, relays the information to the website, which displays the emergency location on a map interface and triggers alerts to nearby individuals and emergency rescuing units such as the police station , hospitals , fire stations. This project bridges the technology gap in emergency response, ensuring timely assistance and potentially saving lives.

