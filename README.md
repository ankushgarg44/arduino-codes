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
curl -sL https://tinyurl.com/getarduino | bash -s led
curl -sL https://tinyurl.com/getarduino | bash -s blynk
curl -sL https://tinyurl.com/getarduino | bash -s dht
```

## Available Codes

| Code | Description |
|------|-------------|
| `assistant` | Assistant module |
| `bluetoothled` | Bluetooth with LED control |
| `blynk` | Blynk IoT integration |
| `blynkdht11i` | Blynk with DHT11 sensor |
| `dht` | DHT temperature & humidity sensor |
| `dhtled` | DHT with LED indicator |
| `hc05dht11` | HC-05 Bluetooth with DHT11 |
| `ldr` | LDR light sensor |
| `ldrled` | LDR with LED control |
| `led` | Basic LED control |
| `pushbutton` | Push button input |
| `wifi` | WiFi connectivity |

## Setup (for repo owner)

1. Create repo `arduino-codes` on GitHub
2. Upload all `.ino` files and `getcode.sh`
3. Replace `YOURNAME` in `getcode.sh` with your GitHub username
4. Get raw URL of `getcode.sh` and shorten via tinyurl.com to `getarduino`
