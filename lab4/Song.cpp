#include "Song.hpp"
#include "SongDuration.hpp"

Song::Song() : title{"Untilted"}, artist{"Unknown"}, duration{0, 0} {

    count_songs++;

}

Song::Song(std::string title, SongDuration duration, std::string artist) : title{title}, artist{artist}, duration{duration} {

    count_songs++;

}

Song::Song(std::string title, unsigned int minutes, unsigned int seconds, std::string artist) : title{title}, duration{minutes, seconds}, artist{artist} {

    count_songs++;

}

Song::~Song() {

    count_songs--;

}

void Song::print() const {
    
    std::cout << this->title << ", Artist: " << this->artist << " [" << duration.get_formatted() << ']' << std::endl;

}

unsigned int Song::count_songs = 0;

unsigned int Song::get_total_songs() {

    return count_songs;

}
