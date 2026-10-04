#include <LiquidCrystal.h>

// LCD pins: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

const int CHECKOUT_SWITCH_PIN = 5;
const int BUZZER_PIN = 7;
const int RFID_TAG_LENGTH = 12;

struct Product {
  const char* tag;
  const char* name;
  int price;
  bool inCart;
};

Product products[] = {
  {"2E0042BE4D9F", "MAGGI", 30, false},
  {"2E0042BE6FBD", "DAIRY MILK", 40, false},
  {"2E0042BE0BD9", "DETTOL SOAP", 20, false},
  {"2E0042BE2EFC", "PARLE COOKIE", 15, false},
  {"2E0042BE2DFF", "LAYS", 25, false},
  {"2E0042BE70A2", "DOVE SHAMPOO", 45, false}
};

const int PRODUCT_COUNT = sizeof(products) / sizeof(products[0]);

char rfidBuffer[RFID_TAG_LENGTH + 1];
int readIndex = 0;
int itemCount = 0;
int totalAmount = 0;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  pinMode(CHECKOUT_SWITCH_PIN, INPUT_PULLUP);

  lcd.begin(16, 2);
  Serial.begin(9600);

  showStartupMessage();
  showCartStatus();
}

void loop() {
  if (digitalRead(CHECKOUT_SWITCH_PIN) == LOW) {
    printFinalBill();
    delay(1000);
    showCartStatus();
  }

  readRfidTag();
}

void showStartupMessage() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Wireless Smart");
  lcd.setCursor(0, 1);
  lcd.print("Shopping Cart");
  delay(2500);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RFID + Zigbee");
  lcd.setCursor(0, 1);
  lcd.print("Billing System");
  delay(2500);
}

void readRfidTag() {
  while (Serial.available() > 0) {
    char input = Serial.read();

    if (input == '\n' || input == '\r') {
      continue;
    }

    rfidBuffer[readIndex] = input;
    readIndex++;

    if (readIndex == RFID_TAG_LENGTH) {
      rfidBuffer[RFID_TAG_LENGTH] = '\0';
      handleTag(rfidBuffer);
      readIndex = 0;
    }
  }
}

void handleTag(const char* tag) {
  beep();

  for (int i = 0; i < PRODUCT_COUNT; i++) {
    if (strncmp(tag, products[i].tag, RFID_TAG_LENGTH) == 0) {
      toggleProduct(i);
      return;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Unknown RFID");
  lcd.setCursor(0, 1);
  lcd.print(tag);
  delay(1500);
  showCartStatus();
}

void toggleProduct(int index) {
  Product& product = products[index];

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(product.name);

  if (product.inCart) {
    product.inCart = false;
    itemCount--;
    totalAmount -= product.price;
    lcd.setCursor(0, 1);
    lcd.print("ITEM REMOVED");
  } else {
    product.inCart = true;
    itemCount++;
    totalAmount += product.price;
    lcd.setCursor(0, 1);
    lcd.print("ADDED RS:");
    lcd.print(product.price);
  }

  delay(1500);
  showCartStatus();
}

void showCartStatus() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ITEMS:");
  lcd.print(itemCount);

  lcd.setCursor(0, 1);
  lcd.print("BILL RS:");
  lcd.print(totalAmount);
}

void printFinalBill() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("FINAL BILL");
  lcd.setCursor(0, 1);
  lcd.print("PAYMENT");

  Serial.println("-----------------------------");
  Serial.println("WIRELESS SHOPPING TROLLEY");

  for (int i = 0; i < PRODUCT_COUNT; i++) {
    if (products[i].inCart) {
      Serial.print(products[i].name);
      Serial.print(" : ");
      Serial.print(products[i].price);
      Serial.println(" RS");
    }
  }

  Serial.println();
  Serial.print("TOTAL AMOUNT IS : ");
  Serial.print(totalAmount);
  Serial.println(" RS");
  Serial.println("-----------------------------");
}

void beep() {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(150);
  digitalWrite(BUZZER_PIN, LOW);
}
