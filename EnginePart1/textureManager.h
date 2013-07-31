//The loadTexture function, which we added to the Graphics class, loads the texture data 
//into D3DPOOL_DEFAULT memory. This is normally video memory. If the graphics device is 
//used by another application, it may become unavailable or “lost” to our game. If that happens, we will need to release and reload the texture data as part of the process of recovering 
//the lost graphics device. By creating a separate texture manager class, we can include the 
//code for dealing with a lost device. When we need to use a texture in our game, we will create a TextureManager object to load and manage each texture.
//The TextureManager initialize function saves a pointer to the graphics system 
//and loads the specified texture file from disk. The graphics->loadTexture function 
//saves the width, height, and pointer to the texture data (Listing 5.17).
//
//Charles; Kelly (2012-07-09). Programming 2D Games (Page 124). A. K. Peters. Kindle Edition. 

#ifndef _TEXTUREMANAGER_H       // Prevent multiple definitions if this 
#define _TEXTUREMANAGER_H       // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "graphics.h"
#include "constants.h"

class TextureManager
{
    // TextureManager properties
  private:
    UINT       width;       // width of texture in pixels
    UINT       height;      // height of texture in pixels
    LP_TEXTURE texture;     // pointer to texture
    const char *file;       // name of file
    Graphics *graphics;     // save pointer to graphics
    bool    initialized;    // true when successfully initialized
    HRESULT hr;             // standard return type

  public:
    // Constructor
    TextureManager();

    // Destructor
    virtual ~TextureManager();

    // Returns a pointer to the texture
    LP_TEXTURE getTexture() const {return texture;}

    // Returns the texture width
    UINT getWidth() const {return width;}

    // Return the texture height
    UINT getHeight() const {return height;}

    // Initialize the textureManager
    // Pre: *g points to Graphics object
    //      *file points to name of texture file to load
    // Post: The texture file is loaded
    virtual bool initialize(Graphics *g, const char *file);

    // Release resources
    virtual void onLostDevice();

    // Restore resourses
    virtual void onResetDevice();
};

#endif

