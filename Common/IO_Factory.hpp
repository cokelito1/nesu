#ifndef _IO_FACTORY_HPP_
#define _IO_FACTORY_HPP_

#include "config_reader.hpp"

#include "IO.hpp"
#include "SDL_Specific/SDL_IO.hpp"
#include "SFML_Specific/SFML_IO.hpp"

class IOFactory {
public:
    static IO* CreateIO(IO_Controller descriptor) {
        switch(descriptor) {
            case IO_Controller::SFML_IO:
                return new SFML_IO;
                break;
            case IO_Controller::SDL_IO:
                return new SDL_IO;
                break;
            default:
                return new SFML_IO;
                break;
        }
    }
}

#endif