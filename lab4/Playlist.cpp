#include "Playlist.hpp"

Playlist::Playlist(unsigned int capacity) : capacity{capacity}, size{0} {

    songs = new Song [capacity];

};

Playlist::Playlist(const Playlist& other) : capacity{other.capacity} {

    size = other.size;

    songs = new Song [capacity];

    for (unsigned int i = 0; i < size; i++) {

        songs[i] = other.songs[i];

    }

}

Playlist& Playlist::operator=(const Playlist& other) {

    if (this == &other) {

        return *this;

    }

    if (capacity != other.capacity) {

        delete [] songs;
        songs = new Song [other.capacity];
        capacity = other.capacity;

    }

    size = other.size;

    for (unsigned int i = 0; i < size; i++) {

        songs[i] = other.songs[i];

    }

    return *this;

}

Playlist::Playlist(Playlist&& other) : songs{other.songs}, capacity{other.capacity}, size{other.size} {

    other.capacity = 0;
    other.size = 0;
    other.songs = nullptr;

}

Playlist& Playlist::operator=(Playlist&& other) {

    if (this == &other) {

        return *this;

    }

    delete [] songs;

    capacity = other.capacity;
    size = other.size;
    songs = other.songs;

    other.capacity = 0;
    other.size = 0;
    other.songs = nullptr;

    return *this;

}

Playlist::~Playlist() {

    delete [] songs;

}

void Playlist::resize(unsigned int new_capacity) {

    Song * temp = new Song [this->capacity];
    
    for (unsigned int i = 0; i < this->size; i++) {

        temp[i] = this->songs[i];

    }

    delete [] songs;
    songs = new Song [new_capacity];
    songs = temp;

}

void Playlist::add_song(const Song& song) {

    this->songs[this->size++] = song;

    if (this->size == this->capacity) {

        resize(2 * this->capacity);

    }

}

int Playlist::get_size() {

    return this->size;

}

void Playlist::print() {

    if (this->size == 0) {

        std::cout << "Playlist is empty" << std::endl;
        return;

    }
    
    for (unsigned int i = 0; i < this->size; i++) {

        //std::cout << i + 1 << ". " << songs[i].get_title() << ", Artist: " << songs[i].get_artist() << " " << songs[i].duration  << std::endl;

        //std::cout << i + 1 << ". " << songs[i].print() << std::endl;
        std::cout << i + 1 << ". ";
        songs[i].print();

    }

}
