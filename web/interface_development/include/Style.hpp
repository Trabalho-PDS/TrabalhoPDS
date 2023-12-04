#pragma once

#include <string>
#include <list>

namespace cwi{

class Style{
    public:
        Style();

        void font_family(std::string font);
        void font_size(int size, std::string unit = "px");
        void font_weight(int size, std::string unit = "px");

        void padding(int size, std::string unit = "px", std::string dir = "");
        
        void margin(int size = 0, std::string unit = "px", std::string dir = "");
	    void margin(std::string dir = "", std::string type = "auto");
	
        void border(int size, std::string type, std::string color);
        void border_radius(int radius);
        
        void height(int size, std::string unit = "px");
        void height(std::string type);
        void max_height(int size, std::string unit = "px");
        
        void width(int size, std::string unit = "px");
        void width(std::string type);
        void max_width(int size, std::string unit = "px");
        
        void color(std::string color);
        void background_color(std::string color);
        void background_image(std::string locate);
        void background_size(std::string config);
        void background_attachment(std::string mode);
        void background_repeat(std::string mode);

        void filter(std::string config);
        void backdrop_filter(std::string config);
        
        void display(std::string type);
	
        void text_align(std::string type);
        
        void flex_wrap(std::string type);
        void flex(int size);

        void overflow(std::string type);
        
        std::list<std::string> property();

    private:
        std::list<std::string> _style;
};

}

