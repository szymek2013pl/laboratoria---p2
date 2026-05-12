#pragma once

#include <string>
#include <variant>
#include <optional>
#include <list>
#include <ostream>

template <typename RatingType>

class Movie {

    public:

        struct Director {

            std::string name;
            int numberOfOscars;

            Director(std::string s, int num) : name{s}, numberOfOscars{num} {}

        };
    
    private:
        
        std::string title;
        int year;
        std::variant<Director, std::string> director;
        std::optional<std::string> description;
        std::list<RatingType> ratings;
    
    public:
        
        // - etap 1
    
        Movie(std::string t, int y, std::variant<Director, std::string> dir, std::optional<std::string> desc = std::nullopt) : title{t}, year{y}, director{dir}, description{desc} {}

        const std::string& getTitle() const {

            return title;

        }

        int getYear() const {

            return year;

        }

        std::optional<std::string> getDescription() const {

            return description;

        }

        std::variant<Director, std::string> getDirector() const {

            return director;

        } 

        const std::list<RatingType>& getRatings() const {
        
            return ratings;

        }

        // - etap 2

        RatingType getAverageRating() const { // - !

            if (getRatings().empty()) {

                return RatingType(0);

            }
            
            RatingType sum(0);
            
            for (auto rating : ratings) {

                sum += rating;

            }

            return sum / ratings.size();

        }

        RatingType getTopRating() const { // - ! const, bo nie modyfikuje stanu

            if (getRatings().empty()) {

                return RatingType(0);

            }
            
            auto it = ratings.begin();
            RatingType val = *it;

            for (; it != ratings.end(); ++it) {

                if (*it > val) {

                    val = *it;

                }

            }

            return val;

        }

        bool operator<(const Movie& other) const {

            if (this->title == other.title) {

                return this->year < other.year; 

            }

            return this->title < other.title;

        }

        bool operator==(const Movie& other) const {

            return this->title == other.title && this->year == other.year;

        }

        Movie& operator+(RatingType rating) { // - ratings.push_back() poniewaz getter zwraca stala referencje

            ratings.push_back(rating);

            return *this;

        }

};

template <class RatingType>

std::ostream& operator<<(std::ostream& os, const Movie<RatingType>& movie) { // - z racji, ze przekazuje const Movie, to np. jest const auto&

    os << movie.getTitle() << "(" << movie.getYear() << "), ";

    if (std::holds_alternative<typename Movie<RatingType>::Director>(movie.getDirector())) {

        const auto& dir = std::get<typename Movie<RatingType>::Director>(movie.getDirector());
        os << "Director: " << dir.name << "(Oscars: " << dir.numberOfOscars << "), ";

    }

    else {
        
        os << "Director: " << std::get<std::string>(movie.getDirector()) << ", ";

    }

    os << "Avg: " << movie.getAverageRating() << ", Top: " << movie.getTopRating() << std::endl;

    if (movie.getDescription().has_value()) {

        os << "Description: " << *(movie.getDescription());

    }

    return os;

}
