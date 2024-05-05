#include "Action.h"

class SaveAction : public Action
{
protected:
	string FileName;

public:

	SaveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};