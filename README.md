# Emergency Alert System using ESP32 and LoRa

## Project Overview

The Emergency Alert System using ESP32 and LoRa is designed to address the critical need for rescuing individuals in emergency situations where they may not have access to a mobile phone or a reliable network connection. This project utilizes IoT and LoRa technology to create a reliable and efficient communication system for emergency alerts.

During emergencies, such as accidents or health crises or any persons in danger, the affected person can press the emergency alert button on their ESP32-based remote. This remote is assigned a unique ID, allowing the system to identify the person in need. As there might be limited or no cellular network coverage, the system leverages LoRa communication to transmit the emergency alert and location data to a designated tower.

The tower, equipped with an ESP32 and LoRa transceiver, acts as a relay station. It receives the emergency alert data from multiple user remotes and appends its own unique ID, representing its location, to the data packet. The tower then forwards this combined information to the central ESP32, located in the city center.

The central ESP32, connected to the internet via Wi-Fi, receives the combined data from the tower through LoRa communication. It extracts the user remote ID and tower ID, and sends this information as a JSON packet to a designated API endpoint on a website.

The website, which serves as a central monitoring and rescue platform, receives the JSON packets containing the emergency alert and location data. It decodes the information and displays it on a map interface, highlighting the precise location of the person in distress. The website also triggers an alert to notify rescue teams or relevant authorities, enabling them to respond swiftly and effectively.

## Necessity of the Project

The Emergency Alert System serves a crucial purpose in scenarios where individuals find themselves in emergency situations without access to mobile phones or a reliable network. This can occur in remote areas with limited network coverage, during natural disasters when networks are disrupted, or when the person is physically unable to use a phone.

By providing a dedicated remote with an emergency alert button, individuals can quickly summon help and share their precise location. This ensures that rescue teams can be dispatched promptly, reducing response times and potentially saving lives.

## Working Methodology

1. User Remote:
   - The user carries an ESP32-based remote with an emergency alert button.
   - On pressing the button, the remote sends its unique ID via LoRa communication to a designated tower.

2. Tower:
   - The tower, equipped with an ESP32 and LoRa transceiver, receives the emergency alert data from the user remote.
   - It appends its own unique ID, representing the tower's location, to the data packet.
   - The tower forwards the combined data to the central ESP32 using LoRa communication.

3. Central ESP32 in the City:
   - The central ESP32, connected to the internet via Wi-Fi, receives the combined data from the tower through LoRa communication.
   - It extracts the user remote ID and tower ID from the data packet.
   - The central ESP32 sends this information as a JSON packet to the website's API endpoint.

4. Website and API:
   - The website hosts an API endpoint to receive the JSON packets containing emergency alert and location data.
   - The API endpoint decodes the JSON data and updates the emergency status and location on the website's map interface.
   - The website triggers alerts to notify rescue teams or relevant authorities.

## Technology Used

- IoT (Internet of Things): The project leverages IoT technology by connecting the ESP32 boards to create a network of remote devices and central hubs for data transmission.

- LoRa (Long Range): LoRa communication is utilized to establish long-range, low-power wireless communication between the user remote, tower, and central ESP32, enabling reliable transmission of emergency alert and location data.

- Wi-Fi: The central ESP32 connects to the internet using Wi-Fi, allowing it to send the emergency data to the website's API endpoint for further processing.

## Technology Gap

The project bridges the technology gap by providing an alternative communication system in scenarios where traditional means, such as mobile networks, may not be available or accessible. By utilizing LoRa and IoT, the system enables individuals to send emergency alerts and share their location, allowing prompt response and rescue operations.

Additionally, by integrating the central ESP32 with Wi-Fi connectivity and a website API, the project takes advantage of existing infrastructure to relay the emergency data to a central monitoring platform. This allows rescue teams and authorities to efficiently track emergencies and coordinate their response efforts.

