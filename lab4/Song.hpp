#ifndef SONG_HPP
#define SONG_HPP

#include "SongDuration.hpp"
#include <iostream>

class Song {

    private:

        std::string title;
        std::string artist;
        SongDuration duration;
    
    public:

        static unsigned int count_songs;
    
        Song();
        Song(std::string title, SongDuration duration, std::string artist="Unknown");
        Song(std::string title, unsigned int minutes, unsigned int seconds = 0, std::string artist = "Unknown");

        ~Song();

        void print() const;

        // - gettery
        
        std::string get_title() const { 
            
            return this->title;
        
        }
        
        std::string get_artist() const { 
            
            return this->artist;
        
        }

        unsigned int get_duration() const {

            return duration.get_total_seconds();

        }

        // - settery

        void set_title(std::string title) {

            this->title = title;

        }

        void set_artist(std::string artist) {

            this->artist = artist;

        }

        void set_duration(unsigned int seconds) {

            this->duration = {seconds / 60, seconds % 60};

        }

        static unsigned int get_total_songs();
 
};

#endif
