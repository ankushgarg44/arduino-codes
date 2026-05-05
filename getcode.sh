#!/bin/bash

# ============================================================
# Arduino Code Fetcher
# Replace YOURNAME with your actual GitHub username
# ============================================================
REPO="https://raw.githubusercontent.com/ankushgarg44/arduino-codes/main"

# Map short names to .ino files
case "$1" in
  assistant)   FILE="assistant.ino" ;;
  bluetoothled) FILE="bluetoothled.ino" ;;
  blynk)       FILE="blynk.ino" ;;
  blynkdht11) FILE="blynkdht11.ino" ;;
  dht)         FILE="dht.ino" ;;
  dhtled)      FILE="dhtled.ino" ;;
  hc05dht11)   FILE="hc05dht11.ino" ;;
  ldr)         FILE="ldr.ino" ;;
  ldrled)      FILE="ldrled.ino" ;;
  led)         FILE="led.ino" ;;
  pushbutton)  FILE="pushbutton.ino" ;;
  wifi)        FILE="wifi.ino" ;;
  *)
    echo "❌ Unknown code: $1"
    echo ""
    echo "Available codes:"
    echo "  assistant, bluetoothled, blynk, blynkdht11i, dht, dhtled,"
    echo "  hc05dht11, ldr, ldrled, led, pushbutton, wifi"
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
