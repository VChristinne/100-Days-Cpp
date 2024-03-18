int led_red = 13;
int led_yellow = 12;
int led_green = 11;
int led_blue = 10;

void setup()
{
    pinMode(led_red, OUTPUT);
    pinMode(led_yellow, OUTPUT);
    pinMode(led_green, OUTPUT);
    pinMode(led_blue, OUTPUT);

    letter_I();
    delay(1000);

    letter_L();
    delay(1000);

    letter_O();
    delay(1000);

    letter_V();
    delay(1000);

    letter_U();
}

void turn_on_all()
{
    digitalWrite(led_red, HIGH);
    digitalWrite(led_yellow, HIGH);
    digitalWrite(led_green, HIGH);
    digitalWrite(led_blue, HIGH);
}

void turn_off_all()
{
    digitalWrite(led_red, LOW);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led_blue, LOW);
}

void dot()
{
    digitalWrite(led_red, HIGH);
    delay(200);
    digitalWrite(led_red, LOW);
    delay(200);
}

void letter_I()
{
    dot();
    dot();
}

void letter_L()
{
    dot();
    turn_on_all();
    delay(1000);
    turn_off_all();
    dot();
    dot();
}

void letter_O()
{
    for (int i=0; i<=2; i++)
    {
        turn_on_all();
        delay(1000);
        turn_off_all();
        delay(500);
    }
}

void letter_V()
{
    dot();
    dot();
    dot();
    turn_on_all();
    delay(1000);
    turn_off_all();
}

void letter_U()
{
    dot();
    dot();
    turn_on_all();
    delay(1000);
    turn_off_all();
}

void loop()
{
    delay(10);
}