#ifndef __UI_ELEMENT__
#define __UI_ELEMENT__

#include "p2Point.h"
#include "p2Log.h"

class UIelement
{
public:
	iPoint position;
	SDL_Rect piece = { 0,0,0,0 };
public:
	UIelement() {};
	~UIelement() {};

	virtual void OnClick() {};
	virtual bool OnRelease() { return true; };
	virtual void OnMouseOver() {  };

	virtual void Draw() {};

	SDL_Rect GetRect()
	{
		return { position.x,position.y,piece.w,piece.h };
	}
};

#endif