#include <stdio.h>

int main() {
    float percentage_alcohol, total_volume, volume_alcohol;

    // Input percentage of alcohol in the total volume
    printf("Enter the percentage of alcohol in the total volume: ");
    scanf("%f", &percentage_alcohol);

    // Input total volume of liquid consumed (in milliliters)
    printf("Enter the total volume of liquid consumed (in milliliters): ");
    scanf("%f", &total_volume);

    // Calculate the volume of alcohol consumed (in milliliters)
    volume_alcohol = (percentage_alcohol / 100) * total_volume;

    // Output the volume of alcohol consumed
    printf("Volume of alcohol consumed: %.2f milliliters\n", volume_alcohol);

    // Check if the volume of alcohol consumed exceeds a certain threshold (e.g., 50 milliliters)
    if (volume_alcohol > 50) {
        printf("You have consumed a significant amount of alcohol!\n");
    }

    return 0;
}
