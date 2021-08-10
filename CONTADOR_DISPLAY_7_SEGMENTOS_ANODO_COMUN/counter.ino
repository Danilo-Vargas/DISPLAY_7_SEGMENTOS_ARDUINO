
// DECLARACIÓN DE LOS PINES

const int pins[7] = {13,12,11,10,9,8,7};

// VARIABLES

int counter = 0;

const byte numbers_anode[10] = {
    0b0000001,     // 0
    0b1001111,     // 1
    0b0010010,     // 2
    0b0000110,     // 3
    0b1001100,     // 4
    0b0100100,     // 5
    0b0100000,     // 6
    0b0001111,     // 7
    0b0000000,     // 8
    0b0001100,     // 9
};

const byte numbers_cathode[10] = {
    0b1111110,     // 0
    0b0110000,     // 1
    0b1101101,     // 2
    0b1111001,     // 3
    0b0110011,     // 4
    0b1011011,     // 5
    0b1011111,     // 6
    0b1110000,     // 7
    0b1111111,     // 8
    0b1110011,     // 9
};

// FUNCIONES

void displayWrite(int character_pos){
    byte character_byte = numbers_anode[character_pos];  // --CAMBIAR LA VARIABLE 'numbers_anode' A 'numbers_cathode'
    int bit;
    for(int c = 0; c < 7; c++){                          // -EN CASO DE USAR UN DISPLAY DE CÁTODO COMÚN
        bit = bitRead(character_byte, c);
        digitalWrite(pins[c], bit);
    }
}

void setup()
{
	for(int p = 0; p < 7; p++){
        pinMode(pins[p], OUTPUT);
    }

    displayWrite(0);
}

void loop()
{
	delay(1000);
    displayWrite(counter);
    counter++;

    if(counter == 10) counter = 0;

}
