#ifndef __UI_TEXT__
#define __UI_TEXT__

#include "p2Point.h"
#include "p2SString.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1App.h"
#include "UIelement.h"
#include "j1Gui.h"
#include "j1Render.h"

class UItext : public UIelement
{
public:
	SDL_Texture* texture;
	//p2SString text;
	SDL_Color colour;
public:
	UItext() {};
	UItext(iPoint pos_, const char* text_, SDL_Color colour_)
	{
		position = pos_;
		texture = App->tex->textures.add(App->font->Print(text_, colour_, App->font->default))->data;
	}

	void Draw()
	{
		App->render->Blit(texture, position.x, position.y);
	}
};

#endif