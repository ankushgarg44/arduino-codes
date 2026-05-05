param(
    [string]$Name
)

# ============================================
# REPLACE WITH YOUR ACTUAL GITHUB USERNAME
# ============================================
$Repo = "https://raw.githubusercontent.com/ankushgarg44/arduino-codes/main"

$FileMap = @{
    "assistant"   = "assistant.ino"
    "bluetoothled" = "bluetoothled.ino"
    "blynk"      = "blynk.ino"
    "blynkdht11i" = "blynkdht11i.ino"
    "dht"        = "dht.ino"
    "dhtled"     = "dhtled.ino"
    "hc05dht11"  = "hc05dht11.ino"
    "ldr"        = "ldr.ino"
    "ldrled"     = "ldrled.ino"
    "led"        = "led.ino"
    "pushbutton" = "pushbutton.ino"
    "wifi"       = "wifi.ino"
}

# Show list if no argument given
if (-not $Name) {
    Write-Host "Usage: .\getcode.ps1 -Name <name>" -ForegroundColor Yellow
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
