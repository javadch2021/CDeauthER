# CDeauthER
A C-based tool for authorized Wi-Fi network scanning and deauthentication attacks using airodump-ng and aireplay-ng, allowing targeted access point scanning and deauthentication of connected stations.



# Network Scan and Deauthentication Tool

This project is a network scanning and deauthentication tool developed in C. It uses `airodump-ng` and `aireplay-ng` to perform network scanning, identify specific targets, and execute targeted deauthentication attacks. The project supports automatic scanning and execution through a command-line interface.

> **Disclaimer**: This tool is for educational purposes only. Unauthorized network scanning or deauthentication attacks are illegal and against most network policies. Use this tool only on networks you own or have explicit permission to test.

---

## Features

- **Full Network Scanning**: Scans all nearby Wi-Fi networks and displays access points.
- **Targeted Scanning**: Allows targeted scanning based on a user-selected MAC address and channel.
- **Deauthentication Attack**: Supports a deauthentication attack on a specific network station.
- **Executable Execution**: Executes an external executable after scanning is complete.

---

## Requirements

- **Operating System**: Linux-based OS (recommended: Kali Linux or any system with aircrack-ng suite installed)
- **Libraries**: Standard C libraries (`stdio.h`, `stdlib.h`, `string.h`, `unistd.h`)
- **Tools**: `airmon-ng`, `airodump-ng`, `aireplay-ng` (part of the aircrack-ng suite)

---

## Installation

1. **Install the aircrack-ng suite** if not already installed:

   ```bash
   sudo apt update
   sudo apt install aircrack-ng

---

## Sample Usage Flow

```
$ sudo ./app -run

Starting monitor mode on wlan0...
Running full network scan... Press Ctrl+C to stop when ready.

# After identifying the target network in the scan output, press Ctrl+C

Enter the target MAC address (e.g., AA:BB:CC:DD:EE:FF): AA:BB:CC:DD:EE:FF
Enter the channel number for the target network: 6
Running targeted scan on AA:BB:CC:DD:EE:FF (channel 6)... Press Ctrl+C to stop.

# After targeted scan completes

Targeted scan complete. Running the executable file...
Stopping monitor mode on wlan0mon...

```
