# Smart Shopping Cart using Arduino RFID and Zigbee

An IoT and embedded systems project that automates product scanning and billing inside a shopping trolley using RFID cards/tags, Arduino, a 16x2 LCD, and Zigbee wireless communication.

## Project Category

- Internet of Things
- Embedded Systems
- Arduino
- RFID Based Billing
- Zigbee Wireless Communication
- Retail Automation
- Final Year Engineering Project

## Problem Statement

Traditional supermarket billing depends on manual barcode scanning at the checkout counter. This creates long queues, increases waiting time, and can make it difficult for customers to track the total bill while shopping.

This project solves the problem by placing RFID-based item scanning and billing directly inside the shopping trolley.

## Features

- Scans RFID-tagged products when they are placed near the reader.
- Displays product name, product price, item count, and total bill on a 16x2 LCD.
- Supports adding and removing items by scanning the same RFID card/tag again.
- Generates a final bill when the checkout switch is pressed.
- Sends bill details wirelessly to the server side using Zigbee.
- Uses a buzzer alert when an RFID card/tag is detected.

## Hardware Components

| Component | Purpose |
| --- | --- |
| Arduino Uno R3 | Main controller for RFID reading, billing logic, LCD, and serial communication |
| RFID Reader | Reads RFID card/tag values for product identification |
| RFID Cards/Tags | Store product IDs used for billing |
| Zigbee Transmitter and Receiver | Sends billing data wirelessly to the server side |
| 16x2 LCD Display | Shows product details and total bill |
| Push Button | Confirms final bill/payment |
| Buzzer | Gives scan feedback |
| 5V Regulated Power Supply | Powers the controller and modules |

## Software Used

- Arduino IDE
- Embedded C / Arduino C++
- Serial communication at 9600 baud
- Proteus simulation, if used for circuit testing

## System Workflow

1. The trolley starts with zero products and zero bill amount.
2. The RFID reader continuously checks for RFID cards/tags.
3. When a valid product tag is scanned, the item is added to the trolley.
4. Product name and updated bill amount are shown on the LCD.
5. If the same product tag is scanned again, that item is removed from the bill.
6. When the customer presses the checkout switch, the final bill is printed over serial and transmitted through Zigbee.

## Product Data Used in Prototype

| RFID Tag | Product | Price |
| --- | --- | ---: |
| `2E0042BE4D9F` | Maggi | Rs. 30 |
| `2E0042BE6FBD` | Dairy Milk | Rs. 40 |
| `2E0042BE0BD9` | Dettol Soap | Rs. 20 |
| `2E0042BE2EFC` | Parle Cookie | Rs. 15 |
| `2E0042BE2DFF` | Lays | Rs. 25 |
| `2E0042BE70A2` | Dove Shampoo | Rs. 45 |

## Repository Structure

```text
.
|-- README.md
|-- src/
|   `-- smart_shopping_cart.ino
|-- docs/
|   |-- project-summary.md
|   |-- linkedin-profile.md
|   `-- circuit-diagram.md
|-- images/
|   `-- README.md
|-- demo/
|   `-- README.md
|-- .gitignore
`-- LICENSE
```

## How to Run

1. Open `src/smart_shopping_cart.ino` in Arduino IDE.
2. Connect the LCD, RFID reader, buzzer, button, and Zigbee module as per your circuit.
3. Update RFID tag values in the code if your cards are different.
4. Select the Arduino board and COM port.
5. Upload the code.
6. Open Serial Monitor at `9600` baud to view transmitted billing output.

## Applications

- Smart retail stores
- Supermarket billing automation
- Queue reduction systems
- RFID-based inventory tracking
- Embedded systems learning project

## Future Improvements

- Add a payment module inside the cart.
- Use a larger display or touchscreen.
- Store product data in EEPROM or an external database.
- Add Wi-Fi or cloud connectivity.
- Add a mobile app for live cart billing.
- Improve inventory updates on the server side.
- Add AI-based product recommendations in an advanced version.

## LinkedIn Project Description

Developed a smart shopping cart using Arduino, RFID, and Zigbee to automate product identification and billing in retail stores. The system scans RFID-tagged products, displays item details and total cost on an LCD, and transmits the final bill wirelessly to the server side using Zigbee communication. This project helped me work with embedded systems, RFID integration, serial communication, wireless modules, and hardware prototyping.

## Topics

`arduino` `iot` `rfid` `zigbee` `embedded-systems` `smart-shopping-cart` `retail-automation` `final-year-project`
