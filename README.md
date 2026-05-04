# Arduino Codes

One command to copy any Arduino code to your clipboard.

## Usage (Any Computer)

```bash
curl -sL https://tinyurl.com/getarduino | bash -s CODE_NAME
```

### PowerShell

If you want to run the published script directly from the raw file URL, use:

```powershell
& ([scriptblock]::Create((irm https://tinyurl.com/txkmrxrp))) -Name blink
```

Replace `blink` with any available code name such as `ldr`, `servo`, or `oled`.

If you already have the file in this repo, you can also run it locally:

```powershell
.\getcode.ps1 -Name blink
```

### Examples

```bash
curl -sL https://tinyurl.com/getarduino | bash -s ldr
curl -sL https://tinyurl.com/getarduino | bash -s servo
curl -sL https://tinyurl.com/getarduino | bash -s temp
```

## Available Codes

| Code | Description |
|------|-------------|
| `ldr` | LDR sensor with 3 LEDs |
| `temp` | DHT11 temperature & humidity |
| `motor` | DC motor with L298N driver |
| `servo` | Servo motor sweep |
| `blink` | Basic LED blink |
| `ultrasonic` | HC-SR04 distance sensor |
| `pir` | PIR motion sensor |
| `bluetooth` | HC-05/06 Bluetooth module |
| `wifi` | ESP8266 WiFi module |
| `oled` | SSD1306 OLED display |
| `keypad` | 4x4 matrix keypad |
| `rfid` | RC522 RFID reader |
| `joystick` | Analog joystick module |
| `relay` | Relay module control |
| `buzzer` | Passive buzzer melody |

## Setup (for repo owner)

1. Create repo `arduino-codes` on GitHub
2. Upload all `.ino` files and `getcode.sh`
3. Replace `YOURNAME` in `getcode.sh` with your GitHub username
4. Get raw URL of `getcode.sh` and shorten via tinyurl.com to `getarduino`
