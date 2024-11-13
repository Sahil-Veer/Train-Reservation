# Reservation System

## Description

This is a simple reservation system implemented in C that allows users to search for a reservation based on a 12-digit reservation number. If the reservation is found, the system displays the passenger's details such as their name, departure date, and departure time. If the reservation is not found, the user is given the option to add a new reservation (if space allows). The system supports up to 6 reservations.

## Problem Addressed

The program is designed to simulate the management of flight or event reservations. It helps manage the storage and retrieval of reservation data and provides the option to add new entries if the reservation number does not exist. The main features include:

- **Input Validation**: Ensures that only 12-digit numeric reservation numbers are accepted.
- **Searching for Reservations**: Allows users to search for existing reservations using a reservation number.
- **Adding New Reservations**: Prompts the user to add a new reservation if the number isn't found.
- **Capacity Limitation**: The system allows a maximum of 6 reservations and prevents adding more once the limit is reached.

## Concepts Used

- **Arrays**: Used to store reservation data such as reservation numbers, passenger names, dates, and times.
- **String Manipulation**: Functions like `strcpy()` and `strcmp()` are used to manage and compare reservation data.
- **Input Validation**: The program ensures that the reservation number input consists of only digits and is exactly 12 characters long.
- **User Interaction**: Uses `printf()` and `scanf()` to interact with the user, guiding them through the process of searching and adding reservations.

## Code Overview

The system stores reservation information in arrays. A user is prompted to enter a reservation number. If the number exists, the reservation details are displayed. If not, the user is asked if they would like to add a new reservation. If the maximum reservation limit (6) has been reached, no new reservations can be added.

The program consists of the following steps:
1. Prompt the user for a 12-digit reservation number.
2. Validate the input to ensure it is a valid 12-digit number.
3. Check if the reservation number exists in the system.
4. If found, display the reservation details.
5. If not found, ask the user if they wish to add a new reservation.
6. Allow the user to input new reservation data if space allows.

## Test Cases

### Test Case 1: Valid Reservation Number (Existing)
- **Input**: Reservation number `911234567890`
- **Expected Output**: 

```
Reservation found: Passenger Name: Alice Departure Date: 20-11-2024 Departure Time: 10:00 AM
```

### Test Case 2: Invalid Reservation Number (Non-numeric)
- **Input**: Reservation number `abc123456789`

- **Expected Output**: 

```
Invalid input. Reservation number must be 12 digits, containing only numbers.
```


### Test Case 3: Invalid Reservation Number (Incorrect Length)
- **Input**: Reservation number `12345`

- **Expected Output**: 

```
Invalid input. Reservation number must be 12 digits, containing only numbers.
```

### Test Case 4: Reservation Number Not Found (Add New Reservation)
- **Input**: Reservation number `123456789012` (not existing)

- **Expected Output**: 

```
Reservation number not found. Would you like to add a new reservation? (y/n): y Enter passenger name: John Doe Enter departure date (DD-MM-YYYY): 25-11-2024 Enter departure time (e.g., 10:00 AM): 1:00 PM Reservation added successfully for John Doe on 25-11-2024 at 1:00 PM.
```

### Test Case 5: Reservation Directory Full (No New Reservations)
- **Input**: Attempt to add a 7th reservation when the system already holds 6 reservations.

- **Expected Output**: 
```
Directory is full. Cannot add more reservations.
```

## References

- [C Programming Language](https://en.wikipedia.org/wiki/C_(programming_language))
- [String Functions in C](https://www.cprogramming.com/tutorial/c/lesson4.html)
- [Input Validation in C](https://www.geeksforgeeks.org/c-program-to-validate-email-address/)











ChatGPT can make mistakes. Ch