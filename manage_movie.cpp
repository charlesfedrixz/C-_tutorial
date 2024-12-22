#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Movie
{
private:
    string movieName;
    string genre;
    int duration;
    double ticket_price;
    int ticket_available;

public:
    // Constructor
    Movie(string m, string g, int d, double tp, int ta)
        : movieName(m), genre(g), duration(d), ticket_price(tp), ticket_available(ta) {}

    // Getters
    string getName() const { return movieName; }
    string getGenre() const { return genre; }
    int getDuration() const { return duration; }
    double getPrice() const { return ticket_price; }
    int getAvailable() const { return ticket_available; }

    // Display movie details
    void displayInfo() const
    {
        cout << "Movie Name: " << movieName << ", Genre: " << genre
             << ", Duration: " << duration << " mins, Ticket Price: " << ticket_price
             << ", Tickets Available: " << ticket_available << endl;
    }

    // Book tickets
    bool bookTicket(int ticketBook)
    {
        if (ticketBook <= 0)
        {
            cout << "Number of tickets must be greater than 0." << endl;
            return false;
        }
        if (ticketBook > ticket_available)
        {
            cout << "Not enough tickets available. Only " << ticket_available << " tickets left." << endl;
            return false;
        }
        ticket_available -= ticketBook;
        cout << ticketBook << " ticket(s) booked successfully!" << endl;
        return true;
    }

    // Cancel tickets
    bool cancelTicket(int ticketCancel)
    {
        if (ticketCancel <= 0)
        {
            cout << "Number of tickets must be greater than 0." << endl;
            return false;
        }
        ticket_available += ticketCancel;
        cout << ticketCancel << " ticket(s) canceled successfully!" << endl;
        return true;
    }
};

void displayMenu()
{
    cout << "\n------ Movie Menu ------" << endl;
    cout << "1. Add Movie" << endl;
    cout << "2. Display All Movies" << endl;
    cout << "3. Book Tickets" << endl;
    cout << "4. Cancel Tickets" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    vector<Movie> Movies;
    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Add Movie
            string name, genre;
            int duration, available;
            double price;

            cin.ignore(); // Clear input buffer
            cout << "Enter movie name: ";
            getline(cin, name);
            cout << "Enter genre: ";
            getline(cin, genre);
            cout << "Enter duration (in minutes): ";
            cin >> duration;
            cout << "Enter ticket price: ";
            cin >> price;
            cout << "Enter total tickets available: ";
            cin >> available;

            Movies.emplace_back(name, genre, duration, price, available);
            cout << "Movie added successfully!" << endl;
            break;
        }
        case 2:
        {
            // Display All Movies
            if (Movies.empty())
            {
                cout << "No movies available!" << endl;
            }
            else
            {
                cout << "\nDisplaying all movies:\n";
                for (const auto &movie : Movies)
                {
                    movie.displayInfo();
                }
            }
            break;
        }
        case 3:
        {
            // Book Tickets
            string name;
            int tickets;

            cin.ignore(); // Clear input buffer
            cout << "Enter movie name to book tickets: ";
            getline(cin, name);

            bool found = false;
            for (auto &movie : Movies)
            {
                if (movie.getName() == name)
                {
                    cout << "Enter the number of tickets to book: ";
                    cin >> tickets;

                    movie.bookTicket(tickets);
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Movie not found!" << endl;
            }
            break;
        }
        case 4:
        {
            // Cancel Tickets
            string name;
            int tickets;

            cin.ignore(); // Clear input buffer
            cout << "Enter movie name to cancel tickets: ";
            getline(cin, name);

            bool found = false;
            for (auto &movie : Movies)
            {
                if (movie.getName() == name)
                {
                    cout << "Enter the number of tickets to cancel: ";
                    cin >> tickets;

                    movie.cancelTicket(tickets);
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Movie not found!" << endl;
            }
            break;
        }
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }

    } while (choice != 5);

    return 0;
}
