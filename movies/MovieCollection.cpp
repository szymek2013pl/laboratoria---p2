#include "MovieCollection.hpp"

const std::map<char, std::vector<Movie<double>>>& MovieCollection::getMoviesByLetter() const{

    return moviesByLetter;

}

const std::vector<Movie<double>> MovieCollection::getAllMovies() {

    std::vector<Movie<double>> res;

    for (auto& it : moviesByLetter) {

        res.insert(res.end(), it.second.begin(), it.second.end());

    }

    return res;

}

void MovieCollection::addMovie(const Movie<double>& movie) {

    auto c = movie.getTitle()[0];
    moviesByLetter[c].push_back(movie);

}

void MovieCollection::sortMovies() {

    for (auto& movie : moviesByLetter) {

        std::sort(movie.second.begin(), movie.second.end());

    }

}

void MovieCollection::removeMoviesOlderThan(char letter, int year) {

    struct is_older {

        int year;

        is_older(int year) : year{year} {}

        bool operator()(const Movie<double>& movie) const {

            return movie.getYear() < year;

        }

    };

    auto it = moviesByLetter.find(letter);

    if (it != moviesByLetter.end()) {

        auto rit = std::remove_if(it->second.begin(), it->second.end(), is_older(year));
        it->second.erase(rit, it->second.end());

    }
     
}

double MovieCollection::getAverageTopRating() {

    struct top_rating {

        double operator()(double sum, const Movie<double>& movie) {

            return sum + movie.getTopRating();

        }

        top_rating() {}

    };

    auto res = getAllMovies();

    if (res.empty()) {

        return 0.0;

    }

    double total = std::accumulate(res.begin(), res.end(), 0.0, top_rating());

    return total / res.size();

}

std::vector<Movie<double>> MovieCollection::getMoviesByDirector(const std::string& director) {

    struct directed_by {

        std::string name;
        
        directed_by(std::string director) : name{director} {}
        
        bool operator()(const Movie<double>& movie) {

            if (std::holds_alternative<typename Movie<double>::Director>(movie.getDirector())) {

                return std::get<typename Movie<double>::Director>(movie.getDirector()).name == name;

            }

            else {

                return std::get<std::string>(movie.getDirector()) == name;

            }

        }

    };

    std::vector<Movie<double>> res;
    auto v = getAllMovies();

    std::copy_if(v.begin(), v.end(), std::back_inserter(res), directed_by(director));

    return res;

}

std::optional<Movie<double>> MovieCollection::findMovieWithAverageAbove(double threshold) {

    struct find_first {

        double val;

        find_first(double threshold) : val{threshold} {}

        bool operator()(const Movie<double>& movie) const{

            return movie.getAverageRating() > val;

        }

    };

    auto res = getAllMovies();
    auto first = std::find_if(res.begin(), res.end(), find_first(threshold));

    if (first != res.end()) {

        return *first; // - wyluskujemy wartosc pod iteratorem

    }
    
    return std::nullopt;

}

std::ostream& operator<<(std::ostream& os, const MovieCollection& collection) {

    for (const auto& it : collection.getMoviesByLetter()) { // - tutaj iterator nie jest jak wskaznik

        os << "=== " << it.first << " ===" << std::endl;

        for (auto jt = it.second.begin(); jt != it.second.end(); ++jt) { // - tutaj iterator jest jak wskaznik

            os << *jt << std::endl;

        }

    }

    return os;

}
