#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_RESERVATIONS 6
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 11
#define MAX_TIME_LENGTH 10
#define RESERVATION_NUM_LENGTH 12

//to check if a string contains only digits
int is_valid_reservation_number(const char *number) {
    for (int i = 0; i < RESERVATION_NUM_LENGTH; i++) {
        if (!isdigit(number[i])) {
            return 0;  // return 0 if the character is not a digit
        }
    }
    return 1;  // return 1 if all characters are digits
}

int main() {
    // rrays to store reservation details
    char reservation_numbers[MAX_RESERVATIONS][RESERVATION_NUM_LENGTH + 1];
    char passenger_names[MAX_RESERVATIONS][MAX_NAME_LENGTH + 1];
    char depart_dates[MAX_RESERVATIONS][MAX_DATE_LENGTH + 1];
    char depart_times[MAX_RESERVATIONS][MAX_TIME_LENGTH + 1];

    int current_size = 5;
    // reservation data
    strcpy(reservation_numbers[0], "911234567890");
    strcpy(passenger_names[0], "Alice");
    strcpy(depart_dates[0], "20-11-2024");
    strcpy(depart_times[0], "10:00 AM");

    strcpy(reservation_numbers[1], "012345678901");
    strcpy(passenger_names[1], "Bob");
    strcpy(depart_dates[1], "21-11-2024");
    strcpy(depart_times[1], "2:30 PM");

    strcpy(reservation_numbers[2], "993456789012");
    strcpy(passenger_names[2], "Charlie");
    strcpy(depart_dates[2], "22-11-2024");
    strcpy(depart_times[2], "6:15 PM");

    strcpy(reservation_numbers[3], "554567890123");
    strcpy(passenger_names[3], "David");
    strcpy(depart_dates[3], "23-11-2024");
    strcpy(depart_times[3], "9:00 AM");

    strcpy(reservation_numbers[4], "885678901234");
    strcpy(passenger_names[4], "Eve");
    strcpy(depart_dates[4], "24-11-2024");
    strcpy(depart_times[4], "11:45 AM");

    char input_number[RESERVATION_NUM_LENGTH + 1];
    int valid_input = 0;
    
    // until valid reservation number is entered
    while (!valid_input) {
        printf("Enter a 12-digit reservation number to search: ");
        scanf("%12s", input_number);

        // to ensure it's only digits
        if (is_valid_reservation_number(input_number)) {
            valid_input = 1;  // exit
        } else {
            printf("Invalid input. Reservation number must be 12 digits, containing only numbers.\n");
        }
    }

    int found = -1; // index of found reservation
    for (int i = 0; i < current_size; i++) {
        if (strcmp(reservation_numbers[i], input_number) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        // reservation found
        printf("Reservation found:\n");
        printf("Passenger Name: %s\n", passenger_names[found]);
        printf("Departure Date: %s\n", depart_dates[found]);
        printf("Departure Time: %s\n", depart_times[found]);
    } else {
        // reservation not found / add new one
        printf("Reservation number not found. Would you like to add a new reservation? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            if (current_size >= MAX_RESERVATIONS) {
                printf("Directory is full. Cannot add more reservations.\n");
            } else {
                char name[MAX_NAME_LENGTH + 1], date[MAX_DATE_LENGTH + 1], time[MAX_TIME_LENGTH + 1];
                printf("Enter passenger name: ");
                scanf(" %50[^\n]", name);  // %50 --> 50 characters, [^\n] --> accept spaces in i/p string
                printf("Enter departure date (DD-MM-YYYY): ");
                scanf("%10s", date);
                printf("Enter departure time (e.g., 10:00 AM): ");
                scanf("%9s", time);

                // add the new reservation
                strcpy(reservation_numbers[current_size], input_number);
                strcpy(passenger_names[current_size], name);
                strcpy(depart_dates[current_size], date);
                strcpy(depart_times[current_size], time);

                current_size++;  // increment the size of the reservation array
                printf("Reservation added successfully for %s on %s at %s.\n", name, date, time);
            }
        } else {
            printf("No new reservation was added.\n");
        }
    }

    return 0;
}
