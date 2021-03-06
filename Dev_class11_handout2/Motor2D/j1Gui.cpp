#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Window.h"
#include "j1Gui.h"

#include "UIimage.h"
#include "UItext.h"
#include "UIbutton.h"

j1Gui::j1Gui() : j1Module()
{
	name.create("gui");
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	atlas = App->tex->Load(atlas_file_name.GetString());

	background = App->tex->Load("gui/background.png");

	/*UIelement* ship_image = new UIimage({ 80, 80 }, { 485, 829, 328, 103 });
	elements.add(ship_image);
	UIelement* example_text = new UItext({ (ship_image->position.x + ship_image->piece.w/2), 65 }, "Hello World", { 255, 255, 0, 255 });
	elements.add(example_text);
	UIelement* ship_button = new UIbutton({ 80, 200 }, { 485, 829, 328, 103 }, "Hello World", { 255, 255, 0, 255 });
	elements.add(ship_button);*/

	UIelement* blizzard = new UIimage({ 450, 480 }, { 271, 0, 127, 80 });
	elements.add(blizzard);
	UIelement* warning = new UIimage({ 20, 500 }, { 275, 84, 130, 39 });
	elements.add(warning);
	UIelement* wowlogo = new UIimage({ 10, 10 }, { 2, 205, 312, 135 });
	elements.add(wowlogo);
	UIelement* textbox1 = new UIimage({ 450, 300 }, { 6, 116, 127, 22 });
	elements.add(textbox1);
	UIelement* check_button = new UIbutton({ 20, 470 }, { 407, 293, 16, 16 });
	elements.add(check_button);
	UIelement* check_text = new UItext({ 45, 470 }, "Remember Account Name", { 255, 255, 0, 255 });
	elements.add(check_text);
	UIelement* button = new UIbutton({ 80, 80 }, { 118, 2, 127, 22 });
	elements.add(button);
	

	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	App->render->Blit(background, 0, 0);

	p2List_item<UIelement*>* item = elements.start;

	while (item != NULL)
	{
		item->data->Draw();
		item = item->next;
	}

	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");
	App->render->Blit(background, 0, 0);

	p2List_item<UIelement*>* item = elements.start;

	while (item != NULL)
	{
		RELEASE(item->data);
		item = item->next;
	}

	return true;
}

// const getter for atlas
SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

// class Gui ---------------------------------------------------

