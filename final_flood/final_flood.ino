// Define CO2 emission factors
float electricity = 0.3929;
float transport1 = 0.192;
float transport2 = 0.171;
float transport3 = 0.04333;
float food = 54.2;
float water = 10.6;
float waste = 0.7;
float lpg = 22.2094;
float fire = 3.67;
float x ;
float blockNum ;
float motorTime ;

const int RelayPin = 38;
const int numBlocks = 10;
const int blockTime = 10000; // in milliseconds




void setup() {
  
  float geysarVal;
  float acVal ;
  float lightFanVal ;
  float petrolCarVal ;
  float dieselCarVal ;
  float passengerVal ;
  float foodVal ;
  float waterVal ;
  float wasteVal ;
  float lpgVal ;
  float burningVal ;
 
  Serial.begin(9600);
  pinMode(RelayPin, OUTPUT); // Initialize serial communication
  digitalWrite(RelayPin, HIGH);
  

}

void loop() {
  // Read sensor values from serial monitor
  Serial.println("Enter values according to your daily life activity: geysar, ac, lightFan, petrolCar, dieselCar, passenger, food, water, waste, lpg, burning");
  while (!Serial.available()); // Wait for input
  float geysarVal = Serial.parseFloat();
  while (!Serial.available()); // Wait for input
  float acVal = Serial.parseFloat();
  while (!Serial.available()); // Wait for input
  float lightFanVal = Serial.parseFloat();
  while (!Serial.available()); // Wait for input
  float petrolCarVal = Serial.parseFloat();
  while (!Serial.available()); // Wait for input
  float dieselCarVal = Serial.parseFloat();
  while (!Serial.available()); // Wait for input
  float passengerVal = Serial.parseFloat();
  while (!Serial.available()); // Wait for input
  float foodVal = Serial.parseFloat();
  while (!Serial.available()); // Wait for input
  float waterVal = Serial.parseFloat();
  while (!Serial.available()); // Wait for input
  float wasteVal = Serial.parseFloat();
  while (!Serial.available()); // Wait for input
  float lpgVal = Serial.parseFloat();
  while (!Serial.available()); // Wait for input
  float burningVal = Serial.parseFloat();


 

  // Calculate CO2 emissions
  float CO2_Electrcity = geysarVal * electricity;
  float CO2_Electrcity1 = acVal * electricity;
  float CO2_Electrcity2 = lightFanVal * electricity;
  float CO2_Trasnport_petrol = petrolCarVal * transport1;
  float CO2_Trasnport_diesel = dieselCarVal * transport2;
  float CO2_Trasnport_passenger = passengerVal * transport3;
  float CO2_Food = foodVal * food;
  float CO2_water = waterVal * water;
  float CO2_waste = wasteVal * waste;
  float CO2_gas = lpgVal * lpg;
  float CO2_fire = burningVal * fire;

  // Calculate average CO2 emissions
  float years = (CO2_Electrcity + CO2_Electrcity1 + CO2_Electrcity2 + CO2_Trasnport_petrol + CO2_Food + CO2_water + CO2_waste + CO2_Trasnport_passenger + CO2_Trasnport_diesel + CO2_gas + CO2_fire) / 11;

  // Convert average CO2 emissions to yearly emissions
  //float years = Average ;
  Serial.print("CO2 Emission by per person per day: ");
  Serial.println(years);

  // Calculate CO2 emissions for Mumbai population
  float time = years * 475.56; //mumbai population
  //float produced_CO2 =` time;
  Serial.print("CO2 Emission by mumbai population per day: ");
  Serial.println(time);

  // Calculate total carbon emission
  //float number = 4775420471360;
  float number = 32000.0;
  // Calculate number of years to reach total carbon emission
  float total_years = 30 * number / time;
  //float years1 = total_years * 30 ;
   Serial.print("Total years left: ");
    Serial.println(total_years);

  float percent_10 = number * 0.1;
  float percent_20 = number * 0.2;
  float percent_30 = number * 0.3;
  float percent_40 = number * 0.4;
  float percent_50 = number * 0.5;
  float percent_60 = number * 0.6;
  float percent_70 = number * 0.7;
  float percent_80 = number * 0.8;
  float percent_90 = number * 0.9;
  float percent_100 = number * 1.0;

  
  int x = 0;

// Break the total carbon emission into 10 blocks
if (time >= 0 and time <= 3200.0)
  x = 1;
if (time >= 3200.0 and time <= 6400.0)
  x = 2;
if (time >= 6400.0 and time <= 9600.0)
  x = 3;
if (time >= 9600.0 and time <= 12800.0)
  x = 4;
if (time >= 12800.0 and time <= 16000.0)
  x = 5;
if (time >= 16000.0 and time <= 19200.0)
  x = 6;
if (time >= 19200.0 and time <= 22400.0)
  x = 7;
if (time >= 22400.0 and time <= 25600.0)
  x = 8;
if (time >= 25600.0 and time <= 28800.0)
  x = 9;
if (time >= 28800.0 and time <= 32000)
  x = 10;


// Print the result
Serial.print("Block-Number: ");
Serial.println(x);

float block = x ;


//float blockNum = x ;

// Break the total carbon emission into 10 blocks
if (Serial.available() > 0) {

if (x ==1 )
  motorTime = 10000;
if (x == 2 )
  motorTime = 20000;
if (x == 3 )
  motorTime = 30000;
if (x == 4 )
  motorTime = 40000;
if (x == 5 )
  motorTime = 50000;
if (x == 6 )
  motorTime = 60000;
if (x == 7 )
  motorTime = 70000 ;
if (x == 8)
  motorTime = 80000;
if (x == 9 )
  motorTime = 90000;
if (x == 10 )
  motorTime = 100000;



  
  digitalWrite(RelayPin, LOW);
  delay(motorTime);
  digitalWrite(RelayPin, HIGH);
   
  
  Serial.println("Pump ran for : " + String(motorTime) + "ms.");
} else {
  Serial.println("Invalid block number.");
    }
}  



