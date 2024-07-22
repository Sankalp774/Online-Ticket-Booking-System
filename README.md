# Online Ticket Booking System

This project is a simple Online Ticket Booking System implemented in C. It allows users to add events, display a list of events, and book tickets for these events. The project demonstrates basic concepts of linked lists, structures, and file handling in C.

## Features

- **Add Events**: Add new events to the system with details like event name, date, available seats, and ticket price.
- **Display Events**: Display the list of available events with their details.
- **Book Tickets**: Book tickets for a selected event, updating the available seats and booked seats accordingly.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)

### Installation

1. Clone the repository:

    ```sh
    git clone https://github.com/yourusername/online-ticket-booking-system.git
    cd online-ticket-booking-system
    ```

2. Compile the program:

    ```sh
    gcc -o ticket_booking_system ticket_booking_system.c
    ```

3. Run the executable:

    ```sh
    ./ticket_booking_system
    ```

## Usage

Upon running the program, you will be presented with a menu with the following options:

1. **Display Events**: Lists all the events available for booking along with their details.
2. **Book Tickets**: Prompts for the event number and the number of tickets to book. Updates the available and booked seats for the selected event.
3. **Exit**: Exits the program.

Example usage:

1. To display events, choose option `1`.
2. To book tickets, choose option `2`, enter the event number, and then the number of tickets.
3. To exit, choose option `3`.

## Code Overview

### Structures

- **Ticket**: Represents an event ticket with details like ticket number, event name, event date, available seats, booked seats, and ticket price. It also contains a pointer to the next ticket in the list.

    ```c
    struct Ticket {
        int ticketNumber;
        char eventName[100];
        char eventDate[100];
        int availableSeats;
        int bookedSeats;
        float ticketPrice;
        struct Ticket *next;
    };
    ```

### Global Variables

- **eventList**: A pointer to the list of events.

    ```c
    struct Ticket *eventList = NULL;
    ```

### Functions

- **createTicket**: Creates a new ticket with the given details.

    ```c
    struct Ticket *createTicket(int ticketNumber, const char *eventName, const char *eventDate, int availableSeats, float ticketPrice);
    ```

- **addEvent**: Adds a new event to the event list.

    ```c
    void addEvent(int ticketNumber, const char *eventName, const char *eventDate, int availableSeats, float ticketPrice);
    ```

- **displayEvents**: Displays the list of available events.

    ```c
    void displayEvents();
    ```

- **bookTickets**: Books tickets for a specified event.

    ```c
    void bookTickets(int eventNumber, int numTickets);
    ```

## Example Code

```c
int main()
{
    addEvent(1, "Concert", "2023-11-10", 100, 50.0);
    addEvent(2, "Movie Premiere", "2023-11-15", 50, 20.0);
    addEvent(3, "Sports Game", "2023-11-20", 200, 30.0);

    int choice;
    int eventNumber, numTickets;
    while (1)
    {
        printf("Online Ticket Booking System\n");
        printf("1. Display Events\n");
        printf("2. Book Tickets\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayEvents();
            break;
        case 2:

            printf("Enter the event number you want to book tickets for: ");
            scanf("%d", &eventNumber);
            printf("Enter the number of tickets you want to book: ");
            scanf("%d", &numTickets);
            bookTickets(eventNumber, numTickets);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any changes or improvements.

## Contact

For any questions or comments, please contact [yourname](mailto:yourname@example.com).

---

Feel free to customize this README further according to your project's specific needs.
