#ifndef __UI_IMAGE__
#define __UI_IMAGE__

#include "p2Point.h"
#include "p2SString.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1App.h"
#include "UIelement.h"
#include "j1Gui.h"
#include "j1Render.h"

class UIimage : public UIelement
{
public:
	UIimage() {};
	UIimage(iPoint pos_, SDL_Rect rect_)
	{
		position = pos_;
		piece = rect_;
	}
	~UIimage() {};

	virtual void Draw()
	{
		App->render->Blit(App->gui->GetAtlas(), position.x, position.y, &piece);
	}
};

#endif