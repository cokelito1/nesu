#ifndef _CONFIG_READER_HPP_
#define _CONFIG_READER_HPP_

#include <string>

enum class IO_Controller {
    SFML_IO,
    SDL_IO
};

enum class Graphic_Controller {
    SFML_Graphics,
    SDL_Graphics
};

enum class Audio_Controller {
    SFML_Audio,
    SDL_Audio
};

struct config_ctx {
    IO_Controller IO;
    Graphic_Controller Graphics;
    Audio_Controller Audio;

    config_ctx() {
        IO = IO_Controller::SFML_IO;
        Graphics = Graphic_Controller::SFML_Graphics;
        Audio = Audio_Controller::SFML_Audio;
    }
};

class ConfigReader {
public:
    ConfigReader();
    ConfigReader(const std::string& filename);
    ~ConfigReader();

    std::string GetStringConfig(const std::string& key);
    int GetIntegerConfig(const::std::string& key);

    config_ctx GetConfiguration();
private:
    std::string config_file;
};

#endif