#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a ticket
struct Ticket
{
    int ticketNumber;
    char eventName[100];
    char eventDate[100];
    int availableSeats;
    int bookedSeats;
    float ticketPrice;
    struct Ticket *next;
};

// Global variable to store the list of events
struct Ticket *eventList = NULL;

// Function to create a new event ticket
struct Ticket *createTicket(int ticketNumber, const char *eventName, const char *eventDate, int availableSeats, float ticketPrice)
{
    struct Ticket *newTicket = (struct Ticket *)malloc(sizeof(struct Ticket));
    if (newTicket)
    {
        newTicket->ticketNumber = ticketNumber;
        strcpy(newTicket->eventName, eventName);
        strcpy(newTicket->eventDate, eventDate);
        newTicket->availableSeats = availableSeats;
        newTicket->bookedSeats = 0;
        newTicket->ticketPrice = ticketPrice;
        newTicket->next = NULL;
    }
    return newTicket;
}

// Function to add a new event to the event list
void addEvent(int ticketNumber, const char *eventName, const char *eventDate, int availableSeats, float ticketPrice)
{
    struct Ticket *newTicket = createTicket(ticketNumber, eventName, eventDate, availableSeats, ticketPrice);
    if (newTicket)
    {
        if (eventList == NULL)
        {
            eventList = newTicket;
        }
        else
        {
            struct Ticket *current = eventList;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newTicket;
        }
    }
}

// Function to display the list of available events
void displayEvents()
{
    struct Ticket *current = eventList;
    int eventNumber = 1;
    while (current)
    {
        printf("Event %d: %s\n", eventNumber, current->eventName);
        printf("Date: %s\n", current->eventDate);
        printf("Available Seats: %d\n", current->availableSeats);
        printf("Price per Ticket: $%.2f\n\n", current->ticketPrice);
        current = current->next;
        eventNumber++;
    }
}

// Function to book tickets for an event
void bookTickets(int eventNumber, int numTickets)
{
    struct Ticket *current = eventList;
    int eventCount = 1;
    while (current)
    {
        if (eventCount == eventNumber)
        {
            if (current->availableSeats >= numTickets)
            {
                current->availableSeats -= numTickets;
                current->bookedSeats += numTickets;
                printf("Successfully booked %d tickets for the event: %s\n", numTickets, current->eventName);
            }
            else
            {
                printf("Not enough available seats for the selected event.\n");
            }
            return;
        }
        current = current->next;
        eventCount++;
    }
    printf("Invalid event number.\n");
}

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
