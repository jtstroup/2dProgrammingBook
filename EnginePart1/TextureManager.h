#ifndef _TEXTUREMANAGER_H	//prevent multiple definitions of this
#define _TEXTUREMANAGER_H	//file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "graphics.h"
#include "constants.h"

class TextureManager
{
private: 
	UINT		width;			//width of texture in pixels
	UINT		height;			//height of texture in pixels
	LP_TEXTURE	texture;		//pointer to texture
	const char	*file;			//name of file
	Graphics	*graphics;		//save pointer to graphics
	bool		initialized;	//true when successfully initialized
	HRESULT		hr;				//standard return type

public:
	//Constructor
	TextureManager();

	//Destructor
	virtual ~TextureManager();

	//Returns a pointer to texture
	LP_TEXTURE getTexture() const { return texture;}

	//Returns the texture width
	UINT getWidth() const {return width;}

	//Returns the texture height
	UINT getHeight() const {return height;}

	//Initialize the TextureManager
	//Pre:	*g points to graphics object
	//		*file points to name of the texture file to load
	//Post:	The texture file is loaded
	virtual bool initialize(Graphics *g, const char *file);

	//Release resources
	virtual void onLostDevice();

	//Restore resources
	virtual void onResetDevice();
};

#endif

