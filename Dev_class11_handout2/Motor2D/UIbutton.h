#ifndef __UI_BUTTON__
#define __UI_BUTTON__

#include "p2Point.h"
#include "p2SString.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1App.h"
#include "UIelement.h"
#include "j1Gui.h"
#include "j1Render.h"

class UIbutton : public UIelement
{
public:
	SDL_Texture* texture;
	//p2SString text;

	UIbutton() {};
	UIbutton(iPoint pos_, SDL_Rect rect_, const char* text_ = "", SDL_Color colour_ = { 255, 255, 255, 255 })
	{
		position = pos_;
		piece = rect_;
		texture = App->tex->textures.add(App->font->Print(text_, colour_, App->font->default))->data;
	}
	void Draw()
	{
		App->render->Blit(App->gui->GetAtlas(), position.x, position.y, &piece);
		App->render->Blit(texture, position.x, position.y + piece.h/2 - 10);
	}
};

#endif