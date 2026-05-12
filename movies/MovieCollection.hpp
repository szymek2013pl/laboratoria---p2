#pragma once

#include "Movie.hpp"

#include <map>
#include <vector>
#include <algorithm>
#include <numeric>

class MovieCollection {

    private:

        std::map<char, std::vector<Movie<double>>> moviesByLetter;
    
    public:

        // - etap 3
    
        const std::map<char, std::vector<Movie<double>>>& getMoviesByLetter() const;
        const std::vector<Movie<double>> getAllMovies();
        void addMovie(const Movie<double>& movie);

        // - etap 4

        void sortMovies();
        void removeMoviesOlderThan(char letter, int year);
        double getAverageTopRating();
        std::vector<Movie<double>> getMoviesByDirector(const std::string& director);
        std::optional<Movie<double>> findMovieWithAverageAbove(double threshold);

};

std::ostream& operator<<(std::ostream&, const MovieCollection& collection);
