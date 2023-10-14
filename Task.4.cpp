#include <iostream>
#include <vector>


struct Movie {
    std::string title;
    int price;
    int seats;
};

void displayMovies(const std::vector<Movie>& movies) {
    std::cout << "Movie Listings:" << std::endl;
    for (int i = 0; i < movies.size(); ++i) {
        std::cout << i + 1 << ". " << movies[i].title << " - $" << movies[i].price << " (" << movies[i].seats << " seats available)" << std::endl;
    }
}

int main() {
    
    std::vector<Movie> movies = {
        {"Movie 1", 10, 50},
        {"Movie 2", 12, 60},
        {"Movie 3", 8, 40}
    };

    while (true) {
        displayMovies(movies);

        int choice;
        std::cout << "Select a movie (1-3) or enter 0 to exit: ";
        std::cin >> choice;

        if (choice == 0) {
            break;
        }

        if (choice >= 1 && choice <= movies.size()) {
            int movieIndex = choice - 1;

            int numTickets;
            std::cout << "Enter the number of tickets you want to book: ";
            std::cin >> numTickets;

            if (numTickets > 0 && numTickets <= movies[movieIndex].seats) {
                
                movies[movieIndex].seats -= numTickets;

                int totalCost = numTickets * movies[movieIndex].price;
                std::cout << "Booking confirmed for " << numTickets << " tickets to " << movies[movieIndex].title << "!" << std::endl;
                std::cout << "Total cost: $" << totalCost << std::endl;
            } else {
                std::cout << "Invalid number of tickets or not enough seats available. Please try again." << std::endl;
            }
        } else {
            std::cout << "Invalid movie selection. Please try again." << std::endl;
        }
    }

    return 0;
}
