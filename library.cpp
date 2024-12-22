#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book
{
private:
    string Title;
    string Author;
    int ISBN;
    bool isAvailable;

public:
    // constructor
    Book(string t, string a, int i, bool avail) : Title(t), Author(a), ISBN(i), isAvailable(avail) {}

    // getters
    string getTitle() const { return Title; }
    string getAuthor() const { return Author; }
    int getISBN() const { return ISBN; }
    bool getAvailability() const { return isAvailable; }

    void borrowBook() { isAvailable = false; }
    void returnBook() { isAvailable = true; }
    void displayBooks() const
    {
        cout << "Title : " << Title << ", Author : " << Author << ", ISBN : " << ISBN << ", Available : " << (isAvailable ? "Yes" : "No") << endl;
    }
};
void displayMenu()
{
    cout << "\n1. Add Book" << endl;
    cout << "2. Search Book" << endl;
    cout << "3. Borrow Book" << endl;
    cout << "4. Return Book" << endl;
    cout << "5. Display All Books" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

vector<Book> library;
int main()
{
    int choice;
    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Add book
            string Title, Author;
            int ISBN;
            bool isAvailable;
            cin.ignore();
            cout << " Enter the Title of the book: ";
            getline(cin, Title);
            cout << " Enter the Author of the book: ";
            getline(cin, Author);
            cout << " Enter the ISBN of the book: ";
            cin >> ISBN;
            cout << " Is  the book Available (1 for Yes, 0 for No): ";
            cin >> isAvailable;

            library.emplace_back(Title, Author, ISBN, isAvailable);
            cout << "Book added successfully!" << endl;
            break;
        }

        case 2:
        {
            // search food
            string searchTitle;
            cin.ignore();
            cout << "Enter book title to search: ";
            getline(cin, searchTitle);

            bool found = false;
            for (const auto &book : library)
            {
                if (book.getTitle() == searchTitle)
                {
                    book.displayBooks();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Book not found." << endl;
            }
            break;
        }

        case 3:
        { // borrow book
            string borrowTitle;
            cin.ignore();
            cout << "Enter book title to borrow: ";
            getline(cin, borrowTitle);

            bool found = false;
            for (auto &book : library)
            {
                if (book.getTitle() == borrowTitle)
                {
                    if (book.getAvailability())
                    {
                        book.borrowBook();
                        cout << "The book has been borrowed successfully!" << endl;
                    }
                    else
                    {
                        cout << "The book is already borrowed!" << endl;
                    }
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Book not found!" << endl;
            }
            break;
        }

        case 4:
        {
            // return book
            string returnTitle;
            cin.ignore();
            cout << "Enter book title to return: ";
            getline(cin, returnTitle);

            bool found = false;
            for (auto &book : library)
            {
                if (book.getTitle() == returnTitle)
                {
                    book.returnBook();
                    cout << "The book has been returned successfully!" << endl;
                }
                else
                {
                    cout << "The book was not borrowed!" << endl;
                }
                found = true;
                break;
            }
            if (!found)
            {
                cout << "Book not found!" << endl;
            }
            break;
        }

        case 5:
        {
            // Display all book
            if (library.empty())
            {
                cout << "No books in the library!" << endl;
            }
            else
            {
                cout << "\nDisplaying all books:" << endl;
                for (const auto &book : library)
                {
                    book.displayBooks();
                }
            }

            break;
        }

        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (choice != 6);
    return 0;
}
