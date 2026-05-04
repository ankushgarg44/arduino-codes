param(
    [string]$Name
)

# ============================================
# REPLACE WITH YOUR ACTUAL GITHUB USERNAME
# ============================================
$Repo = "https://raw.githubusercontent.com/ankushgarg44/arduino-codes/main"

$FileMap = @{
    "ldr"        = "ldr.ino"
    "temp"       = "temp.ino"
    "motor"      = "motor.ino"
    "servo"      = "servo.ino"
    "blink"      = "blink.ino"
    "ultrasonic" = "ultrasonic.ino"
    "pir"        = "pir.ino"
    "bluetooth"  = "bluetooth.ino"
    "wifi"       = "wifi.ino"
    "oled"       = "oled.ino"
    "keypad"     = "keypad.ino"
    "rfid"       = "rfid.ino"
    "joystick"   = "joystick.ino"
    "relay"      = "relay.ino"
    "buzzer"     = "buzzer.ino"
}

# Show list if no argument given
if (-not $Name) {
    Write-Host "Usage: getcode <name>" -ForegroundColor Yellow
    Write-Host ""
    Write-Host "Available codes:" -ForegroundColor Cyan
    $FileMap.Keys | Sort-Object | ForEach-Object { Write-Host "  $_" }
    return   # <-- FIXED: was 'exit', now 'return'
}

# Validate name
if (-not $FileMap.ContainsKey($Name)) {
    Write-Host "❌ Unknown code: $Name" -ForegroundColor Red
    Write-Host ""
    Write-Host "Available codes:" -ForegroundColor Cyan
    $FileMap.Keys | Sort-Object | ForEach-Object { Write-Host "  $_" }
    return   # <-- FIXED: was 'exit', now 'return'
}

# Fetch code
$Url = "$Repo/$($FileMap[$Name])"
try {
    $Code = Invoke-RestMethod -Uri $Url -ErrorAction Stop
} catch {
    Write-Host "❌ Failed to fetch $Url" -ForegroundColor Red
    return   # <-- FIXED
}

if (-not $Code) {
    Write-Host "❌ Empty response from server." -ForegroundColor Red
    return   # <-- FIXED
}

# Copy to clipboard
try {
    $Code | Set-Clipboard
    Write-Host "✅ '$Name' code copied to clipboard!" -ForegroundColor Green
} catch {
    try {
        Add-Type -AssemblyName System.Windows.Forms
        [System.Windows.Forms.Clipboard]::SetText($Code)
        Write-Host "✅ '$Name' code copied to clipboard!" -ForegroundColor Green
    } catch {
        Write-Host "⚠️ Could not copy to clipboard. Printing instead:" -ForegroundColor Yellow
        Write-Output $Code
    }
}
