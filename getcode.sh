#!/bin/bash

# ============================================================
# Arduino Code Fetcher
# Replace YOURNAME with your actual GitHub username
# ============================================================
REPO="https://raw.githubusercontent.com/ankushgarg44/arduino-codes/main"

# Map short names to .ino files
case "$1" in
  ldr)         FILE="ldr.ino" ;;
  temp)        FILE="temp.ino" ;;
  motor)       FILE="motor.ino" ;;
  servo)       FILE="servo.ino" ;;
  blink)       FILE="blink.ino" ;;
  ultrasonic)  FILE="ultrasonic.ino" ;;
  pir)         FILE="pir.ino" ;;
  bluetooth)   FILE="bluetooth.ino" ;;
  wifi)        FILE="wifi.ino" ;;
  oled)        FILE="oled.ino" ;;
  keypad)      FILE="keypad.ino" ;;
  rfid)        FILE="rfid.ino" ;;
  joystick)    FILE="joystick.ino" ;;
  relay)       FILE="relay.ino" ;;
  buzzer)      FILE="buzzer.ino" ;;
  *)
    echo "❌ Unknown code: $1"
    echo ""
    echo "Available codes:"
    echo "  ldr, temp, motor, servo, blink, ultrasonic, pir, bluetooth,"
    echo "  wifi, oled, keypad, rfid, joystick, relay, buzzer"
    exit 1
    ;;
esac

# Fetch the code from GitHub
CODE=$(curl -sL "$REPO/$FILE")

if [ -z "$CODE" ]; then
  echo "❌ Failed to fetch $FILE. Check your internet or the repo URL."
  exit 1
fi

# Detect OS and copy to clipboard
if command -v pbcopy &> /dev/null; then
    # macOS
    echo "$CODE" | pbcopy
    echo "✅ '$1' code copied to clipboard!"
elif command -v xclip &> /dev/null; then
    # Linux with xclip
    echo "$CODE" | xclip -selection clipboard
    echo "✅ '$1' code copied to clipboard!"
elif command -v xsel &> /dev/null; then
    # Linux with xsel
    echo "$CODE" | xsel --clipboard --input
    echo "✅ '$1' code copied to clipboard!"
elif command -v clip.exe &> /dev/null; then
    # Windows Git Bash / WSL
    echo "$CODE" | clip.exe
    echo "✅ '$1' code copied to clipboard!"
else
    # Fallback: just print
    echo "⚠️  No clipboard tool found. Printing code instead:"
    echo ""
    echo "$CODE"
fi
