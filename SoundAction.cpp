#include "SoundAction.h"
#include "ApplicationManager.h"
#include <windows.h>
#include <string>


SoundAction::SoundAction(ApplicationManager* pApp) : Action(pApp)
{
	
}

void SoundAction::ReadActionParameters()
{
	SoundOn = pManager->GetSoundOn();
	action = pManager->GetActType();

	if (action == D_SOUND || action == P_SOUND)
	{
		SoundOn = !SoundOn;
		pManager->SetSoundOn(SoundOn);

	}

	if (SoundOn)
	{
		switch (action)
		{
		case(DRAW_RECT):
			file = "rectangle.wav";
			break;
		case(DRAW_SQR):
			file = "square.wav";
			break;
		case(DRAW_TRI):
			file = "triangle.wav";
			break;
		case(DRAW_CIR):
			file = "circle.wav";
			break;
		case(DRAW_HEX):
			file = "hexagon.wav";
			break;
		case(SELECT):
			file = "select.wav";
			break;
		case(BORDER):
			file = "border color.wav";
			break;
		case(FILL):
			file = "fill color.wav";
			break;
		case(COPY):
			file = "copy.wav";
			break;
		case(CUT):
			file = "cut.wav";
			break;
		case(CLEAR):
			file = "clear all.wav";
			break;
		case(PASTE):
			file = "paste.wav";
			break;
		case(I_DELETE):
			file = "delete.wav";
			break;

		case(R14):
		case(R12):
		case(R2):
		case(R4):
			file = "resize.wav";
			break;
		case(FORWARD):
			file = "bring to front.wav";
			break;
		case(BACKWARD):
			file = "send to back.wav";
			break;
		case(SAVE):
			file = "save file.wav";
			break;
		case(LOAD):
			file = "load file.wav";
			break;
		case(TO_PLAY):
			file = "switch to play mode.wav";
			break;
		case(TO_DRAW):
			file = "switch to draw mode.wav";
			break;
		case(FIG_TYPE):
			file = "play with figures.wav";
			break;
		case(FIG_COLOR):
			file = "play with colors.wav";
			break;
		case(BOTH):
			file = "play with colored figures.wav";
			break;


		case(D_SOUND):
			file = "sound on.wav";
			break;
		case(P_SOUND):
			file = "sound on.wav";
			break;



		}
	}
	else if(action == D_SOUND || action == P_SOUND)
		file = "sound off.wav";





}

//Execute the action
void SoundAction::Execute()
{
	
	//This action needs to read some parameters first
	ReadActionParameters();

	PlaySound(TEXT(file), NULL, SND_ASYNC);
	file = "";

}